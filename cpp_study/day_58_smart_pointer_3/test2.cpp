// 智能指针是raii一种思想的一种应用的体现
// 本质raii就是借助构造函数和析构函数来搞事情
// 因为构造函数和析构函数的特点都是自动调用 不会丢失 java中有gc所以不需要智能指针 gc是垃圾回收机制
#include <iostream>
using namespace std;
#include <mutex>
// 使用raii思想解决死锁问题
// raii 是内容是资源获取就是初始化
// 资源释放就是析构
// 通过构造函数获取资源 通过析构函数释放资源
// 通过这种方式可以保证资源一定会被释
template <class Lock>
class LockGuard
{
public:
    LockGuard(Lock& lock) : _lock(lock) { _lock.lock(); } // 进作用域 加锁

    ~LockGuard() { _lock.unlock(); } // 出作用域 解锁

    LockGuard(const LockGuard<Lock>&) = delete; // 禁止拷贝构造函数
    LockGuard& operator=(const LockGuard<Lock>&) = delete; // 禁止赋值构造函数

private:
    Lock& _lock; // 锁不能拷贝 定义引用成员变量
};

void f()
{
    mutex mtx;
    // mtx.lock();
    // func();  // 有可能抛出异常
    // mtx.unlock();
    LockGuard<mutex> lock(mtx); // 通过构造函数获取资源 通过析构函数释放资源 也就是智能指针的思想
}
int main()
{
    try
    {
        f();
    }
    catch (exception& e)
    {
        cout << "捕获异常" << endl;
    }
    return 0;
}
// 导致死锁的原因是因为在mtx.lock()和mtx.unlock()之间调用了func()函数，而func()函数有可能抛出异常，导致mtx.unlock()没有被调用，从而导致死锁。


// 一般程序碰到内存泄漏重启就可以了
// 如何解决内存泄漏问题
// 1.小心谨慎
// 2.不好处理的地方多用智能指针去管理
// 3.如果怀疑存在内存泄漏 可以使用内存泄漏工具去检测（事后查错)