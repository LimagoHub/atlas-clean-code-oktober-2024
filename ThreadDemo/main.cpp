#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <memory>

class ThreadDemo {


public:
    explicit ThreadDemo() {
        threadHolder_.reserve(threadCount);
        srand(time(NULL));
    }

    auto run() ->void {
        startWorker();
        joinThreads();
        std::cout << "\nfertig" << std::endl;
    }

private:
    static inline const size_t threadCount{10};
    std::vector<std::thread> threadHolder_;

    auto startWorker() -> void {
        for (size_t i = 0; i < threadCount; ++i) {
            const long millis = rand() % 5000;
            threadHolder_.emplace_back(
                    &ThreadDemo::worker,
                    this,
                    i,
                    millis);
        }
    }
    auto joinThreads() -> void
    {
        for (auto& thread : threadHolder_) {
            thread.join();
        }
    }

    auto worker(size_t threadNumber, long millis) -> void {
        std::this_thread::sleep_for(std::chrono::milliseconds(millis));
        std::cout << "Thread Nr. " << threadNumber << " finishes after " << millis << " Millis." << std::endl;
    }
};


int main() {
    ThreadDemo demo;
    demo.run();
    return 0;
}
