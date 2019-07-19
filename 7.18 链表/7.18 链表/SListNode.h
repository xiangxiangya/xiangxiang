#ifndef _SListNode_
#define _SListNode_
#include<stdio.h>
#include<stdlib.h>

typedef int  SLTDataType;

typedef struct SListNode//节点
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList//
{ 
	SListNode* _head; 
}
SList;

SListNode* BuySListNode(SLTDataType x);//创建一个新的节点
void SListInit(SList* plist);//初始化
void SListPushFront(SListNode** pphead, SLTDataType x);//头插
void SListPopFront(SListNode** pphead);//头删
void SListPrint(SListNode* phead);//打印
void SListDestory(SListNode** pphead);//销毁
SListNode* SListFind(SListNode* phead, SLTDataType x);//查
void SListInsertAfter(SListNode* pos, SLTDataType x);//在一个pos后插入
void SListEraseAfter(SListNode* pos);//擦去pos后的数据
void SListRemove(SListNode** pphead, SLTDataType x);//移除一个数据

void SListRemoveAll(SListNode** pphead, SLTDataType x);

void SListReverse(SListNode **pphead);
void SListDestory(SList* plist);

SListNode* IFSameNode(SListNode*headA, SListNode*headB);

#endif