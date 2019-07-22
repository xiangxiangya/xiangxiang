#ifndef _SListNode_
#define _SListNode_
#include<stdio.h>
#include<stdlib.h>

typedef int  SLTDataType;

typedef struct SListNode//�ڵ�
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList//
{ 
	SListNode* _head; 
}
SList;

SListNode* BuySListNode(SLTDataType x);//����һ���µĽڵ�
void SListInit(SList* plist);//��ʼ��
void SListPushFront(SListNode** pphead, SLTDataType x);//ͷ��
void SListPopFront(SListNode** pphead);//ͷɾ
void SListPrint(SListNode* phead);//��ӡ
void SListDestory(SListNode** pphead);//����
SListNode* SListFind(SListNode* phead, SLTDataType x);//��
void SListInsertAfter(SListNode* pos, SLTDataType x);//��һ��pos�����
void SListEraseAfter(SListNode* pos);//��ȥpos�������
void SListRemove(SListNode** pphead, SLTDataType x);//�Ƴ�һ������

void SListRemoveAll(SListNode** pphead, SLTDataType x);

void SListReverse(SListNode **pphead);
void SListDestory(SList* plist);
SListNode* yuesefu(SListNode **pphead, SLTDataType x);

SListNode* IFSameNode(SListNode*headA, SListNode*headB);

#endif