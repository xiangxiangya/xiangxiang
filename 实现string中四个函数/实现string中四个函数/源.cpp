#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>
#if 0
//����ĵ�һ�ַ�ʽ�����ַ�ʽ���������
class mine
{
public:
	class string
	{
	public:
		string(char *str="")//����
		{
			if (str == nullptr)
			{
				str = "";
			}
			_str = new char[strlen(str)+1];
			strcpy(_str, str);
		}

		string(const string &s)//��������
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		string  & operator =(const string & s)
		{
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}

		~string()//����
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char *_str;
	};

};
int main()
{
	mine::string s1("hello");
	mine::string s3;
	s3 = s1;
	system("pause");
	return 0;
	_CrtDumpMemoryLeaks();
}
#endif


//����ĵڶ���ʵ�ַ�ʽ��������򵥵��������
//����һ����֮��ͬ������󲢸�ֵ��Ȼ�󽻻�����ָ���ָ��
class mine
{
public:
	class string
	{
	public:
		string(char *str="")
		{
			if (str == nullptr)
			{
				_str = "";
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		string(const string &s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		string & operator=(const string &s)//=���صĵ�һ�ַ�ʽ
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(_str, tmp._str);
			}
			return *this;
		}

		//string & operator=(string s)//=���صĵڶ��ַ�ʽ
		//{
		//	swap(_str, s._str);
		//	return *this;
		//}

		~string()
		{
			if (_str != nullptr)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char *_str;
	};
};
int main()
{
	mine::string s1("hello");
	mine::string s2 = s1;;
	system("pause");
	return 0;
}