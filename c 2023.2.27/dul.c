#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void QueueInit(Queue* q)// 初始化队列 
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}
void QueuePush(Queue* q, QDataType data)// 队尾入队列 
{
	assert(q);
	QNode* ss = (QNode*)malloc(sizeof(QNode));
	if (ss != NULL)
	{
		ss->a = data;
		ss->next = NULL;
		if (q->_front == NULL)
		{
			q->_front = q->_rear = ss;
		}
		else
		{
			q->_rear->next = ss;
			q->_rear = ss;
		}
	}
}
void QueuePop(Queue* q)// 队头出队列 
{
	assert(q);
	assert(!QueueEmpty(q));
	QNode* next = q->_front->next;
	free(q->_front);
	q->_front = next;
	if (q->_front = NULL)
	{
		q->_rear = NULL;
	}
}
QDataType QueueFront(Queue* q)// 获取队列头部元素 
{
	assert(q->_front);
	return  q->_front->a;
}
QDataType QueueBack(Queue* q)// 获取队列队尾元素 
{
	assert(q->_rear);
	return q->_rear->a;
}
int QueueSize(Queue* q)// 获取队列中有效元素个数 
{
	int i = 0;
	QNode* ss = q->_front;
	while (ss)
	{
		ss = ss->next;
		i++;
	}
	return i;
}
int QueueEmpty(Queue* q)// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
{
	return q->_front == NULL;
}
void QueueDestroy(Queue* q)// 销毁队列 
{

	QNode* ss2 = q->_front->next;
	while (ss2)
	{
		QNode* ss1 = ss2->next;
		free(ss2);
		ss2 = ss1;
	}
	q->_front = q->_rear = NULL;
}