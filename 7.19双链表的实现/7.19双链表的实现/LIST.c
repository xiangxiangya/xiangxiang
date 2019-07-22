
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



void ListDistinct(List* plist)//将有序链表中相同的元素清除
{
	ListNode*tmp;
	for (tmp = plist->_head->_next; tmp != plist->_head->_prev; )//因为这个循环执行的是后删操作所以遍历时要再把
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



void ListMerge(List* plist1, List* plist2)//把list2插入到list1中
{
	ListNode* cur1 = plist1->_head->_next;//节点之前有头结点
	ListNode* cur2 = plist2->_head->_next;
	ListNode*tmp1;
	ListNode*tmp2;
	while (cur1!=plist1->_head&&cur2!=plist2->_head)//双链表遍历的循环退出条件
	{
		if (cur1->_data > cur2->_data)//如果cur1的值大于cur2
		{
			tmp1 = cur1->_prev;//记录cur1前面的位置，因为在交换中会找不到cur1前面的位置
			tmp2 = cur2->_next;//记录cur2后面的位置，因为在交换中会找不到cur2后面的位置
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
	if (cur1 == plist1->_head)//链表1空,把list2后的所有节点都挂在list1后面
	{
		tmp2 = plist2->_head->_prev;
		cur2->_prev = cur1->_prev;
		cur1->_prev->_next = cur2;
		tmp2->_next = cur1;
		cur1->_prev = tmp2;
	}
	free(plist2->_head);  
}

















