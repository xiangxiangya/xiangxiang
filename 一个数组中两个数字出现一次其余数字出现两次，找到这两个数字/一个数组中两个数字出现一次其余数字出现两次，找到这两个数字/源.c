#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//1����������е���������
	int i = 0;
	int num = 0;
	int pos = 0;//pos���������iλΪ1��λ��
	int x = 0;
	int y = 0;
	for (i = 0; i < len; i++)
	{
		//num = num^arr[i];
		num ^= arr[i];
	}
	//2��num�϶������Ľ����
	//--->�ҵ�num�����Ƶ�һλΪ1��λ��

	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	//3���������飬��Ϊ����������
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
