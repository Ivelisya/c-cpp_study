//
// Created by 20212 on 28/8/2024.
//
//指针可以在任何时间指向任何实体
/*
int main(){
    char c1 = 10;
    char& c2 = c1;
    char* p1= &c1;

}*/
#include <iostream>
using namespace std;
int Add(int left,int right){
    return left + right;
}
inline void Swap(int&x1,int&x2){
    int tmp = x1;
    x1 = x2;
    x2 = tmp;
}//inline函数会在调用它的地方展开
//内联函数是一种空间换时间的做法
//代码太长，循环太长不适用
//一般内联适用于小函数，一般小于20行的，其次像递归这样的或者比较长的都不适用于内联
//inline对于编译器而言只是一个建议
//inline不建议声明和定义分离，分离会导致链接错误
//c++建议用内联代替宏函数
//宏缺点 不能调 可读性比较差

//频繁调用Swap是有消耗的，调用函数需要建立栈帧
//如何解决:
//1.c语言中使用宏函数
//2.c++使用内联函数
int main(){
//    int ret = Add(1,2);
    int a = 0,b = 2;
    Swap(a,b);
    return 0;
}