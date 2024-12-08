//
// Created by 20212 on 12/9/2024.
//
#include <iostream>

using namespace std;

//class Data {
//public:
//    Data(int year) : _year(year) {}
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    Data d1(1);
//    Data d2 = 2;//隐式类型的转换，构造出tmp(2),再用tmp拷贝构造d2(tmp) 最后编译器优化成直接构造
//    //Data d2 = {1,2,3} c++11才支持
//    Data d3 = d1;
//
//    int i = 1;
//    const double& d = i;//隐式类型转换，会产生中间的临时变量  引用的中间的临时变量， 类型为const
//
//    //临时对象具有常性
//}
//static成员
//设计一个类，可以计算这个类总计产生了多少个对象
//int n = 0;
class A {
public:
    A() {
        ++n;
    }

    A(const A &a) {
        ++n;
    }

    static int GetN() {//没有this指针，函数中不能访问非静态的成员

        return n;
    }

    void Print() {
        cout << n << endl;
    }

private:
    static int n;//声明 不是属于某个对象，是属于类的所有对象，属于这个类
    //不在对象中，n在静态区
};

int A::n = 0;//定义
A &f1(A &a) {
    return a;
}

int main() {
    A a1;
    A a2;
    f1(a1);
    f1(a2);
//    cout << A::n <<endl;
    a1.Print();
    return 0;

    //问题是谁都可以对n进行修改
}