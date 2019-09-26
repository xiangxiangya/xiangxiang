#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>
#if 0
//深拷贝的第一种方式，这种方式很容易理解
class mine
{
public:
	class string
	{
	public:
		string(char *str="")//构造
		{
			if (str == nullptr)
			{
				str = "";
			}
			_str = new char[strlen(str)+1];
			strcpy(_str, str);
		}

		string(const string &s)//拷贝构造
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

		~string()//析构
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


//深拷贝的第二种实现方式，代码更简单但不好理解
//申请一个与之相同的类对象并赋值，然后交换两个指针的指向
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

		string & operator=(const string &s)//=重载的第一种方式
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(_str, tmp._str);
			}
			return *this;
		}

		//string & operator=(string s)//=重载的第二种方式
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