#define _CRT_SECURE_NO_WARNINGS 1
#include"STACT.h"
#include<stdlib.h>
#include<stdio.h>


void StackInit(Stack* ps)
{
	STDataType *tmp = (STDataType*)malloc(sizeof(STDataType)*size);
	ps->_a = tmp;//ָ��̬���ٵ�����
	ps->_capacity=size;
	ps->_top=0;//�������Ϊ������±�
}
void StackDestory(Stack* ps)
{
	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = 0;
		ps->_top = 0;
	}
}

STDataType* StackFront(Stack*ps)
{
	if (ps->_top == 0)
	{
		return (STDataType)0;
	}
	return ps->_a[ps->_top-1];
}
void StackPush(Stack* ps, STDataType x)
{
	if (ps->_top>=ps->_capacity)//
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*ps->_capacity);	
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	if (ps->_top == 0)
	{
		return;
	}
	ps->_top--;
	//free(ps->_a[ps->_top-1]);
	//ps->_a[ps->_top-1] == NULL;
}

STDataType StackTop(Stack* ps)
{
	STDataType tmp;
	tmp = ps->_a[ps->_top-1];
	return tmp;
}

void Print(Stack* ps)
{
	int i = 0;
	for (i = 0; i < ps->_top; i++)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}
int StackEmpty(Stack* ps)
{
	if (ps->_top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int StackSize(Stack* ps);