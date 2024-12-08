//
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
void test_set1()
{
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(7);
    s.insert(8);
    // 排序＋去重
    set<int>::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    // set<int> copy(s);

    // for (auto e : copy)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;
    // auto pos = s.find(3);
    set<int>::iterator pos = s.find(3);
    // set 是 二叉搜索树 O(logN)
    // 算法 find O(N)
    //  使用算法 find 和使用 set 内置 find 的区别
    s.erase(pos);
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}
// erase 传值 底层就是由迭代器实现
// erase 传迭代器可以判断是否找到了这个值

void test_map1()
{
    // map -> pair (key,value)
    map<int, int> m;
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(2, 2));
    m.insert(pair<int, int>(3, 3));
    m.insert(make_pair(4, 4)); // 函数模板构造一个对象
    // 大家都喜欢用make_pair，因为是由编译器自己推演

    map<int, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << (*it).first << ":" << (*it).second << " ";
        cout << it->first << ":" << it->second << " ";

        ++it;
    }
    cout << endl;

    for (auto &e : m)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;
}

void test_map2()
{
    std::map<std::string, std::string> dict;
    dict.insert(pair<std::string, std::string>("sort", "排序"));
    dict.insert(make_pair("string", "排序"));

    std::map<std::string, std::string>::iterator it = dict.begin();
    while (it != dict.end())
    {
        cout << it->first << ":" << it->second << " ";
        ++it;
    }
    cout << endl;
}

void test_map3()
{
    string strs[]{"西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜"};
    map<string, int> coutMap;
    for (auto &str : strs)
    {
        map<string, int>::iterator ret = coutMap.find(str);
        if (ret != coutMap.end())
        {
            ret->second++;
        }
        else
        {
            coutMap.insert(make_pair(str, 1));
        }
    }

    for (auto &e : coutMap)
    {
        cout << e.first << " : " << e.second << " ";
    }
    cout << endl;
}
int main()
{
    // test_set1();
    // test_map1();
    // test_map2();
    test_map3();
}

// 如果把中国所有人的身份存入set中，查找一个人在不在最多31次
// set ： 快

// 左值 可取地址的对象 代表一个持久对象或内存位置
// 右值 临时值