//
// Created by 20212 on 25/7/2024.
//
#include "sort.h"

void InsertSort(int *a, int n) {
    assert(a);
    for (int i = 0; i < n - 1; ++i) {
        //所以 i应该 < n-1 因为，i < n - 1,它的边界即为n-2,end + 1，则为n - 1,不会产生越界
        //把end + 1往[0,end]区间插入保持它有序
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0) {
            if (a[end] > tmp) {
                a[end + 1] = a[end];
                --end;
            } else {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}

void ShellSort(int *a, int n) {
    int gap = n;
    //1.gap>1相当于预排序
    //2.gap == 1相当于直接插入排序
    while (gap > 1) {
        gap = gap / 3 + 1;//+1保证最后一次gap一定是1
        //gap == 1最后一次相当于直接插入排序
        for (int i = 0; i < n - gap; ++i) {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0) {
                if (a[end] > tmp) {
                    a[end + gap] = a[end];
                    end -= gap;
                } else {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}

void Swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void SelectSort(int *a, int n) {
    assert(a);
    int begin = 0, end = n - 1;
    while (begin < end) {
        //在begin和end之间找出最小和最大的数的下标
        int mini, maxi;
        mini = maxi = begin;
        for (int i = begin + 1; i <= end; ++i) {
            if (a[i] > a[maxi]) {
                maxi = i;
            }
            if (a[i] < a[mini]) {
                mini = i;
            }
        }
        Swap(&a[begin], &a[mini]);
        //如果maxi和begin位置重叠，则maxi的位置需要修正
        if (begin == maxi) {
            maxi = mini;
        }
        Swap(&a[end], &a[maxi]);
        ++begin;
        --end;
    }
}//时间复杂度 o(n^2)
//堆排序
void AdjustDown(int *a, int n, int root) {
    int parent = root;
    //左孩子
    int child = parent * 2 + 1;
    while (child < n) {
        if (child + 1 < n && a[child + 1] > a[child]) {
            ++child;
        }
        if (a[child] > a[parent]) {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        } else {
            break;
        }
    }
}

void HeapSort(int *a, int n) {
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
        AdjustDown(a, n, i);
    }
    int end = n - 1;
    while (end > 0) {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        --end;
    }
}

void BubbleSort(int *a, int n) {
    int end = n;
    while (end > 0) {
        int exchange = 0;
        for (int i = 1; i < end; ++i) {
            if (a[i - 1] > a[i]) {
                Swap(&a[i - 1], &a[i]);
                exchange = 1;
            }
        }
        if (exchange == 0) {
            break;
        }
    }

}
//希尔排序是对直接插入排序的优化
//直接插入排序，时间复杂度是 O(n^2) 单趟插入是 O(n)
//空间复杂度O(1)
//什么情况下最好?什么情况下最坏?
//顺序有序最好
//逆序最坏

//希尔排序，又叫缩小量排序

//插入排序 1.预排序(让数组接近有序) 2.直接插入排序
//1.预排序 把间距为gap的值分为一组，进行插入排序
//gap越大，前面大的数可以越快到后面，后面小的数可以越快到前面，但是gap越大，越不接近有序，gap越小越接近有序，如果gap=1，其实就相当于直接插入排序，就有序了
//gap > 1预排序
//gap = 1 直接插入排序