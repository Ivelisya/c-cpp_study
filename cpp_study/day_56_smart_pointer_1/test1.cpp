//
// Created by 20212 on 25-1-7.
//
#include <iostream>
using namespace std;
#include "SmartPtr.h"

int div()
{
    int a, b;
    cin >> a >> b;
    if (b == 0)
    {
        throw invalid_argument("除0错误");
    }
    return a / b;
};

void f1()
{
    int* p = new int;
    // try
    // {
    //     cout << div() << endl;
    // }
    // catch (...)
    // {
    //     delete p;
    //     throw;
    // }
    //... 捕捉任意异常
    // delete p;
    SmartPtr<int> sp(p);
    cout << div() << endl;
};
//智能指针的坑
// int main()
// {
//     try
//     {
//         f1();
//     }
//     catch (exception& e)
//     {
//         cout << e.what() << endl;
//     }
//     return 0;
// }
int main()
{
    SmartPtr<int> sp1(new int);
    SmartPtr<int> sp2(sp1);
    //三种解决方案
    //1.管理权转移
    //2.禁止拷贝
    //3.引用计数

    //原因是没有定义拷贝构造函数，所以会调用默认的拷贝构造函数，导致两个指针指向同一个地址，当其中一个指针释放内存后，另一个指针就会指向一个无效的地址
    return 0;


    //c++98  auto_ptr 管理权转移
    //c++11  unique_ptr 禁止拷贝
    //c++11  shared_ptr 引用计数 会有循环引用的问题
    //weak_ptr 解决循环引用问题
}
