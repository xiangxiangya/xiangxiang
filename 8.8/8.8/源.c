#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct a
{
	short c;
	long b;
	char d;
	long a;
}a;


//int fun(int x,int y)
//{
//	static int m = 0;
//	static int i = 2;
//	i += m + 1;
//	m = i + x + y;
//	return m;
//}
//int Change(int *p)
//{
//	int y = 8;
//	y = y - *p;
//	p = &y;
//	return 0;
//}
int fun(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);
	}
	return count;
}
struct B
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};

enum A
{
	x1,
	y1,
	z1=5,
	a1,
	b1
};
Change(char * str)
{

}
Fun(char *str)
{
	char *p = str;
	char arr[20];
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			strcpy(arr, p + 1);
			*p = '%';
			*(p + 1) = '2';
			*(p + 2) = '0';
			strcpy(p + 3, arr);
			p = p + 3;
			continue;
		}
		p++;
	}
}
int Fun2(int *arr[4][4], int num)
{
	int row = 0;
	int col = 3;
	while (row<=3 && col>=0)
	{
		if (arr[row][col] > num)
		{
			col--;
		}
		else
		if (arr[row][col] < num)
		{
			row++;
		}
		else
			return 1;
	}
	return 0;
}

int main()
{
	char str[30]  = "abc defgx yz";
	Fun(&str);
	int arr[4][4] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	int num = 0;
	scanf("%d", &num);
	int rst=Fun2(&arr, num);
	if (rst == 1)
	{
		puts("yes");
	}
	else
	{
		puts("no");
	}
	/*char *p = str;
	char arr[20];
	while (*p !='\0')
	{
		if (*p == ' ')
		{
			strcpy(arr, p+1);
			*p = '%';
			*(p + 1) = '2';
			*(p + 2) = '0';
			strcpy(p + 3, arr);
			p = p + 3;
			continue;
		}
		p++;

	}*/
	printf("%s", str);


	/*Change(&str);*/

	//printf("%d", sizeof(struct B));
	//printf("fun(2017)=%d\n", fun(2019));
	//char arr[2][4];
	//strcpy((char*)arr, "you");
	//strcpy(arr[1], "me");
	//arr[0][3] = '&';
	//printf("%s", arr);
		//int xx = 3;
	//int *p = &xx;
	//Change(p);
	//printf("%d", *p);
	//char str[] = "memmove can be very useful......";
	//memcpy(str + 17, str + 15, 4);
	//int num = 9;
	//int count = 0;
	//while (num)
	//{
	//	count++;
	//	num = num&(num - 1);
	//}
	//printf("%d", count);
	//int j = 4;
	//int m = 1;
	//int k;
	//k = fun(j, m);
	//printf("%d", k);
	//k = fun(j, m);
	//printf("%d/n", k);
	 //char str[] = "This is a-si simple string@xiangxiang";
	 //char *pch;
	 //pch = strtok(str, " @-");
	 //while (pch != NULL)
	 //{
		// printf("%s\n", pch);
		// pch = strtok(str, " @-");
	 //}
	 //char * pch; 
	 //pch = strstr(str, "simple");
	 //strncpy(pch, "sample", 6); 
	 //puts(str);

	
	//int i = 1;
	//int sum = 0;
	//while (i < 10)
	//{
	//	sum = sum + 1;
	//	i++;
	//}
	//printf("%d %d", i, sum);
	//printf("%d", sizeof(a));
	//int x = 0;
	//x = 5 > 1 + 2 && 2 || 2 * 4 < 4 - !0;
	//printf("%d", x);
	/*char a[20];
	char*p1 = (char*)a;
	char *p2 = (char*)(a + 5);
	int n = p2 - p1;
	printf("%d", n);*/
	system("pause");
	return 0;
}
//int main()
//{
//	int n = 7;
//	int a1 = 1;
//	int a2 = 1;
//	int a3 = 0;
//	if (n < 3)
//	{
//		printf("1\n");
//	}
//	else
//	{
//		for (n; n>2;n--)
//		{
//			a3 = a2 + a1;
//			a1 = a2;
//			a2 = a3;
//
//		}
//		printf("%d", a3);
//	}
//	
//	system("pause");
//	return 0;
//}