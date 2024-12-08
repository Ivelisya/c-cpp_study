//
// Created by 20212 on 2024/3/20.
//
//数组一组相同类型元素的集合
#include <stdio.h>
//int main(){
//    int arr[8];
//    for(int i = 1;i<10;i++){
//        arr[i] = i;
//    }
//    for(int i = 1;i<10;i++){
//        printf("%d",arr[i]);
//    }
//
//}
//int main(){
////    int a = 110;//初始化
//    int arr[11] = {1,2,3,4,5,9,77,8,6,9,20};
////数组的下标从0开始
////一维数组在内存中是连续存放的
////随着数组下表的增长，地址是由低到高变化的
////数组名是数组首元素的地址
//    int*p = arr;
//    int size = sizeof(arr)/sizeof(arr[0]);
//    for(int i=0;i<size;i++){
//        printf("%d\n",*p);
//        p++;
//    }
//}
//int main(){
////    int arr[3][4];//二维数组的定义
////初始化 创建的同时赋值
//      int arr[3][4] = {1,2,3,4,5,6,7,88,9,8,0,99};
////不完全初始化 补0
////    int i,j = 0;
////    for(i = 0;i < 3;i++){
////        for(j = 0;j<4;j++){
////            printf("%p\n",&arr[i][j]);
//
//// 二维数组在内存中也是连续存放的 初始化时一行有几个元素不能省略
//        }
//    }
//}
//void bubble_sort(int arr[],int sz){
////    确定趟数
//
//    int i = 0;
//    for(i = 0;i<sz - 1;i++){
////        一趟冒泡排序
//        int j = 0;
//        for (j = 0;j<sz - 1 - i;j++){
//            if(arr[j] > arr[j+1]){
//            int tmp = arr[j];
//            arr[j] = arr[j + 1];
//            arr[j + 1] = tmp;
//            }
//        }
//    }
//}
//int main(){
//    int arr[] = {9,8,7,6,5,4,3,2,1,0};
//    int sz =  sizeof(arr)/sizeof(arr[0]);
//    bubble_sort(arr,sz);//
//    return 0;
//}