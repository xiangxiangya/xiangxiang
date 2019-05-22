#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int My_strncmp(char *str1, char * str2, int n)
{
	while (n)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		if (*str1 < *str2)
		{
			return -1;
		}
		str1++;
		str2++;
		n--;
	}
	return 0;
}
int main()
{
	char str1[] = "wo shi zhu";
	char str2[] = "wo shi zhu";
    int ret = My_strncmp(str1, str2, 4);
	printf("%d", ret);
	system("pause");
	return 0;
}