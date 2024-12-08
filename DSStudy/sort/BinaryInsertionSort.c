#include <stdio.h>

#define MAX 10

typedef struct {
    int r[MAX + 1];
    int length;
} SqList;

void BinaryInsert(SqList *L) {
    int i, j;
    for (i = 2; i <= L->length; i++) {  // 从2开始，因为L->r[0]用作哨兵元素
        if (L->r[i - 1] > L->r[i]) {
            L->r[0] = L->r[i];  // 哨兵元素
            int low = 1, high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (L->r[0] >= L->r[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            for (j = i - 1; j >= high + 1; j--) {
                L->r[j + 1] = L->r[j];
            }
            L->r[high + 1] = L->r[0];
        }
    }
}

int main() {
    SqList L = {.length = MAX};
    // 初始化数组，示例数据
    int sampleData[MAX] = {3, 1, 4, 5, 9, 2, 6, 7, 8, 0};
    for (int i = 1; i <= MAX; i++) {
        L.r[i] = sampleData[i - 1];
    }

    printf("Before sorting:\n");
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i]);
    }
    printf("\n");

    BinaryInsert(&L);

    printf("After sorting:\n");
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i]);
    }
    printf("\n");

    return 0;
}
