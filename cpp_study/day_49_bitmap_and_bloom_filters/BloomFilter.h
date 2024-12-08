#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <cstdint>
using namespace std;

namespace bit
{
    // 使用 std::bitset 来简化位图操作
    class bitset
    {
    public:
        // 构造函数，初始化位图
        bitset(size_t N)
        {
            _bits.resize((N + 31) / 32); // 根据位图大小动态分配
        }

        // 将x位置设为1
        void set(size_t x)
        {
            size_t index = x / 32; // 计算x映射的位置在第几个整形
            size_t pos = x % 32;   // 计算x映射的位置在整形的第几位
            _bits[index] |= (1 << pos); // 将第pos位置1
        }

        // 将x位置设为0
        void reset(size_t x)
        {
            size_t index = x / 32;
            size_t pos = x % 32;
            _bits[index] &= ~(1 << pos); // 将第pos位置0
        }

        // 检查x位置是否为1
        bool test(size_t x) const
        {
            size_t index = x / 32;
            size_t pos = x % 32;
            return _bits[index] & (1 << pos); // 将第pos位置1，进行与运算
        }

    private:
        std::vector<uint32_t> _bits; // 位图，使用 uint32_t 来简化位操作
    };
}

namespace study
{
    // 哈希函数 1
    struct HashStr1
    {
        size_t operator()(const std::string& str) const
        {
            size_t hash = 0;
            for (size_t i = 0; i < str.size(); ++i)
            {
                hash = hash * 131 + str[i]; // 使用131的常数来计算哈希值
            }
            return hash;
        }
    };

    // 哈希函数 2
    struct HashStr2
    {
        size_t operator()(const std::string& str) const
        {
            size_t hash = 0;
            for (size_t i = 0; i < str.size(); ++i)
            {
                hash = hash * 65599 + str[i]; // 使用65599的常数来计算哈希值
            }
            return hash;
        }
    };

    // 哈希函数 3
    struct HashStr3
    {
        size_t operator()(const std::string& str) const
        {
            size_t hash = 0;
            for (size_t i = 0; i < str.size(); ++i)
            {
                hash = hash * 137 + str[i]; // 使用137的常数来计算哈希值
            }
            return hash;
        }
    };

    // 布隆过滤器模板类
    template <class K, class Hash1 = HashStr1, class Hash2 = HashStr2, class Hash3 = HashStr3>
    class bloomfilter
    {
    public:
        // 构造函数，传入位图的大小
        bloomfilter(size_t size) : _bs(size * 5), _N(size * 5) {}  // 初始化位图

        // 将键添加到布隆过滤器
        void set(const K& key)
        {
            size_t index1 = Hash1()(key) % _N; // 使用 Hash1 函数计算哈希值
            size_t index2 = Hash2()(key) % _N; // 使用 Hash2 函数计算哈希值
            size_t index3 = Hash3()(key) % _N; // 使用 Hash3 函数计算哈希值

            _bs.set(index1); // 将对应位置设为1
            _bs.set(index2);
            _bs.set(index3);
        }

        void reset(const K& key)
        {
            //将映射的位置给0就可以？
            //不能删除，因为可能会误删
        }
        // 检查一个键是否存在于布隆过滤器中
        bool test(const K& key)
        {
            size_t index1 = Hash1()(key) % _N; // 计算哈希值
            if (!_bs.test(index1)) return false; // 如果对应位置为0，返回 false

            size_t index2 = Hash2()(key) % _N; // 计算哈希值
            if (!_bs.test(index2)) return false; // 如果对应位置为0，返回 false

            size_t index3 = Hash3()(key) % _N; // 计算哈希值
            if (!_bs.test(index3)) return false; // 如果对应位置为0，返回 false

            return true; // 如果所有对应位置都为1，返回true（可能是误报）
        }

    private:
        bit::bitset _bs; // 位图对象，用于存储布隆过滤器的数据
        size_t _N;
    };

    // 测试布隆过滤器
    void test_bloomfilter()
    {
        bloomfilter<std::string> bf(100);
        bf.set("hello");
        bf.set("world");
        bf.set("bloom");
        bf.set("abcd");
        bf.set("bcad");

        // 测试布隆过滤器
        cout << bf.test("hello") << endl;   // 应输出 1
        cout << bf.test("world") << endl;   // 应输出 1
        cout << bf.test("bloom") << endl;   // 应输出 1
        cout << bf.test("abcd") << endl;    // 应输出 1
        cout << bf.test("bcad") << endl;   // 应输出 1
        cout << bf.test("not_in_filter") << endl; // 应输出 0
    }

}

#endif //BLOOMFILTER_H
