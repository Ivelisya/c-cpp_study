//
// Created by admin on 24-10-9.
//
// #include <iostream>
// #include <string>
// using namespace std;
// string aa = "aaaa";
// int main() {
//
// }
#include <iostream>
#include <vector>
using namespace std;
//迭代器失效
void test_vector() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    vector<int>::iterator it = v.begin();
    //
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);
    //it指向增容前的地址 增容导致失效

    //push_back insert resize reserve等可能会扩容的接口都会导致迭代器失效
    while (it != v.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void test_vector2() {
    vector<int> v;
    v.push_back(1);
    v.push_back(12);
    v.push_back(32);
    v.push_back(4);
    v.push_back(8);
    v.push_back(6);
    v.push_back(7);

    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        if (*it % 2 == 0) {
            it = v.erase(it);//删除it之后，it的位置就失效了，再++ 就不行 因为已经被删除了
            //it会返回删除的it的下一个位置的迭代器
        }else {
            ++it;
        }
    }
    for (auto e: v) {
        cout << e << " ";
    }
    cout << endl;

    //不管在哪个平台 erase(it)之后就已经失效了 只是导致的结果不一样而已
}

int main() {
    test_vector2();
}
