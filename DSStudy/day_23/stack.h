#pragma once
//栈也可以写成静态的
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
typedef int STDataType;
typedef struct Stack{
    STDataType * _a;
    int _top;//栈顶下标
    int _capacity;
}Stack;
//初始化和销毁
void StackInit(Stack *pst);
void StackDestory(Stack *pst);
//插入和取出
void StackPush(Stack* pst,STDataType x);
void StackPop(Stack* pst);
//数据个数
int StackSize(Stack *pst);
//返回1是空，返回0是非空
int StackEmpty(Stack *pst);

STDataType StackTop(Stack* pst);