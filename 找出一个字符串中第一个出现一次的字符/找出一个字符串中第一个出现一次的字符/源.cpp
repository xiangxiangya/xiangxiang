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
		arr[s[i]] += 1;//������s�ַ�����ŵ�λ���ǹ̶��ģ�ÿ�γ��־͸�����1
	}
	for (i = 0; i < s.size(); i++)
	{
		if (arr[s[i]] == 1)//��0λ�ÿ�ʼ�����ж�ֱ���ҵ���һ��1
		{
			cout << s[i]<< endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}