#include <iostream>

void Printf(int* a, int n) //��ӡ����
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
	if (left == right)//���һ����
	{
		Printf(a, right + 1);
		return;
	}
	for (int i = left, j = 0; left + j <= right; j++)
	{
		//��������һ��������
		int temp = a[i];
		a[i] = a[i + j];
		a[i + j] = temp;

		Permutation(a, left + 1, right);//���������

		//������
		temp = a[i];
		a[i] = a[i + j];
		a[i + j] = temp;
	}
}
int main() //������
{
	int a[] = { 1,2,3,4 }, n = 4;
	printf("���룺[1,2,3,4]");
	printf("\n");
	printf("�����\n");
	Permutation(a, 0, n - 1);
	return 0;
}