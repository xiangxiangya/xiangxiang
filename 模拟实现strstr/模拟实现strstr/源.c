#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//const char *My_strstr(const char *str1, const char *str2)
//{
//	const char *s1 = NULL;
//	const char *s2 = NULL;
//	const char *start = str1;
//	while (*start != '\0')
//	{
//     	s1 = start;//s1回退到上一次的下一个位置
//		s2 = str2;//s2回退到str2的起始位置
//		while (*s1 != '\0' && *s2 != '\0'&&*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return start;
//		}
//		if (*s1 == '\0')
//		{
//			return NULL;
//		}
//		start++;
//	}
//	return NULL;
//}
const char *My_strstr(const char *str1, const char *str2)

{
	const char*s1 = NULL;
	const char*s2 = NULL;
	const char *flag = str1;
	while (*str1 != '\0')
	{
		s1 = flag;//s1回退到上一次的下一个位置
		s2 = str2;//s2回退到str2的起始位置
		while (*s1 != '\0'&&*s2 != '\0'&&*s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return flag;
		}
		if (*s1 == '\0')
		{
			return NULL;
		}
		flag++;
	}
	return NULL;
}
int main()
{
	char str1[100] = "accdef";
	char str2[] = "cd";
	printf("%s\n", My_strstr(str1, str2));
	system("pause");
	return 0;
}