//
// Created by 20212 on 24-11-1.
//
#include <stdio.h>
void swap(int* a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectSort(int arr[], int n) {
    int i, j, min;
    for (i = 0; i < n; i++) {
        min = i; // 假设第一个就是最小的
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) { // 去掉分号
                min = j; // 更新最小值的索引
            }
        }
        swap(&arr[i], &arr[min]); // 修正交换的位置
    }
}

void testSelectSort() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    SelectSort(arr, n);

    printf("排序后的数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    testSelectSort();
    return 0;
}
//O(n^2) 不稳定