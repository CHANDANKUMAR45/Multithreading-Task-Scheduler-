# 🚀 Multithreading Task Scheduler (C++)

## 📌 Overview

This project implements a **Thread Pool (Task Scheduler)** in C++ to execute multiple tasks concurrently.
It demonstrates core concepts of **Operating Systems and Multithreading**, such as concurrency, synchronization, and efficient resource utilization.

---

## 🎯 Features

* Fixed-size **Thread Pool**
* **Task Queue (FIFO)** for scheduling tasks
* Parallel task execution using multiple threads
* Synchronization using:

  * `std::mutex`
  * `std::condition_variable`
* Safe and graceful thread shutdown
* Low-latency execution

---

## ⚙️ Tech Stack

* **Language:** C++ (C++17)
* **Concepts Used:**

  * Multithreading (`std::thread`)
  * Mutex Locks
  * Condition Variables
  * Atomic Variables
  * Queue (Task Scheduling)

---

## 🧠 How It Works

### 1. Thread Pool

A fixed number of worker threads are created at the start.
Each thread continuously waits for tasks.

### 2. Task Queue

Tasks are stored in a queue using `function<void()>`.
New tasks are added using the `enqueue()` method.

### 3. Task Execution

Worker threads pick tasks from the queue and execute them concurrently.

### 4. Synchronization

* `mutex` ensures safe access to shared data
* `condition_variable` notifies threads when new tasks arrive

---

## 💻 Example Output

Task 1 is running on thread 12345
Task 2 is running on thread 67890
Task 1 completed
Task 2 completed
...
All tasks finished.

---

## ▶️ How to Run

### Step 1: Compile

g++ -std=c++17 -pthread main.cpp -o scheduler

### Step 2: Run

./scheduler

---

## 📂 Project Structure

.
├── main.cpp
├── README.md

---

## 🔥 Key Learnings

* Understanding of **multithreading and concurrency**
* Efficient task scheduling using thread pools
* Avoiding race conditions using synchronization
* Writing scalable and high-performance code

---

## 🚀 Future Improvements

* Priority-based task scheduling
* Dynamic thread pool resizing
* Task timeout handling
* Logging and monitoring system

---

## 👨‍💻 Author

**Chandan Kumar**
Email: [chandankumarin03@gmail.com](mailto:chandankumarin03@gmail.com)
GitHub: https://github.com/chandan57

---

## ⭐ Contribution

Feel free to fork, improve, and contribute to this project.

---

## 📌 Resume Description (Use this)

Built a multithreaded task scheduler using C++ with thread pool and task queue, enabling efficient parallel execution using mutex and condition variables, demonstrating strong understanding of concurrency and OS concepts.
