#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"STACT.h"
int main()
{
	BTNode*cur=BinaryTreeCreate("ABD##E#H##CF##G##");
	//BinaryTreePrevOrder(cur);
	//BinaryTreeInOrder(cur);
	//BinaryTreePostOrder(cur);
	//BinaryTreeLevelOrder(cur);
	//BinaryTreePrevOrderNonR(cur);
	printf("%d",BinaryTreeComplete(cur));
	system("pause");
	return 0;
}