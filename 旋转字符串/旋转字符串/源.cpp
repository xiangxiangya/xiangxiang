#define _CRT_SECURE_NO_WARNINGS 1
//���һ���ַ���Ϊstr�����ַ�����ǰ�����ⲿ��Ų�������γɵ��ַ�����str����ת�ʡ�
//����str=��12345����str����ת���С�12345������45123���ȵȡ����������ַ������ж��Ƿ�Ϊ��ת��

//����˼·��
//��һ���ַ���ƴ�����ε�һ���µ��ַ����ڣ���������ַ����ڲ�����û��
//��һ���ַ������ҵ��Ļ����ǣ��Ҳ����Ͳ���
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