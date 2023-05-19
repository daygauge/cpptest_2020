#pragma once
#include <iostream>
#include <malloc.h>
#include <cassert>



typedef struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}BinaryTreeNode;


BinaryTreeNode* Create(BinaryTreeNode ls);//初始化
BinaryTreeNode* BinaryTreeDestory(int* a, int* aing);//根据数组前序构建二叉树
void BinaryTreeDestory(BinaryTreeNode** ls);//销毁二叉树
int BinaryTreeSize(BinaryTreeNode* ls);//二叉树节点个数
int BinaryTreeLeafSisze(BinaryTreeNode* ls);//二叉树叶子节点个数
int BinaryTreeLevelKSize(BinaryTreeNode* ls, int k);//二叉树第K层节点个数

void BinaryTreePrevOrder(BinaryTreeNode* ls);// 二叉树前序遍历 
void BinaryTreeInOrder(BinaryTreeNode* ls);// 二叉树中序遍历
void BinaryTreePostOrder(BinaryTreeNode* ls);// 二叉树后序遍历

typedef int lsdata;
typedef struct Heap
{
	int size;
	int capacity;
	lsdata* a;
}HP;

void hp_init(HP* ls);//初始化
void hp_destory(HP* ls);//销毁

void hp_push(HP* ls, lsdata a);//插入
void hp_up(lsdata* ls, int child);//向上调整
void hp_down(lsdata* ls, int size ,int child);//向下调整

void hp_pop(HP* ls);//删除堆顶
lsdata hp_top(HP* ls);//取堆顶数据
int hp_size(HP* ls);//堆数据个数;



