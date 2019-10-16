#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	vector<int> v(4, 100);
	auto it = v.begin();
	for (it; it != v.end(); it++)
	{
		cout << *it;
	}
	system("pause");
	return 0;
}

