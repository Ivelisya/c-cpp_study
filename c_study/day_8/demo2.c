//
// Created by 20212 on 2024/3/18.
//
//void Add(int *p){
//    (*p) ++;
//}
////int main();
//想要在函数内部改变一个值，应该传址
//函数可以嵌套调用，不能嵌套定义
//链式访问，一个函数的参数作为另一个函数的参数
//应该先定义然后再调用
//静态库使用之前先导入 pragma comment(lib,"...lib")
#include <stdio.h>
int main(){
    int a = 20;
    int b = 10;
//定义是一种更强有力的声明
//函数的声明一般放在头文件里面
//
    int Add(int a,int b);
    int c = Add(a,b);
    printf("你好");
}