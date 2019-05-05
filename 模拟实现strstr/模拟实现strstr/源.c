#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int  My_strstr(char arr1[], char  arr2[])
{
	if (strlen(arr1) != strlen(arr2))
	{
		return -1;
	}
	char *p = arr1;
	char *q = arr2;
	while (*p != '\0')
	{
		if (*p != *q)
		{
			return -1;
		}
		else
		{
			p++;
			q++;
		}
	}
	return 1;
}
int main()
{
	char arr1[100] = "abcde";
	char arr2[] = "abcde";
	int result=My_strstr(arr1,arr2);
	if (result == 1)
	{
		printf("找到了");
	}
	else
	{
		printf("没找到");
	}
	system("pause");
	return 0;
}