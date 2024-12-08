//
// Created by 20212 on 11/05/2024.
//
#include "Slist.h"
SListNode * BuySListNode(SListDataType x){
    SListNode *newNode = (SListNode *) malloc(sizeof(sizeof(SListNode)));
    if (newNode == NULL) {
        printf("申请失败");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void SListPrint(SListNode* phead){
    SListNode* cur = phead;
    while(cur != NULL){
        printf("%d->",cur -> data);
        cur = cur -> next;
    }
    printf("NULL\n");
}
//这里phead接收的是一级指针的值
//所以应该使用二级指针接收

//类比 想要改变int,应该传int的地址 所以想要改变地址，应该传指针的地址
void SListPushBack(SListNode** pphead,SListDataType x){
//在这里向后重新申请一个变量 无论是否为空，这里都需要开辟一个新的节点-
    SListNode* newNode = BuySListNode(x);
    if (*pphead == NULL){
        *pphead = newNode;
    }else {
        //找尾巴
        SListNode * tail = *pphead;
        while (tail->next != NULL) {
            tail = tail->next;0
        }

        tail->next = newNode;
    }
}
void SListPopBack(SListNode **pphead){
    //1.空
    //2.一个
    //3.一个以上
    if(*pphead == NULL){
        return;
    }else if((*pphead) -> next == NULL){
        free(*pphead);
        *pphead = NULL;
    }
    else{
        SListNode*prev = NULL;
        SListNode*tail = *pphead;
        while(tail -> next != NULL){
            prev = tail;
            tail = tail -> next;
        }
        free(tail);
        prev -> next = NULL;
    }
}
void SListPushFront(SListNode **pphead,SListDataType x){
    SListNode* newNode = BuySListNode(x);
    //1.为空节点时
    //2.不为空节点时
    if(*pphead == NULL){
        *pphead = newNode;
    }else{
        newNode -> next =  *pphead;
        *pphead = newNode;
    }
}
void SListPopFront(SListNode **pphead){
    //1.为空节点
    //2.只有一个节点
    //3.有多个节点
    if(*pphead == NULL){
        return;
//    }else if((*pphead)->next == NULL){
//        free(*pphead);
//        //需要将pphead置为空指针 因为free掉了之后，它指向的值就会成为随机数，直接访问会出现野指针
//        *pphead = NULL;
//    }else{
//        *pphead = (*pphead) -> next;
//        //内存泄露是指针丢了
    }else{
//        SListNode * next = (*pphead) -> next; 保存后一个
//        free(*pphead);
//        *pphead = next;
        SListNode * cur = *pphead;
        //保存前一个
        *pphead = (*pphead) -> next;
        free(cur);
        //free把内存的操作权交还给系统,即指针的地址不变,但指向的内存丢失了,成为了随机值
    }
}

SListNode * SListFind(SListNode* phead,SListDataType x){
    SListNode *cur = phead;
    while(cur){
        if(cur -> data == x){
            return cur;
        }
        cur = cur -> next;
    }
    return NULL;
}
void SListInsertAfter(SListNode* pos,SListDataType x){
    SListNode* newNode = BuySListNode(x);
    SListNode *next = pos -> next;
    pos -> next = newNode;
    newNode -> next = next;
}