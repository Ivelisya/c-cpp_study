//
// Created by 20212 on 24-4-24.
//
#include <stdio.h>
//联合体的大小的计算
union Un{
    char a[5];
    int i;
};
int main(){
    union Un n;
    printf("%d\n",sizeof(n));
}
//联合体也存在对齐
//联合体的大小至少是最大成员的大小
//联合体的的大小为成员最大对齐数的整数倍