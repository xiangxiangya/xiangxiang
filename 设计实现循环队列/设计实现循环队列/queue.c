#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"

void QueueInit(Queue* pq)
{
	pq->front=pq->rear=pq->data;
	pq->size = 0;
}

void QueueDestory(Queue* pq)
{
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}

void QueuePush(Queue* pq, QuDataType x)
{
	if (pq->size + 1 == QueueMAX)
	{
		return;
	}
	*(pq->rear) = x;
	pq->rear++;
	pq->size++;
	if ((pq->rear) - (pq->data) == QueueMAX)//rear到数组的最后一个元素    //完成了一个循环队列
	{
		pq->rear = pq->data;//让real重新指向data
	}
}

void QueuePop(Queue* pq)
{
	if (pq->size == 0)
	{
		return;
	}

	pq->front++;
	pq->size--;

	if ((pq->front) - (pq->data) == QueueMAX)//front到数组的最后一个元素   //完成了一个循环队列
	{
		pq->front = pq->data; //让front重新指向data
	}
}

QuDataType QueueFront(Queue* pq)
{
	if (pq->size == 0)
	{
		return(QuDataType)0;
	}
	return *pq->front;
}

QuDataType QueueBack(Queue* pq)
{
	if (pq->size == 0)
	{
		return(QuDataType)0;
	}
	if (pq->rear = pq->data)
	{
		return pq->data[QueueMAX - 1];
	}
	return *(pq->rear-1);
}