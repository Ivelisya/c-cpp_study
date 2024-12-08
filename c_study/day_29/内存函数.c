//
// Created by 20212 on 24-4-20.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
void* my_memcpy(void*dest,const void* src,size_t num){
    void* ret = dest;
    assert(dest && src);
    while(num --) {
        *(char *) dest = *(char *) src;
        dest = (char*)dest +1;
        src = (char*)src +1;
    }
    return ret;
}
int main() {
//    FILE*pf = fopen("test.txt","r");
//    if (pf == NULL){
//        perror("fopen");
//    }
// isdigit 如果是数字字符返回非0的字，如果不是返回0
//    char ch = 'a';
//    int ret = islower(ch);
//tolower 转换成小写字符
//    printf("%d\n",ret);
//    char arr[20] = {0};
//}
int arr1[10] = {1,2,3,4,5,6,7,8,10};
int arr2[10] = {0};
my_memcpy(arr2,arr1,20);
return 0;
}
//内存操作函数
//memcpy - 内存拷贝
