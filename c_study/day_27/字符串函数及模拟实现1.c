//
// Created by 20212 on 24-4-17.
//
#include <string.h>
#include <stdio.h>
#include <assert.h>
//库函数里面返回的是 unsigned int
// my_strlen
//int my_strlen(const char* str){
//    int count = 0;
//    assert(str != NULL);
//    while(*str != '\0'){
//        count ++;
//        str++;
//    }
//    return count;
//}
//int main(){
//    char arr[] = "abc";
//    int len = my_strlen(arr);
////如果字符当中没有/0，一直走到/0为止
////返回随机数
//    printf("%d",len);
//
//}
//strcopy 将字符串指向对应数组去
//int main(){
//    char arr[20] = {0};
//    printf("%s,\n",strcpy (arr,"helloworld"));
//}
//要保证目标空间足够大，可以放下原字符串
//目标空间必须可变
char* my_strcat(const char *dest,const char *src){
//1.找到目标字符串的/0
//2.源数据追加过去
    char * ret = dest;
    while(*dest){
        dest ++;
    }
    while(*dest++ == *src++){
        ;
    }
    return ret;
}
int main(){
    char arr[20] = "hallo";
    printf("%s",my_strcat(arr,"world"));
}