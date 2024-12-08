//
// Created by 20212 on 24-10-31.
//
#include <iostream>
#include <vector>
using namespace std;

//[5, 2, 9, 1, 5, 6]
namespace method1
{
    vector<int> slice(const vector<int>& v, size_t start, size_t end)
    {
        if (start > end || end > v.size())
        {
            throw out_of_range("Invalid slice indices");
        }
        return vector<int>(v.begin() + start, v.begin() + end);
    }

    vector<int> InsertionSort(const vector<int>& v)
    {
        vector<int> sorted = {v[0]}; //5
        vector<int> unsorted = slice(v, 1, v.size());
        for (int i = 0; i < unsorted.size(); i++)
        {
            int key = unsorted[i];
            //5 | 2 9 1 5 6
            sorted.push_back(key);
            //5 2
            int j = sorted.size() - 2; //j = 0 -> 1 -> 2
            //j >= 0;
            while (j >= 0 && sorted[j] > key) //5 > 2
            {
                sorted[j + 1] = sorted[j]; //5 5
                j--;
            }
            sorted[j + 1] = key;
        }
        return sorted;
    }
}

namespace method2
{
    void InsertionSort(vector<int>& v)
    {
        for(int i = 1;i < v.size();i++)
        {
            int key = v[i];//1
            int j = i - 1;//0
            //5 2
            while(j >= 0 && v[j] > key)//5 > 2
            {
                v[j + 1] = v[j];
                j --;
            }
            v[j + 1] = key;
        }
    }
}

int main()
{
    vector<int> v = {5, 2, 9, 1, 5, 6};
    // vector<int> sorted = InsertionSort(v);
    method2::InsertionSort(v);
    // for(auto a: sorted)
    vector<int>::iterator it = v.begin();
    while(it != v.end())
    {
        cout << *it << " ";
        it ++;
    }
    cout << endl;
}
//O(n^2) 稳定