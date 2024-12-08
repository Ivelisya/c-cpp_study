#include <iostream>
// Created by 20212 on 24-10-15.
//
#include <list>
#include <algorithm>
#include <vector>
using namespace std;

void print_list(const list<int>& l)
{
    list<int>::const_iterator it = l.begin();
    for (; it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test_list()
{
    list<int> lit1;
    lit1.push_back(1);
    lit1.push_back(2);
    lit1.push_back(3);
    lit1.push_back(4);
    lit1.push_back(5);
    lit1.push_back(6);
    list<int>::iterator it1 = lit1.begin();
    while (it1 != lit1.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;
    print_list(lit1);

    list<int> lt2;
    lt2.push_back(1);
    lt2.push_back(2);
    lt2.push_back(3);
    lt2.push_back(4);
    for (auto e : lt2)
    {
        cout << e << " ";
    }
    cout << endl;

    //reverse 逆置
    //reserve 保留

    list<int>::reverse_iterator rit2 = lt2.rbegin();
    while(rit2 != lt2.rend())
    {
        cout << *rit2 << " ";
        ++rit2;
    }
    cout << endl;
}

void test_list2()
{
    list<int> lit1;
    lit1.push_back(1);
    lit1.push_back(2);
    lit1.push_back(3);
    lit1.push_back(4);
    lit1.push_back(0);
    lit1.push_front(-1);
    print_list(lit1);
    lit1.pop_front();
    lit1.pop_back();
}
//迭代器从使用性质分为三种 ：单向forword_list 双向list 随机vector
//从使用的场景分迭代器 ：正向迭代器 反向迭代器 + const迭代器

void test_list3()
{
    list<int> lit1;
    lit1.push_back(1);
    lit1.push_back(2);
    lit1.push_back(3);
    lit1.push_back(4);
    lit1.push_back(5);
    lit1.push_front(-1);
    // print_list(lit1);
    // lit1.pop_front();
    // lit1.pop_back();
    //lit1.insert(begin() + 3,30) 因为是链表 所以不支持
    //使用算法代替
    list<int>::iterator pos = find(lit1.begin(), lit1.end(), 3);
    if(pos != lit1.end())
    {
        lit1.insert(pos,30);//这里insert之后迭代器失效了吗
    }
    print_list(lit1);
}

void test_vector()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int>::iterator pos = find(v.begin(), v.end(), 3);
    if(pos != v.end())
    {
        v.insert(pos,30);//这里insert之后迭代器失效了吗
    }
}

//迭代器失效 增容问题

//replace 把一个链表转移到另外一个链表

void test_list4()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(6);
    lt.push_back(3);
    lt.push_back(2);
    // lt.sort();
    lt.reverse();
    print_list(lt);
}

void test_list5()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(6);
    lt.push_back(3);
    lt.push_back(2);
    lt.push_back(4);
    lt.push_back(5);
    lt.push_back(6);
    list<int>::iterator it = lt.begin();
    while(it != lt.end())
    {
        if(*it % 2 == 0)
        {
            it = lt.erase(it);//erase掉这里后，这里就已经失效了
        }
        else
        {
            ++it;
        }
        // ++it;
    }
    print_list(lt);
}
int main()
{
    test_list5();
    // test_list();
}
