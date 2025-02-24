#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

// 类型转换 c++是强类型语言
#if 0
int main(){
    int i  = 1;
    double d = 8.88;
    i = d;//发生了类型转化 c语言支持相近类型的隐式类型转换(相近类型，也就是意义相似的类型)
    cout << i << endl;

    int *p = nullptr;
    p = (int*)i;// c语言支持相近类型的强制类型转换(不相近类型，也就是意义差别很大的类型)
    cout << p << endl;

    //指针和整型是不相近类型

    //c++ 兼容c语言留下来的隐式和显示转换
    
    return 0;
}
#endif
// c++中引入了四种命名的强制类型转换符号
// static_cast
// const_cast
// dynamic_cast
// reinterpret_cast
class A
{

protected:
    int _a;
};
class B : public A
{
protected:
    int _b;
};
void f_cast(A* pa)
{
    // 如果想区分pa是指向父类对象还是子类对象
    B* pb = dynamic_cast<B*>(pa); // dynamic_cast 多态类型转化
    if (pb != nullptr)
    {
        cout << "子类对象" << endl;
    }
    else
    {
        cout << "父类对象" << endl;
    }
}
int main()
{
    int i = 1;
    double d = 8.88;
    int* p = nullptr;
    d = static_cast<double>(i); // c语言的隐式类型转换
    p = reinterpret_cast<int*>(i); // c语言大部分的强制类型转换 (不相近类型，也就是意义差别很大的类型)
    volatile const int ci = 10; // const中的值会放入寄存器当中
    int* pi = const_cast<int*>(&ci); // 去掉const属性 对应c语言中强制类型转换(const)
    cout << ci << endl; // 为什么是10是因为const中的值会放入寄存器当中 cout是在寄存器中取值
    *pi = 20;
    cout << *pi << endl;
    A a;
    B b;
    A* pa = &a;
    B* pb = &b;
    pa = pb; // c++中子类对象可以赋值给父类对象的指针，引用，这个过程当中会发生切片 这是语法天然支持的，这个叫向上转换

    // 如果是父类的指针或者引用，传给子类的指针 这个过程叫 向下转换
    // 向上转化都可以成功，因为是天然支持
    // 向下转化有可能成功，要看具体情况
    //  dynamic_cast 多态类型转化
    //dynamic_cast 只能用于有虚函数的类 只适用于多态类型
    //dynamic_cast 通过去虚表的上方存储的标识信息，来判断指向的是父类对象还是子类对象

    //dynamic_cast是通过到pa指向对象上方的虚表中找到标识信息，来判断pa指向的是父类对象还是子类对象 所以要求必须是多态类型
}

//总结一下 尽量少用强制类型转换
//explict关键字可以防止隐式类型转换