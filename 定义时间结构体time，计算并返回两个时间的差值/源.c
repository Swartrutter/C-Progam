#include <stdio.h>
struct Time
{
	int h;
	int min;
	int s;
};
int main(void)
{
	struct Time t, t1, t2;
	struct Time TimeDiff(struct Time p1, struct Time p2);
	printf("�����һ��ʱ��:");
	scanf_s("%d%d%d", &t1.h, &t1.min, &t1.s);
	printf("����ڶ���ʱ��:");
	scanf_s("%d%d%d", &t2.h, &t2.min, &t2.s);
	t = TimeDiff(t1, t2);
	printf("����ʱ�̵�ʱ���Ϊ:");
	printf("hour=%d minute=%d second=%d", t.h, t.min, t.s);
}
struct Time TimeDiff(struct Time p1, struct Time p2)
{
	struct Time tt;
	int num, sum, com;
	num = p1.h * 3600 + p1.min * 60 + p1.s;
	sum = p2.h * 3600 + p2.min * 60 + p2.s;
	com = num - sum;
	if (com < 0) com = com + 24 * 3600;
	tt.h = com / 3600;
	tt.min = (com - tt.h * 3600) / 60;
	tt.s = com % 60;
	return tt;
}