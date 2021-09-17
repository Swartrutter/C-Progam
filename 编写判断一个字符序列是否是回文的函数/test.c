#include <stdio.h>
#include "Queue.h"
#include "SeqStack.h"
void main() {
	char a[20];
	printf("输入一串字符：\n");
	gets(a);
	if (a[0] != '@') {
		int i = 0;
		DataType S = 0;
		DataType Q = 0;
		SeqStack s;
		SeqCQueue q;
		StackInitate(&s);  //初始化堆栈
		QueueInitiate(&q);   //初始化队列
		while (a[i] != '@') {
			StackPush(&s, a[i]); //入栈
			QueueAppend(&q, a[i]); //入队列
			i++;
		}
		while (s.top != s.base) {
			StackPop(&s, &S);//出栈
			QueueDelete(&q, &Q);//出队列
			if (S != Q) {
				printf("fasle\n");
				break; //如果出栈和出队列的元素不同，则表示不是回文，停止出栈
			}
		}
		if (s.top = s.base)
			printf("true");//出栈和出队列的元素每一个都相同，表示是回文
	}
	else {
		printf("false\n");
	}
}