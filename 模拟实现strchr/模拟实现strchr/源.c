#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int  My_strchr(char arr[],char a)
{
	int x = 1;
	char *p = arr;
	while (*p != '\0')
	{
		if (*p == a)
		{
			return x;
		}
		p++;
		x++;
	}
	return NULL;
}
int main()
{
	char arr[] = "abcdef";
	char str = 'g';
	int result = My_strchr(arr,str);
	if (result == NULL)
	{
		printf("没找到\n");
	}
	else
	printf("位置是：%d\n", result);
	system("pause");
	return 0;
}