//
// Created by 20212 on 10/05/2024.
//
#pragma once
//顺序表，有效数据在数组中必须是连续的
//静态顺序表设计(固定大小)
//动态顺序表（大小可变）
typedef int SLDataType;
#define N 10
#if 0
struct SeqList{
    SLDataType a[N];
    int size;
};
#endif
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
typedef struct SeqList{
    SLDataType* a;
    int size;
    int capacity;
}SL,SeqList;

void SeqListCheckCapacity(SL* ps);
void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListPushBack(SL* ps ,SLDataType x);//尾插
void SeqListPrint(SL* ps );//打印
void SeqListPopBack(SL* ps );//尾删
void SeqListPushFront(SL* ps ,SLDataType x);//头插
void SeqListPopFront(SL* ps );//头删
//
void SeqListInsert(SL* ps,int pos,SLDataType x);//任意地方插入
void SeqListErase(SL* ps,int pos);//任意位置删除