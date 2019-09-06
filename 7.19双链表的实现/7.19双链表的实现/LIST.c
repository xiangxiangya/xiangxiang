
#define _CRT_SECURE_NO_WARNINGS 1
#include"LIST.h"
#include<stdio.h>
#include<stdlib.h>


void ListInit(List* plist)
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}


void ListInsertFront(ListNode* pos, LTDataType x)
{
	if (pos == NULL)
	{
		return;
	}
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode*tmp = pos->_prev;
	cur->_data = x;
	cur->_next = pos;
	pos->_prev = cur;
	cur->_prev = tmp;
	tmp->_next = cur;
}


void ListInsertBack(ListNode* pos, LTDataType x)
{
	if (pos == NULL)
	{
		return;
	}
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode*tmp = pos->_next;
	cur->_data = x;
	cur->_prev = pos;
	pos->_next = cur;
	cur->_next = tmp;
	tmp->_prev = cur;

}

ListNode* ListFind(List* plist, LTDataType x)
{
	if (plist == NULL)
	{
		return;
	}
	ListNode*cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}


void ListPushBack(List* plist, LTDataType x)
{
	ListInsertFront(plist->_head, x);
}

void ListPushFront(List* plist, LTDataType x)
{
	ListInsertBack(plist->_head, x);
}

void ListPrint(List* plist)
{
	ListNode*cur;
	printf("head->");
	for (cur=plist->_head->_next; cur != plist->_head;cur=cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL");
}

void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}


void ListRemove(List* plist, LTDataType x)
{
	ListNode*tmp;
	for (tmp = plist->_head->_next; tmp != plist->_head; tmp = tmp->_next)
	{
		if (tmp->_data == x)
		{
			ListErase(tmp);
			return;
		}	
	}
	return NULL;
}



void ListDistinct(List* plist)//��������������ͬ��Ԫ�����
{
	ListNode*tmp;
	for (tmp = plist->_head->_next; tmp != plist->_head->_prev; )//��Ϊ���ѭ��ִ�е��Ǻ�ɾ�������Ա���ʱҪ�ٰ�
	{
		if (tmp->_data == tmp->_next->_data)
		{
			ListErase(tmp->_next);
		}
		else
		{
			tmp = tmp->_next;
		}
	}
}



void ListMerge(List* plist1, List* plist2)//��list2���뵽list1��
{
	ListNode* cur1 = plist1->_head->_next;//�ڵ�֮ǰ��ͷ���
	ListNode* cur2 = plist2->_head->_next;
	ListNode*tmp1;
	ListNode*tmp2;
	while (cur1!=plist1->_head&&cur2!=plist2->_head)//˫���������ѭ���˳�����
	{
		if (cur1->_data > cur2->_data)//���cur1��ֵ����cur2
		{
			tmp1 = cur1->_prev;//��¼cur1ǰ���λ�ã���Ϊ�ڽ����л��Ҳ���cur1ǰ���λ��
			tmp2 = cur2->_next;//��¼cur2�����λ�ã���Ϊ�ڽ����л��Ҳ���cur2�����λ��
			cur2->_next = cur1;
			cur1->_prev = cur2;
			cur2->_prev = tmp1;
			tmp1->_next = cur2;
			cur2 = tmp2;
		}
		else
		{
			cur1 = cur1->_next;
		}
	}
	if (cur1 == plist1->_head)//����1��,��list2������нڵ㶼����list1����
	{
		tmp2 = plist2->_head->_prev;
		cur2->_prev = cur1->_prev;
		cur1->_prev->_next = cur2;
		tmp2->_next = cur1;
		cur1->_prev = tmp2;
	}
	free(plist2->_head);  
}

















