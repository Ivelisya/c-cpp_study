//
// Created by 20212 on 17/8/2024.
//
//函数重载 -> 一词多义
#include <iostream>
using namespace std;
//函数重载 一个函数有多个意义
//函数重载，函数名相同，参数不同
//对返回值没有要求
//只是返回值不同，没办法构成重载
void Func(int i, char ch) {
    cout << "Func(int, char) called: " << i << " " << ch << endl;
}
void Func(char ch, int i) {
    cout << "Func(char, int) called: " << ch << " " << i << endl;
}

int main() {
    Func(1, 'a');  // Corrected this line
    Func('b', 2);  // Example of using the second overload
}

//重载:
//1.什么是函数重载
//2.c++是如何支持函数重载的，为什么c语言不支持

//1.预处理 -> 头文件展开，宏替换，条件编译，去掉注释
//2.编译 -> 检查语法，生成汇编代码
//3.汇编 -> 将汇编代码生成二进制的机器码
//4.链接 -> 将两个目标文件链接到一起 生成可执行程序

//c++可以函数重载是因为c++有函数名修饰
//c++符号表中的名字与类型关联 而c语言不关联 所以使用c语言的时候 会出现同名函数冲突
//
//extern c 按c语言的修饰规则在符号表命名函数