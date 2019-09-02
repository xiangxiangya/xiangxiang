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
	//if (*pphead == NULL)
	//{
	//	return;
	//}
	//while ((*pphead)->_next)
	//{
	//	SListEraseAfter(*pphead);
	//}
	//
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

void SListReverse2(SListNode **pphead)//第二种方法实现链表的逆置（前插后删）
{
	SListNode*oldh=*pphead;
	SListNode*head=*pphead;
	SListNode*pos = head->_next;
	SListNode*next=pos->_next;
	oldh->_next = NULL;
	while (pos)
	{
		pos->_next = head;
		head = pos;
		pos = next;
		if (next != NULL)
		{
			next = next->_next;
		}

	}
	*pphead = head;
}




void SListReverse(SListNode **pphead)//方法一逆置链表(三变量交换指向法）
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


SListNode* IFSameNode(SListNode*headA, SListNode*headB)//是否有相同的节点 课件第九题
{
	SListNode*longerhead = headA;//假设长 的是A
	SListNode*shorterhead = headB;
	int lena = 0;
	int lenb = 0;
	int gas = 0;
	int i = 0;
	SListNode*cur;
	for (cur = headA; cur; cur = cur->_next)
	{
		lena++;
	}
	for (cur = headB; cur; cur = cur->_next)
	{
		lenb++;
	}
	gas = abs(lena - lenb);
	if (lenb > lena)
	{
		longerhead = headB;
		shorterhead = headA;
	}
	for (i = 0; i < gas; i++)
	{
		longerhead = longerhead->_next;
	}
	for (; shorterhead&&longerhead; shorterhead = shorterhead->_next, longerhead = longerhead->_next)
	{
		if (shorterhead == longerhead)
		{
			return shorterhead;
		}
	}
	return NULL;
}

SListNode *detectCycle(SListNode*head)//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
{
	SListNode*slow = head;
	SListNode*fast= head;
	while (fast && slow && fast->_next)//判断两个指针是否会相遇
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if (fast == slow)//相遇则跳出
		{
			break;
		}
	}

	for (fast, head; fast&&fast->_next; fast = fast->_next, head = head->_next)//head和相遇点到入环点的距离相等
	{
		if (head = fast)
		{
			return fast;
		}
	}

	return NULL;
}




SListNode* yuesefu(SListNode **pphead, SLTDataType x)//约瑟夫环
{
	SListNode*tmp = *pphead;
	SListNode*cur = *pphead;
	int i = 0;
	while (tmp->_next!= tmp)
	{
		for (i = 0; i < x - 1; i++)
		{
			tmp = tmp->_next;
		}
		SListEraseAfter(tmp);
		tmp = tmp->_next;
	}
	tmp->_next = NULL;
	return;
}



void insert(SListNode **pphead,int n)//将一个数字插入一个有序的链表里
{
	SListNode*cur;
	SListNode*tmp;
	SListNode*tmp2;
	tmp2 = *pphead;
	if (n<tmp2->_data)
	{
		SListNode*new = (SListNode*)malloc(sizeof(SListNode));
		new->_next =*pphead;
		new->_data = n;
		*pphead = new;
		return;
	}
	for (cur = *pphead,tmp=*pphead; cur;)
	{
		if (n > cur->_data)
		{
			tmp =cur;
			cur=cur->_next;
		}
		else
		{
			SListNode*new1 = (SListNode*)malloc(sizeof(SListNode));
			tmp->_next = new1;
			new1->_data = n;
			new1->_next = cur;
			return;
		}
	}
	SListNode*new2 = (SListNode*)malloc(sizeof(SListNode));
	tmp->_next = new2;
	new2->_data = n;
	new2->_next = NULL;
}


SListNode * Fun(SListNode **pphead, int k)//查找链表倒数第k个元素

{
	SListNode*cur=*pphead;
	SListNode*tmp = *pphead;

	int i = 0;
	int count = 0;
	for (cur = *pphead; cur; cur = cur->_next)
	{
		count++;
	}
	for (i = 0; i < count - k; i++)
	{
		tmp = tmp->_next;
	}
	return tmp;

}