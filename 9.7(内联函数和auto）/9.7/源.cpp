#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;

#if 0
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	for (auto &g : arr)//�������е�Ԫ�ؽ�������
	{
		g *= 2;
	}
	for (auto g : arr)//��ֵ�ķ�ʽ��ȡ�����е�Ԫ��
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