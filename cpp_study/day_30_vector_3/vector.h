#pragma once
#include <cassert>
#include <iostream>
#include <cstring> // 需要包含这个头文件以使用 memcpy
#include <algorithm> // 引入算法头文件以使用 std::copy
using namespace std;

namespace vector_study {
    template<class T>
    class vector {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;

        vector() : _start(nullptr), _finish(nullptr), _endofstorage(nullptr) {
        }

        ~vector() {
            delete[] _start; // 添加析构函数以释放内存
            _start = _finish = _endofstorage = nullptr;
        }

        //v1 = v3
        // vector<T>& operator= (const vector<T> &v) {
        //     if( this != &v) {
        //         delete[]_start;
        //         _start = new T[v.capacity()];
        //         memcpy(_start,v._start,sizeof(T)*v.size());
        //     }
        // }
        vector<T> &operator =(vector<T> v) {

            //通过这个每次交换都会进行一次深拷贝，代价极大
            swap(_start, v._start);
            swap(_finish, v._finish);
            swap(_endofstorage, v._endofstorage);
            return *this;
        }

        //v2(v1)
        /* vector(const vector<T> &v) {
             _start = new T[v.capacity()];
             _finish = _start;
             _endofstorage = _start + v.capacity();
             for(size_t i = 0;i < v.size();i++) {
                 *_finish = v[i];
                 ++_finish;
             }
         }
         */
        vector(const vector<T> &v): _finish(nullptr), _start(nullptr), _endofstorage(nullptr) {
            reserve(v.capacity());
            for (const auto e: v) {
                this->push_back(e);
            }
        }

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
                T *tmp = new T[n]; // 新的内存
                if (_start) {
                    //使用memcpy就会出现问题，因为memcpy是一个浅拷贝

                    //for(size_t i = 0;i < sz;++i){tmp[i] = _start[i]}调用的是 operator = 是深拷贝
                    std::copy(_start, _finish, tmp); // 使用 std::copy 复制已有元素
                    delete[] _start; // 释放旧内存
                }
                _start = tmp;
                _finish = _start + sz;
                _endofstorage = _start + n; // 更新 _endofstorage
            }
        }

        void insert(iterator pos, const T &x) {
            if (_finish == _endofstorage) {
                size_t n = pos - _start;
                size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
                reserve(newcapacity);
                pos = _start + n; // 更新 pos
            }
            iterator end = _finish - 1;
            while (end >= pos) {
                *(end + 1) = *end; // 移动元素
                end--;
            }
            *pos = x;
            ++_finish;
        }

        void push_back(const T &x) {
            insert(_finish, x);
        }

        size_t size() const {
            return _finish - _start;
        }

        size_t capacity() const {
            return _endofstorage ? (_endofstorage - _start) : 0; //防御性编程，使代码更加健壮
        }

        T &operator[](size_t i) {
            assert(i < size());
            return _start[i]; // _start[i] 是 *(_start + i) 的简写
        }

        const T &operator[](size_t i) const {
            assert(i < size());
            return _start[i]; // _start[i] 是 *(_start + i) 的简写
        }

        void pop_back() {
            assert(_finish > _start);
            --_finish;
        }

        iterator erase(iterator pos) {
            assert(pos < _finish);
            iterator it = pos;
            while (it < _finish - 1) {
                // 移动元素，直到倒数第二个元素
                *it = *(it + 1);
                ++it;
            }
            --_finish;
            return pos;
        }

        void resize(size_t n, const T &val = T()) {
            if (n < size()) {
                _finish = _start + n;
            } else {
                if (n > capacity()) {
                    reserve(n);
                }
                while (_finish < _start + n) {
                    *_finish = val;
                    ++_finish;
                }
            }
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage; // 容器的总容量
    };

    void print_vector(const vector<int> &v) {
        vector<int>::const_iterator it = v.begin();
        while (it != v.end()) {
            cout << *it << " ";
            it++;
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
        for (auto &e: v) {
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
        v.reserve(10);
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        // print_vector(v);
        v.insert(v.begin(), 0);
        print_vector(v);
        cout << v.size() << " ";
        cout << v.capacity() << " ";
    }

    void test_insert_and_erase() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        cout << "Initial vector: ";
        print_vector(v); // 应该输出: 1 2 3

        v.insert(v.begin() + 1, 99); // 在第二个位置插入 99
        cout << "After inserting 99 at position 1: ";
        print_vector(v); // 应该输出: 1 99 2 3

        v.erase(v.begin() + 2); // 删除第三个元素 (原来的 2)
        cout << "After erasing element at position 2: ";
        print_vector(v); // 应该输出: 1 99 3
    }

    void test_resize() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        cout << "Initial vector: ";
        print_vector(v); // 应该输出: 1 2 3

        v.resize(5, 0); // 调整大小为 5，并用 0 填充新增元素
        cout << "After resizing to 5: ";
        print_vector(v); // 应该输出: 1 2 3 0 0

        v.resize(2); // 调整大小为 2，缩小
        cout << "After resizing to 2: ";
        print_vector(v); // 应该输出: 1 2
    }

    void test_edge_cases() {
        vector<int> v;

        // 测试从空 vector 中 pop_back
        cout << "Trying to pop_back from an empty vector..." << endl;
        try {
            v.pop_back(); // 应该触发断言
        } catch (const std::exception &e) {
            cout << "Caught an exception: " << e.what() << endl;
        }

        // 测试访问超出范围
        cout << "Trying to access out of range index..." << endl;
        try {
            cout << v[0] << endl; // 应该触发断言
        } catch (const std::exception &e) {
            cout << "Caught an exception: " << e.what() << endl;
        }

        // 测试 push_back 到容量为 0 的情况
        cout << "Pushing back to a new vector..." << endl;
        v.push_back(42);
        cout << "After pushing back 42: ";
        print_vector(v); // 应该输出: 42
    }

    void test_vector() {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);

        vector<int> v2(v1);
        for (size_t i = 0; i < v1.size(); ++i) {
            cout << v1[i] << " ";
        }
        cout << endl;

        for (size_t i = 0; i < v2.size(); ++i) {
            cout << v2[i] << " ";
        }
        cout << endl;
    }

    void test_vector5() {
        vector<string> v;
        v.push_back("111111111111111111111111111111");
        v.push_back("222211111111111111111111111111111");
        v.push_back("333311111111111111111111111111");
        v.push_back("444441111111111111111111111111");
        for(auto e:v) {
            cout << e << " ";
        }
        cout <<endl;
    }
}

//memset 是按字节处理
//mem系列全部都是按字节处理

//int j = int()
//int i = int()
//double d = double();
//double e = double(1.1);
//可以认为内置函数也有构造函数 int()就是 0 严格来说内置类型是没有构造函数的 但为了更好的支持模板 于是就产生了

//memcpy是一个浅拷贝 memcpy 只是按字节将数据从源地址复制到目标地址
