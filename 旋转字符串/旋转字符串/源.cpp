#define _CRT_SECURE_NO_WARNINGS 1
//如果一个字符串为str，把字符串的前面任意部分挪到后面形成的字符串交str的旋转词。
//比如str=“12345”，str的旋转串有“12345”、“45123”等等。给定两个字符串，判断是否为旋转词

//解题思路：
//将一个字符串拼接两次到一个新的字符串内，在这个新字符串内查找有没有
//另一个字符串，找到的话就是，找不到就不是
#include<iostream>
#include<stdlib.h>
using namespace std;
#include<string>
int main()
{
	string str1;
	string str2;
	int n, m;
	cin >> n;
	cin >> m;
	int i = n;
	cin >> str1;
	cin >> str2;
	string s3;
	if (n != m)
	{
		cout << "NO" << endl;
	}
	else
	{
		s3 = str2;
		s3.append(str2);
		if (s3.find(str2) != string::npos)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	system("pause");
	return 0;
}