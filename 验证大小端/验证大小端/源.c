#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//����һ����������ķ���
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







////����������ָ��ķ���
//int main()
//{
//	int a = 1;
//	int ret =*((char *)&a);
//	if (ret == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	system("pause");
//	return 0;
//}