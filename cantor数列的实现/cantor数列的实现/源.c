#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	int line = 0;

	scanf("%d", &n);
	while (line < n)
	{
		n = n - line;
		line++;
	}

		if (line % 2 == 0)
			printf("%d/%d", n, line + 1 - n);
		else
			printf("%d/%d", line + 1 - n, n);
	
	system("pause");
	return 0;
}