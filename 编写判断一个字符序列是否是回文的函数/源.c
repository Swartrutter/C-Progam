#include <stdio.h>
#include<string.h>
void main()
{
	int i = 0;
	char a[20];
	printf("ÊäÈëÒ»´®×Ö·û:\n");
	gets(a);
	int j = strlen(a) - 1;
	while (i <= j){
		if (a[i] == a[j]){
			i++;
			j--;
		}
		else
			break;
	}
	if (i >= j)
		printf("true");
	else
		printf("false");
}