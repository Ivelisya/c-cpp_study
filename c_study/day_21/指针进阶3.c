//
// Created by 20212 on 2024/4/7.
//
//int main(){

//    (*(void(*)())0)();
//    调用0地址处的函数
//    该函数无参，返回类型是void
//    1.void(*)()
//    2.(void(*)())0 - 对0强制类型转换，被解释成一个函数地址
//    3.*(void(*)())0 - 对0地址进行解引用操作
//    4.(*(void(*)())0)() - 调用0地址处的函数
//    return 0;
//}
#include <stdio.h>
//void print(int * ptr,int sz){
//    for(int i = 0;i < sz;i++){
//        printf("%d\n",i);
//    }
//}
//int main(){
//    int arr[10] = {1,2,3,4,5,6,7,8,9};
//    int * p = arr;
//    int sz = sizeof(arr)/sizeof(arr[0]);
////    这里p是一级指针
//    print(p,sz
//    );
//}
//void test(int **pa2){
//    **pa2 = 20;
//}
//int main(){
//    int a = 10;
//    int *pa = &a;//pa是一级指针
//    int ** ppa = &pa;//ppa是二级指针
//    test(ppa);
//    test(&pa);
//    int * arr[10];
//    test(arr);//也可以传一级指针数组的地址
////一级指针 int*p指向整形的指针char * pc指向字符的指针;void *pv无类型的指针;
////二级指针 char **p;int **p;
////数组指针 int(*p)[4];
//}
/**
* 函数指针 指向函数的指针 存放函数地址
 *
*/
int Add(int a, int b ){
    return a+b;
}
//int main(){
//    int arr[10] = {0};
//    //&arr 取出数组的地址
//    int (*parr)[10] = &arr;
//    //parr 是指向数组的指针 - 存放的是数组的地址
////
////&函数名 取到的是函数的地址
////数组名 != &数组名
////&函数名 = 函数名
//    int (*pf)(int,int) = &Add;//pf这个时候就是一个函数指针
//}
//void (*pt)(char*) = &test;
int main(){
    int (*pf)(int,int) = Add;//Add === pf
    int ret = pf(3,5);//只有函数指针，*才可以省略
    printf("%d\n",ret);
}