#include <stdio.h>

void StraightInsert(int *arr, int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            int temp = arr[i];  // 暂存需要插入的元素
            arr[i] = arr[i - 1]; // 将元素后移以腾出空间

            // 从 i - 1 向前查找插入位置
            for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
                arr[j + 1] = arr[j];  // 元素后移
            }
            arr[j + 1] = temp;  // 插入到正确位置
        }
    }
}
int main() {
    int arr[10] = {10, 3, 20, 11, 76, 13, 46, 99, 1, 31};
    int n = sizeof(arr) / sizeof(int);
    StraightInsert(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
