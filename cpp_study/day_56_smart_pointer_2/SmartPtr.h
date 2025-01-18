#pragma once
#include <iostream>
using namespace std;
// 帮我们管理资源的释放 无论是函数正常结束还是异常结束 都能保证资源的释放


// RAII 利用对象生命周期来控制程序资源
// RAII和智能指针的关系
// RAII是一种托管资源的方法，智能指针是RAII的一种实现
template <class T>
class SmartPtr
{
public:
    SmartPtr(T* ptr) : _ptr(ptr) {}

    ~SmartPtr()
    {
        if (_ptr)
        {
            std::cout << "Deleting _ptr" << std::endl;
            delete _ptr;
        }
    }

    T& operator*() { return *_ptr; }

    T* operator->() { return _ptr; }

    // 拷贝赋值运算符重载
    SmartPtr& operator=(const SmartPtr& other)
    {
        if (this != &other)
        {
            // 先释放旧资源
            if (_ptr)
                delete _ptr;
            // 深拷贝新资源
            _ptr = new T(*other._ptr);
        }
        return *this;
    }

private:
    T* _ptr;
};
//引用计数使用指针 指针通过动态开辟


//shared_ptr 处理线程安全的问题


