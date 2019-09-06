#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>


void QueueInit(Queue* pq)
{
	pq->_front = NULL;
	pq->_rear = NULL;
}

//void QueueDestory(Queue* pq)
//{
//	free(pq->);	
//}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode*tmp = (QueueNode*)malloc(sizeof(QueueNode)*10);
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}

void QueuePush(Queue* pq, QUDataType x)//Î²²å
{
	if (pq->_rear == NULL)
	{
		QueueNode*tmp = BuyQueueNode(x);
		pq->_front = tmp;
		pq->_rear = tmp;
	}
	else
	{
		QueueNode*tmp = BuyQueueNode(x);
		pq->_rear->_next = tmp;
		pq->_rear=tmp;
	}
		
}
void QueuePop(Queue* pq)//Í·É¾
{
	QueueNode*tmp = pq->_front->_next;
	free(pq->_front);
	pq->_front = tmp;
}
QUDataType QueueFront(Queue* pq)
{
	/*printf("%d\n", pq->_front->_data);*/
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)
{
	printf("%d\n", pq->_rear->_data);
}
int QueueEmpty(Queue* pq)
{
	if (pq->_front == NULL)
	{
		return 1;
	}
	return 0;

}

int QueueSize(Queue* pq);

void Printf(Queue* pq)
{
	QueueNode*tmp;
	for (tmp = pq->_front; tmp; tmp = tmp->_next)
	{
		printf("%d->", tmp->_data);
	}
	printf("NULL");
}