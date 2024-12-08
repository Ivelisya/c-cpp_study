//
// Created by 20212 on 19/9/2024.
//
#include <iostream>

using namespace std;
struct ListNode_C {
    int _val;
    struct ListNode_C *_next;
    struct ListNode_C *_prev;
};
typedef struct ListNode_C ListNode_C;

ListNode_C *BuyNode(int val) {
    struct ListNode_C *node_c = (struct ListNode_C *) malloc(sizeof(struct ListNode_C));
    node_c->_val = 1;
    node_c->_next = NULL;
    node_c->_prev = NULL;
    return node_c;
}

struct ListNode_CPP {
    int _val;
    //c++兼容C struct的用法
    //在CPP钟，struct已经可以认为是类，和class一样，区别是有默认访问限定符
    ListNode_CPP *_next;
    ListNode_CPP *_prev;
};

void DestoryListNode_C(ListNode_C* node){

}
//int main() {
//    int *p1 = (int *) malloc(sizeof(int));
//    int *p2 = new int;
//    //内置类型 new和malloc一样
//    //自定义类型 new和malloc不同
//    //new 会调用自定义类型的构造函数和析构函数
//    ListNode_CPP*node4 = new ListNode_CPP;
//    delete node4;
//    //c++
//    return 0;
//}
int main(){
    ListNode_CPP a[10]; //当定义 ListNode 时调用一次构造函数 a[10] 代表调用十次
    ListNode_CPP* p = new ListNode_CPP[10];
    //创建十次,需要手动调用析构函数
    delete[] p;
    return 0;
}