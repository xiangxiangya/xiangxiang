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
	SListNode *tmp = BuySListNode(x);//����һ���ڵ�
	tmp->_next = *pphead;//�����ڵ�������ͷ����ָ����ԭ���Ľڵ�
	*pphead = tmp;//���½ڵ�����Ϊͷ
}

void SListPopFront(SListNode** pphead)//ͷɾ
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


void SListPrint(SListNode* phead)//��ӡ
{
	SListNode *cur;//���������ָ�����ʽ
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
	SListNode*tmp = pos->_next;//����һ����ʱָ��ָ��erase��Ԫ��
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


void SListRemove(SListNode** pphead, SLTDataType x)//�������Ԫ��
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


void SListRemoveAll(SListNode** pphead, SLTDataType x)//ɾ���б�ǵ�Ԫ��
{
	SListNode* tmp;
	while (*pphead && (*pphead)->_data== x)
	{
		SListPopFront(pphead);
	}

	for (tmp = *pphead; tmp && tmp->_next;)//tmp��tmp->next����Ϊ��ʱ����ѭ��
	{
		if (tmp->_next->_data == x)//��������һ��Ԫ����tmp���䣬�����ж���һ��Ԫ��
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->_next;
		}
	}
}

void SListReverse(SListNode **pphead)//��������(����������ָ�򷨣�
{
	SListNode*pre = *pphead;
	SListNode*cru = pre->_next;
	SListNode*next = cru;
	 
	pre->_next = NULL;
	while (next)
	{
		next = cru->_next;
		cru->_next = pre;//��ؼ��Ļ�ָ��  ֮���Բ���next����Ϊ�������λ������Ҫ�õ�next
		pre = cru;
		cru = next;
	}
	*pphead = pre;

}