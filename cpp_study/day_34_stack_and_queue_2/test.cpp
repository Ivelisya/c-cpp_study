//
// Created by 20212 on 24-10-21.
//
//deque 迭代器非常复杂
//iterator it = d.begin()
//while(it != d.end(){
//cout <<*it<<" ";
//++it;
//} cout << endl;

//deque缺点：1.大量频繁的operator[]的效率低
//list缺点:不支持随机访问
//vector缺点:头插头删效率低，空间不够增容代价大

//deque比vector效率差了四到五呗
//priority_queue 优先级高的出
#include <queue>
#include <iostream>
#include <functional>
#include "priority_queue.h"
using namespace std;
//容器适配器 都不支持迭代器遍历，因为他们通常都包含一些特性
//如果支持迭代器随便遍历，那他们无法很好的保持它的性质
void test_priority_queue()
{
    //如果想变成小的优先级高应该怎么做 仿函数
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    pq.push(6);
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

//仿函数 函数对象
namespace study
{
    template <class T>
    struct less
    {
        bool operator()(const T& x1, const T& x2)
        {
            return x1 < x2;
        }
    };

    template <class T>
    struct greater
    {
        bool operator()(const T& x1, const T& x2)
        {
            return x1 > x2;
        }
    };
}

void test_sort()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    sort(v.begin(), v.end());
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

//除了默认访问限定符不一样,struct和class在c++中是一样的
//一般情况，成员部分私有部分共有就用class
//所有成员都开放就用struct
int main()
{
    // test_priority_queue();
    // study_priority_queue::test_priority_queue();

    // study::less<int> lessFunc;
    // cout << lessFunc(1, 2) << endl;
    //lessFunc不是一个函数，是一个对象 调用operator() lessFunc.operator()(1,2)
    //仿函数 函数对象 它的对象可以像函数一样使用
    test_sort();
    return 0;
}
