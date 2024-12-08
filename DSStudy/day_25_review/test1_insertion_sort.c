#include <stdio.h>

//
// Created by 20212 on 12/8/2024.
//
//直接插入排序,假设第一个元素已经是有序的,从第二个元素开始（称为当前元素）,将它与前面已经排序的部分进行比较
//设数组为 5 2 9 1 5 6
void InsertionSort(int *a,int n){
    int key,i,j;
    for(i = 1;i < n;i++){
        int key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
void PrintArr(int *a,int n){
    for(int i = 0;i < n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int a[] = {5,2,9,1,5,6};
    InsertionSort(a,sizeof(a)/sizeof(int));
    PrintArr(a,sizeof(a)/sizeof(int));
}

//是一个稳定的排序算法，时间复杂度 最坏情况下O(n^2)，最好情况下O(n)，平均O(n^2)