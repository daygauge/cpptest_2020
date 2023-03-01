#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	// size_t _size;
}Queue;

void QueueInit(Queue* pq);//初始化

void QueueDestroy(Queue* pq);//销毁
void QueuePush(Queue* pq, QDataType x);//队尾入队列
void QueuePop(Queue* pq);//队头出队列
QDataType QueueFront(Queue* pq);//返回队头
QDataType QueueBack(Queue* pq);//返回队尾
int QueueSize(Queue* pq);//队列元素个数
bool QueueEmpty(Queue* pq);//队列是否为空


void day(Queue* pq);



