#include <iostream>

void Printf(int* a, int n) //打印函数
{
	printf("[");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1)printf(",");
	}
	printf("]\n");
}
void Permutation(int* a, int left, int right)
{
	if (left == right)//最后一个数
	{
		Printf(a, right + 1);
		return;
	}
	for (int i = left, j = 0; left + j <= right; j++)
	{
		//与其后面的一个数交换
		int temp = a[i];
		a[i] = a[i + j];
		a[i + j] = temp;

		Permutation(a, left + 1, right);//后面的排序

		//换回来
		temp = a[i];
		a[i] = a[i + j];
		a[i + j] = temp;
	}
}
int main() //主函数
{
	int a[] = { 1,2,3,4 }, n = 4;
	printf("输入：[1,2,3,4]");
	printf("\n");
	printf("输出：\n");
	Permutation(a, 0, n - 1);
	return 0;
}