// 之前已经学过一些设计模式
// 1.迭代器模式 --基于面向对象三大特性之一的封装设置的
// 用一个迭代器封装之后，不暴露容器的结构情况下，统一的方式去遍历容器
// 2.适配器模式 --体现的是一种复用
// 还有一些常见的设计模式如:工厂模式，装饰器模式，观察者模式，单例模式
#include <iostream>
#include <memory>

// 单例模式 在一个进程中 只能有一个实例对象 就叫做单例模式
// 1.什么场景下使用 比如一个进程中有一个内存池
// 类的名称是随着你的场景给的，比如你给的是内存池，那么你就定义成MemoryPool
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
class Singleton
{
public:
    static Singleton* GetInstance()
    {
        // 多线程下，可能会出现多个线程同时进入到这个函数中，导致多次创建对象
        {//添加一个局部作用域，让锁的生命周期更短   
            unique_lock<mutex> lock(_mutex);
            if (_pinst == nullptr)
            {
                _pinst = new Singleton();
            }
        }

        return _pinst;
    }
    Singleton(const Singleton& s) = delete;

private:
    Singleton() {}
    static Singleton* _pinst;
    static mutex _mutex;
};
Singleton* Singleton::_pinst = nullptr;
mutex Singleton::_mutex;
int main()
{
    vector<thread> vthreads;
    int n = 4;
    for (int i = 0; i < n; ++i)
    {
        vthreads.push_back(thread(
            []()
            {
                // cout << std::this_thread::get_id() << endl;
                cout << Singleton::GetInstance() << endl;
            }));
    }
    return 0;
}
