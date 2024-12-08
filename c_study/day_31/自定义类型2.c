//
// Created by 20212 on 24-4-23.
//
//默认对齐数可以被修改
#include <stdio.h>
//#pragma pack(2)//修改默认对齐数
//一般设偶数
//offsetof
//#include <stddef.h>
//struct s1{
//    char c1;
//    int i;
//    char c2;
//}s;
//int main(){
//    printf("%d\n",offsetof(struct s1,c1));
//}
//结构体传参
//传值 对空间和时间都是浪费
//传地址 对空间的利用率更高
//结构体在传参的时候，一般传递 地址


//位段 整型 家族
struct A{
    int _a:2;//:是位段的声明
    //位段存在的意义是为了帮你节省空间
    //根据你的需求来设计所占字节的大小
};
int main(){
    int _b:20;
}
//在vs中，从地位到高位使用

//存在位段的跨平台问题
//位段有符号无符号不确定
//位段 最大的数目无法确定
//从左到右还是从右到左不确定