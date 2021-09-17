#pragma once
#include <stdio.h>
#define MaxStackSize 100
typedef int DataType;

typedef struct {
    DataType queue[MaxStackSize];
    int rear;   //��βָ��
    int front;  //��ͷָ��
    int count;  //������
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

//�����
int QueueAppend(SeqCQueue* Q, DataType x)
{
    if (Q->count > 0 && Q->front == Q->rear)
    {
        printf("���������޷����룡\n");
        return 0;
    }
    else {
        Q->queue[Q->rear] = x;  //��x�����β
        Q->rear = (Q->rear + 1) % MaxStackSize;  //��βָʾ����һ
        Q->count++;  //��������һ
        return 1;
    }
}

//������
int QueueDelete(SeqCQueue* Q, DataType* d)
{
    if (Q->count == 0)
    {
        printf("�����ѿ�������Ԫ�س����У�\n");
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

//ȡ��ͷԪ��
int QueueGet(SeqCQueue Q, DataType* d)
{
    if (Q.count == 0)
    {
        printf("�����ѿ�������Ԫ�س����У�\n");
        return 0;
    }
    else
    {
        *d = Q.queue[Q.front];
        return 1;
    }
}