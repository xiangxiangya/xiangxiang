#ifndef _STACT_H_
#define _STACT_H_

#include<stdio.h>
#include<stdlib.h>

typedef int STDataType;

#define size 2

typedef struct Stack 
{
	STDataType* _a;   
	int _top;       // Õ»¶¥   
	int _capacity;  // ÈÝÁ¿ 
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDataType x); 
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps); 
void Print(Stack* ps);
int StackSize(Stack* ps);


#endif