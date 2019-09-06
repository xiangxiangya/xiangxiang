#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
char * My_strncpy(char *str1, char *str2,int n)
{
	char *ret = str1;
	while (*str1 != '\0')
	{
		str1++;
	}
	while (n)
	{
		*str1 = *str2;
		str1++; 
		str2++;
		n--;
	}
	return ret;
}
int main()
{
	char str1[100] = "abcdefg";
	char str2[100] = "opqrstuvw";
	int n = 2;
	printf("%s\n", My_strncpy(str1, str2, 4));
	system("pause");
	return 0;
}