#define _CRT_SECURE_NO_WARNINGS 1
#include "text.h"

void cs1()
{
	Z s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	printf("%d\n", StackTop(&s));
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPrint(&s);
	
	StackPop(&s);
	StackPop(&s);
	StackPrint(&s);

	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
	printf("%d\n", StackEmpty(&s));
}
int main()
{
	//cs1();
}