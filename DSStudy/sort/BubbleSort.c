#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct {
    DataType *arr;
    int length;
} SeqList;

void BubbleSort(SeqList *L) {
    for (int i = 0; i < L->length - 1; i++) {
        for (int j = 0; j < L->length - 1 - i; j++) {
            if (L->arr[j] > L->arr[j + 1]) {
                int temp = L->arr[j];
                L->arr[j] = L->arr[j + 1];
                L->arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    // 初始化一个序列
    SeqList list;
    printf("请输入序列的长度: ");
    scanf("%d", &list.length);
    // 分配内存并初始化数组
    list.arr = (DataType *)malloc(list.length * sizeof(DataType));
    if (list.arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    // 读取序列的元素
    printf("请输入序列的元素: ");
    for (int i = 0; i < list.length; i++) {
        scanf("%d", &list.arr[i]);
    }
    // 输出排序前的序列
    printf("排序前的序列: ");
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.arr[i]);
    }
    printf("\n");
    // 调用BubbleSort函数进行排序
    BubbleSort(&list);
    // 输出排序后的序列
    printf("排序后的序列: ");
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.arr[i]);
    }
    printf("\n");
    // 释放内存
    free(list.arr);
    return 0;
}
