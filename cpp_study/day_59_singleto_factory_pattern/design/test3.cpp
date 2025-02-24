#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//类型转换 c++是强类型语言

int main(){
    int i  = 1;
    double d = 8.88;
    i = d;//发生了类型转化 c语言支持相近类型的隐式类型转换(相近类型，也就是意义相似的类型)
    cout << i << endl;

    int *p = nullptr;
    p = (int*)i;// c语言支持相近类型的强制类型转换(不相近类型，也就是意义差别很大的类型)
    cout << p << endl;

    //指针和整型是不相近类型

    //c++ 兼容c语言留下来的隐式和显示转换
    
    return 0;
}