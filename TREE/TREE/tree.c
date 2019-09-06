#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"
#include"STACT.h"
#include"queue.h"

BTNode* BinaryTreeCreate(BTDataType* a)//��ʼ����
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
void BinaryTreePrevOrder(BTNode*cur)//ǰ�����
{
	if (cur != NULL)
	{
		printf("%c ", cur->_data);
		BinaryTreePrevOrder(cur->_left);
		BinaryTreePrevOrder(cur->_right);
	}
}
void BinaryTreeInOrder(BTNode*cur)//�������
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



void BinaryTreeLevelOrder(BTNode* root)//�ö���ʵ�ֲ������
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


void BinaryTreePrevOrderNonR(BTNode* root)//���õݹ�  ջ�ķ�ʽʵ��ǰ�����
{
	Stack st;
	
	BTNode*cur=root;
	StackInit(&st);
	while (cur||!StackEmpty(&st))
	{
		putchar(cur->_data);
		if (cur->_right)//�Һ��ӷ���ջ�У���ΪҪ�������Һ��Ӻ��
		{
			StackPush(&st, cur->_right);
		}
		
		if (cur->_left)//��Ϊ��ǰ��������������൱�ڱ����Ĺ���
		{
			cur = cur->_left;
		}
	
		else//����Ҳ���ǵ�û������ʱ�ĳ�ջ������Ȼ�������ջ�Ľڵ���Ϊ����ӡ��ѭ���ж��������Һ��ӽ�����ջ��ջ������
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

int BinaryTreeComplete(BTNode* root)//�ж��Ƿ�Ϊ��ȫ������
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
		if (flag && (tmp->_left || tmp->_right))//�����flag=1��������ж϶������ÿ���ڵ��Ƿ�ΪҶ�ӣ��������Ҷ����return0
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


