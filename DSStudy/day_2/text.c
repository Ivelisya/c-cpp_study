//
// Created by 20212 on 10/05/2024.
//
#include "Seqlist.h"
//测试头尾插入删除
void TestSeqList1(){
    SeqList s;
    SeqListInit(&s);
    SeqListPushBack(&s,1);
    SeqListPushBack(&s,2);
    SeqListPushBack(&s,3);
    SeqListPushBack(&s,4);
    SeqListPushBack(&s,1);
    SeqListPushBack(&s,2);
    SeqListPushBack(&s,3);
    SeqListPushBack(&s,4);
    SeqListPushBack(&s,1);
    SeqListPushBack(&s,2);
    SeqListPushBack(&s,3);
    SeqListPushBack(&s,4);
//    SeqListPrint(&s);
//    SeqListPopBack(&s);
//    SeqListPopBack(&s);
//    SeqListPrint(&s);
//    SeqListPushFront(&s,-1);
//    SeqListPrint(&s);
//    SeqListPopFront(&s);
//    SeqListPopFront(&s);
    SeqListInsert(&s,0,-5);
    SeqListPrint(&s);
    SeqListErase(&s,0);
    SeqListPrint(&s);
}
int main(){
    TestSeqList1();

    return 0;
}