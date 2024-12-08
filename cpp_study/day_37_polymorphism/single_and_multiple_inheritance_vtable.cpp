//
// Created by 20212 on 24-10-28.
//
using namespace std;
#include <iostream>
//单继承
class Base
{
public:
    virtual void Func1()
    {
        cout << "Base::Func1()" << endl;
    }

    virtual void Func2()
    {
        cout << " Base::Func2()" << endl;
    }

private:
    int a;

private:
    int _b = 1;
};

class Derive : public Base
{
public:
    virtual void Func1() override
    {
        cout << "Derive::Func1()" << endl;
    }

    virtual void Func3()
    {
        cout << "Derive::Func3()" << endl;
    }

    virtual void Func4()
    {
        cout << "Derive::Func4()" << endl;
    }

private:
    int b = 2;
};
typedef void(*VF_PTR)();//义一个函数指针变量定 参数为空 返回值为void
//函数指针类型typedef
void PrintVFTable(VF_PTR* pTable)//函数指针的数组的地址
{
    for(size_t i = 0;pTable[i] != nullptr;++i)
    {
        printf("vfTable[%d]:%p\n",i,pTable[i]);
        VF_PTR f = pTable[i];
        f();
    }
    cout << endl;
}
int main()
{
    Base b;
    Derive d;
    PrintVFTable((VF_PTR*)(*(int**)&b));

    PrintVFTable((VF_PTR*)(*(int**)&d));
    return 0;
}
//多继承