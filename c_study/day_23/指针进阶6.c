//
// Created by 20212 on 2024/4/10.
//
//10 -> 9
//
//void bubble_sort(int arr[],int sz){
//    int i = 0;
//     for(i = 0;i < sz - 1;i++){
////   一趟冒泡排序
//        int j = 0;
//        for(j = 0;j < sz -1 -i;j++){
//            if(arr[j] > arr[j + 1]){
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//     }
//}
#include <stdio.h>
int cmp_int(const void*e1,const void * e2){
   return *(int*)e1 - *(int*)e2;
}
#include <stdlib.h>
int main(){
    int arr[10] = {9,2,3,6,1,0,6,3,12,34};
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr,sz,sizeof(arr[0]), cmp_int);
    for(int i = 0;i < sz;i ++){
        printf("%d\n",arr[i]);
    }
}

