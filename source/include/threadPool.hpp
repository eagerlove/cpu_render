#pragma once

#include "common.hpp"

namespace CPURender{
    class Task {
    public:
        virtual void run() = 0;
    };

    class ThreadPool{
    public:
        ThreadPool(size_t threadCount = 0);
        ~ThreadPool();

        static void WorkFun(ThreadPool *master);
        void addTask(Task *task);
        Task *getTask();
    private:
        int alive;
        std::vector<std::thread> threads;
        std::list<Task *> tasks;
        std::mutex lock;
    };

}
