#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"

void SListInit(SListNode** pphead)
{
	*pphead = NULL;
}

SListNode* BuySListNode(SLTDataType x)

{
	SListNode*res = (SListNode*)malloc(sizeof(SListNode));
	res->_data = x;
	res->_next = NULL;
	return res;
}

void SListPushFront(SListNode**pphead, SLTDataType x)
{
	SListNode *tmp = BuySListNode(x);//申请一个节点
	tmp->_next = *pphead;//将两节点相连，头本来指的是原来的节点
	*pphead = tmp;//将新节点设置为头
}

void SListPopFront(SListNode** pphead)//头删
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode *tmp = (*pphead)->_next;
	/*free(*pphead);*/
	*pphead = NULL;
	*pphead = tmp;
}


void SListPrint(SListNode* phead)//打印
{
	SListNode *cur;//链表遍历，指针的形式
	for (cur = phead; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}


SListNode* SListFind(SListNode* phead, SLTDataType x)
{
	if (phead == NULL)
	{
		return;
	}
	SListNode* cur;
	for (cur = phead; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}


void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode *tmp = BuySListNode(x);
	tmp->_next = pos->_next;
	pos->_next =tmp ;

}

void SListEraseAfter(SListNode* pos)
{
	SListNode*tmp = pos->_next;//定义一个临时指针指向erase的元素
	if (tmp == NULL)
	{
		return;
	}
	pos->_next = tmp->_next;
	free(tmp);
}


void SListDestory(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	while ((*pphead)->_next)
	{
		SListEraseAfter(*pphead);
	}
	
	free(*pphead);
	*pphead = NULL;
}


void SListRemove(SListNode** pphead, SLTDataType x)//清除单个元素
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode*cur;
	if ((*pphead)->_data== x)
	{
		SListPopFront(pphead);
	}
	for (cur = *pphead; cur->_next; cur = cur->_next)
	{
		if (cur->_next->_data == x)
		{
			SListEraseAfter(cur);
			return;
		}
	}
}


void SListRemoveAll(SListNode** pphead, SLTDataType x)//删所有标记的元素
{
	SListNode* tmp;
	while (*pphead && (*pphead)->_data== x)
	{
		SListPopFront(pphead);
	}

	for (tmp = *pphead; tmp && tmp->_next;)//tmp和tmp->next都不为空时进入循环
	{
		if (tmp->_next->_data == x)//如果清除了一个元素则tmp不变，继续判断下一个元素
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->_next;
		}
	}
}

void SListReverse(SListNode **pphead)//逆置链表(三变量交换指向法）
{
	SListNode*pre = *pphead;
	SListNode*cru = pre->_next;
	SListNode*next = cru;
	 
	pre->_next = NULL;
	while (next)
	{
		next = cru->_next;
		cru->_next = pre;//最关键的换指向  之所以不用next是因为后面的移位操作需要用到next
		pre = cru;
		cru = next;
	}
	*pphead = pre;

}