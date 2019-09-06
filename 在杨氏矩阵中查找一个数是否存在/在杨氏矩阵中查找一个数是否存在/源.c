#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
Find(int arr[3][3], int px, int py, int key)
{
	int x = 0;
	int y = 2;
	while (x<3&&y>=0)
	{
		if (arr[x][y] == key)
		{
			printf("找到了\n");
			return;
		}
		else
		if (arr[x][y] < key)
		{
			x++;
		}
		if (arr[x][y] < key)
		{
			y--;
		}
	}
	printf("找不到\n");
}
int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int x = 3;//行数
	int y = 3;//列数
	int key = 12;
	Find(arr, x, y, key);
	system("pause");
	return 0;

}