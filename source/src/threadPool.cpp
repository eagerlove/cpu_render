#include "threadPool.hpp"

namespace CPURender {
    ThreadPool::ThreadPool(size_t threadCount) {
        alive = 1;
        if (threadCount == 0) {
            threadCount = std::thread::hardware_concurrency();
        }
        for (size_t i = 0; i < threadCount; i++) {
            threads.push_back(std::thread(ThreadPool::WorkFun, this));
        }
   }

   ThreadPool::~ThreadPool() {
    while (!tasks.empty()) {
        std::this_thread::yield();
    }
    alive = -1;
    for (auto &thread : threads) {
        thread.join();
    }
    threads.clear();
   }

    void ThreadPool::WorkFun(ThreadPool *master) {
        while (master->alive == 1) {
            Task *task = master->getTask();
            if (task != nullptr) {
                task->run();
            } else {
                std::this_thread::yield();
            }
        }
    }

    void ThreadPool::addTask(Task *task) {
        std::lock_guard<std::mutex> guard(lock);
        tasks.push_back(task);
    }

    Task *ThreadPool::getTask() {
        std::lock_guard<std::mutex> guard(lock);
        if (tasks.empty()) {
            return nullptr;
        }
        Task *task = tasks.front();
        tasks.pop_front();
        return task;
    }

}
