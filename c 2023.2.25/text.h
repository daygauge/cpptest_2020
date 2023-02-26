#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct zan
{
	int* a;
	int top;
	int capacity;
}Z;

//初始化
void StackInit(Z* ps);

//销毁
void StackDestroy(Z* ps);

//打印
void StackPrint(Z* ps);

//入栈
void StackPush(Z* ps, int x);

//出栈
void StackPop(Z* ps);

//返回栈顶元素
int StackTop(Z* ps);

//返回栈的大小
int StackSize(Z* ps);

//栈是否为空
bool StackEmpty(Z* ps);