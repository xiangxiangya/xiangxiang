#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
int main()
{
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, 3);
	system("pause");
	return 0;
}