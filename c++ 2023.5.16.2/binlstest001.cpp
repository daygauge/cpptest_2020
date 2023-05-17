#define _CRT_SECURE_NO_WARNINGS 1
#include "binlstest001.h"

BinaryTreeNode* Create(int a)//初始化
{
    BinaryTreeNode* ls = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (ls != NULL)
    {
        ls->data = a;
        ls->left = ls->right = NULL;
        return ls;
    }
    return NULL;
}

BinaryTreeNode* BinaryTreeDestory(int* a, int* aint)//根据数组前序构建二叉树
{
    if (a[*aint] == '#')
        return NULL;

    BinaryTreeNode* cls = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (cls != NULL)
    {
        cls->data = a[*aint];
        cls->left = cls->right = NULL;

        (*aint)++;
        cls->left = BinaryTreeDestory(a, aint);
        (*aint)++;
        cls->right = BinaryTreeDestory(a, aint);
        return cls;
    }
    return 0;

}

void BinaryTreeDestory(BinaryTreeNode** ls)//销毁二叉树
{
    if (*ls != NULL)
    {
        BinaryTreeDestory(&((*ls)->left));
        BinaryTreeDestory(&((*ls)->right));
        free(*ls);
        *ls = NULL;
    }
}

int BinaryTreeSize(BinaryTreeNode* ls)//二叉树节点个数
{
    if (ls == NULL)
    {
        return 0;
    }
    return BinaryTreeSize(ls->left) + BinaryTreeSize(ls->right) + 1;
}

int BinaryTreeLeafSisze(BinaryTreeNode* ls)//二叉树叶子节点个数
{
    if (ls == NULL)
        return 0;
    if (ls->left == NULL && ls->right == NULL)
        return 1;

    return BinaryTreeLeafSisze(ls->left) + BinaryTreeLeafSisze(ls->right);
}

int BinaryTreeLevelKSize(BinaryTreeNode* ls, int k)//二叉树第K层节点个数
{
    if (ls == NULL)
        return 0;
    if (k == 1)
        return 1;
    return BinaryTreeLevelKSize(ls->left, k - 1) + BinaryTreeLevelKSize(ls->right, k - 1);
}

void BinaryTreePrevOrder(BinaryTreeNode* ls)// 二叉树前序遍历 
{
    if (ls != NULL)
    {
        printf("%c ", ls->data);
        BinaryTreePrevOrder(ls->left);
        BinaryTreePrevOrder(ls->right);
    }
}

void BinaryTreeInOrder(BinaryTreeNode* ls)// 二叉树中序遍历
{
    if (ls != NULL)
    {
        BinaryTreePrevOrder(ls->left);
        printf("%c ", ls->data);
        BinaryTreePrevOrder(ls->right);
    }
}

void BinaryTreePostOrder(BinaryTreeNode* ls)// 二叉树后序遍历
{
    if (ls != NULL)
    {
        BinaryTreePrevOrder(ls->left);
        BinaryTreePrevOrder(ls->right);
        printf("%c ", ls->data);
    }
}