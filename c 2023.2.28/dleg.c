#define _CRT_SECURE_NO_WARNINGS 1

#include "dtueil.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* s1 = pq->head;
	while (s1)
	{
		QueueNode* s2 = s1->next;
		free(s1);
		s1 = s2;
	}
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* ss = (QueueNode*)malloc(sizeof(QueueNode));
	if (ss != NULL)
	{
		ss->data = x;
		ss->next = NULL;

		if (pq->head==NULL)
		{
			pq->head = pq->tail = ss;
		}
		else
		{
			pq->tail->next = ss;
			pq->tail = ss;
		}
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* ss = pq->head;
	pq->head = pq->head->next;
	free(ss);
	if (pq->head == NULL)
	{
		pq->head = pq->tail = NULL;
	}
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->tail->data;
}
int QueueSize(Queue* pq)
{
	QueueNode* ss = pq->head;
	int i = 0;
	while (ss)
	{
		ss = ss->next;
		i++;
	}
	return i;
}


void day(Queue* pq)
{
	assert(pq);
	QueueNode* ss = pq->head;
	while (ss)
	{
		printf("%d ", ss->data);
		ss = ss->next;
	}
	printf("\n");
}