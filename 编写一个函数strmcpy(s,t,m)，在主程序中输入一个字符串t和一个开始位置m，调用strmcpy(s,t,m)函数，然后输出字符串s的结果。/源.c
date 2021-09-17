/*编写一个函数strmcpy(s,t,m)，该函数将字符串t中从m个字符开始的全部字符复制到字符串s中去。在主程序中输入一个字符串t和一个开始位置m，调用strmcpy(s,t,m)函数，然后输出字符串s的结果。
例如：输入字符串liwangzhajinxiao和开始位置2，输出：wangzhajinxiao。
#include <stdio.h>
#include <string.h>
int main()
{
	int strmcpy(int s, int t, int m);
	int m;
	char s, t;
	printf("输入一个字符串：");
	scanf_s("%s", &t);
	printf("输入从第m个字符开始复制字符串：");
	scanf_s("%d", &m);
	s = strmcpy(s, t, m);
	printf("字符串t从第%d个字符去掉后新的字符串为：%s", m, s);
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