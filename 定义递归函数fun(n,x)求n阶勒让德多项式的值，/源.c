/*����ݹ麯��fun(n,x)��n�����õ¶���ʽ��ֵ��*/
#include <stdio.h>
int main()
{
	double fun(int n, double x);
	int n;
	double x;
	printf("����һ������n��ʵ��x��");
	scanf_s("%d%lf", &n, &x);
	printf("%d�����õö���ʽ��ֵΪ��%lf", n,fun(n, x));
	return 0;
}
double fun(int n, double x)
{
	if (n == 0) return 0;
	else if (n == 1) return x;
	else return ((2.0 * n - 1) * x - fun(n - 1, x) - (n - 1) * fun(n - 2, x)) / n;
}