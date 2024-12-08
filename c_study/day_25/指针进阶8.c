//
// Created by 20212 on 24-4-12.
//
//sizeof(数组名) 数组名表示整个数组，所以sizeof(数组名)表示整个数组所占的字节数
// & 数组名 表示整个数组的地址
// &数组名[0] 表示数组的首地址  
//strlen接受指针，计算字符串长度，遇到\0结束
#include <stdio.h>
/*int main(){
    int a[] = {1,2,3,4};
    printf("%d\n",sizeof(a)); //16
    printf("%d\n",sizeof(&a)); //8 虽然是数组的地址，但也是地址 sizeof计算的是一个数组的大小，所以是8
    printf("%d\n",sizeof(a+1)); //8
}*/
//int my_strlen(char* str){};
//&arr + 1 跳过一个数组

//地址，指针的大小是4/8个字节
//char arr[] = "abcdef";
//arr = {a,b,c,d,e,f,\0}
//&arr 指的是数组的地址，但是它指向的是数组的首地址
//char *p = "abcdef";
//p[0] --> *(p+0) --> a
int main(){
char *p = "abcdef";
//char *p --> p[] = {a,b,c,d,e,f,\0}
//p[0] --> *(p+0) --> a

printf("%d\n",strlen(p)); //6
}