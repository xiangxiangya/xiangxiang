#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;

//int Swap(int x, int y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//	return x;
//}
//int main()
//{
//	int x = 1;
//	int y = 2;
//	Swap(1, 2);
//
//    cout << "result=" << x<< endl;
//	system("pause");
//	return 0;
//}

int g_a = 0;

int &Add(int x, int y)
{
	int g_a = x + y;
	return g_a;
}
int main()
{
	int a = Add(1, 2);
	Add(4, 5);
	cout << a << endl;
	system("pause");
	return 0;
}