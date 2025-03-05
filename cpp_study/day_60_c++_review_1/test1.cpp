#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
// stl整体复习梳理
// stl由六大组件构成
// 容器 算法 迭代器 仿函数 适配器 空间配置器

//     空间配置器（内存池）
// 仿函数 容器 迭代器 算法
//     适配器
// 容器（重点中的重点） :string vector list
// 迭代器（重点） 使用的角度分类 ： 正向迭代器 + 反向迭代器 + const 组合成四种迭代器。从功能角度分类:单向迭代器 +
// 双向迭代器 + 随机迭代器 算法（重点）  重点：sort find copy 仿函数（重点） 重点：普通函数对象 + 适配器函数对象

// 单向迭代器：forward_list unordered_list 只支持++操作
// 双向迭代器：list,map/set 支持++ --操作
// 随机：string,deque,array,vector 支持++ -- + -
using namespace std;
/*
int main()
{

    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {10, 20, 30, 40, 50};
    swap(v1, v2); // c++98中不建议，因为涉及深拷贝 不仅仅是vector，所有的容器交换都不建议
    v1.swap(v2); // c++98中建议，因为只是交换了指针，不涉及深拷贝
}
*/
// c++11 当中的写法 随便用 两个都可以
#if 0
    template<class T> void swap( T& a, T& b ){
       T c(std::move(a));
            a = std::move(b);
            b = std::move(c);
    } 这里是c++11中的写法 c++11当中使用移动赋值,移动构造
#endif
// 迭代器按功能分类和算法之间的关系
// 一个算法能不能处理一个容器的数据，就看这个算法的参数声明接受对象的名称
int main(){
    vector<int> v1 = {1, 2, 3, 4, 5};
    list<int> l1 = {10, 20, 30, 40, 50};
    forward_list<int> fl1 = {100, 200, 300, 400, 500};
    reverse(v1.begin(), v1.end()); // 反转算法
    reverse(l1.begin(), l1.end());
    // reverse(fl1.begin(), fl1.end()); // 不能使用reverse算法 因为forward_list只支持单向迭代器 而reverse需要双向迭代器 因为其中有++ --操作
}

//全排列算法 function template