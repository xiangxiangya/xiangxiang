#define _CRT_SECURE_NO_WARNINGS 1
#include"STACT.h"
#include<stdlib.h>
#include<stdio.h>
int main()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 3);
	StackPush(&ps, 5);
	StackPush(&ps, 7);
	StackPush(&ps, 1);
	/*StackPop(&ps);*/

	/*STDataType tmp = StackTop(&ps);
	printf("%d", tmp);*/

	/*Print(&ps);*/
	StackEmpty(&ps);
	StackDestory(&ps);
	system("pause");
	return 0;
}