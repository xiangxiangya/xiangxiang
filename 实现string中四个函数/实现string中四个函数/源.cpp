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

<<<<<<< HEAD
#if 0
=======

>>>>>>> 4c7836991e4cd026a94646733e0ce96cea094601
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
<<<<<<< HEAD
	mine::string s2 = s1;
	system("pause");
	return 0;
}
#endif

//string类中的常用函数实现
class mine
{
public:
	typedef char* iterator;

	class string
	{
	public:
		//----------------------------构造类
		string(char *str = "")//字符串构造和空构造
			:_str(new char[strlen(str) + 1])
			, _size(strlen(str))
			, _capacity(15)
		{
			if (str == nullptr)
			{
				_str = "";
			}
			strcpy(_str, str);
		}

		string(int n,char c)//用单个字符构造
			:_size(n)
			, _capacity(_size+1)
		{
			_str = new char[n + 1];
			memset(_str, c, n);
			_str[_size] = '\0';
		}

		string(const string &s)//拷贝构造
			:_str(nullptr)
		{
			_size = s._size;
			_capacity = s._capacity;
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		string & operator=(const string &s)//=重载的第一种方式
		{
			if (this != &s)
			{
				_size = s._size;
				_capacity = s._capacity;
				string tmp(s._str);
				swap(_str, tmp._str);
			}
			return *this;
		}

		string & operator=(string s)//=重载的第二种方式
		{
			_size = s._size;
			_capacity = s._capacity;
			swap(_str, s._str);
			return *this;
		}


		//输出运算符的重载，注意返回值的类型和参数列表——cout的类型
		//都是引用类型
		friend  ostream & operator<<( ostream & _cout, string & s)               
		{
			for (auto e : s)//类中的范围for循环必须有begin（）和end（）代表范围
			{
				cout << e;
			}
			return _cout;
		}

		~string()
		{
			if (_str != nullptr)
			{
				delete[] _str;
				_str = nullptr;
				_size = 0;
				_capacity = 0;
			}
		}

		//----------------------------迭代器
		//返回的不是一个元素 故不是return ——str[]
		//返回的是一个字符串
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str+_size;
		}

		//----------------------------容器
		int size(const string &s)
		{
			return s._size;
		}
		int capacity(const string &s)
		{
			return s._capacity;
		}

		void resize(int n)//缩小容量
		{
			if (n < _size)//缩小
			{
				_size = n;
				_str[_size] = '\0';
			}
		}

		void resize(int n,char c)//扩大容量
		{
				if (_capacity > n+_size)//不需要扩容
				{
					_size = n;
					memset(_str + _size, c, n);
				}
				else//需要扩容
				{
					reserve(n);
					int len = strlen(_str);
					memset(_str+len, c, n);
					_str[_size] = '\0';
				}
		}
		void reserve(int n=0)//扩容
		{
			
				int newcapacity = 2 * _capacity + n;
				char *tmp = new char[newcapacity];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_size = _size + n;
				_capacity = newcapacity;
		}

		//----------------------------元素访问
		char & operator[](int pos)
		{
			return _str[pos];
		}


		//----------------------------修改
		string & append(char *s)//追加字符串
		{
			int len = strlen(s);
			if (len + _size > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + len, s);
			_str[_size] = '\0';
			_size = strlen(_str);
			return *this;
		}

		string & push_back(char c)//尾插一个字符
		{
			if (_size + 1 > _capacity)
			{
				reserve(2);
			}
			char *tmp = new char[strlen(_str)+2];
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_str[_size] = c;
			_size++;
			_str[_size] = '\0';
			_size++;
			return *this;
		}

		//----------------------------string类特有
		const char* c_str() const
		{
			return _str;
		}

		size_t find(const string& str, size_t pos = 0) const;//查找
		size_t rfind(const string& str, size_t pos = npos) const;//后序查找


	private:
		char *_str;
		int _size;
		int _capacity;
		static const int npos = -1;
	};
};

ostream & operator<<(ostream& _cout, string & s);


#if 0
int main()
{
	mine::string s1("hello");
	s1.resize(10, '$');
	cout << s1 << endl;
	system("pause");
	return 0;
	_CrtDumpMemoryLeaks();
}
#endif



#if 0
int main()
{
	mine::string s1("hello");
	s1.push_back('!');//???????????????????
	cout << s1 << endl;
	system("pause");
	return 0;
	_CrtDumpMemoryLeaks();
}
#endif

=======
	mine::string s2 = s1;;
	system("pause");
	return 0;
}
>>>>>>> 4c7836991e4cd026a94646733e0ce96cea094601
