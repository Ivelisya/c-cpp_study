//
// Created by 20212 on 2024/3/26.
//
//数组：一组相同类型的元素的集合
//结构体：也是一些值的集合，但是值的类型可以不同！
#include  <stdio.h>
//struct Stu{
//    //成员变量
//    char name[20];//名字
//    int age;//年龄
//    char id[20];
//} s1,s2;//s1,s1也是结构体变量，不过是全局变量，因为在大括号外面创建的
//struct B{
//    char c;
//    struct Stu a;
//};
//int main(){
//    //s是局部变量
//    struct B AlgorithmExercises = {'c',{"smzy",11,"a"}};
//    struct B* ps = &AlgorithmExercises;
//    printf("%s\n",(*ps).a.id);
//    printf("%s\n",ps -> a.id);
//    printf("%s",AlgorithmExercises.a.name);
//    return 0;
//}
//. //->
//结构体内可以放另一个结构体
struct B{
    char a;
    char name[10];
    int id[10];
};
struct A{
    char b;
    char name[10];
    struct B bb;
};
void print(struct A x){
    printf("%c\n",x.b);
}
void print1(struct A * ps){
    printf("%c\n",ps->b);
}
int main(){
    struct A a = {'a',"smzy",{'a',"mzy",1234}};
//    struct A * ps = &a;
    print(a);//传值调用 在空间和时间上都有浪费
    struct A * p = &a;
    print1(&a);//传址调用
//    传地址效率更高
//函数调用的参数压栈 栈，是一种数据结构 先进的后出，后进的先出
//    printf("%c\n",ps -> bb.a);
//    printf("%c\n",ps -> b);
//写一个函数打印a的内容
}