#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _Queue_
#define _Queue_
#include<stdio.h>
#include<stdlib.h>


#define QueueMAX 8
typedef int QuDataType;

typedef struct Queue
{
	QuDataType data[QueueMAX];//一直是数组首元素的地址
	QuDataType*front;
	QuDataType*rear;
	size_t size;
}Queue;



void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, QuDataType x);
void QueuePop(Queue* pq);

QuDataType QueueFront(Queue* pq);
QuDataType QueueBack(Queue* pq);


#endif