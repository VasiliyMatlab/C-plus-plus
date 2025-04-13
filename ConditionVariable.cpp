#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

#define THREADS_NUM 3

using namespace std;

void worker(int id, std::condition_variable& cv, std::mutex& mutex, int& counter) {
    cout << "Thread " << id << " started" << endl;
    this_thread::sleep_for(chrono::milliseconds(400 * id));
    
    {
        std::unique_lock<std::mutex> lock(mutex);
        counter--;
        if (counter == 0) {
            cv.notify_one();
        }
    }
    
    cout << "Thread " << id << " ended" << endl;
}

int main(void) {
    std::condition_variable cv;
    std::mutex mutex;
    int counter = THREADS_NUM;
    thread threads[THREADS_NUM];

    for (int i = 0; i < THREADS_NUM; i++) {
        threads[i] = thread(worker, i, ref(cv), ref(mutex), ref(counter));
    }

    cout << "All threads started, wait them" << endl;

    {
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, [&]() { return counter == 0; });
    }

    cout << "All threads done. End work" << endl;

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
