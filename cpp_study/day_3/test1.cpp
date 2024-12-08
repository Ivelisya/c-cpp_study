//
// Created by 20212 on 19/8/2024.
//
//引用是给已经存在的变量取别名

#include <iostream>
using namespace std;
//int a = 10;
//int& b = a;
//int& c = b;
//int& e = c;
////引用必须初始化，引用一个实体之后不能再引用别的
//int main(){
//    const int a = 10;
//    const int&b = a;
//    //引用时不能进行权限放大
//    //引用时权限缩小是被允许的
//    return 0;
//}

//1.引用做参数
void swap_c(int*p1,int*p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void swap_cpp(int&r1,int&r2){
    int tmp = r1;
    r1 = r2;
    r2 = tmp;
}
int main(){
    int a = 0,b = 1;
    swap_c(&a,&b);
    swap_cpp(a,b);
    return 0;
}