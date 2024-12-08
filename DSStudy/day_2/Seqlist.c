//
// Created by 20212 on 10/05/2024.
//
#include "Seqlist.h"

void SeqListInit(SL *s) {
    s->a = (SLDataType *) malloc(sizeof(SLDataType) * 4);
    if (s->a == NULL) {
        printf("false\n");
        exit(-1);
    }
    s->size = 0;
    s->capacity = 4;
}

void SeqListPushBack(SL *ps, SLDataType x)//尾插
{
    assert(ps);
    //如果满了，需要增容
    SeqListCheckCapacity(ps);
    //越界是设点检查
    //size的位置其实是最后一个元素下一个元素位置的下标
    ps->a[ps->size] = x;
    ps->size++;
}

void SeqListPrint(SL *ps) {
    assert(ps);
    for (int i = 0; i < ps->size; i++) {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

void SeqListPopBack(SL *ps) {
    assert(ps);
    ps->a[ps->size - 1] = 0;
    ps->size--;
}

void SeqListPushFront(SL *ps, SLDataType x) {
    int end = ps->size - 1;
    //循环想的是结束的条件，写的是继续的条件
    SeqListCheckCapacity(ps);
    while (end >= 0) {
        ps->a[end + 1] = ps->a[end];
        --end;
    }
    ps->a[0] = x;
    ps->size++;
}

void SeqListCheckCapacity(SL *ps) {
    assert(ps);
    //如果满了，需要增容
    if (ps->size >= ps->capacity) {
        //如果后面有足够的空间，原地扩容
        //如果没有，在新的空间扩容，把原本空间的内容拷贝过去然后释放原来的空间
        //一般增2倍 因为增大的频率越高，代价越大
        //增二倍是内存越大越减少增容的频次
        //但也带来了浪费
        //这是一个折中的选择
        ps->capacity *= 2;
        ps->a = (SLDataType *) realloc(ps->a, sizeof(SLDataType) * ps->capacity);
        if (ps->a == NULL) {
            printf("扩容失败");
            exit(-1);
        }
    }
}

void SeqListDestroy(SL *ps) {
    free(ps->a);
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void SeqListPopFront(SL *ps) {
    assert(ps);
    int start = 0;
    while (start < ps->size - 1) {
        ps->a[start] = ps->a[start + 1];
        ++start;
    }
    ps->size--;
}

void SeqListInsert(SL *ps, int pos, SLDataType x) {
    assert(ps);
    assert(pos < ps->size && pos >= 0);
    //插入之前判断有没有满
    SeqListCheckCapacity(ps);
    int end = ps->size - 1;
    while (end >= pos) {
        //循环写继续的条件，我们想的是结束之后
        ps->a[end + 1] = ps->a[end];
        --end;
    }


    ps->a[pos] = x;
    ps->size++;
    SeqListCheckCapacity(ps);
}

//size_t = unsigned int
void SeqListErase(SL *ps, int pos) {
    assert(ps);
    assert(pos < ps->size && pos >= 0);
    while (pos < ps->size - 1) {
        ps->a[pos] = ps->a[pos + 1];
        pos++;
    }
    ps->size--;
}
//删除元素