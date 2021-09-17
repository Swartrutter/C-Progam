/*定义递归函数fun(n,x)求n阶勒让德多项式的值，*/
#include <stdio.h>
int main()
{
	double fun(int n, double x);
	int n;
	double x;
	printf("输入一个整数n和实数x：");
	scanf_s("%d%lf", &n, &x);
	printf("%d阶勒让得多项式的值为：%lf", n,fun(n, x));
	return 0;
}
double fun(int n, double x)
{
	if (n == 0) return 0;
	else if (n == 1) return x;
	else return ((2.0 * n - 1) * x - fun(n - 1, x) - (n - 1) * fun(n - 2, x)) / n;
}