#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"



void SListPrint(SListNode* plist)
{
	if (plist)
	{
		while (plist->next)
		{
			printf("%d->", plist->data);
			plist = plist->next;
		}
		printf("%d->", plist->data);
	}
	printf("\n");
}
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* lsjg = (SListNode*)malloc(sizeof(SListNode));
	assert(lsjg);
	lsjg->data = x;
	lsjg->next = NULL;
    return lsjg;
	
}
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* ls =  BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = ls;
	}
	else
	{
		SListNode* lsbr = *pplist;
		while (lsbr->next)
		{
			lsbr = lsbr->next;
		}
		lsbr->next = ls;
	}
}
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* ls = BuySListNode(x);
	ls->next = *pplist;
	*pplist = ls;
}
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	SListNode* ls = *pplist;
	SListNode* ls1 = NULL;
	while (ls->next)
	{
		ls1 = ls;
		ls = ls->next;
	}
	free(ls);
	if (ls1)
		ls1->next = NULL;
	else
		*pplist = NULL;
}
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* ls = *pplist;
	if (ls->next)
	{
		ls = ls->next;
		free(*pplist);
		*pplist = ls;
	}
	else
	{
		free(*pplist);
		*pplist = NULL;
	}
}
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	while (plist->next&& plist->data != x)
	{
		plist = plist->next;
	}
	if (plist->data == x)
		return plist;
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	if (pos->next)
	{
		SListNode* ls = pos->next;
		if (ls->next)
		{
			pos->next = BuySListNode(x);
			pos->next->next = ls;
		}
	}
	else
	{
		SListPushBack(&pos,x);
	}
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SListNode* ls = pos->next;
		pos->next = ls->next;
		free(ls);
	}
}
void SListDestroy(SListNode** plist)
{
	assert(plist);
	SListNode* ls = *plist;
	while (ls)
	{
		SListNode* lss = ls->next;
		free(ls);
		ls = lss;
	}
	*plist = NULL;
}