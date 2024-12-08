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

//[begin,end]
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

//1.左右指针法
int PartSort(int *a, int begin, int end) {
    int key = a[end];
//    int midIndex = GetMidIndex(a,begin,end);
//    Swap(&a[midIndex],&a[end]);
    int keyIndex = end;
//如果在key在左边则右边先走，如果key在右边则左边先走
    while (begin < end) {
        //begin找大

        //这样保证begin和end在比key大的位置相遇
        while (begin < end && a[begin] <= key) {
            ++begin;
        }
        //end找小
        while (begin < end && a[end] >= key) {
            --end;
        }
        Swap(&a[begin], &a[end]);
    }
    Swap(&a[begin], &a[keyIndex]);
    return begin;
}

//挖坑法
//开始先挖一个坑
//然后左右填
void PartSort1(int *a, int begin, int end) {
    int midIndex = GetMidIndex(a, begin, end);
    Swap(&a[midIndex], &a[end]);
    int key = a[end];

    while (begin < end) {
        while (begin < end && a[begin] <= key) {
            ++begin;
        }
        // 左边找到比key大的填到右边的坑, 左边begin位置就形成新的坑
        if (begin < end) {
            a[end] = a[begin];
        }

        while (begin < end && a[end] >= key) {
            --end;
        }
        // 右边找到比key小的填到左边的坑，end位置就形成新的坑
        if (begin < end) {
            a[begin] = a[end];
        }
    }
    // 最后将key填到中间的坑中
    a[begin] = key;
}
//extern void PrintArray(int *a, int n);
//3.前后指针法
//cur找小跟++prev的交换，把小的翻到左边，把大的往后推
void PartSort3(int* a, int begin, int end) {
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
}
void QuickSort(int *a, int left, int right) {
    assert(a);
    if (left >= right) {
        return;
    }
//    PrintArray(a, sizeof(a) / sizeof(int));
//    PrintArray(a, right);

    int div = PartSort(a, left, right);
//    PrintArray(a, right);

    QuickSort(a, left, div - 1);
    QuickSort(a, div + 1, right);
}

//快排 最好的情况 时间复杂度O(N * logN) 到 O(N*2)
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

//快速排序
//1.左边的比key小，右边的比key大
//2.5 key放到他正确的位置
//3.采用递归分治 分为多个小问题

//右边做key左边先走

//实际当中我们无法保证选key是中位数
//那么我们是不是可以考虑至少不要选到最大的或者最小的左key

//三数取中法 保证不要选到最小或者最大，让有序时变成最优

//存在三数取优之后。综合而言快排O(N*logN)

//快速排序
//1.左右指针法
//2.挖坑法
//3.前后指针法