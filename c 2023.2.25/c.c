#define _CRT_SECURE_NO_WARNINGS 1
#include "text.h"


void StackInit(Z* ps)//初始化
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestroy(Z* ps)//销毁
{
	assert(ps);
	free(ps);
	ps = NULL;
}
void StackPrint(Z* ps)//打印
{
	assert(ps);
	int i = 0;
	while (ps->top != i)
	{
		printf("%d ", ps->a[i]);
		i++;
	}
	printf("\n");
}
void StackPush(Z* ps, int x)//入栈
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		ps->capacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		int* s = (int*)realloc(ps->a, ps->capacity*sizeof(int));
		if (s == NULL)
		{
			exit(-1);
		}
		ps->a = s;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Z* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
int StackTop(Z* ps)
{
	return ps->a[--ps->top];
}
int StackSize(Z* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(Z* ps)
{
	assert(ps);
	return ps->top==0;
}