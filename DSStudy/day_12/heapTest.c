//
// Created by 20212 on 6/6/2024.
//
#pragma once
typedef int HPDataType;
#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
struct heap{
    HPDataType *_a;
    int _size;
    int _capacity;
};
void Swap(HPDataType*p1,HPDataType*p2){
    HPDataType temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void AdjustDown(int *a,int n,int root){
    int parent = root;
    int child = parent*2 +1;
    while(child < n){
        if(child + 1 < n && a[child +1] < a[child]){
            ++child;
        }
        if(a[child] < a[parent]){
            Swap(&a[child],&a[parent]);
            parent = child;
            child = parent *2 +1;
            
        }else{
            break;
        }
    }

}
void HeapSort(int *a,int n){
    //1.建堆
    for(int i = (n-1-1)/2;i >= 0;--i){
        AdjustDown(a,n,i);
    }
}