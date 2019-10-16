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


#if 0
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
<<<<<<< HEAD
	mine::string s2 = s1;
	system("pause");
	return 0;
}
#endif

//string���еĳ��ú���ʵ��
class mine
{
public:
	typedef char* iterator;

	class string
	{
	public:
		//----------------------------������
		string(char *str = "")//�ַ�������Ϳչ���
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

		string(int n,char c)//�õ����ַ�����
			:_size(n)
			, _capacity(_size+1)
		{
			_str = new char[n + 1];
			memset(_str, c, n);
			_str[_size] = '\0';
		}

		string(const string &s)//��������
			:_str(nullptr)
		{
			_size = s._size;
			_capacity = s._capacity;
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		string & operator=(const string &s)//=���صĵ�һ�ַ�ʽ
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

		string & operator=(string s)//=���صĵڶ��ַ�ʽ
		{
			_size = s._size;
			_capacity = s._capacity;
			swap(_str, s._str);
			return *this;
		}


		//�������������أ�ע�ⷵ��ֵ�����ͺͲ����б���cout������
		//������������
		friend  ostream & operator<<( ostream & _cout, string & s)               
		{
			for (auto e : s)//���еķ�Χforѭ��������begin������end��������Χ
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

		//----------------------------������
		//���صĲ���һ��Ԫ�� �ʲ���return ����str[]
		//���ص���һ���ַ���
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str+_size;
		}

		//----------------------------����
		int size(const string &s)
		{
			return s._size;
		}
		int capacity(const string &s)
		{
			return s._capacity;
		}

		void resize(int n)//��С����
		{
			if (n < _size)//��С
			{
				_size = n;
				_str[_size] = '\0';
			}
		}

		void resize(int n,char c)//��������
		{
				if (_capacity > n+_size)//����Ҫ����
				{
					_size = n;
					memset(_str + _size, c, n);
				}
				else//��Ҫ����
				{
					reserve(n);
					int len = strlen(_str);
					memset(_str+len, c, n);
					_str[_size] = '\0';
				}
		}
		void reserve(int n=0)//����
		{
			
				int newcapacity = 2 * _capacity + n;
				char *tmp = new char[newcapacity];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_size = _size + n;
				_capacity = newcapacity;
		}

		//----------------------------Ԫ�ط���
		char & operator[](int pos)
		{
			return _str[pos];
		}


		//----------------------------�޸�
		string & append(char *s)//׷���ַ���
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

		string & push_back(char c)//β��һ���ַ�
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

		//----------------------------string������
		const char* c_str() const
		{
			return _str;
		}

		size_t find(const string& str, size_t pos = 0) const
		{
			if (_str == str.c_str)
			{
				return ;
			}
			return npos;
		}//����
		size_t rfind(const string& str, size_t pos = npos) const;//�������


	private:
		char *_str;
		int _size;
		int _capacity;
		static const int npos = -1;
	};
};

ostream & operator<<(ostream& _cout, string & s);



int main()
{
	mine::string s1("hello");
	s1.resize(10, '$');
	cout << s1 << endl;
	system("pause");
	return 0;
	_CrtDumpMemoryLeaks();
}




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


