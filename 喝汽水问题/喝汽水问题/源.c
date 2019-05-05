#define _CRT_SECURE_NO_WARNINGS 1

/*.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
给20元，可以多少汽水。
编程实现。*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int total = 20;  //汽水总数
	int kps = 0;     //空瓶数
	int sy = 0;     //剩余空瓶
	kps = 20;
	while (kps >= 1)
	{
		kps = kps + sy;
		total = total + kps / 2;
		sy = kps % 2;
		kps = kps / 2;
	}
	printf("total = %d\n", total);
	system("pause");
	return 0;
}
