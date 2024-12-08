//
// Created by 20212 on 24-11-1.
//
void shell_sort(int arr[], int n)
{
    int i, j, inc, key;
    //初始增量:n/2,每一趟之后除以二
    for (inc = n / 2; inc > 0; inc /= 2)
    {
        for (i = inc; i < n; i++)
        {
            key = arr[i];
            for (j = i; j >= inc && key < arr[j - inc]; j -= inc)
            {
                arr[j] = arr[j - inc];
            }
            arr[j] = key;
        }
    }
}
//O(n^1.5) 不稳定
