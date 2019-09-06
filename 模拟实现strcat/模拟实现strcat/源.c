#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
My_strcat(char arr1[], char arr2[],int len)
{
	char *p = arr1 + len+1;
	char *q = arr2;
	while (*q != '\0')
	{
		*p = *q;
		p++; 
		q++;
	}
}
int main()
{
	char arr1[100] = "abcdef";
	int len = strlen(arr1) - 1;
	char arr2[] = "abcdef";
	My_strcat(arr1, arr2,len);
	printf("%s", arr1);
	system("pause");
	return 0;
}