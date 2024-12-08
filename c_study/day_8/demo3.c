//
// Created by 20212 on 2024/3/18.
//
//函数递归
//程序直接或者间接调用自己的方法叫做递归 由最后一次调用的开始返回
#include <stdio.h>
//int main(){
//    printf("hheh");
//    main();
////    函数自己调用自己叫做递归
////递归的主要思想在于把大事化小
//    return 0;
//
//}
//void print(unsigned int n){
//    if (n>9){
//        print(n / 10);
//    }
//    printf("%d\n",n%10);
////    递归必须要有限制条件
//}
//int main(){
//    unsigned int num;
//    scanf("%u",&num);
//    print(num);
//}
//栈区 局部变量 函数形参   栈空间耗尽就栈溢出
//写递归代码的时候,不能死递归,都有跳出条件
//递归的层次不能太深
//堆区 动态内存分配 malloc
//静态区 全局变量 静态变量
