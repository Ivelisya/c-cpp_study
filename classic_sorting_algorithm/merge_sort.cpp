#include <vector>
//
// Created by 20212 on 24-10-31.
//
//归并排序 实现两个函数 1.合并 2.递归分组
//划分合并算法
#include <iostream>
using namespace std;
#include <vector>

vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> newArray;
    int i = 0, j = 0; //两个指针 一个i 一个j
    while (i < a.size() && j < b.size())
    {
        if (a[i] > b[j])
        {
            newArray.push_back(b[j]);
            j++;
        }
        else
        {
            newArray.push_back(a[i]);
            i++;
        }
    }
    for (; i < a.size(); i++)
    {
        newArray.push_back(a[i]);
    }
    for (; j < b.size(); j++)
    {
        newArray.push_back(b[j]);
    }
    return newArray;
}
vector<int> mergeSort(vector<int> arr)
{
    if(arr.size() <= 1)
        return arr;
    vector<int> leftPart,rightPart;
    int n = arr.size();
    for(int i = 0;i < n/2;i++)
    {
        leftPart.push_back(arr[i]);
    }
    for(int i = n/2;i < n;i++)
    {
        rightPart.push_back(arr[i]);
    }
    return merge(mergeSort(leftPart),mergeSort(rightPart));
}

void testMergeSort() {
    vector<int> testArray = {38, 27, 43, 3, 9, 82, 10};
    vector<int> sortedArray = mergeSort(testArray);

    cout << "原数组: ";
    for (int num : testArray) {
        cout << num << " ";
    }
    cout << endl;

    cout << "排序后数组: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    testMergeSort();
    return 0;
}
//O(nlogn) 稳定