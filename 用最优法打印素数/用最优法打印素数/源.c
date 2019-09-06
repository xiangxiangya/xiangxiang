

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int num = 0;
	int j = 0;
	
	for (num = 101; num <= 200; num=num+2)
	{
		int t = sqrt(num);
		for (j = 2; j <= t; j++)
		{
			if (num%j == 0)
				break;//如果能整除就跳出该次循环，避免多余运算
		}
		   if(j>t)//该条件代表没有整除。
			printf("%d ", num);
	}
	printf("\n");
	system("pause");
	return 0;
}