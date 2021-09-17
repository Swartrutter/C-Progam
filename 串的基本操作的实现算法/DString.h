#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//���Ķ�̬����ṹ�嶨��Ϊ��
typedef struct {
	char* str;
	int maxLength;
	int length;
}DString;

//��ʼ������
void Initiate(DString* S, int max, char* string) {
	//��ʼ���������������洢���Ķ�̬����ռ��Լ�����ص�������ֵ
	int i;
	S->str = (char*)malloc(sizeof(char) * max);//���붯̬����ռ�
	S->maxLength = max;//�ö�̬����Ԫ�ص�������
	S->length = strlen(string);//�ô���ǰ�ĳ���
	for (i = 0; i < S->length; i++)
		S->str[i] = string[i];    //��ֵ
}

//�����Ӵ�����
int Insert(DString* S, int pos, DString T) {
	//������S�е�posλ�ò����ִ�T�����ɹ��򷵻�1��ʧ���򷵻�0
	int i;
	if (pos < 0) {
		printf("����pos����");
		return 0;
	}
	else {
		if (S->length + T.length > S->maxLength) {
			//realloc(p,size)����ʵ�ֽ�p��ָ���ѷ����ڴ����Ĵ�С��Ϊsize�����·����ڴ�����ԭ�������ڴ����е�����ֵ
			realloc(S->str, (S->length + T.length) * sizeof(char));//��������S->str��ָ������ռ䣬ԭ����Ԫ�ش�����������ǰ��
			S->maxLength = S->length + T.length;//���µĶ�̬����Ԫ�ص�������
		}
		for (i = S->length - 1; i >= pos; i--)
			S->str[i + T.length] = S->str[i];//�ƴκ���T.length��λ��
		for (i = 0; i < T.length; i++)
			S->str[pos + i] = T.str[i];//�����ִ�
		S->length += T.length;//���µ�Ԫ�����ݸ���
		return 1;
	}
}

//ɾ���Ӵ��Ĳ���
int Delete(DString* S, int pos, int len) {
	//ɾ������S�д�posλ�ÿ�ʼ�ĳ���Ϊlen���Ӵ���ɾ���ɹ�����1��ɾ��ʧ�ܷ���0
	int i;
	if (S->length <= 0) {
		printf("������δ����ַ�Ԫ�أ�����Ԫ�ؿ�ɾ��\n");
		return 0;
	}
	else if (pos < 0 || len<0 || pos + len>S->length) {
		printf("����pos��len���Ϸ���\n");
		return 0;
	}
	else {
		for (i = pos + len; i <= S->length; i++) 
			S->str[i - len] = S->str[i];//�ƴ�ǰ��len��λ��
		S->length -= len;//���µ�Ԫ�ظ���
		return 1;
	}
}

//ȡ�Ӵ��Ĳ���
int SubString(DString* S, int pos, int len, DString* T) {
	//ȡ����S�д�posλ�ÿ�ʼ�ĳ���Ϊlen���Ӵ�����ȡ�ɹ��󷵻�1��ʧ���򷵻�0
	int i;
	if (pos < 0 || len<0 || pos + len>T->length) {
		printf("pos��len�Ĳ������Ϸ���\n");
		return 0;
	}
	if (len > T->maxLength) {
		realloc(T->str, len * sizeof(char));//�������붯̬����ռ�
		T->maxLength = len;//�ô�T��������Ԫ�ص�������
	}
	for (i = 0; i < len; i++)
		T->str[i] = S->str[i + pos];//ȡ����S�д�posλ�ÿ�ʼ�ĳ���Ϊlen���Ӵ�
	T->length = len;//�ô�T��������Ԫ�ظ���
	return 1;
}

//��������
void Destroy(DString* S) {
	//������S��ռ�õ��ڴ�ռ�
	free(S->str);
	S->maxLength = 0;
	S->length = 0;
}