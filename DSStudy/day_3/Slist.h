//
// Created by 20212 on 11/05/2024.
//
//相较于顺序表，无增容的概念，用一个申请一个，不会浪费空间
#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef int SListDataType;
typedef struct SListNode{
    SListDataType data;
    struct SlistNode* next;
}SListNode;
void SListPushBack(SListNode**phead,SListDataType x);
void SListPopBack(SListNode **phead);
void SListPushFront(SListNode **pphead,SListDataType x);
void SListPopFront(SListNode **pphead);
//
void SListPrint(SListNode*phead);
SListNode * SListFind(SListNode* phead,SListDataType x);
void SListInsertAfter(SListNode* pos,SListDataType x);