//
// Created by 20212 on 2024/6/4.
//

#pragma once
typedef int HPDataType;
#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
struct heap{
    HPDataType *_a;
    int _size;
    int _capacity;
};
void HeapInit(struct heap* php,HPDataType* a,int n);
void HeapDestory(struct heap *php);
void AdustDown(HPDataType *a,int n,int root);
void HeadPush(struct heap* php,HPDataType x);
void HeadPop(struct heap* php);
HPDataType HeapTop(struct heap* php);
