#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s("abccbdabe");
	int arr[256] = { 0 };
	int i = 0;
	for (i = 0; i < s.size(); i++)
	{
		arr[s[i]] += 1;//数组中s字符串存放的位置是固定的，每次出现就给它加1
	}
	for (i = 0; i < s.size(); i++)
	{
		if (arr[s[i]] == 1)//从0位置开始依次判断直到找到第一个1
		{
			cout << s[i]<< endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}