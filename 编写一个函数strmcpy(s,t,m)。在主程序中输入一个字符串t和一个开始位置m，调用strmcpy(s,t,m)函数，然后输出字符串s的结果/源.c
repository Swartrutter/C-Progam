/*编写一个函数strmcpy(s,t,m)，该函数将字符串t中从m个字符开始的全部字符复制到字符串s中去。在主程序中输入一个字符串t和一个开始位置m，调用strmcpy(s,t,m)函数，然后输出字符串s的结果。
例如：输入字符串liwangzhajinxiao和开始位置2，输出：wangzhajinxiao。*/
#include<stdio.h>
void main()
{
	void* strmcpy(char* s, char* t, int m);
	char t[80], s[80], * p;   int m, n = 0;
	printf("输入一个字符串t:");
	scanf_s("%s", t);/*输入一个字符串储存到数组中*/
	printf("输入数字m:");
	scanf_s("%d", &m);
	getchar();/*吞掉回车键*/
	strmcpy(s, t, m);
	printf("复制后的字符串为：%s\n", s);
}
void* strmcpy(char* s, char* t, int m)
{
	int n;
	for (n = 0; n < m; n++)  t++;
	while (*t != '\0')   *s++ = *t++;/*依次赋值*/
	*s = '\0';
}