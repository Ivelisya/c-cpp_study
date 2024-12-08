//
// Created by 20212 on 2024/6/5.
//
#include "heap.h"
void HeapSort(int* a,int n){
    //1.建堆(倒着调)
     for(int i =(n-1-1);i >= 0;--i){
         AdustDown(a,n,i);
     }
}

int main(){
    int a[] = {27,15,19,18,28,34,65,49,25,37};
    HeapSort(a,sizeof(a)/sizeof(HPDataType));
    return 0;
}