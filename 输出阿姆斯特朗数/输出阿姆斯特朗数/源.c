#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int tmp = 0;
	int num = 0;
	int count = 0;//Î»Êý
	int j = 0;
	int sum = 0;
	int modflag = 1;
	for (num = 0; num < 1000000000; num++)
	{
		if (num%modflag==0)
		{
			count++;
			modflag *= 10;
		}
		for (j = num; j; j/=10)
		{
			tmp = j % 10;
			sum = sum+pow(tmp, count);
		}
		if (sum == num)
		{
			printf("%d\n", num);
		}
		sum = 0;
	}
	system("pause");
	return 0;
}