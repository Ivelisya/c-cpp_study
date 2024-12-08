//
// Created by 20212 on 30/8/2024.
//
#include <iostream>
using namespace std;
int main(){
    int array[] = {1,2,4,6,4,8};
    //c语言中的做法
    for(int i = 0;i< sizeof(array)/sizeof(int);++i){
        array[i] *= 2;
    }
    for(int i = 0;i < sizeof(array)/sizeof(int);++i){
        cout << array[i] << " ";
    }
    cout << endl;

    //数组在传参之后会退化成指针


    //c++中 -> 范围for(语法糖) ->特点写起来比较简洁
    for(auto& e : array){
        e *= 2;
    }
    for(auto e:array){
        cout << e << " ";
    }
    cout << endl;

//    int* p = NULL;
//    //c++11中，推荐像下面那样去用
//    int* p2 = nullptr;
//NULL在c++当中本质是个宏 define NULL 0
//所以c++中推荐nullptr而不是NULL。NULL的值是0，nullptr是空指针，使用NULL可以会导致函数重载匹配不到对应的函数

}