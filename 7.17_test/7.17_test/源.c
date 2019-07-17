#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"seqlist.h"
int main()
{
	SeqList test;
	SeqListInit(&test,2);

	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 6);
	SeqListPushBack(&test, 7); 
	SeqListPushBack(&test, 8); 


	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 2); 
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 6); 
	SeqListPushBack(&test, 4);


	//SeqListPopBack(&test);
	//SeqListPushFront(&test, 7);
	//SeqListPopFront(&test);

	/*int size=SeqListFind(&test,5);
	printf("%d", size);*/

	//SeqListInseZrt(&test, 3, 5);
	//SeqListErase(&test, 2);

	//SeqListRemove(&test, 4);

	//SeqListModify(&test, 2, 4);

	//SeqListRemoveAll(&test, 4);

	//printf("%d ", SeqListBinaryFind(&test, 9));


	SeqListBubbleSort(&test);

	SeqListPrint(&test);


    SeqListDestory(&test);

	system("pause");
	return 0;
}