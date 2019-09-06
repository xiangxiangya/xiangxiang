#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int fun(char *s)
//{
//	char *p = s;
//	while (*p != '\0')
//	{
//		p++;
//	}
//	return (p - s);
//}
//f(int x, int y)
//{
//	return (x&y) + ((x^y) >> 1);
//}
void fun(int x, int y, int *c, int *d)
{
	*c = x + y;
	*d = x - y;
}

#define MA(x,y) (x*y)

#define sum(a,b,c) a+b+c

int f(int n)
{
	static int i = 1;
	if (n >= 5)
		return n;
	n = n + i;
	i++;
	return f(n);
}
int func()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++)
	{
		k++;
	}
	return k;
}
int main()
{
	char str[] = "ABCDEFG";
	char *p1, *p2;
	p1 = "abcd"; p2 = "efgh";
	strcpy(str + 1, p2 + 1);
	strcpy(str + 3, p1 + 3);
	puts(str);
	/*char a[] = "123456789", *p = a;
	int i = 0;
	while (*p)
	{
		if (i % 2 == 0)
			*p = '!';
		i++;
		p++;
	}
	puts(a);*/
	/*printf("%d", (func()));*/
	//int i = 3;
	//int j = 2;
	//printf("%d", i*(sum(i, (i + j), j)));
	//int i = 5;
	//printf("%d", MA(i, i + 1) - 7);
	/*int c[] = { 1, 3, 5 };
	int *k = c + 1;
	printf("%d", *k++);*/
	/*int a[] = { 0, 2, 4, 6, 8 };
	int *p = a + 1;
	printf("%d", *(p--));*/
	//int a = 4, b = 3, c = 0, d = 0;
	//fun(a, b, &c, &d);
	//printf("%d %d", c, d);
	//int result = f(2, 4);
	//printf("%d", result);
	//int a[10] = { 0 };
	//a[1] = a[3] * a[5];
	//unsigned char a = 0xA5;
	//unsigned char b = ~a >> 4 + 1;
	//printf("%d", b);
	//printf("%d", a);
	/*int arr[4] = { 0 };
	int arr2[4] = { 1 };*/
	/*printf("%d", fun("goodbye!"));*/
	system("pause");
	return 0;
}
