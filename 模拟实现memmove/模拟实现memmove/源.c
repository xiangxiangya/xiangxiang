#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
void *my_memmove(void *dst,const void * src, int num)
{
	void *ret = dst;
	if (dst > src&&(char *)dst <((char *) src + num))//dst包含于src的情况，从后往前进行操作
	{
		dst = (char *)dst + num - 1;//将dst指向最后一个元素
		src = (char *)src + num - 1;
		while (num--)
		{
			*(char*)dst = *(char*)src;
			dst=(char *)dst-1;
			src=(char*)src-1;
		}
	}
	else
	{
		while (num--)
		{
			*(char*)dst = *(char*)src;
			dst = (char *)dst + 1;
			src = (char*)src + 1;
		}
	}
	return (ret);
}
int main()
{
	char dst[100] = "hello world";
	my_memmove(dst + 1, dst, strlen(dst) + 1);
	printf("%s\n",dst);

	my_memmove(dst, dst+1, strlen(dst) + 1);
	printf("%s", dst);
	system("pause");
	return 0;
}