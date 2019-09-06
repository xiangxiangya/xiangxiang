#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int_cmp(void *xp,void *yp)
{
	int *x = xp;
	int *y = yp;
	if (*x == *y)
	{
		return 0;
	}
	if (*x > *y)
	{
		return 1;
	}if (*x < *y)
	{
		return -1;
	}
}
int main()
{
	int i = 0;
	int arr[] = { 1, 3, 2, 45, 21, 88, 54, 23, 44, 57 };
	int len = sizeof(arr) / sizeof(arr[0]);
	qsort(arr,len,sizeof(int),int_cmp);//提供比较函数，将两元素比较，比较两元素的大小必须知道其元素
	for (i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	system("pause");
	return 0;
}