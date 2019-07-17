#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"seqlist.h"


void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->array=(SLDataType*)calloc(capacity,sizeof(SLDataType));
	psl->capacity=capacity;
	psl->size=0;
}


void SeqListDestory(SeqList* psl)//
{
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->capacity = 0;
		psl->size = 0;
	}
	
}


void SeqListPrint(SeqList* psl)
{
	int i;
	for (i = 0; i <psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");

}


void CheckCapacity(SeqList* psl)//检查是否满了
{
	if (psl->size >= psl->capacity)
	{
		psl->capacity *=  2;
		psl->array = (SLDataType*)realloc(psl->array, psl->capacity*sizeof(SLDataType));
	}
}


void SeqListPushBack(SeqList* psl, SLDataType x)//添加一个元素在最后
{
	CheckCapacity(psl);
	psl->array[psl-> size ] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl)//删除最后一个元素
{
	CheckCapacity(psl);
	psl->array[psl->size] = psl->array[psl->size + 1];
	psl->size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)//添加一个元素在最前
{
	CheckCapacity(psl);
	int i = 0;
	for (i = psl->size; i >= 0; i--)
	{
		
		psl->array[i + 1] = psl->array[i];
		CheckCapacity(psl);
	}
	psl->array[0] = x;
	psl->size++;
}

void SeqListPopFront(SeqList* psl)//删除第一个元素
{
	int i = 0;
	for (i = 0; i <psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//查找一个元素
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}


void SeqListInseZrt(SeqList* psl, size_t pos, SLDataType x)//向指定位置添加一个元素

{
	CheckCapacity(psl);
	int i = pos;
	for (i = psl->size; i >= pos; i--)
	{

		psl->array[i + 1] = psl->array[i];
		CheckCapacity(psl);
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos)//擦除一个元素
{
	int i = pos;
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}


void SeqListRemove(SeqList* psl, SLDataType x)//将第一次出现的元素移除
{
	SeqListErase(psl, SeqListFind(psl, x));
}


void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//修改一个元素
{
	psl->array[pos] = x;
}

void SeqListRemoveAll(SeqList* psl, SLDataType x)//移除所有出现的元素
{
	int capacity = psl->capacity;
	SLDataType*array1 = (SLDataType*)calloc(capacity, sizeof(SLDataType));
	int i = 0;
	int j = 0;
	for (i = 0,j=0; i <= psl->size; i++)
	{
		if (psl->array[i] != x)
		{
			array1[j] = psl->array[i];
			j++;
		}
	}
	free(psl->array);
	psl->array = array1;
	psl->size = j-1;
}


int SeqListBinaryFind(SeqList* psl, SLDataType x)//二分查找
{
	int left = 0;
	int right = psl->size;
	int mid = 0;
	
	while (left < right)
	{
		mid = (left + right) / 2;
		if (x>psl->array[mid])
		{
			left=mid;
		}
		else 
		if (x < psl->array[mid])
		{
			right = mid;
		}
		else
		{
			return mid;
		}
	}
      return mid;
}


void SeqListBubbleSort(SeqList* psl)//排序

{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < psl->size; i++)
	{
		for (j = 0; j < psl->size - i-1; j++)
		{
			if (psl->array[j]>psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j+1];
				psl->array[j+1] = tmp;
			}
		}
	}
}
