#define _CRT_SECURE_NO_WARNINGS 1
#include"LIST.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 5);
	//ListInsertFront(ListFind(&list,5), 4);//≤‚ ‘≤Â»Î
	ListPushBack(&list, 5);
	ListPushBack(&list, 5);

	ListPushBack(&list, 5);
	ListPushBack(&list, 5);
	//ListPushFront(&list, 7);
	//ListPushFront(&list, 8);
	//ListPushFront(&list, 9);

	//ListErase(ListFind(&list, 5));//≤‚ ‘erase
	//ListRemove(&list, 7);

	ListDistinct(&list);
	ListPrint(&list);
	system("pause");
	return 0;
}

















