#pragma once
#include <stdio.h>
#define MaxStackSize 100
typedef int DataType;


typedef struct {
    DataType stack[MaxStackSize];
    int top;
    int base;
}SeqStack;

void StackInitate(SeqStack* S)
{
    S->top = 0;
    S->base = 0;
}

int StackNotEmpty(SeqStack S)
{
    if (S.top <= 0)  return 0;
    else return 1;
}

int StackPush(SeqStack* S, DataType x)
{
    if (S->top >= MaxStackSize) {
        printf("��ջ�����޷����룡 \n");
        return 0;
    }
    else {
        S->stack[S->top] = x;
        S->top++;
        return 1;
    }
}

int StackPop(SeqStack* S, DataType* d)
{
    if (S->top <= 0) {
        printf("��ջ�ѿ�������Ԫ�س�ջ��\n");
        return 0;
    }
    else
    {
        S->top--;
        *d = S->stack[S->top];
    }
}

int StackTop(SeqStack S, DataType* d)
{
    if (S.top <= 0) {
        printf("��ջ�ѿգ�\n");
        return 0;
    }
    else {
        *d = S.stack[S.top - 1];
        return 1;
    }
}