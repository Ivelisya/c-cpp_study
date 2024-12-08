#include <vector>
//
// Created by 20212 on 24-10-31.
//
using namespace std;
#include <iostream>
#include <vector>
void BubbleSort(vector<int> & v)
{
    for(int i= 0;i < v.size();i++)
    {
        for(int j = 0;j < v.size() - i - 1;j++)
        {
            if(v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
int main()
{
    vector<int> v = {5, 2, 9, 1, 5, 6};
    BubbleSort(v);
    for(auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;
}
//O(n^2) 稳定