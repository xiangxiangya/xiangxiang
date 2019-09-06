#define _CRT_SECURE_NO_WARNINGS 1
//实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
#include<stdio.h>
#include<stdlib.h>
void Spin(char *str,int len,int k)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < k; j++)//控制左旋的次数
	{
		char *p = str;
		char tmp = 0;
		for (i = 1; i < len; i++)//将第一个字母放到最后的位置
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