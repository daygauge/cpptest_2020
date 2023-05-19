#pragma once
#include <malloc.h>
#include <assert.h>
#include <iostream>
#include <queue>

typedef int binlst;
typedef struct BinaryTreeNodes
{
	struct BinaryTreeNodes* left;
	struct BinaryTreeNodes* right;
	binlst data;

}BTNode;

BTNode* BuyNode(binlst a);
BTNode* CreatBinaryTree(binlst* ls, int* lp);
void printfbtn(BTNode* ls);
void levelOrder(BTNode* ls);