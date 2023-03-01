#define _CRT_SECURE_NO_WARNINGS 1
#include "dtueil.h"

//void QueueInit(Queue* pq)//初始化
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
//void QueueDestroy(Queue* pq)//销毁
//{
//	assert(pq);
//	QueueNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		QueueNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//
//	pq->head = pq->tail = NULL;
//}
//
//void QueuePush(Queue* pq, QDataType x)//队尾入队列
//{
//	assert(pq);
//	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (pq->head == NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//
//void QueuePop(Queue* pq)//队头出队列
//{
//	assert(pq);
//	//if (pq->head == NULL)
//	//	return;
//	assert(!QueueEmpty(pq));
//
//	QueueNode* next = pq->head->next;
//	free(pq->head);
//	pq->head = next;
//	if (pq->head == NULL)
//	{
//		pq->tail = NULL;
//	}
//}
//
//QDataType QueueFront(Queue* pq)//返回队头
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)//返回队尾
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->tail->data;
//}
//
//int QueueSize(Queue* pq)//队列元素个数
//{
//	assert(pq);
//
//	int n = 0;
//	QueueNode* cur = pq->head;
//	while (cur)
//	{
//		++n;
//		cur = cur->next;
//	}
//
//	return n;
//}
//
//bool QueueEmpty(Queue* pq)//队列是否为空
//{
//	assert(pq);
//	return pq->head == NULL;
//}