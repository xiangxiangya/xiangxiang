#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int My_strcmp(char str1[], char str2[])
{
	char *p = str1;
	char *q = str2;
	while ((*p != '\0') || (*q != '\0'))
	{
		if (*p > *q)
		{
			return 1;
		}
		else if (*p < *q)
		{
			return -1;
		}
		p++;
		q++;
	}
	return 0;
}
int main()
{
	    char str1[100];
		char str2[100];
		scanf("%s", &str1);
		scanf("%s", &str2);
		int result = My_strcmp(str1, str2);
		if (result == 0)
		{
			printf("两个字符串相等");
		}
		if (result > 0)
		{
			printf("str1大于str2");
		}
		if (result < 0)
		{
			printf("str1小于str2");
		}
	system("pause");
	return 0;
}