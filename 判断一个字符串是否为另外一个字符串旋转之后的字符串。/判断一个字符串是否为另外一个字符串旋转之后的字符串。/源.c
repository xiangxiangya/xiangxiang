#define _CRT_SECURE_NO_WARNINGS 1
//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC

//思路：将str2与str1自身拼接一次后比较看有没有相同部分
#include<stdio.h>
#include<stdlib.h>
int Judge1(char *str1, char *str2)
{
	strncat(str1, str1, strlen(str1));//将str1字符串本身拼接一次
	if (strstr(str1, str2) != NULL)//查找字符串，若没有则返回空值
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
		printf("一样\n");
	}
	else
		printf("不一样\n");
	system("pause");
	return 0;
}