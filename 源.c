#define _CRT_SECURE_NO_WARNINGS 1
//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
#include<stdio.h>
#include<stdlib.h>
void Spin(char *str,int len,int k)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < k; j++)//���������Ĵ���
	{
		char *p = str;
		char tmp = 0;
		for (i = 1; i < len; i++)//����һ����ĸ�ŵ�����λ��
		{
			tmp = *p;
			*p = *(p + 1);
			*(p + 1) = tmp;
			p++;
		}
	}
}
int main()
{
	int k = 0;
	char str[] = "abcdef";
	int  len = strlen(str);
	scanf("%d", &k);
	Spin(str,len,k);
	printf("%s", str);
	system("pause");
	return 0;
}