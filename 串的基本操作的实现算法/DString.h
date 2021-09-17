#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//串的动态数组结构体定义为：
typedef struct {
	char* str;
	int maxLength;
	int length;
}DString;

//初始化操作
void Initiate(DString* S, int max, char* string) {
	//初始化操作用来建立存储串的动态数组空间以及给相关的数据域赋值
	int i;
	S->str = (char*)malloc(sizeof(char) * max);//申请动态数组空间
	S->maxLength = max;//置动态数组元素的最大个数
	S->length = strlen(string);//置串当前的长度
	for (i = 0; i < S->length; i++)
		S->str[i] = string[i];    //赋值
}

//插入子串操作
int Insert(DString* S, int pos, DString T) {
	//在主串S中的pos位置插入字串T，若成功则返回1，失败则返回0
	int i;
	if (pos < 0) {
		printf("参数pos出错！");
		return 0;
	}
	else {
		if (S->length + T.length > S->maxLength) {
			//realloc(p,size)函数实现将p所指的已分配内存区的大小改为size，在新分配内存区中原样保留内存区中的数据值
			realloc(S->str, (S->length + T.length) * sizeof(char));//重新申请S->str所指的数组空间，原数组元素存放在新数组的前面
			S->maxLength = S->length + T.length;//置新的动态数组元素的最大个数
		}
		for (i = S->length - 1; i >= pos; i--)
			S->str[i + T.length] = S->str[i];//移次后移T.length个位置
		for (i = 0; i < T.length; i++)
			S->str[pos + i] = T.str[i];//插入字串
		S->length += T.length;//置新的元素数据个数
		return 1;
	}
}

//删除子串的操作
int Delete(DString* S, int pos, int len) {
	//删除主串S中从pos位置开始的长度为len的子串，删除成功返回1，删除失败返回0
	int i;
	if (S->length <= 0) {
		printf("主串中未存放字符元素，已无元素可删！\n");
		return 0;
	}
	else if (pos < 0 || len<0 || pos + len>S->length) {
		printf("参数pos和len不合法！\n");
		return 0;
	}
	else {
		for (i = pos + len; i <= S->length; i++) 
			S->str[i - len] = S->str[i];//移次前移len个位置
		S->length -= len;//置新的元素个数
		return 1;
	}
}

//取子串的操作
int SubString(DString* S, int pos, int len, DString* T) {
	//取主串S中从pos位置开始的长度为len的子串，串取成功后返回1，失败则返回0
	int i;
	if (pos < 0 || len<0 || pos + len>T->length) {
		printf("pos和len的参数不合法！\n");
		return 0;
	}
	if (len > T->maxLength) {
		realloc(T->str, len * sizeof(char));//重新申请动态数组空间
		T->maxLength = len;//置串T的新数组元素的最大个数
	}
	for (i = 0; i < len; i++)
		T->str[i] = S->str[i + pos];//取主串S中从pos位置开始的长度为len的子串
	T->length = len;//置串T的新数组元素个数
	return 1;
}

//撤销操作
void Destroy(DString* S) {
	//撤销串S所占用的内存空间
	free(S->str);
	S->maxLength = 0;
	S->length = 0;
}