#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<stdlib.h>
typedef int QUDataType;

typedef struct QueueNode 
{ 
	struct QueueNode* _next;   
    QUDataType _data;
}QueueNode;

typedef struct Queue {
	QueueNode* _front; // ��ͷ   
	QueueNode* _rear;  // ��β
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(QUDataType x); 
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq); 
int QueueSize(Queue* pq);
void Printf(Queue* pq);
void TestQueue();



#endif