#define _CRT_SECURE_NO_WARNINGS 1
//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC

//˼·����str2��str1����ƴ��һ�κ�ȽϿ���û����ͬ����
#include<stdio.h>
#include<stdlib.h>
int Judge1(char *str1, char *str2)
{
	strncat(str1, str1, strlen(str1));//��str1�ַ�������ƴ��һ��
	if (strstr(str1, str2) != NULL)//�����ַ�������û���򷵻ؿ�ֵ
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char str1[100] = "abcdef";
	char str2[]="cdefab";
	int ret = Judge1(str1, str2);
	if (ret == 1)
	{
		printf("һ��\n");
	}
	else
		printf("��һ��\n");
	system("pause");
	return 0;
}