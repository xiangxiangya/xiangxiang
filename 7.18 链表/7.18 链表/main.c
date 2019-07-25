#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"
#include<stdio.h>


//
//int main()//约瑟夫环的测试
//{
//
//	SListNode *head;
//	SListNode*plast;
//	SListNode*cur;
//	SListInit(&head);
//	SListPushFront(&head, 1);
//	plast = head;
//	SListPushFront(&head, 2);
//	SListPushFront(&head, 3);
//	SListPushFront(&head, 4);
//	SListPushFront(&head, 5);
//	plast->_next = head;
//	cur=yuesefu(&head, 3);
//	printf("%d",cur->_data);
//	//SListPrint(head);
//	system("pause");
//	return 0;
//}

int ___main()//测试给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
{
	SListNode *head;
	SListInit(&head);
	SListPushFront(&head, 1);
	SListPushFront(&head, 2);
	SListPushFront(&head,3);
	SListPushFront(&head, 4);
	SListPushFront(&head, 5);
	//head->_next->_next->_next->_next= head->_next->_next;
	/*SListPrint(head);*/
	SListNode*tmp = detectCycle(head);
	if (tmp == NULL)
	{
		printf("NULL");
	}
	else
	{
		printf("%d", tmp->_data);
	}

	system("pause");
	return 0;
}

int __main()//测试IFSameNode
{
	SListNode *headA; 
	SListInit(&headA);
	SListNode *headB;
	SListInit(&headB);
	SListNode *headc;
	SListInit(&headc);
	SListPushFront(&headc, 1);
	SListPushFront(&headc, 2);
	SListPushFront(&headA, 1);
	SListPushFront(&headA, 2);
	SListPushFront(&headA, 3);

	SListPushFront(&headB, 4);
	SListPushFront(&headB, 5);


	headA->_next->_next->_next= headc;//将三个链表连接在一起
	headB->_next->_next = headc;


	//SListPrint(headA);
	//SListPrint(headB);
	SListNode *tmp;
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


int main()
{
	SListNode *head;//链表定义规则就是定义一个结构体指针
	SListInit(&head);
	SListPushFront(&head, 20);
	SListPushFront(&head, 15);
	SListPushFront(&head, 10);
	SListPushFront(&head, 5);
	//SListPushFront(&head, 5);
	//SListPushFront(&head, 4);
	//SListPushFront(&head, 3);
	//SListPushFront(&head, 7);
	//SListPushFront(&head, 8);

	//SListRemove(&head,3);
	//SListPopFront(&head);
	//SListInsertAfter(head, 4);
	//SListEraseAfter(head);
	/*SListRemoveAll(&head, 3);*/
	//SListReverse(&head);
	//SListReverse2(&head);
	insert(&head, 50);
	SListPrint(head);
	SListDestory(&head);
	system("pause");
	return 0;

}