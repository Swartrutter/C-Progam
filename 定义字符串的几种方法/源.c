#include <stdio.h>
int main(void)
{
	char a[7] = "HELLO";//第一种
	char b[] = "HELLO";//第二种

	char d[10];//第三种
	gets(d);

	char e[] = { 'a','b','c','\0' };//第四种
	int f[] = { 1,2,33,4,5 };

	printf("%s\n", a);
	printf("%s\n", b);
	printf("%s\n", d);
	printf("%s\n", e);
	printf("%d\n", f[3]);

	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(b));
	printf("%d\n", sizeof(e));
	return 0;
}