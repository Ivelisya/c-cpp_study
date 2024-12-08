//
// Created by 20212 on 24-10-28.
//
#include <iostream>
using namespace std;
//包含纯虚函数的类 抽象类 抽象类不能实例化出对象
// class Car
// {
// public:
//     virtual void Drive() = 0;//纯虚函数 不需要实现
// };
// class Benz:public Car
// {
// public:
//
// };
// int main()
// {
//     return 0;
// }
//纯虚函数强制重写
//动态绑定 -> 多态
//内联函数没有地址 所以内联函数不能是虚函数

//这里常考一道笔试题:sizeof(base)是多少
// class Base
// {
// public:
//     virtual void Func1()
//     {
//         cout << "Func1()" << endl;
//     }
//     //函数编译成指令放在了代码段
// private:
//     int _b = 1;
// };
// int main()
// {
//     cout << sizeof(Base) << endl;
//     // cout << sizeof(int) << endl;
// //Base内有 虚表指针 和 int
//     //虚函数表其实就是一个指针数组(虚函数指针)
//     return 0;
// }
// class Person
// {
// public:
//     virtual void BuyTicket()
//     {
//         cout << "买票-全价" << endl;
//     }
//
//     int _p = 1;
// };
//
// class Student : public Person
// {
// public:
//     virtual void BuyTicket() override
//     {
//         cout << "买票-半价" << endl;
//     }
//
//     int _s = 2;
// };
//
// void Func(Person& p)
// {
//     //p指向person类型的对象就调用person虚函数
//     //p指向student类型的对象就调用student虚函数
//     p.BuyTicket();
// }
//
// int main()
// {
//     Person Mike;
//     Func(Mike);
//     cout << sizeof(Mike) << endl;
//     Student Peter;
//     Func(Peter);
//     cout << sizeof(Peter) << endl;
//
//     //满足多态的两个条件 1.虚函数的重写2.父类的指针或引用调用
//     //多态的原理是 指向谁就到谁的虚表里面去找
//     //重写的目的是覆盖虚表
//     //多态是运行时到指向的对象的虚表中查找要调用的虚函数的地址来进行调用
//
//     //运行时到指向对象的虚函数表中查找对应的虚函数地址
//
//     //普通函数和虚函数被编译成指令之后存在代码段
// }
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

    void Func3()
    {
        cout << " Base:: Func3()" << endl;
    }

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

private:
    int _d = 2;
};
void f1(double d)
{

}
int main()
{
    Base b;
    Derive d;

    return 0;
    //虚表本质是一个函数指针数组
}

//虚函数和虚函数表都是存在代码段

//静态绑定 静态的多态 (静态：编译时确定函数地址）

//动态绑定 动态的多态（动态:运行时到虚表中找函数地址)
