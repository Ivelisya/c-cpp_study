//
// Created by 20212 on 11/05/2024.
//
//数据结构 以某种结构的形式把内存组织起来管理
//百分之95的数据结构都是关注 增删改查
#include "Slist.h"
int main(){
    SListNode* pList = NULL;
    //链表只有一个头指针
    SListPushBack(&pList,1);
    SListPushBack(&pList,2);
    SListPushBack(&pList,34);
    SListPrint(pList);
//    SListPopBack(&pList);
//    SListPopBack(&pList);
//    SListPopBack(&pList);
//    SListPushFront(&pList,-1);
    SListPopFront(&pList);
//    SListPrint(pList);
    SListNode * pos = SListFind(pList,34);
//    if(pos){
//        pos -> data = 30;
//    }
    SListInsertAfter(pos,100);
    SListPrint(pList);
}