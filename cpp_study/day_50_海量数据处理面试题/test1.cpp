#include "../day_49_bitmap_and_bloom_filters/BloomFilter.h"
//
// Created by 20212 on 24-12-9.
//
/*给定100亿个整数，设计算法找到只出现一次的整数
 分析：100亿个整数，每个整数4字节，共40GB，内存无法一次性加载
 数据出现0次 1次 2次及以上
 */
class solution
{
public:
    void set(size_t x)
    {
        if (_bs1.test(x) == false && _bs2.test(x) == false)
        {
            _bs2.set(x);//01
        }else if (_bs1.test(x) == false && _bs2.test(x) == true)
        {
            _bs1.set(x);//10
            _bs2.reset(x);
        }
    }
private:
    bit::bitset _bs1;
    bit::bitset _bs2;
};