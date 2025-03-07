// 适配器 又叫配接器 是一种设计模式
// stack queue 默认是对deque的封装转化而来 当然也可以使用
// priority_queue 默认是对vector的封装转化而来，不过是在vector上面使用了堆算法

// 仿函数
#include <iostream>
using namespace std;
// 仿函数一般配合算法,作用就是:提高算法的灵活性

// 使用场景 比如 priority_queue，可以用仿函数控制优先级
// map/set,可以使用仿函数控制key的比较方式
// unordered_map和unordered_set,可以使用仿函数控制key转化成整形，取模映射
// sort，可以使用仿函数控制数据的比较大小的方式，控制升序还是降序
// 仿函数能做的一些事，函数指针可以，lambda表达式也可以(lambda底层就是仿函数)
// 容器的底层实现由结构实现
// 空间配置器 ：（内存池）
// 容器需要大量内存 -> 操作系统 -> 申请内存 -> 释放内存

// 池化技术：线程池，连接池
// 线程池：提前创建好一些线程，放在池子里面，需要的时候直接拿来用
// 连接池：提前创建好一些连接，放在池子里面，需要的时候直接拿来用
// 池化技术也是有缺点的 池化技术的缺点：
// stl的空间配置器 分为 1级空间配置器 和 2级空间配置器
// 一级空间配置器：就是malloc和free的封装，并且处理失败抛异常
// 注意的是，默认情况下是没有设置这个函数指针句柄，也就是说默认情况下，一级空间配置器和 operator new是一样的

// 申请内存x byte内存，看x对应映射位置的哈希桶中有没有内存对象，如果有就直接取走

// 如果申请的内存不是8的整数倍怎么办 向8的整数倍对其就可以
// 比如申请 1-8 字节 都是 8 字节
// 申请9 - 16 字节 都是 16 字节

// 内存碎片 外碎片 内碎片
// 外碎片问题 ->
// 大量借出去小块内存，还回来了大部分内存，但是他们不连续，碎片化，导致我们申请不出连续的大块内存。就是我有内存，但是碎片化了，不能用

// 内核中针对大量小块内存申请到碎片化问题，使用一个slab分配器，slab分配器是一种内存池技术，用于解决内存碎片化问题

// 内核中已经有slab分配器申请小块内存，为什么stl还要自己实现一个
// 1.内核是针对整个系统的所有程序，并且每个去堆申请，消耗是比较大的
// 2.stl的容器需要全是小块内存，而且需求大小比较集中，那么自己设计一个，自己用，效率很高也能顺便解决内存碎片问题

// 空间配置器
/*void* allocate(size_t n)
{
    return malloc(n);
}
    */
/*void *allocate(size_t n){
    if(n > 128)
    else
}
    */
//内存池 -> 解决频繁申请小块内存的问题
//主要解决:效率问题，顺带解决外碎片问题，自己也有内碎片
//一个进程中有一个空间配置器，进程中所有的容器需要内存，都从这个空间配置器中申请内存