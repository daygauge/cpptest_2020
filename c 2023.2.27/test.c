#define _CRT_SECURE_NO_WARNINGS 1
//#include "test.h"
#include "ls.h"

//int main()
//{
//	MyCircularQueue* ss = myCircularQueueCreate(3);
//	printf("%d\n", myCircularQueueEnQueue(ss, 1));
//	printf("%d\n", myCircularQueueEnQueue(ss, 2));
//	printf("%d\n", myCircularQueueEnQueue(ss, 3));
//	printf("%d\n", myCircularQueueEnQueue(ss, 4));
//	printf("%d\n", myCircularQueueRear(ss));
//	printf("%d\n", myCircularQueueIsFull(ss));
//	printf("%d\n", myCircularQueueDeQueue(ss));
//	printf("%d\n", myCircularQueueDeQueue(ss));
//	printf("%d\n", myCircularQueueRear(ss));
//
//	return 0;
//}

//typedef struct {
//    ST* z1;
//    ST* z2;
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//    ST* z1s = (ST*)malloc(sizeof(ST));
//    ST* z2s = (ST*)malloc(sizeof(ST));
//    StacKInit(z1s);
//    StacKInit(z2s);
//    MyQueue* z = (MyQueue*)malloc(sizeof(MyQueue));
//    z->z1 = z1s;
//    z->z2 = z2s;
//    return z;
//}
//void myQueuePush(MyQueue* obj, int x)
//{
//    StackPush(obj->z1, x);
//}
//int myQueuePop(MyQueue* obj)
//{
//    if (StackEmpty(obj->z2))
//    {
//        while (!StackEmpty(obj->z1))
//        {
//            StackPush(obj->z2, StackTop(obj->z1));
//            StackPop(obj->z1);
//        }
//    }
//    int s = StackTop(obj->z2);
//    StackPop(obj->z2);
//    return s;
//}
//int myQueuePeek(MyQueue* obj)
//{
//    if (StackEmpty(obj->z2))
//    {
//        while (StackEmpty(obj->z1) == 0)
//        {
//            StackPush(obj->z2, StackTop(obj->z1));
//            StackPop(obj->z1);
//        }
//    }
//    return StackTop(obj->z2);
//}
//bool myQueueEmpty(MyQueue* obj)
//{
//    return StackEmpty(obj->z1) && StackEmpty(obj->z2);
//}
//void cs2()
//{
//    MyQueue* zan = myQueueCreate();
//    myQueuePush(zan, 1);
//    myQueuePush(zan, 2);
//    printf("%d\n", myQueuePeek(zan));
//    printf("%d\n", myQueuePop(zan));
//    printf("%d\n", myQueueEmpty(zan));
//}

//void cs3()
//{
//    Queue ssd;
//    QueueInit(&ssd);
//    QueuePush(&ssd, 1);
//    QueuePush(&ssd, 2);
//    QueuePush(&ssd, 3);
//    QueuePush(&ssd, 4);
//    printf("%d\n", QueueFront(&ssd));
//    printf("%d\n", QueueBack(&ssd));
//    printf("%d\n", QueueSize(&ssd));
//    printf("%d\n", QueueEmpty(&ssd));
//
//
//    printf("%d\n", QueueFront(&ssd));
//    QueuePop(&ssd);
//    printf("%d\n", QueueFront(&ssd));
//    QueuePop(&ssd);
//    printf("%d\n", QueueFront(&ssd));
//    QueuePop(&ssd);
//    printf("%d\n", QueueFront(&ssd));
//    QueueDestroy(&ssd);
//
//    return;
//}

//typedef struct {
//    Queue* d1;
//    Queue* d2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//    MyStack* ss = (MyStack*)malloc(sizeof(MyStack));
//    Queue ds1;
//    Queue ds2;
//    QueueInit(&ds1);
//    QueueInit(&ds2);
//    ss->d1 = &ds1;
//    ss->d2 = &ds2;
//    return ss;
//}
//
//void myStackPush(MyStack* obj, int x) {
//    QueuePush(obj->d1, x);
//}
//
//int myStackPop(MyStack* obj) {
//    while (QueueSize(obj->d1) != 1)
//    {
//        QueuePush(obj->d2, QueueFront(obj->d1));
//        QueuePop(obj->d1);
//    }
//    QDataType ss = QueueFront(obj->d1);
//    QueuePop(obj->d1);
//    while (QueueSize(obj->d2))
//    {
//        QueuePush(obj->d1, QueueFront(obj->d2));
//        QueuePop(obj->d2);
//    }
//    return ss;
//}
//
//int myStackTop(MyStack* obj) {
//    while (QueueSize(obj->d1) != 1)
//    {
//        QueuePush(obj->d2, QueueFront(obj->d1));
//        QueuePop(obj->d1);
//    }
//    QDataType ss = QueueFront(obj->d1);
//    QueuePush(obj->d2, QueueFront(obj->d1));
//    QueuePop(obj->d1);
//    while (QueueSize(obj->d2))
//    {
//        QueuePush(obj->d1, QueueFront(obj->d2));
//        QueuePop(obj->d2);
//    }
//    return ss;
//}
//
//bool myStackEmpty(MyStack* obj) {
//    return QueueEmpty(obj->d1) ? true : false;
//}
//
//void myStackFree(MyStack* obj) {
//    QueueDestroy(obj->d1);
//    QueueDestroy(obj->d2);
//}
//
//void cs4()
//{
//    MyStack* ss = myStackCreate();
//    myStackPush(ss, 1);
//    myStackPush(ss, 2);
//    printf("%d\n ", myStackTop(&ss));
//    printf("%d\n", myStackPop(ss));
//    printf("%d\n", myStackEmpty(ss));
//}
void csss()
{
    Queue ss;
    QueueInit(&ss);
    QueuePush(&ss, 1);
    QueuePush(&ss, 2);
    QueuePush(&ss, 3);
    QueuePush(&ss, 4);
    QueuePop(&ss);
    QueuePop(&ss);
    QueuePop(&ss);
    QueuePop(&ss);


}
int main()
{
    //cs2();
    //cs3();
    csss();
    //cs4();

    return 0;
}