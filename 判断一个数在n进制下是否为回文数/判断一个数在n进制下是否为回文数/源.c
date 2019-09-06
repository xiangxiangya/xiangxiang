#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num = 0;
	int n = 0;//½øÖÆ
	int new_num = 0;
	int i = 0;
	int tmp = 0;
	scanf("%d%d", &num, &n);
	for (i = num; i; i = i / n)
	{
		tmp = new_num * 10;
		new_num = i%n + tmp;
	}
	if (num == new_num)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	system("pause");
	return 0;
}