#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

namespace mine//�Լ�����������ռ䣬Ϊ�˷�ֹ����е�list��ͻ
{

	template <class T>//������һ���ڵ���
	class ListNode
	{
		public:
		ListNode(const T &data=T())//û�д��εĻ�����T���Ͷ����Ĭ�Ϲ��캯��
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
		typedef ListNode<T> Node;//�Խڵ�������������������ʹ��
		typedef Iterator<T> Self;
		Iterator(Node *cur)//���캯��
			:_pCur(cur)
		{
		}

		T& operator *()//����ָ��ķ�ʽ��������
		{
			return _pCur->_data;
		}

		T *operator ->()
		{
			return &(_pCur->_data);
		}

		Self& operator++()//ǰ��++
		{
			_pCur = _pCur->_pNext;
			return *this;
		}

		Self& operator++(int)//����++
		{
			Self tmp(*this);
			_pCur = _pCur->_pNext;
			return *tmp;
		}

		Self& operator--()//ǰ��--
		{
			_pCur = _pCur->_pPre;
			return *this;
		}

		Self &operator--(int)//����--
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




	template <class T>//list��
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef Iterator<T> iterator;
	public:
		//////////////////////////////////////////////////////////////
		//����������
		typedef ListNode<T> Node;//�Խڵ�������������ʹ���������ӷ���
		list()//Ĭ�Ϲ��캯����ֻ����һ��ͷ�ڵ�
		{
			CreatHead();
		}

		list(int n, const T& val)//����n��ֵΪval
		{
			CreatHead();
			for (int i=0; i < n; i++)
			{
				push_back(val);
			}
		}

		template<class iterator>
		list(iterator first, iterator end)//���乹��
		{
			CreatHead();
			while (first != end)
			{
				push_back(*first);
				first++;
			}
		}

		list(const list<T> &L)//��������
		{
			CreatHead();
			Node*cur = L._phead->_pNext;
			while (cur != L._phead)
			{
				push_back(cur->_data);
				cur = cur->_pNext;
			}
		}

		list <T>& operator=(const list<T> & l)//��ֵ�����������
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
		//������
		iterator begin()
		{
			return iterator(_phead->_pNext);
		}
		iterator end()
		{
			return iterator(_phead);
		}



		//////////////////////////////////////////////////////////////
		//����
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
		// Ԫ�ط���
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
		//Ԫ���޸�
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

		void clear()//ͷɾ
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
