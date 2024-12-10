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
}
#endif

