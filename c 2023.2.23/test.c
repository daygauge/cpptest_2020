#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"


ListNode* ListCreate()// 创建返回链表的头结点.
{
	ListNode* xtsr = (ListNode*)malloc(sizeof(ListNode));
	if (xtsr == NULL)
		return;
	xtsr->_next = xtsr;
	xtsr->_prev = xtsr;
	return xtsr;
}

void ListPrint(ListNode* pHead)// 双向链表打印
{
	assert(pHead);
	ListNode* tstls = pHead->_next;
	while (tstls!=pHead)
	{
		printf("%d ", tstls->_data);
		tstls = tstls->_next;
	}
	printf("\n");
}

ListNode* ccskfar(int x)
{
	ListNode* krsc = (ListNode*)malloc(sizeof(ListNode));
	if (krsc == NULL)
		return;
	krsc->_data = x;
	return krsc;
}
void ListPushBack(ListNode* pHead, LTDataType x)/// 双向链表尾插
{
	assert(pHead);
	ListInsert(pHead, x);
	//ListNode* pisds = pHead->_prev;
	//ListNode* crds = ccskfar(x);
	//pisds->_next = crds;
	//crds->_prev = pisds;
	//crds->_next = pHead;
	//pHead->_prev = crds;
}
void ListPopBack(ListNode* pHead)// 双向链表尾删
{
	assert(pHead && pHead->_next != pHead);
	ListErase(pHead->_prev);
	//ListNode* wei = pHead->_prev->_prev;
	//free(wei->_next);
	//wei->_next = pHead;
	//pHead->_prev = wei;
}
void ListPushFront(ListNode* pHead, LTDataType x)// 双向链表头插
{
	assert(pHead);
	ListInsert(pHead->_next, x);
	//ListNode* nedxign = ccskfar(x);
	//ListNode* nedes = pHead->_next;

	//pHead->_next = nedxign;
	//nedxign->_prev = pHead;
	//nedxign->_next = nedes;
	//nedes->_prev = nedxign;
}

void ListPopFront(ListNode* pHead)// 双向链表头删
{
	assert(pHead);
	ListErase(pHead->_next);
	//ListNode* nesdx = pHead->_next->_next;
	//free(pHead->_next);
	//pHead->_next = nesdx;
	//nesdx->_prev = pHead;
}

ListNode* ListFind(ListNode* pHead, LTDataType x)// 双向链表查找
{
	assert(pHead);
	ListNode* ndex = pHead->_next;
	while (ndex!= pHead)
	{
		if (ndex->_data == x)
			return ndex;
		ndex = ndex->_next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)// 双向链表在pos的前面进行插入
{
	assert(pos);
	ListNode* nextcr =  ccskfar(x);
	ListNode* prevp = pos->_prev;
	prevp->_next = nextcr;
	nextcr->_prev = prevp;
	nextcr->_next = pos;
	pos->_prev = nextcr;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posprev = pos->_prev;
	ListNode* posnext = pos->_next;
	free(pos);
	posprev->_next = posnext;
	posnext->_prev = posprev;
}

void ListDestory(ListNode* pHead)// 双向链表销毁
{
	assert(pHead);
	ListNode* Des = pHead->_next;
	while (Des != pHead)
	{
		Des = Des->_next;
		free(Des->_prev);
	}
	pHead->_data = pHead;
	pHead->_prev = pHead;
}