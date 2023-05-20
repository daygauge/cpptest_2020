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

BTNode* BuyNode(binlst a);//创建一个节点
BTNode* CreatBinaryTree(binlst* ls, int* lp);//根据数组构建二叉树
void printfbtn(BTNode* ls);//二叉树前序遍历
void levelOrder(BTNode* ls);//二叉树层序遍历
void btndestry(BTNode* ls);//二叉树销毁