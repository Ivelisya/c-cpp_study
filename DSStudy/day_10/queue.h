//
// Created by 20212 on 2024/5/29.
//
#pragma once
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef int QDataType;
typedef struct QueueNode{
    struct QueueNode* _next;
    QDataType _data;
}QueueNode;
typedef struct Queue{
    QueueNode* _head;
    QueueNode* _tail;
}Queue;
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq,QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue*pq);
QDataType  QueueBack(Queue* pq);
int QueueTmpty(Queue* pq);
int QueueSize(Queue* pq);
