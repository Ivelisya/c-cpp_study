//
// Created by 20212 on 24-4-24.
//
//地址从左到右边，从低到高
//大端 低地址放在高位，高地址放在地位
#include <stdio.h>
union Un{
    char c;
    int i;
};
//联合体。可能其中的成员公用同一块内存空间
//联合体 至少是最大成员的大小
int main(){
    union Un u;
    printf("%p\n",&u);
    printf("%p\n",&(u.c));
    printf("%p\n",&(u.i));
    printf("%d\n",sizeof(u));
}