
// Created by 20212 on 2024/3/27.

//模拟实现strcpy函数
#include <stdio.h>
#include <string.h>
#include <assert.h>
//void my_strcpy(char*dest,char*src){
//    while((*src) != '\0'){
//        *dest = *src;
//        *dest++ = *src++;
//    }*dest = *src;
//}
//char *strcpy( char *strDestination, const char *strSource );
//void my_strcpy(char *dest,const char * src){
//    assert(src != NULL);//断言，如果条件为真什么都不会发生，为假的话，会返回错误信息
//    assert(dest != NULL);
//    while(*dest++ = *src++);
//}
//int main(){
//    char arr1[20] = "xxxxxxxxxxx";
//    char arr2[] = "hello";
//    char * ps = &arr1;
//    char * p = &arr2;
//    my_strcpy(ps,p);
//    printf("%s\n",arr1);
//    return 0;
//}
int main(){
    const int num = 1;
    int * ps = &num;
    *ps = 2;//const如果放在*的左边，修饰的是*p，表示指针指向的内容，是不能通过指针改变的
    printf("%d",num);
}
