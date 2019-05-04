#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
Mystrlen(char str[], char strcopy[])
{
	int *p = str;
	int *q = strcopy;
	while (*p != '\0')
	{
		*q = *p;
		p++;
		q++;
	}
}
int main()
{
	char str[100] = "abcdef";
	char strcopy[100] = "0";
	Mystrlen(str, strcopy);
	printf("%s", strcopy);
	system("pause");
	return 0;
}