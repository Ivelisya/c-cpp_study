#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

int main()
{
    const int n = 100;
    mutex mtx; // 共享的互斥锁
    condition_variable cv; // 条件变量
    bool is_even_turn = true; // 表示当前是否该打印偶数

    // 打印偶数的线程
    thread t1([&]() {
        for (int i = 0; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return is_even_turn; }); // 等待轮到偶数线程
            cout << "Thread " << this_thread::get_id() << ": " << i << endl;
            is_even_turn = false; // 切换到奇数线程
            cv.notify_one(); // 通知奇数线程
        }
    });

    // 打印奇数的线程
    thread t2([&]() {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return !is_even_turn; }); // 等待轮到奇数线程
            cout << "Thread " << this_thread::get_id() << ": " << i << endl;
            is_even_turn = true; // 切换到偶数线程
            cv.notify_one(); // 通知偶数线程
        }
    });

    t1.join();
    t2.join();

    return 0;
}
