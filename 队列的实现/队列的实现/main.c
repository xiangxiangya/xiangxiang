#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	Queue test;
	QueueInit(&test);
	QueuePush(&test, 3);
	QueuePush(&test, 4);
	QueuePush(&test, 5);
	QueuePush(&test, 6);
	QueuePush(&test, 7);
	QueuePop(&test);
	//QueueFront(&test);
	QueueBack(&test);
	//Printf(&test);
	//QueueDestory(&test);
	system("pause");
	return 0;
}