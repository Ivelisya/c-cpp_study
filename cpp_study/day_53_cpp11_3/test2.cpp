//
// Created by 20212 on 24-12-24.
//

//c++11 线程库
//特点：跨平台，面向对象封装的类（每个线程是个类对象）
//实现原理：封装库时使用了条件编译，也就是说它的底层还是调用了不同平台的线程api
#include <iostream>
using namespace std;
#include <thread>
#include <mutex>
mutex mtx;
int x = 0;

void Add(int n)
{
    mtx.lock();
    for (int i = 0; i < n; ++i)
    {
        ++x;
    }
    mtx.unlock();
}


int main()
{
    int n = 0;
    thread t1(Add, 10);
    thread t2(Add, 10);
    t1.join();
    t2.join();
    cout << x << endl;
}
