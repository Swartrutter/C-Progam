/*��дһ������strmcpy(s,t,m)���ú������ַ���t�д�m���ַ���ʼ��ȫ���ַ����Ƶ��ַ���s��ȥ����������������һ���ַ���t��һ����ʼλ��m������strmcpy(s,t,m)������Ȼ������ַ���s�Ľ����
���磺�����ַ���liwangzhajinxiao�Ϳ�ʼλ��2�������wangzhajinxiao��*/
#include<stdio.h>
void main()
{
	void* strmcpy(char* s, char* t, int m);
	char t[80], s[80], * p;   int m, n = 0;
	printf("����һ���ַ���t:");
	scanf_s("%s", t);/*����һ���ַ������浽������*/
	printf("��������m:");
	scanf_s("%d", &m);
	getchar();/*�̵��س���*/
	strmcpy(s, t, m);
	printf("���ƺ���ַ���Ϊ��%s\n", s);
}
void* strmcpy(char* s, char* t, int m)
{
	int n;
	for (n = 0; n < m; n++)  t++;
	while (*t != '\0')   *s++ = *t++;/*���θ�ֵ*/
	*s = '\0';
}