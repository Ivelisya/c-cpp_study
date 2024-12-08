//
// Created by 20212 on 25/7/2024.
//

#include "sort.h"

void PrintArray(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void TestInsertSort() {
    int a[] = {3, 1, 4, 1, 7, 3, 8, 23, 2, 1111, 0};
    PrintArray(a, sizeof(a) / sizeof(int));
    InsertSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort() {
    int a[] = {3, 1, 4, 1, 7, 3, 8, 23, 2, 1111, 0};
    PrintArray(a, sizeof(a) / sizeof(int));
    ShellSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSelectSort() {
    int a[] = {3, 1, 4, 1, 7, 3, 8, 23, 2, 1111, 0};
    PrintArray(a, sizeof(a) / sizeof(int));
    SelectSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort() {
    int a[] = {3, 1, 4, 1, 7, 3, 8, 23, 2, 1111, 0};
    PrintArray(a, sizeof(a) / sizeof(int));
    BubbleSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

void TestHeapSort() {
    int a[] = {3, 1, 4, 1, 7, 3, 8, 23, 2, 1111, 0};
    PrintArray(a, sizeof(a) / sizeof(int));
    HeapSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}
void TestQucikSort() {
    int a[] = {3, 1, 4, 1, 7, 3, 8, 23, 2, 1111, 0};
    PrintArray(a, sizeof(a) / sizeof(int));
    QuickSort(a,0 ,sizeof(a) / sizeof(int)-1);
    PrintArray(a, sizeof(a) / sizeof(int));
}

int main() {
//    TestInsertSort();
//    TestShellSort();
//    TestBubbleSort();
    TestQucikSort();
}
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <assert.h>
//#include "sort.h"
//
//// Function prototypes
//void InsertSort(int* a, int n);
//void ShellSort(int* a, int n);
//
//void GenerateRandomArray(int* a, int n, int range) {
//    for (int i = 0; i < n; ++i) {
//        a[i] = rand() % range;
//    }
//}
//
//void CopyArray(int* dest, int* src, int n) {
//    for (int i = 0; i < n; ++i) {
//        dest[i] = src[i];
//    }
//}
//
//void PrintArray(int* a, int n) {
//    for (int i = 0; i < n; ++i) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//}
//
//int main() {
//    const int SIZE = 100000; // Adjust size as needed
//    const int RANGE = 100000; // Adjust range as needed
//
//    int* array = (int*)malloc(SIZE * sizeof(int));
//    int* arrayCopy = (int*)malloc(SIZE * sizeof(int));
//
//    if (array == NULL || arrayCopy == NULL) {
//        printf("Memory allocation failed\n");
//        return 1;
//    }
//
//    GenerateRandomArray(array, SIZE, RANGE);
//    CopyArray(arrayCopy, array, SIZE);
//
//    // Test InsertSort
//    clock_t start = clock();
//    InsertSort(array, SIZE);
//    clock_t end = clock();
//    double duration = (double)(end - start) / CLOCKS_PER_SEC;
//    printf("InsertSort took %f seconds.\n", duration);
//
//    // Test ShellSort
//    CopyArray(array, arrayCopy, SIZE);
//    start = clock();
//    ShellSort(array, SIZE);
//    end = clock();
//    duration = (double)(end - start) / CLOCKS_PER_SEC;
//    printf("ShellSort took %f seconds.\n", duration);
//
//    free(array);
//    free(arrayCopy);
//
//    return 0;
//}
