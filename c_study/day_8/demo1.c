//
// Created by 20212 on 3/13/2024.
//
//传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式
//写一个函数 判断是不是素数
//#include <stdio.h>
//int main() {
//    int i = 0;
//    for (i = 100; i < 1000; i++) {
//        printf("%d\n", i);
//    }
//    return 0;
//}
//传址调用让外部变量与函数体建立起联系
//int is_prime(int n){
//
//    //2 -> n-1 之间的数字
//    int j = 0;
//    for (j = 2;j < n;j++){
//        if (n % j == 0){
//                return 0;
//        }
//        return 1;
//    }
//}
#include <stdio.h>
//int binary_search(int a[],int k,int s){
//    int left = 0;
//    int right = s - 1;
//}
//int main(){
//    int arr[] = {1,2,3,4,5,6,7,8,9,10};
//    int key = 7;
//    int ret = binary_search(arr,key,sz);
//    if (-1 == ret){
//        printf("找不到\n");
//    }
//    else{
//        printf("找到了:%d",ret);
//    }
//}
int Add(int a,int b){
    return a + b;
}