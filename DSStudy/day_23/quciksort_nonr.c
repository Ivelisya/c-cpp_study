#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

// 已有的函数
void Swap(int *p1, int *p2);

int GetMidIndex(int a[], int begin, int end);

int PartSort3(int *a, int begin, int end);

void QuickSortNonR(int *a, int left, int right);

void _MergeSort(int *a, int left, int right, int *tmp);

void MergeSort(int *a, int n);

int main() {
    int array[] = {34, 7, 23, 32, 5, 62, 32, 2, 1, 74};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

//    QuickSortNonR(array, 0, size - 1);
    MergeSort(array, size);
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

// 这里是已有的函数实现
void Swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int GetMidIndex(int a[], int begin, int end) {
    int mid = (begin + end) / 2;

    if (a[begin] < a[mid]) {
        if (a[mid] < a[end]) {
            return mid;
        } else if (a[begin] < a[end]) {
            return end;
        } else {
            return begin;
        }
    } else {
        if (a[mid] > a[end]) {
            return mid;
        } else if (a[begin] < a[end]) {
            return begin;
        } else {
            return end;
        }
    }
}

int PartSort3(int *a, int begin, int end) {
    int midIndex = GetMidIndex(a, begin, end);
    Swap(&a[midIndex], &a[end]);
    int key = a[end];
    int cur = begin;
    int prev = begin - 1;

    while (cur < end) {
        if (a[cur] < key) {
            prev++;
            Swap(&a[prev], &a[cur]);
        }
        cur++;
    }
    Swap(&a[prev + 1], &a[end]);
    return prev + 1;  // Return the partition index
}

void QuickSortNonR(int *a, int left, int right) {
    Stack st;
    StackInit(&st);

    StackPush(&st, right);
    StackPush(&st, left);
    while (!StackEmpty(&st)) {
        int begin = StackTop(&st);
        StackPop(&st);
        int end = StackTop(&st);
        StackPop(&st);

        if (begin < end) {
            int div = PartSort3(a, begin, end);
            if (div + 1 < end) {
                StackPush(&st, end);
                StackPush(&st, div + 1);
            }
            if (begin < div - 1) {
                StackPush(&st, div - 1);
                StackPush(&st, begin);
            }
        }
    }
    StackDestory(&st);
}

//时间复杂度O(N*logN)
//空间复杂度O(N)
void _MergeSort(int *a, int left, int right, int *tmp) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int index = begin1;

    while (begin1 <= end1 && begin2 <= end2) {
        if (a[begin1] < a[begin2]) {
            tmp[index++] = a[begin1++];
        } else {
            tmp[index++] = a[begin2++];
        }
    }
    while (begin1 <= end1) {
        tmp[index++] = a[begin1++];
    }
    while (begin2 <= end2) {
        tmp[index++] = a[begin2++];
    }

    for (int i = left; i <= right; ++i) {
        a[i] = tmp[i];
    }
}

void MergeArr(int *a, int begin1, int end1, int begin2, int end2, int *tmp) {
    int left = begin1, right = end2;
    int index = begin1;

    while (begin1 <= end1 && begin2 <= end2) {
        if (a[begin1] < a[begin2]) {
            tmp[index++] = a[begin1++];
        } else {
            tmp[index++] = a[begin2++];
        }
    }
    while (begin1 <= end1) {
        tmp[index++] = a[begin1++];
    }
    while (begin2 <= end2) {
        tmp[index++] = a[begin2++];
    }

    for (int i = left; i <= right; ++i) {
        a[i] = tmp[i];
    }
}

void _MergeSortNonR(int *a, int n) {
    assert(a);
    int *tmp = (int *) malloc(sizeof(int) * n);
    int gap = 1;

    while (gap < n) {
        for (int i = 0; i < n; i += 2 * gap) {
            int begin1 = i;
            int end1 = i + gap - 1;
            int begin2 = i + gap;
            int end2 = i + 2 * gap - 1;

            if (begin2 < n) {
                if (end2 >= n) {
                    end2 = n - 1;
                }
                MergeArr(a, begin1, end1, begin2, end2, tmp);
            }
        }
        gap *= 2;
    }

    free(tmp);
}

void MergeSort(int *a, int n) {
    assert(a);
    int *tmp = (int *) malloc(sizeof(int) * n);
    _MergeSort(a, 0, n - 1, tmp);
    free(tmp);
}

