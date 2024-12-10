//
// Created by 20212 on 24-12-10.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <initializer_list>
using namespace std;
#if 0
class Point
{
public:
    Point(int x = 0, int y = 0):_x(x),_y(y),_z(1)
    {

    }
private:
    int _x;
    int _y,_z;
};
int main()
{
    int x = 1;
    //c++11
    vector<int> v1{1,2,3,4,5,6};
    vector<int> v2 = {7,8,9,10,11,12};
    list<int> l1{1,2,3,4,5};
    list<int> l2 = {6,7,8,9,10};

    map<string,int> m{{"苹果",1},{"香蕉",2},{"橘子",3}};
    Point p1(1,2);
    Point p2{3,4};
    Point p3 = {5,6};

    initializer_list<int> ilt2 = {1,2,3,4,5,6};
    //容器是如何支持这种花括号里列表初始化的呢？
    //容器内部提供了一个构造函数，接受一个initializer_list<T>对象
    //vector (initializer_list<value_type> il,       const allocator_type& alloc = allocator_type());
    //容器支持花括号列表初始化，本质是增加了一个构造函数，接受一个initializer_list<T>对象
}
#endif
//类型推导 属于RTTI run time type identification

#if 0
int main()
{
    int a = 10;
    double b = 20;

    auto c = a + b;
    // decltype(a + b)c;

    //可以拿到类型名称
    cout << typeid(c).name() << endl;

    //假设我想定义一个变量，这个变量的类型和a+b的类型一样
    decltype(c)d;//decltype 推出c的类型定义d 通过对象推导出类型
}
#endif

//auto 和 范围for
//熟悉
#if 0
int main()
{
    std::map<std::string,std::string> dict = {{"C","C Language"},{"C++","C++ Language"},{"Python","Python Language"}};
    auto it = dict.begin();
    for(;it != dict.end();it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
    cout << "----------------" << endl;
    for (auto &e : dict)//这里是自动推导出来的类型 auto的优势就是可以把在类型比较复杂的地方，可以简化代码
    {
        cout << e.first << " : " << e.second << endl;
    }
    //范围for 当容器中对象比较大，或者这个对象要做深拷贝,如string
    //最好给&和const,可以减少拷贝提高效率
    //auto 不能作为形参 和 返回值

    //容器支持范围for的原理:范围for会被编译器编译成迭代器,意味着支持迭代器就支持范围for
}
#endif

//除了stl的容器可以使用范围for用法，数组也可以(原生指针可以认为是天然的迭代器) 比如 vector string 的迭代器就是原生指针。

//final 和 override 关键字
//final 修饰的类不能被继承 修饰的虚函数不能被重写
//override 修饰的虚函数必须是重写基类的虚函数 作为重写之后的标记

//final 修饰类 类就变成最终类 不能被继承
//override 是子类重写函数，检查是否完成重写。不满足重写的条件，则会报错

//智能指针(熟悉)

//新容器
//c++98容器
//string/vector/list/map/set + stack/queue/priority_queue
//c++11容器
//array(定长数组)/forward_list(单链表)/unordered_map/unordered_set/multimap/multiset
#include <array>
//array(定长数组): 实际用的很少，缺点：定长+存储的空间一般在栈上，栈上的空间有限
//forward_list 单链表 不能尾插，只能头插 不能尾删，只能头删
//unordered_map/unordered_set:推荐使用，因为他们的效率高于map/set
// int main()
// {
//     array<int,100> a;
//     return 0;
// }
//右值引用

//默认成员函数控制
//1.显式缺省成员函数

//要求a的对象不能拷贝和赋值(防拷贝)
//c++98 只声明不实现，这样就没办法用(拷贝对象) 缺陷 别人可以在类外实现
class A
{
public:
    A() = default;//显式缺省构造函数 编译器显示指定生成这个东西
    A(const int &a):_a(a)
    {

    }
private:
    int _a;
};
int main()
{
    A a1;//无法通过编译 缺少默认构造函数 因为拷贝构造也是默认构造函数
    return 0;
}

