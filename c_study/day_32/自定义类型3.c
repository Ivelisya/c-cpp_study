//
// Created by 20212 on 24-4-23.
//
//枚举 一一列举
//声明枚举类型
#include <stdio.h>
//枚举常量
//枚举可以增加可读性
//和define相比增加类型检查
//防止命名污染
enum Color{//里面放的是枚举的可能取值
    RED,
    GREEN,
    BLUE
};
//枚举类型的成员是常量
enum Sex{
    MALE,
    FEMALE
};

int main(){
    //cpp 语法检查更加严格
    printf("%d",RED);
};