#include "threadPool.hpp"

using namespace CPURender;

class SimpleTask : public Task {
public:
    void run() override {
        std::cout << "Hello cpu " << std::endl;
    }
};

int main() {
    ThreadPool thread_pool;
    thread_pool.addTask(new SimpleTask());
    thread_pool.addTask(new SimpleTask());
    thread_pool.addTask(new SimpleTask());
    thread_pool.addTask(new SimpleTask());
    thread_pool.addTask(new SimpleTask());
    thread_pool.addTask(new SimpleTask());
    return 0;
}