//
// Created by 20212 on 2024/6/4.
//
#include "heap.h"
void HeapInit(struct heap* php,HPDataType* a,int n){
    php -> _a = (HPDataType*)malloc(sizeof(HPDataType)* n);
    memcpy(php -> _a,a,sizeof(HPDataType)*n);
    php -> _size = n;
    php -> _capacity = n;

    //构建堆
    for(int i = (n -1 -1)/2;i >= 0; --i){
        AdustDown(php -> _a,php -> _size,i);
    }
}
void Swap(HPDataType*p1,HPDataType*p2){
    HPDataType temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
//前提是左右子树都是小堆
void AdustUp (HPDataType *a,int n,int child){
    int parent = (child-1)/2;
    while(child > 0){
        if(a[child] < a[parent]){
            Swap(&a[child],&a[parent]);
            child = parent;
            parent = (child -1)/2;
        }
        else{
            break;
        }
    }
}
void AdustDown(HPDataType *a,int n,int root){
    int parent = root;
    int child = parent *2 + 1;//左孩子
    while(child < n){
        //找出左右子树中小的那个
        if(child+1 < n && a[child+1] < a[child]){
            ++child;
        }
        if(a[child] < a[parent]){
            Swap(&a[child],&a[parent]);
            parent = child;
            child = parent *2 +1;
        }else{
            break;
        }
    }

}
void HeapDestory(struct heap* php){
    assert(php);
    free(php -> _a);
    php -> _a = NULL;
    php -> _capacity = php -> _size = 0;
}
void HeadPush(struct heap* php,HPDataType x){
     assert(php);
     if(php -> _size == php -> _capacity){
         php -> _capacity *= 2;
         HPDataType *tmp = (HPDataType *)(php-> _a,sizeof(HPDataType)* php -> _capacity);
        php -> _a = tmp;
     }
     php -> _a[php ->_size ++] = x;
     AdustUp(php -> _a,php -> _size,php -> _size -1);
}
void HeadPop(struct heap* php){
    assert(php);
    assert(php -> _size >0);
    Swap(&php -> _a[0],&php -> _a[php -> _size -1]);
    php -> _size --;
    AdustDown(php -> _a,php -> _size,0);
}

HPDataType HeapTop(struct heap* php){
    return php -> _a[0];
}