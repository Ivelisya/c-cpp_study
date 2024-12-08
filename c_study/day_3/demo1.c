//
// Created by 20212 on 3/8/2024.
//
#include <stdio.h>
#include <string.h>
//作用域和生命周期
//作用域：变量的作用范围
//生命周期：变量的存在时间
//局部变量的作用域是从定义的位置开始到所在的代码块结束
//全局变量的作用域是整个工程
//跨文件访问全局变量需要用extern关键字声明
//变量的生命周期是变量从创建到销毁的时间段
//局部变量的生命周期是从定义到所在的代码块结束，从进局部范围生命开始，到离开局部范围结束
//全局变量的生命周期是整个工程
//常量 不变的量
//1.字面常量 10 3.14 'a' "hello"
//2.const修饰的变量 const int a = 10; const修饰的变量是只读变量 被const修饰的变量不能被修改 此时a为常变量 本质是变量 只是被const修饰了
//3.#define 定义的常量 #define MAX 100 本质是一个宏定义
//4.enum枚举常量 可以一一列举的常量
//
//#define MAX 100 #define 指令是预处理指令的一种,预处理器会在编译之前将代码中所有出现的 MAX 文本替换为 100。
//enum Sex{
//////    这种枚举变量的未来可能取值
//   MALE = 3,//赋初值，在最开始给他一个值
//    FEMALE
//};
//int main(){
////    int n = MAX;
////    printf("n = %d\n",n);
////    return 0;
//    enum Sex s = MALE;
//    printf("%d\n",s);
//    return 0;
//}
////
//字符串 一串字符 ->用双引号括起来的字符

//int main(){
////    数组是一组相同类型的数据的集合
////    "hello world";
////    字符串的结束标志是'\0'
////    char arr[] = "hello world";
////    return 0;
////    printf("%s\n",arr);
////    return 0;
//
//    char arr1[] = {'a','b','c','d','e','f','g'};
////    由这里可得出结论，字符串的结束标志是'\0'
//    char arr2[] = "abcdefg";
//    int len = strlen(arr1);
//    printf("%s\n",arr1);
//    printf("%s\n",arr2);
//    printf("%d\n",len);//没有'\0'的字符串长度是不确定的，返回随机值
//    return 0;
//
//}














//int g_val = 2024;
//int main(){
//    {
//        int a = 10;
//        printf("a = %d\n",a);
//    }
//    return 0;
//}
//程序的生命周期是main函数的生命周期