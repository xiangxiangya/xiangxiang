#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//1、异或数组中的所有数字
	int i = 0;
	int num = 0;
	int pos = 0;//pos用来保存第i位为1的位置
	int x = 0;
	int y = 0;
	for (i = 0; i < len; i++)
	{
		//num = num^arr[i];
		num ^= arr[i];
	}
	//2、num肯定是异或的结果。
	//--->找到num二进制第一位为1的位数

	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	//3、遍历数组，分为两个子数组
	for (i = 0; i < len; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}
	printf("%d,%d\n", x, y);
	return 0;
}
