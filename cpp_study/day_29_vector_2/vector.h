#pragma once
#include <cassert>
#include <iostream>
#include <cstring> // 需要包含这个头文件以使用 memcpy
using namespace std;

namespace vector_study {
    template<class T>
    class vector {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        vector() : _start(nullptr), _finish(nullptr), _endofstorage(nullptr) {}

        iterator begin() {
            return _start;
        }
        const_iterator begin() const {
            return _start;
        }

        iterator end() {
            return _finish;
        }

        const_iterator end() const {
            return _finish;
        }

        void reserve(size_t n) {
            if (n > capacity()) {
                size_t sz = size();
                T* tmp = new T[n]; // 新的内存
                if (_start) {
                    memcpy(tmp, _start, sizeof(T) * sz); // 复制已有元素
                    delete[] _start; // 释放旧内存
                }
                _start = tmp;
                _finish = _start + sz;
                _endofstorage = _start + n; // 更新 _endofstorage
            }
        }
        void insert(iterator pos,T& x) {
            if (_finish == _endofstorage) {
                size_t n = pos - _start;
                size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
                reserve(newcapacity);
                //扩容之后产生了一段新的内存空间
                //会出现迭代器失效
                pos = _start + n;
            }
            iterator end = _finish - 1;
            //pos是指向原本内存空间的指针
            while(end >= pos) {
                *(end + 1) = *end;
                end--;
            }
            *pos = x;
            ++_finish;
        }
        void push_back(const T& x) {
            insert(_finish,x);
        }

        size_t size() {
            return _finish - _start;
        }

        size_t capacity() {
            return _endofstorage ? (_endofstorage - _start) : 0;//防御性编程，使代码更加健壮
        }

        T& operator[](size_t i) {
            assert(i < size());
            return _start[i]; // _start[i] 是 *(_start + i) 的简写
        }

        void pop_back() {
            assert(_finish > _start);
            --_finish;
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage; // 容器的总容量
    };
    void print_vector(const vector<int> &v) {
        vector<int>::const_iterator it = v.begin();
        while(it != v.end()) {
            cout << *it << " ";
            it ++;
        }
        cout << endl;
    }


    void test_vector1() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);

        // 测试迭代器遍历
        vector<int>::iterator it = v.begin();
        while (it != v.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        // 测试范围循环
        for (auto &e : v) {

            e -= 1;
            std::cout << e << " ";
        }
        std::cout << std::endl;

        // 测试下标访问
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        std::cout << std::endl;

        // 测试容量和大小
        cout << "Size: " << v.size() << endl;
        cout << "Capacity: " << v.capacity() << endl;

        // 测试 reserve 扩容功能
        v.reserve(20);
        cout << "After reserve(20):" << endl;
        cout << "Size: " << v.size() << endl;
        cout << "Capacity: " << v.capacity() << endl;

        // 再次添加元素以验证扩容
        v.push_back(7);
        v.push_back(8);
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        std::cout << std::endl;
    }
    void vector_test2() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        print_vector(v);
    }
}
