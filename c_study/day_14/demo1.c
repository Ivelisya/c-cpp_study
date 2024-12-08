//bug 臭虫 引起计算机出现错误的东西 找bug的过程叫做调试
//拒绝迷信式的调试，采用科学性的调试
#include <stdio.h>
int Add(int x,int y){
    int z = x + y;
    return z;
}
int main(){
    int arr[10] = {0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for(i = 0;i<sz;i++){
        arr[i] = i + 1;
        int a = 1,b =2 ;
        int c = Add(a,b);
        printf("%d",arr[i]);
    }
}