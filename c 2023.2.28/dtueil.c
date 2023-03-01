#include "dtueil.h"



void cs1()
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


}
void cs2()
{
	Queue ss;
	QueueInit(&ss);
	QueuePush(&ss, 1);
	QueuePush(&ss, 2);
	QueuePush(&ss, 3);
	QueuePush(&ss, 4);
	QueuePop(&ss);
	day(&ss);

	QueuePush(&ss, 4);
	QueuePush(&ss, 4);
	QueuePush(&ss, 4);
	QueuePush(&ss, 4);
	QueuePush(&ss, 4);
	QueuePush(&ss, 4);
	QueuePush(&ss, 4);
	day(&ss);

	QueuePop(&ss);
	day(&ss);
	QueuePop(&ss);
	day(&ss);
	QueuePop(&ss);
	day(&ss);
	QueuePop(&ss);
	day(&ss);
	QueuePop(&ss);
	day(&ss);
	QueuePop(&ss);
	day(&ss);
	QueuePop(&ss);
	day(&ss);
	QueuePop(&ss);
	day(&ss);
	QueuePop(&ss);
	day(&ss);
	QueuePop(&ss);
	day(&ss);
	QueuePop(&ss);
	day(&ss);
}

typedef struct {
	Queue* d1;
	Queue* d2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* ss = (MyStack*)malloc(sizeof(MyStack));
	Queue* d1s = (Queue*)malloc(sizeof(Queue));
	Queue* d2s = (Queue*)malloc(sizeof(Queue));
	QueueInit(d1s);
	QueueInit(d2s);
	ss->d1 = d1s;
	ss->d2 = d2s;
	return ss;
}

void myStackPush(MyStack* obj, int x) {
	QueuePush(obj->d1, x);
}

int myStackPop(MyStack* obj) {
	while (QueueSize(obj->d1) != 1)
	{
		QueuePush(obj->d2, QueueFront(obj->d1));
		QueuePop(obj->d1);
	}
	QDataType ss = QueueFront(obj->d1);
	QueuePop(obj->d1);
	while (QueueSize(obj->d2))
	{
		QueuePush(obj->d1, QueueFront(obj->d2));
		QueuePop(obj->d2);
	}
	return ss;
}

int myStackTop(MyStack* obj) {
	while (QueueSize(obj->d1) != 1)
	{
		QueuePush(obj->d2, QueueFront(obj->d1));
		QueuePop(obj->d1);
	}
	QDataType ss = QueueFront(obj->d1);
	QueuePush(obj->d2, QueueFront(obj->d1));
	QueuePop(obj->d1);
	while (QueueSize(obj->d2))
	{
		QueuePush(obj->d1, QueueFront(obj->d2));
		QueuePop(obj->d2);
	}
	return ss;
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(obj->d1) ? true : false;
}

void myStackFree(MyStack* obj) {
	QueueDestroy(obj->d1);
	QueueDestroy(obj->d2);
}
void cs3()
{
	MyStack* ss = myStackCreate();
	myStackPush(ss, 1);
	myStackPush(ss, 2);
	printf("%d",myStackTop(ss));
	printf("%d", myStackPop(ss));
	printf("%d", myStackEmpty(ss));
}

int main()
{
	//cs1();
	//cs2();
	cs3();
}