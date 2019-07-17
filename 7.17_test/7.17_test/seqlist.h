#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef int SLDataType;//修改数据的类型时方便

typedef struct SeqList
{
	SLDataType* array;  // 指向动态开辟的数组
	size_t size;       // 有效数据个数
	size_t capacity;   // 容量空间的大小
}SeqList;

// 基本增删查改接口
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);

void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInseZrt(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);

void SeqListRemoveAll(SeqList* psl, SLDataType x);
int SeqListBinaryFind(SeqList* psl, SLDataType x);
void SeqListBubbleSort(SeqList* psl);




#endif