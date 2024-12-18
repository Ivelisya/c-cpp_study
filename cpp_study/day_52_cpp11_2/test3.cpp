// lambda表达式
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

struct Goods
{
    string _name;
    double _price;
    int    _num;
};

template <class T>
struct Greater

{
    bool operator()(const T &left, const T &right)
    {
        return left > right;
    };
};

template <class T>
bool GreaterFunc(const T &left, const T &right)
{
    return left > right;
}

// decltype(auto) - 返回值类型推导
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::sort(array, array + sizeof(array) / sizeof(array[0]), Greater<class T>());
}