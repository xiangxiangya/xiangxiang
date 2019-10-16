#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef class Student
{
public:
	char _name[8];
	char _id[5];
	int _score;
}Student;

typedef class Slist
{
public:
	Student _student;
	Slist *_next;
}Slist;

Slist* Buynode()
{
	Slist *cur = new Slist;
	cur->_next = nullptr;
	return cur;
}
void Init(Slist **head)//��ʼ��
{
	(*head) = new Slist;
	(*head)->_next = nullptr;
}

Slist * Insert_f(Slist **head)//ͷ��
{
	auto n=0;
	auto i = 0;
	cout << "ͷ�弸�����ݣ�" << endl;
	cin >> n;
	cout << "������->" << endl;
	Slist *tmp=nullptr;
	for (i = 0; i < n; i++)
	{
		Slist *cur = Buynode();
		(*head)->_next = cur;
		cur->_next = tmp;
		cin >> cur->_student._id >> cur->_student._name >> cur->_student._score;
		tmp = cur;
	}
	return (*head)->_next;
}

void Serchinname(Slist*head)
{
	char str[8];
	cout << "������Ҫ���ҵ����֣�" << endl;
	cin >> str;
	Slist *cur;
	for (cur = head; cur; cur = cur->_next)
	{
		if (str == cur->_student._name)
		{
			cout << cur->_student._id << "-" << cur->_student._score << endl;
			return;
		}
	}
	cout << "û���ҵ�����" << endl;
}

Slist *Insert_b(Slist**head)//���
{
	auto n = 0;
	auto i = 0;
	Slist*tmp = (*head);
	cout << "��弸�����ݣ�" << endl;
	cin >> n;
	cout << "������->" << endl;
	for (i = 0; i < n; i++)
	{
		Slist *cur = Buynode();
		cin >> cur->_student._id >> cur->_student._name >> cur->_student._score;
		tmp->_next = cur;
		tmp = cur;
	}
	return (*head)->_next;
	
}
void Print(Slist *head)//��ӡ
{
	Slist * cur;
	for (cur = (head)->_next; cur; cur = cur->_next)
	{
		cout << cur->_student._id << "|" << cur->_student._name << "|" << cur->_student._score << endl;
	}
}

void Destroy(Slist**head)//����
{
	Slist *tmp=(*head);
	Slist *tmpnext = tmp->_next;
	while (tmpnext)
	{
		delete tmp;
		tmp = tmpnext;
		tmpnext = tmpnext->_next;
	}
}
int main()
{
	Slist *S;
	Init(&S);
	//Insert_f(&S);
	Insert_b(&S);
	//Print(S);
	//Serchinname(S);
	Destroy(&S);
	system("pause");
	return 0;
	_CrtDumpMemoryLeaks();
}