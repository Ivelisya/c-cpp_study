#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        // 比pivot小的，全部换到前面去
        if (arr[j] < pivot) {
            swap(&arr[j], &arr[i++]);
        }
    }
    // 此时，i指向的元素一定大于等于pivot;
    swap(&arr[high], &arr[i]);
    return i;
}

void qsort(int arr[], int low, int high) {
    if (low < high) {
        int mid = partition(arr, low, high);
        qsort(arr, low, mid - 1);
        qsort(arr, mid + 1, high);
    }
}

void quick_sort(int arr[], int len) {
    qsort(arr, 0, len - 1);
}

int main() {
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, len);
    
    printf("Sorted array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
//O(nlogn) 不稳定