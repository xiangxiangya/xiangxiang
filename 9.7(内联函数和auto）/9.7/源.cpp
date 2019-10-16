#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;

#if 0
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	for (auto &g : arr)//对数组中的元素进行引用
	{
		g *= 2;
	}
	for (auto g : arr)//以值的方式获取数组中的元素
	{
		cout << g << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif

int main()
{
	const int a = 10;
	int *pa = (int*)&a;
	*pa = 100;
	cout << a << endl;
	cout << *pa << endl;
	system("pause");
	return 0;
}