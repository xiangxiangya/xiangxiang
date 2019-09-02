#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define CIR(r) r*r

unsigned long g_u = 0;
void init(unsigned long ularg)
{
	ularg = 0x01;
	return;
}
//int fun(int a, int b)
//{
//	if (a > b)
//	{
//		return (a + b);
//	}
//	else
//	{
//		return (a - b);
//	}
//}
int f(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;
	return (a);
}
int x = 3;
void inc()
{
	static int x = 1;
	x *= (x + 1);
	printf("%d", x);
	return;
}
#define MOD(x,y) x%y

int fun(int a[], int k)
{
	int min = a[0];
	int i = 0;
	for (i = 0; i < k; i++)
	{
		if (min>a[i])
		{
			min = a[i];
		}
	}
	return min;
}
void func(char str[2])

{
	int m = sizeof(str);
	int n = strlen(str);
	printf("%d", m);
	printf("%d", n);
}
#define MIN(x,y) x>y?y:x

char my()
{
	char buffer[6] = { 0 };
	char *s = "hello world";
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}
	//printf("%s", buffer);
	return buffer;
}
int main()
{
	int i = 1;
	printf("%d,%d", sizeof(i++), i);
	//printf("%s", my());
	/*char buffer[6] = { 0 };
	char *s = "hello world";
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}

	printf("%s", buffer);*/
	//int x[] = { 1, 2, 3, 4, 5, 6 };
	//int *p = x;
	//int a = (p += 2, *p++);
	//printf("%d",a);
	//char *str[3] = { "stra", "strb", "strc" };
	//char *p = str[0];
	//int i = 0;
	//while (i < 3)
	//{
	//	printf("%s", p++);
	//	i++;
	//}
	

	//char  arr[] = "abc";
	//char arr2[] = { 'a', 'b','c' };
	//arr[0] = 'd';
	//arr2[0] = 'd';
	//puts(arr);
	//puts(arr2);
	//printf("%d", sizeof(arr));
	//printf("%d", sizeof(arr2));

	//int a[5] = { 1, 2, 3, 4, 5 };
	//int *p1 = (int *)(&a + 1);
	//int *p2 = (int *)((int)a + 1);
	//int *p3 = (int *)(a + 1);
	//printf("%d,%x,%d", p1[-1], p2[0], p3[1]);

	
	/*
	printf("%d", MIN(2, 3));*/
	//int a, x;
	//for (a = 0, x = 0; a <= 1 && !x++; a++)
	//{
	//	a++;
	//}
	//printf("%d %d", a, x);
	//printf("%d", 1 << 3 + 2);
	//char str[] = "hello";
	//func(str);

	//int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	//int len = 4;
	//int i = 0;
	//int j = 0;
	//for (i = 0; i < len + 1; i++)

	//int s = 0, n;
	//for (n = 0; n < 4; n++)
	//{
	//	switch (n)
	//	{
	//	default:s += 4;
	//	case 1:s += 1;
	//	case 2:s += 2;
	//	case 3:s += 3;
	//	}
	//}
	//printf("%d", s);

	//char s[] = "\\123456\123456\t";
	//printf("%d", strlen(s));
	/*char arr1[] = "abcdefg";
	char arr2[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	printf("%d,%d", strlen(arr1), strlen(arr2));*/

	//int a[7] = { 3, 5, 2, 1, 6, 7, 9 };
	//int k = 3;
	//int res=fun(a,k);
	//printf("%d", res);

	//int m = 0;
	//int n = 0;
	//for (m = 0, n = -1; n = 0; m++, n++)
	//{
	//	n++;
	//}
	//int i;
	//for (i = 1; i < x; i++)
	//{
	//	inc();
	//}
	//int a = 2, i, k;
	//for (i = 0; i < 2; i++)
	//{
	//	k = f(a++);

	//}
	//printf("%d", k);
	//int x = 3, y = 8, z = 6, r;
	//r = fun(fun(x, y), 2 * z);
	//printf("%d", r);
	//init(g_u);
	//printf("%lu", g_u);
	//int a = 1;
	//int b = 2;
	//int t;
	//t = CIR(a + b);
	//printf("%d\n", t);
	system("pause");


	return 0;
}