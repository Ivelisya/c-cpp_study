// Created by 20212 on 2024/3/28.
//
#include <stdio.h>
#include <assert.h>
// int main(){
//     int a = 10;
//     int const *p = &a;//const放在*两边时地址指针和指向都不能改变
//     printf("a = %d\n", a);
// }
// int const * const * const p; 修饰p *p �? **p
// 把src指向的内容拷贝放进dest指向的空间中
//从本质上，希望dest指向的内容被修改，src指向的内容不可能被修�?
// strcpy这个库函数，其实返回的是目标空间的起始地址
char * my_srcpy(char*dest,const char*src){
    assert(src!= NULL);//断言
    assert(dest != NULL);
    char * ret = dest;//取到的是目标空间的起始地址
    while(*dest++ = *src++){
        ;
        // 从起始地址开始的每一个坐标的指向替换
    }
    return ret;//返回目标空间的起始地址
}
int main(){
    char arr1[20] = "xxxxxxxxxxxx";
    char arr2[] = "hello world";
    printf("%s\n",my_srcpy(arr1,arr2));
}