//
// Created by 20212 on 3/10/2024.
//
//结构体使c语言有能力描述复杂对象 stuck
#include <stdio.h>
struct stu{
    char name[20];
    int age;
    double score;
};
struct book{
    char name[20];
    int price;
    char id[30];
};
//lf是double类型的格式，输出双精度浮点数
int main(){
    struct stu s1 = {"张三",20,99.9};//结构体的创建和初始化
    struct book b1 = {"C语言",30,"123456"};//.操作符  结构体变量.成员变量
//  printf("%s\n,%lf",s1.name,s1.score);
    struct stu* ps = &s1;//结构体指针
//    (*ps).age = 30;//(*ps)是一个结构体变量,()的原因是.的优先级高于*
    printf("%s\n",ps -> name);
//    左边为结构体的指针，右边为结构体的成员变量
    return 0;
}
