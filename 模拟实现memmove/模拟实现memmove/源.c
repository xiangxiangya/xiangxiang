#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
void *my_memmove(void *dst,const void * src, int num)
{
	void *ret = dst;
	if (dst > src&&(char *)dst <((char *) src + num))//dst������src��������Ӻ���ǰ���в���
	{
		dst = (char *)dst + num - 1;//��dstָ�����һ��Ԫ��
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
	system("pause");
	return 0;
}