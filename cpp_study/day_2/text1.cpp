//
// Created by 20212 on 19/8/2024.
//
#include <iostream>
using namespace std;
int main(){
//    int a = 1;
//    int& ra = a;//表示ra是a的引用，引用
    //引用是给已有的变量取别名，编译器不会再给它新开辟空间

    //引用的特性
    //1.引用必须在定义的时候进行初始化
    //2.一个变量可以有多个引用
//    int &c = a;
//    int d = 2;
//    c = d;
    //引用一旦引用一个实体，就不可以再进行更改
//    int a = 0;
//    int &b = a;
//    return 0;
    const int a = 0;
    //int &b = a;//b的类型是int，编译不通过，原因是a是只读，b的类型是int，也就是可读可写
    const int&b = a;
    int c =1;
    int& d = c;
    const int& e = c;//可以实现 c是可读可写，e变成别名只读
    //总结：引用取别名时，变量访问的权限可以缩小不可以放大

    int i = 0;
    double db = i;//隐式类型转换 转换时会产生一个临时变量，临时变量具有常性
    const double&rb = i;//所以引用时需要加上const
    const float&rf = i;

}