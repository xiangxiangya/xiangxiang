#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"
#include"STACT.h"
#include"queue.h"

BTNode* BinaryTreeCreate(BTDataType* a)//初始化树
{
	BTNode*tmp;
	static int i = 0;
	if (a[i] == ENDTAG)
	{
		i++;
		return NULL;
	}
	tmp = (BTNode*)malloc(sizeof(BTNode));
	tmp->_data = a[i];
	i++;
	tmp->_left = BinaryTreeCreate(a);
	tmp->_right = BinaryTreeCreate(a);
	return tmp;
}
void BinaryTreePrevOrder(BTNode*cur)//前序遍历
{
	if (cur != NULL)
	{
		printf("%c ", cur->_data);
		BinaryTreePrevOrder(cur->_left);
		BinaryTreePrevOrder(cur->_right);
	}
}
void BinaryTreeInOrder(BTNode*cur)//中序遍历
{
	if (cur != NULL)
	{
		BinaryTreeInOrder(cur->_left);
		printf("%c ", cur->_data);
		BinaryTreeInOrder(cur->_right);
	}
}
void BinaryTreePostOrder(BTNode*cur)
{
	if (cur != NULL)
	{
		BinaryTreePostOrder(cur->_left);
		BinaryTreePostOrder(cur->_right);
		printf("%c ", cur->_data);
	}
}



void BinaryTreeLevelOrder(BTNode* root)//用队列实现层序遍历
{
	Queue qu;
	BTNode*tmp;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueEmpty(&qu))
	{
		tmp = QueueFront(&qu);
		printf("%c ", tmp->_data);
		if (tmp->_left)
		{
			QueuePush(&qu, tmp->_left);
		}
		if (tmp->_right)
		{
			QueuePush(&qu, tmp->_right);
		}
		QueuePop(&qu);
	}

}


void BinaryTreePrevOrderNonR(BTNode* root)//不用递归  栈的方式实现前序遍历
{
	Stack st;
	
	BTNode*cur=root;
	StackInit(&st);
	while (cur||!StackEmpty(&st))
	{
		putchar(cur->_data);
		if (cur->_right)//右孩子放入栈中，因为要先来的右孩子后出
		{
			StackPush(&st, cur->_right);
		}
		
		if (cur->_left)//因为是前序遍历所以左孩子相当于遍历的过程
		{
			cur = cur->_left;
		}
	
		else//（出也就是当没有左孩子时的出栈操作，然后将这个出栈的节点作为根打印再循环判断它的左右孩子进行入栈出栈操作）
		{
			cur=StackFront(&st); 
			StackPop(&st);
		}
	}
	StackDestory(&st);
}





void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack st;
	BTNode*cur = root;
	StackInit(&st);
	while (cur || StackEmpty(&st))
	{
		for (; cur;cur= cur->_left)
		{
			StackPush(&st, cur->_left);
		}
		while (StackEmpty(&st))
		{
			cur = StackFront(&st);
			putchar(cur->_data);
			StackPop(&st);
			cur = cur->_right;
		}
	}
}




void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode * cur = root;
	
	Stack st;
	int tag[32] = { 0 };

	StackInit(&st, 100);

	while (cur || !StackEmpty(&st))
	{
		for (; cur; cur = cur->_left)
		{
			StackPush(&st, cur);
			tag[st._top] = 0;
		}

		while (!StackEmpty(&st) && tag[st._top] == 1)
		{
			cur = StackFront(&st);
			putchar(cur->_data);
			StackPop(&st);
			cur = NULL;
		}

		if (!StackEmpty(&st))
		{
			tag[st._top] = 1;
			BTNode * tmp = StackFront(&st);
			cur = tmp->_right;
		}
	}
	StackDestory(&st);
}

int BinaryTreeComplete(BTNode* root)//判断是否为完全二叉树
{
	Queue qu;
	int flag=0;
	BTNode*tmp;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueEmpty(&qu))
	{
		tmp = QueueFront(&qu);
		printf("%c ", tmp->_data);
		QueuePop(&qu);
		if (flag && (tmp->_left || tmp->_right))//如果在flag=1的情况下判断队列里的每个节点是否为叶子，如果不是叶子则return0
		{
			return 0;
		}
		if (tmp->_left&&tmp->_right)
		{
			QueuePush(&qu, tmp->_left);
			QueuePush(&qu, tmp->_right);
		}
		else
		if (tmp->_right&&!tmp->_left)
		{
			return 0;
		}
		else
		if (!tmp->_right)
		{
			flag = 1;
			if (tmp->_left)
			{
				QueuePush(&qu,tmp->_left);
			}
		}

	}
	return 1;
}

void BinaryTreeDestory(BTNode* root)
{
	BTNode*left, *right;
	if (root)
	{
		left = root->_left;
		right = root->_right;
		free(root);
		BinaryTreeDestory(left);
		BinaryTreeDestory(right);
	}
}


