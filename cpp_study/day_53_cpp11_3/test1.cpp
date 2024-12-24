#include <iostream>
#include <string>
using namespace std;

// lambda表达式其实是是定义了一个匿名函数对象，这个对象可以被赋值给一个变量，也可以直接调用
// 1.掌握lambda表达式写的格式
// 2.lambda表达式的使用场景 (对比仿函数 函数指针)
// 3.lambda表达式的原理
#if 0
int main()
{
    //[捕获外部变量](参数列表) mutable(可选) -> 返回类型 {函数体}
    int a = 0, b = 1;
    // 实现一个a+b的lambda表达式
    auto add1 = [](int x, int y) -> int { return x + y; };
    cout << add1(a, b) << endl;
    // 捕捉列表就是捕捉跟我一个作用域的对象
    // 1.传值捕捉 [a]捕捉a [b]捕捉b [=]捕捉所有的外部变量
    // 2.传引用捕捉 [&a]捕捉a [&b]捕捉b [&]捕捉所有的外部变量

    // 3.如果要修改捕捉的变量，需要加上mutable关键字
    auto add2 = [a, b]() -> int { return a + b; };
    add2();
    auto swap1 = [](int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    };
    swap1(a, b);

    auto swap2 = [&a, &b]()
    {
        int tmp = a;
        a = b;
        b = tmp;
    };
/* 不正确的用法
    auto swap3 = [a,b]() mutable
    {
        int tmp = a;
        a = b;
        b = tmp;
    };
*/
    return 0;
}
#endif

// 匿名函数对象不同作用域可以同名 ::是全局作用域

int main()
{
    int a = 1, b = 2;
    //对象 = 对象（编译器生成的lambda_uuid仿函数的对象）（参数）;
    auto add = [](int x, int y) -> int { return x + y; };
    //add底层还是依靠仿函数实现，也就是说你定义了一个lambda表达式
    //实际上编译器会生成一个叫 lambda_uuid的类，仿函数operator()的参数和实现
    //就是我们写的lambda表达式的参数和实现
    add(1, 20);//call lambda_uuid::operator()(1, 20)
}
