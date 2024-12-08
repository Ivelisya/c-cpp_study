//
// Created by 20212 on 2024/5/27.
//



#include "stack.h"
void StackInit(Stack *pst){
    assert(pst);
    pst -> _a = malloc(sizeof(STDataType) *4);
    pst -> _top = 0;
    pst -> _capacity = 4;
}
void StackDestory(Stack *pst){
    assert(pst);
    free(pst ->_a);
    pst -> _top = 0;
    pst -> _capacity = 0;
}
//插入和取出
void StackPush(Stack* pst,STDataType x){
    assert(pst);
    //空间不够则增容
    if(pst -> _top == pst -> _capacity){
        pst -> _capacity *= 2;
        STDataType* tmp = realloc(pst -> _a,sizeof(STDataType)*
        pst -> _capacity);
        if(tmp == NULL){
            printf("内存不足");
            exit(-1);
        }
        pst -> _a = tmp;
    }
    pst -> _a[pst->_top] = x;
    pst -> _top ++;
}
void StackPop(Stack* pst){
    assert(pst);
    if(pst -> _top > 0)
        --pst->_top;
}
int StackSize(Stack *pst){
    assert(pst);
    return pst -> _top;
}
//返回1是空，返回0是非空
int StackEmpty(Stack *pst){
    assert(pst);
    return pst -> _top == 0 ? 1 : 0;
}
STDataType StackTop(Stack* pst){
    assert(pst);
    assert(pst -> _top > 0);
    return pst -> _a[pst -> _top -1];
}