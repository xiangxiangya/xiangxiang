#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;

#if 0
//��������ķ�ʽ��
int main()
{
	string s("hello world!");
	for (auto e : s)//
	{
		cout << e << endl;
	}

	string::iterator it = s.begin();
	for (it; it<s.end(); it++)
	{
		cout << *it << endl;
	}

	auto it = s.begin();
	for (it; it != s.end(); it++)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
#endif

//
//class data
//{
//public:
//	void fun(int a)
//	{
//
//	}
//private:
//	int a;
//};
//
//int main()
//{
//	data a;
//	system("pause");
//	return 0;
//}

#if 0
int main()
{
	string s("hello world!");
	int ret = s.find('?');
	if (ret == string::npos)
	{
		cout << "no" << endl;
	}
	else
	{
		cout << ret << endl;
	}
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	string s1;
	string s2;
	s1= "hello";
	s2 = '!';
	string s3;
	s3 = s1 + s2;
	system("pasue");
	return 0;
}
#endif

#if 0
int main()
{
	string s(6, 's');
	auto it = s.begin();
	for (it; it != s.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}
#endif


#if 0
int main()
{
	string s("hello");
	s.reserve();
	system("pause");
	return 0;
}
#endif


int _main()
{
	string s;
	getline(cin, s);
	cout << s;
	system("pause");
	return 0;
}
<<<<<<< HEAD
 
int main()
{
	cout << "hello" << endl;
	return 0;
}
=======
<<<<<<< HEAD
//ok
=======
>>>>>>> 0eeba4de1c6b0f3c2999a35cee1ca02c3326c8bb
>>>>>>> ea0f34cd8b3541be6f39bb45a947196ecb9039fc
