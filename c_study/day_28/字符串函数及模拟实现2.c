//
// Created by 20212 on 24-4-18.
//
#include <stdio.h>
#include <string.h>
//int main(){
//    char arr[10];
//
//// strcat不能自己跟自己追加 因为strcat 在追加自己的时候，会丢掉/0，当/0没有时，无法停止，所以程序会死
////    strcat
//}

//strcmp 字符串比较函数
//存在大的字符的字符串比较大
//int my_strcmp(char * s1,char * s2){
//    while(*s1 == *s2){
//        if(*s1 == '\0'){
//            return 0;
//        }
//        s1 ++;
//        s2 ++;
//    }
//    return *s1 - *s2;
//}
//int main(){
////    int ret = strcmp("abbbb","abc");
////    printf("%d\n",ret);
//char * p = "abcef";
//char * q = "abcdef";
//int ret = my_strcmp(p,q);
//if(ret >0){
//    printf("p>q");
//}
//    if(ret < 0){
//        printf("p<q");
//    }
//    if(ret == 0){
//        printf("p = q");
//    }
//}
int main(){
    char arr1[20] = "abcdef";
    char arr2[] = "qwer";
//    strncpy
//    strncmp
    strncat(arr1,arr2,2);
    printf("%s\n",arr1);
}