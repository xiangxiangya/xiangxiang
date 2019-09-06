#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
union un
{
	char c;
	int i;
};

void foo(int b[][3])
{
	++b;
	b[1][1] = 9;
}
#define	N 3
#define Y(n) ((N+1)*n)
int main()
{
	/*int i, x, y;
	i = x = y = 0;
	do
	{
		++i;
		if (i % 2)
			x += i, i++;
		y += i++;
	} while (i <=7);
	printf("%d %d %d", i, x, y);
*/


	//int a, b;
	//printf("%d", (a = 2, b = 5, a++, b++, a + b));
	/*printf("%f", (double)(10 / 4 * 4));
*/
	/*char ch = -1;
	printf("%d", ch);*/

	//int i = 6;
	//if (i <= 6)
	//	printf("hello");
	//else
	//	printf("bye");

	/*int z = 2 * (N + Y(5 + 1));
	printf("%d", z);*/

	//int i = 10;
	//long long t = sizeof(i++);
	//printf("%d", i);

	/*int x = 0, y = 0, z = 0;
	z = (x == 1) && (y = 2);
	printf("%d", y);*/



	//int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	//foo(a);
	//printf("%d", a[2][1]);

	int a[5] = { 1, 2, 3, 4, 5 };
	printf("%d", (int)a + 1);
	//int *p1 = (int *)((int)a + 1);
	//printf("%d", p1[0]);


	//union un un;
	//un.i = 0x11223344;
	//un.c = 0x55;
	//printf("%x", un.i);


	/*char a = 127;
	printf("%u\n", a);*/
	

	//char a = -128;
	//printf("%u\n", a);


	/*	char a = -1;
		signed char b = -1;
		unsigned char c = -1;
		printf("a=%d,b=%d,c=%d", a, b, c);*/

	/*int a = 4;
	printf("%d\n", a);
	printf("%d\n", &a);
	printf("%d", *(int *)&a);*/
	/*char str1[] = "abcdefg";
	char str2[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	printf("%d\n", strlen(str1));
	printf("%d\n", sizeof(str1));
	printf("%d\n", strlen(str2));
	printf("%d\n", sizeof(str2));*/
	//int a = 4, b = 3,*w, *p, *q;
	//p = &a;
	//q = &b;
	//w = q;
	//q = NULL;
	//*q = 0;
	//w = p;
	//*p = a;
	//*p = *q;
	system("pause");
	return 0;
}