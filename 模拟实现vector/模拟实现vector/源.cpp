#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;


class mine
{
public:
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector()//构造一个空的vector
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
		}

		vector(int n, const T&data)
			:_start(new T[n])
			, _finish(_start+n)
			, _endofstorage(_start+n)
		{
			int i = 0;
			while (i < n)
			{
				_start[i] = data;
				i++;
			}
		}

		template<class Iterator>
		vector(Iterator first, Iterator last)//区间构造
		{
			_start = new T[last - first];
			_finish = _start + (last - first);
			_endofstorage = _finish;
			int n = last - first;
			int i = 0;
			while (i<n)
			{
			_start[i] = *first++;
			i++;
			}
		
		}

		vector(const T&v)//拷贝构造函数
		{
			int size = v.size();
			_start = new T[size];
			_finish = _start + size;
			_endofstorage = _finish;
			for (int i = 0; i < v.size(); i++)
			{
				_start[i] = v[i];
			}
		}

		vector & operator =(const vector &v)
		{
			if (&v != this)
			{
				int size = v.size();
				T*cur = _start;
				if (this->size() < size)
				{
					//reserve(size);
				}
				/*for (int i = 0; i < size; i++)
				{
					cur[i] = v[i];
					cur++;
				}*/
				memcpy(_start,v._start, v.size()*sizeof(T));
			}
			
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = nullptr;
				_finish = nullptr;
				_endofstorage = nullptr;
			}
		}

		///////////////////////////////////////
		//迭代器
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		///////////////////////////////////////
		//容量
		int size()const
		{
			return (_finish - _start);
		}


		int capacity()const
		{
			return _endofstorage - _start;
		}

		bool empty()const
		{
			return _start == _finish;
		}

		/*void reserve(int newcap)
		{
			int oldcap = _endofstorage - _start;
			if (oldcap >= newcap)
			{
				_finish = _start + newcap;
			}
			else
			{
				T*tmp = new T[newcap];
				memset(tmp, _start, size());
				delete[] _start;
				_start = tmp;
				_finish = _start + size();
				_endofstorage = _finish;
			}
		}*/


		///////////////////////////////////////
		//元素访问

		const T & operator [](int pos)const
		{
			return _start[pos];
		}
	private:
		T *_start;
		T * _finish;
		T *_endofstorage;
	};
};



void testfun1()//拷贝构造函数的测试
{
	mine::vector<int> v(5, 10);
	mine::vector <int >v2(v);
	auto it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		it++;
	}
}

void testfun2()//区间构造的测试
{
	mine::vector<int > v1(5, 10);
	mine::vector <int>v2(v1.begin(), v1.end());
	auto it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		it++;
	}
}

void testfun3()
{
	mine::vector<int > v1(5, 8);
	mine::vector<int> v2(10, 10);
	v2 = v1;
	auto it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		it++;
	}
}
int main()
{
	//testfun1();
	testfun2();
	//testfun3();
	system("pause");
	return 0;
}