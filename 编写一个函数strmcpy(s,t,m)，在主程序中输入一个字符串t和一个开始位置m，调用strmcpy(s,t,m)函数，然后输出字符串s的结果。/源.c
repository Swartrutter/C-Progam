/*��дһ������strmcpy(s,t,m)���ú������ַ���t�д�m���ַ���ʼ��ȫ���ַ����Ƶ��ַ���s��ȥ����������������һ���ַ���t��һ����ʼλ��m������strmcpy(s,t,m)������Ȼ������ַ���s�Ľ����
���磺�����ַ���liwangzhajinxiao�Ϳ�ʼλ��2�������wangzhajinxiao��
#include <stdio.h>
#include <string.h>
int main()
{
	int strmcpy(int s, int t, int m);
	int m;
	char s, t;
	printf("����һ���ַ�����");
	scanf_s("%s", &t);
	printf("����ӵ�m���ַ���ʼ�����ַ�����");
	scanf_s("%d", &m);
	s = strmcpy(s, t, m);
	printf("�ַ���t�ӵ�%d���ַ�ȥ�����µ��ַ���Ϊ��%s", m, s);
}
*/
#include<stdio.h>
void main()
{
	void * strmcpy(char* s, char* t, int m);
	char t[80], s[80], * p;
	int m, n = 0;
	scanf_s("%d", &m);
	getchar();
	scanf_s("%s", t);
	strmcpy(s, t, m);
	printf("%s\n", s);
}
void * strmcpy(char* s, char* t, int m)
{
	int n;
	for (n = 0; n < m; n++)
		t++;
	while (*t != '\0')
		*s++ = *t++;
	*s = '\0';
}