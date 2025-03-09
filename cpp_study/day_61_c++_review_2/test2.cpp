#include <iostream>
using namespace std;
char arr[] = "abcdef";
/*
strlen 不计算/0的大小


总结 sizeof算对象类型的大小，所以先看对象什么类型
     strlen算字符串长度，遇到/0结束,注意 不计算 /0的大小  -> \0 不计入长度
*/
