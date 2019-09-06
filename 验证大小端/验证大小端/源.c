#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//方法一，用联合体的方法
union 
{
	int a;
	char  i;
}un;
int main()
{
	un.i = 1;
	if (un.a==1)
	{
		printf("xiao");
	}
	else
	{
		printf("da");
	}
	system("pause");
	return 0;
}







////方法二，用指针的方法
//int main()
//{
//	int a = 1;
//	int ret =*((char *)&a);
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	system("pause");
//	return 0;
//}