#define _CRT_SECURE_NO_WARNINGS 1
#include "btntestls.h"


//创建一个节点
BTNode* BuyNode(binlst a)
{
	BTNode* ls = (BTNode*)malloc(sizeof(BTNode));//堆区开辟节点
	assert(ls);

	//初始化
	ls->data = a;
	ls->left = ls->right = NULL;
	return ls;
}

BTNode* CreatBinaryTree(binlst* ls, int* lp)//根据数组构建二叉树
{
	//采用先序遍历思想
	if (ls[*lp] == 0)//数组为0则代表二叉树是空节点
	{
		(*lp)++;
		return NULL;
	}
	BTNode* btnls = BuyNode(ls[*lp]);//堆区开辟节点
	(*lp)++;//数组值使用后,位置++
	btnls->left = CreatBinaryTree(ls, lp);
	btnls->right = CreatBinaryTree(ls, lp);
	return btnls;
}

void printfbtn(BTNode* ls)//二叉树前序遍历
{
	if (ls == NULL)
	{
		//std::cout << '#' << " ";
		return;
	}
	std::cout << ls->data << " ";
	printfbtn(ls->left);
	printfbtn(ls->right);

}
void levelOrder(BTNode* ls)//二叉树层序遍历
{
	std::queue<BTNode*> q;//创建队列
	if (ls != NULL)
	{
		q.push(ls);//写入头节点
	}

	while (!q.empty())
	{
		BTNode* lscs = q.front();
		std::cout << lscs->data << " ";//返回队列第一个元素的值
		q.pop();
		if (lscs->left != NULL)
			q.push(lscs->left);
		if (lscs->right != NULL)
			q.push(lscs->right);
	}
}
void btndestry(BTNode* ls)//二叉树销毁
{
    if(!ls)
		return;
	btndestry(ls->left);
	btndestry(ls->right);
	free(ls);//采用后序遍历方法，否则会找不到子节点
}