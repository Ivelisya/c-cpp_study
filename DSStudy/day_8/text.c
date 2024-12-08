#include "List.h"

void TextList1() {
    ListNode* phead = NULL;
    ListInit(&phead);
    ListPushBack(phead, 1);
    ListPushBack(phead, 2);
    ListPushBack(phead, 3);
    ListPushBack(phead, 6);
    ListPushFront(phead, 5);
    ListNode* pos = ListFind(phead, 6);
    ListInsert(pos, 30);
    ListErase(pos);
    ListPrint(phead);
}

int main() {
    TextList1();
    return 0;
}
