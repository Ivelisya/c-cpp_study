//
// Created by 20212 on 25-2-17.
//
#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
    A() { std::cout << "A::A()" << std::endl; }
    ~A() { std::cout << "A::~A()" << std::endl; }

private:
    int _a1;
    int _a2;
};

template <class T>
struct DeleteArray
{
    void operator()(T* pa)
    {
        delete[] pa;
        std::cout << "DeleteArray" << std::endl;
    }
};

// 解决c++11中shared_ptr不能删除数组的问题
//  使用仿函数 来删除 [] new 出来的数组
int main()
{
    // 1. 普通shared_ptr使用
    std::shared_ptr<A> sp1(new A);

    // 2. 使用DeleteArray删除数组
    std::shared_ptr<A> sp2(new A[3], DeleteArray<A>());

    // 3. 使用make_shared创建（推荐）
    auto sp3 = std::make_shared<A>();

    // 4. 共享所有权示例
    auto sp4 = sp3;
    std::cout << "引用计数: " << sp3.use_count() << std::endl;

    return 0;
}
