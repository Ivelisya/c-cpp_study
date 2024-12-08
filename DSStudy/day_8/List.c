#include "List.h"

void ListInit(ListNode** pphead) {
    *pphead = BuyListNode(0);
    (*pphead)->next = *pphead;
    (*pphead)->prev = *pphead;
}

ListNode* BuyListNode(LTDataType x) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->next = NULL;
    node->prev = NULL;
    node->data = x;
    return node;
}

void ListPushBack(ListNode* phead, LTDataType x) {
    assert(phead);
    ListNode* tail = phead->prev;
    ListNode* newnode = BuyListNode(x);
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = phead;
    phead->prev = newnode;
}

void ListPopBack(ListNode* phead) {
    assert(phead);
    ListNode* tail = phead->prev;
    ListNode* tailPrev = tail->prev;
    tailPrev->next = phead;
    phead->prev = tailPrev;
    free(tail);
    tail = NULL;
}

void ListPrint(ListNode* phead) {
    assert(phead);
    ListNode* cur = phead->next;
    while (cur != phead) {
        printf("%d -", cur->data);
        cur = cur->next;
    }
}

void ListPopFront(ListNode* phead) {
    assert(phead->next != phead);
    ListNode* first = phead->next;
    ListNode* second = first->next;
    phead->next = second;
    second->prev = phead;
    free(first);
    first = NULL;
}

void ListPushFront(ListNode* phead, LTDataType x) {
    assert(phead);
    ListNode* first = phead->next;
    ListNode* newnode = BuyListNode(x);
    phead->next = newnode;
    newnode->prev = phead;
    newnode->next = first;
    first->prev = newnode;
}

ListNode* ListFind(ListNode* phead, LTDataType x) {
    assert(phead);
    ListNode* cur = phead->next;
    while (cur != phead) {
        if (cur->data == x)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

void ListInsert(ListNode* pos, LTDataType x) {
    assert(pos);
    ListNode* posPrev = pos->prev;
    ListNode* newnode = BuyListNode(x);
    posPrev->next = newnode;
    newnode->prev = posPrev;
    newnode->next = pos;
    pos->prev = newnode;
}

void ListErase(ListNode* pos) {
    assert(pos);
    ListNode* posPrev = pos->prev;
    ListNode* posNext = pos->next;
    free(pos);
    posPrev->next = posNext;
    posNext->prev = posPrev;
}

void ListDestroy(ListNode** phead) {
    ListClear(*phead);
    free(*phead);
    (*phead) = NULL;
}

void ListClear(ListNode** phead) {
    assert(*phead);
    ListNode* cur = (*phead)->next;
    while (cur != *phead) {
        ListNode* next = cur->next;
        free(cur);
        cur = next;
    }
    (*phead)->next = (*phead);
    (*phead)->prev = (*phead);
}
