//
// Created by 20212 on 24-10-23.
//
#include <iostream>
#include <string.h>
using namespace std;

// 模板函数：比较两个对象是否相等
template <class T>
bool IsEqual(T& left, T& right)
{
    return left == right; // 默认情况下直接使用 == 进行比较
}

// 全特化：针对 char* 类型进行特殊处理，比较字符串内容
template <>
bool IsEqual<char*>(char*& left, char*& right)
{
    return strcmp(left, right) == 0; // 使用 strcmp 函数比较字符串内容是否相等
}

// 类模板
template <class T1, class T2>
class Data
{
public:
    Data() { cout << "普通模板: Data<T1,T2>" << endl; }
};

// 类模板的偏特化：偏特化处理第一个模板参数为 int 的情况
template <class T2>
class Data<int, T2>
{
public:
    Data() { cout << "偏特化: Data<int,T2>" << endl; }
};

template <class T1, class T2>
class Data<T1*, T2*>
{
public:
    Data() { cout << "普通模板: Data<T1*,T2*>" << endl; }
};
//偏特化 可以是特化部分参数/或者对一些参数进一步的限制
int main()
{
    int a = 0, b = 1;
    cout << IsEqual(a, b) << endl; // 输出结果为 0（false），因为 0 != 1

    char* p1 = (char*)"hello"; // 注意：需要将字符串字面量转换为 char*
    char* p2 = (char*)"world";
    cout << IsEqual(p1, p2) << endl; // 输出结果为 0（false），因为 "hello" != "world"

    Data<int, char> d1; // 使用偏特化的模板
    Data<double, char> d2; // 使用普通模板
    return 0;
}

// 全特化 (Full Specialization)：为特定类型提供完全不同的实现，
// 如上例的 char* 类型特化，专门处理字符串的比较逻辑。

// 偏特化 (Partial Specialization)：只为某些特定条件下的类型提供特殊处理，
// 例如，在类模板中，偏特化处理第一个模板参数为 int 的情况。
