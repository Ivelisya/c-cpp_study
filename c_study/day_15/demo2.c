#include <stdio.h>
#include <assert.h>
int my_strlen(const char * p){
    assert(p);//p为空时，为空指针，为假，报错
    int num = 0;
    while(*p++ && ++num){
        ;
    }
    return num;
}
// extern声明外界符号
int main(){
    char arr1[] = "";
    int num = my_strlen(arr1);
    printf("%d\n",num);
    printf("%s","你好");
}