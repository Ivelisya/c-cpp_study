//
// Created by admin on 24-10-11.
//
//为什么会有list
//为了补充vector的缺点存在的

//vector的缺点
//1.头部和中部的删除效率低。O(n)，因为需要挪动数据

//2.插入数据空间不够增容。增容需要开新空间，拷贝数据，释放旧空间,会付出很大的代价.
//优点:
//1.支持下标的随机访问。间接的就很好的支持排序，二分查找，堆算法等

//list出现就是为了解决vector的缺陷

//优点
//list头插效率高。为O（1）
//list插入数据是新增节点，不需要增容
//缺点
//1.不支持随机访问
//所以实际使用中 vector和llist是相辅相成的两个容器


//list是应该顺序容器，允许在任意地方 插入 本质是一个双向链表
//#include <list>
//#include <iostream>
//using namespace std;
//
//void test_list() {
//    list<int> l;
//    l.push_back(1);
//    l.push_back(12);
//    l.push_back(13);
//    l.push_back(14);
//
//    list<int>::iterator it = l.begin();
//    while (it != l.end()) {
//        cout << *it << " ";
//        ++it;
//    }
//    cout << endl;
//}

//list是一个运行在任意位置以常数时间插入删除
//O(1)即为常数次
#include <iostream>
#include "lish.h"
int main()
{
    study_list::test_list1();
}