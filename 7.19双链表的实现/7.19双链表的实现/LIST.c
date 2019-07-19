
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


















