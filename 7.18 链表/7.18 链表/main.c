#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"
#include<stdio.h>

int main()
{
	SListNode *head;
	system("pause");
	return 0;
}

int _main()//测试IFSameNode
{
	SListNode *headA; 
	SListInit(&headA);
	SListNode *headB;
	SListInit(&headB);
	SListNode *a;
	SListPushFront(&a, 5);
	SListPushFront(&headA, 1);
	SListPushFront(&headA, 2);
	SListPushFront(&headA, 3);
	SListPushFront(&a, 5);
	SListPushFront(&headB, 4);
	SListPushFront(&headB, 5);
	SListNode *tmp;
	//tmp=headA->_next->_next->_next;
	//tmp = headB->_next->_next;
	tmp=IFSameNode(headA, headB);
	if (tmp == NULL)
	{
		printf("NULL");
	}
	else
	{
		printf("%d", tmp->_data);
	}
	//printf("%d", tmp->_data);
	system("pause");
	return 0;
}


int _main()
{
	SListNode *head;//链表定义规则就是定义一个结构体指针
	SListInit(&head);
	SListPushFront(&head, 1);
	SListPushFront(&head, 2);
	SListPushFront(&head, 3);
	SListPushFront(&head, 4);
	SListPushFront(&head, 5);
	SListPushFront(&head, 6);
	SListPushFront(&head, 7);
	SListPushFront(&head, 8);

	//SListRemove(&head,3);
	//SListPopFront(&head);
	//SListInsertAfter(head, 4);
	//SListEraseAfter(head);
	/*SListRemoveAll(&head, 3);*/
	//SListReverse(&head);
	SListPrint(head);
	SListDestory(&head);
	system("pause");
	return 0;

}