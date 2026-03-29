#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>

using namespace std;

class ThreadPool {
private:
    vector<thread> workers;                  // Worker threads
    queue<function<void()>> tasks;           // Task queue

    mutex queue_mutex;
    condition_variable condition;
    atomic<bool> stop;

public:
    // Constructor
    ThreadPool(int num_threads) : stop(false) {
        for (int i = 0; i < num_threads; i++) {
            workers.emplace_back([this]() {
                while (true) {
                    function<void()> task;

                    {
                        unique_lock<mutex> lock(this->queue_mutex);

                        // Wait until task available OR stop signal
                        this->condition.wait(lock, [this]() {
                            return this->stop || !this->tasks.empty();
                        });

                        if (this->stop && this->tasks.empty())
                            return;

                        task = move(this->tasks.front());
                        this->tasks.pop();
                    }

                    // Execute task
                    task();
                }
            });
        }
    }

    // Add new task
    void enqueue(function<void()> task) {
        {
            unique_lock<mutex> lock(queue_mutex);
            tasks.push(move(task));
        }
        condition.notify_one();
    }

    // Destructor (cleanup)
    ~ThreadPool() {
        stop = true;
        condition.notify_all();

        for (thread &worker : workers) {
            worker.join();
        }
    }
};

// Example task
void exampleTask(int id) {
    cout << "Task " << id << " is running on thread "
         << this_thread::get_id() << endl;

    this_thread::sleep_for(chrono::seconds(1));

    cout << "Task " << id << " completed" << endl;
}

// Main function
int main() {
    ThreadPool pool(4); // 4 threads

    // Add tasks
    for (int i = 1; i <= 10; i++) {
        pool.enqueue([i]() {
            exampleTask(i);
        });
    }

    // Give time for tasks to finish
    this_thread::sleep_for(chrono::seconds(5));

    cout << "All tasks finished." << endl;

    return 0;
}