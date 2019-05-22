#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
char *My_strncat(char *str1,char * str2, int n)
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
	char str1[100] = "To be ";
	char str2[100] = "or not to be";
	int n = 6;
	char *p = My_strncat(str1, str2, n);
	printf("%s", p);
	system("pause");
	return 0;
}