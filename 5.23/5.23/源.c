#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *src = "hallo bit";
	char dst[32];
	memcpy(dst, src, strlen(src) + 1);
	printf(dst);
	system("pause");
	return 0;
}
#pragma pack(1)//设置编译器的默认对齐数