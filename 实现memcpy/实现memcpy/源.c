#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
My_memcpy(void * str,const void * arr,int a)
{
	char *p = str;
	char *q = arr;
	int i = 0;
	for (; i < a; i++)
	{
		*p = *q;
		p++;
		q++;
	}
}
int main()
{
	char str[100] = "abcd";
	char arr[] = "cdfe";
	My_memcpy(str, arr, 3);
	printf("%s", str);
    system("pause");
	return 0;
}