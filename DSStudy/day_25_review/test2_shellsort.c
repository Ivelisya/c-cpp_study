#include <stdio.h>

//
// Created by 20212 on 14/8/2024.
//
void ShellSort(int* a, int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int key = a[i];
            int j = i - gap;
            while (j >= 0 && a[j] > key) {
                a[j + gap] = a[j];
                j = j - gap;
            }
            a[j + gap] = key;
        }
        gap = gap / 2;
    }
}

void PrintArr(int *a,int n){
    for(int i = 0;i < n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int a[] = {5,2,9,1,5,6};
    ShellSort(a,sizeof(a)/sizeof(int));
    PrintArr(a,sizeof(a)/sizeof(int));
}
