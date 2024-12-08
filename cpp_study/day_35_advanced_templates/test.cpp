//
// Created by 20212 on 24-10-22.
//
#include <iostream>
using namespace std;
// #define F 100
//类型模板参数

//模板可以解决复用问题

//类型参数 + 非类型模板参数
//double不能作非类型模板参数
//string也不能作非类型模板参数

//实际中的非模板参数基本的都是整形
//非类型模板参数是一个常量
//因为是一个常量所以可以作数组的大小
template<class T, int N>//char int short 一般是int 他们都是整形家族的
//array容器是一个定长数组 fixed-size固定长度
//vector容器是一个变长数组
class Array
{
public:
    Array()
    {

    }
private:
    T _a[N];
};
int main()
{
    Array<int,100> a1;
    Array<int,1000> a2;

    return 0;
}
//这是类封装的静态的数组

