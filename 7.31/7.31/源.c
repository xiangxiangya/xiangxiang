#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//void Replace(char * str)
//{
//	int i = 0;
//	char *tmp;
//	while (*str != '\0')
//	{
//		if (*str == ' ')
//		{
//
//			*str = '%';
//			*(str + 1) = '2';
//			*(str + 2) = '0';
//			*(str + 3) =tmp;
//			
//			str = str + 2;
//		}
//		str++;
//	}
//	
//	return;
//}

int main()
{
	char arr1[] = "hello\0world";
	char arr2[15] = { 0 };
	strcpy(arr2, arr1);
	printf("%d", strlen(arr2));
	printf("%d", sizeof(arr1));

	//int x = 2;
	//int z = 2;
	//int y = 3;
	//if (x > y)
	//	z = 1;
	//else if (x == y)
	//	z = 0;
	//else
	//	z = -1;
	//printf("%d", z);
	//const char*str1 = "abcdef";
	//const char*str2 = "bbb";
	//if (strlen(str2) - strlen(str1)>0)
	//{
	//	printf("str2>str1\n");
	//}
	//else
	//{
	//	printf("srt1>str2\n");
	//}
	system("pause");
	return 0;
}

//int _main()
//{
//
//	char  str[100] = "abc defgx yz";
//
//
//	/*Replace(&str);
//	 printf("%s", str);*/
//	/*int a = 10;
//	printf("%d", a += a *= a -= a / 3);*/
//	//const char *p = "Hello!";
//	//printf("%c", *p);
//	//typedef struct
//	//{
//	//	int a; char b; short c; short d;
//	//}A;
//	//printf("%d", sizeof(A));
//	//int a[2][] = { { 12 }, { 34 } };
//	//int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	//printf("%d", a[1]+1);
//	//char str[6] = { '\0' };
//	//int a = 1; 
//	//int b = 2;
//	//int c = (a>b, a = b + 10, a, b = a + 1);
//	//printf("%d", c);
//	//int i = 0;
//	//int j = 0;
//	//int a = 0;
//	//for (i = 0; i < 2; i++)
//	//{
//	//	for (j = 0; j < 4; j++)
//	//	{
//	//		if (j % 2)
//	//			break;
//	//		a++;
//	//	}
//	//	a++;
//	//}
//	//int a[] = { 2,4,6,8,10,12,14,16,18,20,22,24};
//	//int k = 0;
//	//int *q[4];
//	//for (k = 0; k < 4; k++)
//	//{
//	//	q[k]=&a[k*3];
//	//}
//	system("pause");
//	return 0;
//}
////int main()
////{ 
////  int i = 0;   
////  int k = 0;  
////  for (i = 0, k = 0; k = 0; i++, k++)
////  {
////	  k++;
////  }
////
////	//for (;;)
////	//{
////	//	printf("hehe\n");
////	//}
////	//int i = 0;  
////	//for (i = 1; i <= 10; i++)   
////	//{
////	//	if (i == 5)        
////	//continue;   
////	//printf("%d ", i);
////	//}   
////	system("pause");
////	return 0; 
////}