#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>
#define LSS
#ifndef LSS
typedef int STData;
typedef struct ss
{
    STData* a;
    int top;
    int capacity;
}ST;
void StacKInit(ST* sp);//初始化
void StacKDestroy(ST* sp);//销毁
void StackPrint(ST* sp);//打印
void StackPush(ST* ps, STData x);//入栈
void StackPop(ST* ps);//出栈
STData StackTop(ST* sp);//返回栈顶的值
int StackSize(ST* sp);//栈的元素个数
bool StackEmpty(ST* ps);//栈是否为空
#else
//typedef int QDataType;
//typedef struct ss
//{
//    struct ss* next;
//    QDataType a;
//}QNode;
//typedef struct Queue
//{
//    QNode* _front;
//    QNode* _rear;
//}Queue;
//void QueueInit(Queue* q);// 初始化队列 
//void QueuePush(Queue* q, QDataType data);// 队尾入队列 
//void QueuePop(Queue* q);// 队头出队列 
//QDataType QueueFront(Queue* q);// 获取队列头部元素 
//QDataType QueueBack(Queue* q);// 获取队列队尾元素 
//int QueueSize(Queue* q);// 获取队列中有效元素个数 
//int QueueEmpty(Queue* q);// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
//void QueueDestroy(Queue* q);// 销毁队列 
#endif // !LSS




//typedef struct {
//    int* AS;
//    int tset;
//
//    int n1;
//    int n2;
//} MyCircularQueue;
//
//MyCircularQueue* myCircularQueueCreate(int k) //初始化
//{
//    MyCircularQueue* Mycs = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    int* pa = (int*)malloc((k + 1) * sizeof(int));
//    Mycs->AS = pa;
//    Mycs->tset = k;
//    Mycs->n1 = 0;
//    Mycs->n2 = 0;
//
//    return Mycs;
//}
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) //插入元素
//{
//    if ((obj->n2 + 1) % (obj->tset + 1) == obj->n1)
//    {
//        return false;
//    }
//    obj->AS[obj->n2++] = value;
//    if (obj->n2 == obj->tset+1)
//        obj->n2 = 0;
//    return true;
//
//}
//bool myCircularQueueDeQueue(MyCircularQueue* obj)//删除元素
//{
//    if (obj->n1 == obj->n2)
//    {
//        return false;
//    }
//    obj->n1++;
//    if (obj->n1 == obj->tset+1)
//        obj->n1 = 0;
//    return true;
//}
//int myCircularQueueFront(MyCircularQueue* obj) //获取队首元素
//{
//    if (obj->n1 != obj->n2)
//    {
//        return obj->AS[obj->n1];
//    }
//    return -1;
//}
//int myCircularQueueRear(MyCircularQueue* obj) //获取队尾元素
//{
//    if (obj->n1 == obj->n2)
//        return -1;
//    if (obj->n2 == 0)
//        return obj->AS[obj->tset];
//    else
//        return obj->AS[obj->n2 - 1];
//}
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) //检测是否为空
//{
//    return obj->n1 == obj->n2;
//}
//bool myCircularQueueIsFull(MyCircularQueue* obj) //检测是否已满
//{
//
//    return (obj->n2 + 1) % (obj->tset + 1) == obj->n1;
//}
//void myCircularQueueFree(MyCircularQueue* obj) 
//{
//
//}
