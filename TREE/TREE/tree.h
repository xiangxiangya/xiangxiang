#ifndef _BTREE_H_
#define _BTREE_H_


#include<stdio.h>
#include<stdlib.h>

#define ENDTAG '#'

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;


BTNode* BinaryTreeCreate(BTDataType* a);
void BinaryTreePrevOrder(BTNode*cur);
void BinaryTreeInOrder(BTNode*cur);
void BinaryTreePostOrder(BTNode*cur);
void BinaryTreeLevelOrder(BTNode* root);
void Destroy(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
int BinaryTreeComplete(BTNode* root);
void BinaryTreeDestory(BTNode* root);




#endif