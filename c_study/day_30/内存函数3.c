//
// Created by 20212 on 24-4-22.
//
//结构是一些值的集合
//数组是一组相同类型的元素的集合
//struct Book{
//    char name[20];
//    int price;
//    char id[12];
//} b2,b3,b4;//b2,b3,b4是全局的
//int main(){
//    //b1在这里是局部变量
//    struct Book b1;//使用结构体创建变量
//}
//struct {
//    char c;
//    int i;
//} s;//匿名结构体，直接创建一个结构体变量 但是只能使用一次
//
//struct A{
//    int a;
//};
//struct B{
//    struct A sa;
//};
//struct Node{
//    int data;
//    struct Node* next;//自己能够找到自己同类型下一个节点的地址 自引用自己，得到下一个节点的地址 因为指针有大小，所以不会报错
//};
////结构体内不能存在自己会出现死递归
#include <stdio.h>
struct s{
    char c;
    int a;
};
int main(){
    struct s b1 = {'x',2};
    printf("%d\n",sizeof(b1));
    return 0;
}
// .针对结构体变量 -> 针对结构体指针