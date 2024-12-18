#include <algorithm>
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
    }
};

// decltype(auto) - 返回值类型推导
// int main()
// {
//     int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     std::sort(array, array + sizeof(array) / sizeof(array[0]), Greater<int>());

//     // 输出排序后的数组
//     for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//     {
//         cout << array[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
int main()  // lm
{
    // 最简单的lambda表达式
    // [] {};  // 匿名函数
    // int  a = 3, b = 4;
    // auto add = [](int x1, int x2) -> int { return x1 + x2; };  // 7
    // add(a, b);
    // // lambda表达式格式：[捕获外部变量](参数列表) mutable(可选) -> 返回类型 {函数体}
    // auto add2  = [a, b]() -> int { return a + b; };  // 7
    // auto swap2 = [&a, &b] {
    //     int temp = a;
    //     a        = b;
    //     b        = temp;
    // };
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::sort(array, array + sizeof(array) / sizeof(array[0]), [](int x1, int x2) -> bool {
        return x1 < x2;
    });
    cout << "排序后的数组：";
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
    {
        cout << array[i] << " ";
    }
}