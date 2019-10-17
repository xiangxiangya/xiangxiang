#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

namespace mine//自己定义的命名空间，为了防止与库中的list冲突
{

	template <class T>//定义了一个节点类
	class ListNode
	{
		public:
		ListNode(const T &data=T())//没有传参的话调用T类型对象的默认构造函数
		:_pPre(nullptr)
		, _pNext(nullptr)
		, _data(data)
		{
		}
		ListNode<T>*_pPre;
		ListNode<T>*_pNext;
		T _data;
	};





	template<class T>
	class Iterator
	{
	public:
		typedef ListNode<T> Node;//对节点类重命名，方便后面的使用
		typedef Iterator<T> Self;
		Iterator(Node *cur)//构造函数
			:_pCur(cur)
		{
		}

		T& operator *()//按照指针的方式进行引用
		{
			return _pCur->_data;
		}

		T *operator ->()
		{
			return &(_pCur->_data);
		}

		Self& operator++()//前置++
		{
			_pCur = _pCur->_pNext;
			return *this;
		}

		Self& operator++(int)//后置++
		{
			Self tmp(*this);
			_pCur = _pCur->_pNext;
			return *tmp;
		}

		Self& operator--()//前置--
		{
			_pCur = _pCur->_pPre;
			return *this;
		}

		Self &operator--(int)//后置--
		{
			Self tmp(*this);
			_pCur = _pCur->_pPre;
			return *tmp;
		}

		bool operator ==(const Self & l)
		{
			if (l._pCur==_pCur)
			{
				return true;
			}
			return false;
		}

		bool operator !=(const Self & l)
		{
			return !(_pCur == l._pCur);
		}

		Node * _pCur;
	};




	template <class T>//list类
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef Iterator<T> iterator;
	public:
		//////////////////////////////////////////////////////////////
		//构造与析构
		typedef ListNode<T> Node;//对节点类型重命名，使用起来更加方便
		list()//默认构造函数，只创建一个头节点
		{
			CreatHead();
		}

		list(int n, const T& val)//构造n个值为val
		{
			CreatHead();
			for (int i=0; i < n; i++)
			{
				push_back(val);
			}
		}

		template<class iterator>
		list(iterator first, iterator end)//区间构造
		{
			CreatHead();
			while (first != end)
			{
				push_back(*first);
				first++;
			}
		}

		list(const list<T> &L)//拷贝构造
		{
			CreatHead();
			Node*cur = L._phead->_pNext;
			while (cur != L._phead)
			{
				push_back(cur->_data);
				cur = cur->_pNext;
			}
		}

		list <T>& operator=(const list<T> & l)//赋值运算符的重载
		{
			if (&l != this)
			{
				clear();
				Node*cur = l._phead->_pNext;
				while (cur != l._phead)
				{
					push_back(cur->_data);
					cur = cur->_pNext;
				}
			}
			return *this;
		}

		~list()
		{
			clear();
			delete _phead;
		}

		//////////////////////////////////////////////////////////////
		//迭代器
		iterator begin()
		{
			return iterator(_phead->_pNext);
		}
		iterator end()
		{
			return iterator(_phead);
		}



		//////////////////////////////////////////////////////////////
		//容量
		int size()
		{
			int size = 0;
			Node*cur = _phead->_pNext;
			while (cur != _phead)
			{
				size++;
				cur = cur->_pNext;
			}
			return size;
		}

		bool empty()
		{
			if (_phead->_pNext == _phead)
			{
				return true;
			}
			return false;
		}

		void resize(int newsize, const T&data = T())
		{
			int oldsize = size();
			if (newsize > oldsize)
			{
				for (int i = oldsize; i < newsize; i++)
				{
					push_back(data);
				}
			else
			{
				for (int i = newsize; i < oldsize; i++)
				{
					pop_back();
				}
			}
			}
		}


		///////////////////////////////
		// 元素访问
		T& front()
		{
			return _pHead->_pNext->_data;
		}

		const T& front()const
		{
			return _pHead->_pNext->_data;
		}

		T& back()
		{
			return _pHead->_pPre->_data;
		}

		const T& back()const
		{
			return _pHead->_pPre->_data;
		}



		//////////////////////////////////////////////////////////////
		//元素修改
		void push_back(const T& data)
		{
			insert(end(), data);
		}

		void pop_back()
		{
			erase(--end()); 
		}


		iterator insert(iterator pos,const T& data)
		{
			Node*cur = new Node(data);
			Node*tmp = pos._pCur;
			cur->_pNext = tmp;
			cur->_pPre = tmp->_pPre;
			cur->_pPre->_pNext = cur;
			tmp->_pPre = cur;
			return iterator(cur);
		}

		iterator erase(iterator pos)
		{
			Node*del = pos._pCur;
			if (del == _phead)
			{
				return end();
			}
			Node *ret = del->_pNext;
			del->_pPre->_pNext = del->_pNext;
			del->_pNext->_pPre = del->_pPre;
			delete del;
			return iterator(ret);
		}

		void clear()//头删
		{
			Node *cur = _phead->_pNext;
			while (cur != _phead)
			{
				_phead->_pNext = cur->_pNext;
				delete cur;
				cur = _phead->_pNext;
			}
			_phead->_pNext = _phead;
			_phead->_pPre = _phead;
		}

	private:
		void CreatHead()
		{
			_phead = new Node;
			_phead->_pPre = _phead;
			_phead->_pNext = _phead;
		}
	private:
		Node* _phead;
	};
};

int main()
{
	mine::list<int> l(5,10);
	mine::list<int> s(l);
	for (auto e : s)
	{
		cout << e;
	}
	system("pause");
	return 0;
}
