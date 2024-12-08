//
// Created by admin on 24-10-6.
//
/*
 *
 *vector 是一个顺序容器 使用一个可以改变大小的数组实现
 *
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//string更多的表示单项信息
//allocator 内存池
void text_vector1() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    vector<int> v2(v1);
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << v2[i] << " ";
    }
    cout << endl;

    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(40);
    v3.push_back(50);

    v1 = v3;
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";
    }
}

void test_vector() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //遍历修改数据
    //1.operator[] + size;
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        cout << *it * 2 << " ";
        ++it;
    }
    cout << endl;

    //3.范围for
    for (auto e: v) {
        cout << e << " ";
    }
    cout << endl;
}

void print_vector(const vector<int> &v) {
    vector<int>::const_iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

void test_vector3() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(12);
    v.push_back(2);
    v.push_back(8);
    v.push_back(6);
    //普通正向迭代器 可读可写
    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    print_vector(v);
    vector<int>::reverse_iterator rit = v.rbegin();
    while (rit != v.rend()) {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}

void test_vector4() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(12);
    v.push_back(2);
    v.push_back(8);
    v.push_back(6);

    cout << v.size() << " ";
    cout << v.capacity() << endl;

    //增容次数越多效率越低 因为每次增容都会有代价

    //为什么是二倍，为什么是1.5倍
    //增多增少是一种选择 windows和linux平台不同 增多少是一种选择

    //vector有一定程度的缺陷 缺陷是增容是会付出代价的
}

void test_vector5() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    //vector[]使用断言来防止错误
}
void test_vector6() {
    vector<int> v;
    v.push_back(10);
    v.push_back(211);
    v.push_back(31);
    v.push_back(42);
    v.push_back(501);
    v.push_back(61);
    // v.insert(v.begin(),0);
    // v.insert(v.begin(),-1);
    for(auto e: v) {
        cout << e << " ";
    }
    cout << endl;
    //要求删掉211
    // v.erase(v.begin() + 1);
    vector<int>::iterator pos = find(v.begin(),v.end(),211);
    sort(v.begin(),v.end());
    if (pos != v.end()) {
        v.erase(pos);
    }

    for(auto e: v) {
        cout << e << " ";
    }
}
int main() {
    // text_vector1();
    // test_vector();
    // test_vector4();
    test_vector6();
}

