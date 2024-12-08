//
// Created by 20212 on 2024/5/30.
//
#include "queue.h"
//1.先进先出的场景
int main(){
    Queue q;
    QueueInit(&q);
    QueuePush(&q,1);
    QueuePush(&q,2);
    QueuePush(&q,3);
    while(!QueueTmpty(&q)){
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");
}