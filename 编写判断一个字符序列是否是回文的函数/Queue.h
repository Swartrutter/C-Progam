#pragma once
#include <stdio.h>
#define MaxStackSize 100
typedef int DataType;

typedef struct {
    DataType queue[MaxStackSize];
    int rear;   //队尾指针
    int front;  //队头指针
    int count;  //计数器
}SeqCQueue;

void QueueInitiate(SeqCQueue* Q)
{
    Q->rear = 0;
    Q->front = 0;
    Q->count = 0;
}

int QueueNotEmpty(SeqCQueue Q)
{
    if (Q.count != 0) return 1;
    else return 0;
}

//入队列
int QueueAppend(SeqCQueue* Q, DataType x)
{
    if (Q->count > 0 && Q->front == Q->rear)
    {
        printf("队列已满无法插入！\n");
        return 0;
    }
    else {
        Q->queue[Q->rear] = x;  //将x插入队尾
        Q->rear = (Q->rear + 1) % MaxStackSize;  //队尾指示器加一
        Q->count++;  //计数器加一
        return 1;
    }
}

//出队列
int QueueDelete(SeqCQueue* Q, DataType* d)
{
    if (Q->count == 0)
    {
        printf("队列已空无数据元素出队列！\n");
        return 0;
    }
    else
    {
        *d = Q->queue[Q->front];
        Q->front = (Q->front + 1) % MaxStackSize;
        Q->count--;
        return 1;
    }
}

//取队头元素
int QueueGet(SeqCQueue Q, DataType* d)
{
    if (Q.count == 0)
    {
        printf("队列已空无数据元素出队列！\n");
        return 0;
    }
    else
    {
        *d = Q.queue[Q.front];
        return 1;
    }
}