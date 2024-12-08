//
// Created by 20212 on 2024/3/27.
//
#include <stdio.h>
void test1(){
    printf("hehe\n");
}
void test2(){
    test1();
}
void test3(){
    test2();
}
int main(){
    test3();
 }