// 智能指针是raii一种思想的一种应用的体现
// 本质raii就是借助构造函数和析构函数来搞事情
// 因为构造函数和析构函数的特点都是自动调用 不会丢失 java中有gc所以不需要智能指针 gc是垃圾回收机制
#include <iostream>
using namespace std;
#include <mutex>
void f()
{
    mutex mtx;
    mtx.lock();
    // func();  // 有可能抛出异常
    mtx.unlock();
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
