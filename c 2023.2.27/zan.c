#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


#ifndef LSS
void StacKInit(ST* sp)//初始化
{
	assert(sp);
	sp->a = NULL;
	sp->capacity = 0;
	sp->top = 0;
}
void StacKDestroy(ST* sp)//销毁
{
	assert(sp);
	if (sp->a)
		free(sp->a);
	sp->a = NULL;
	sp->capacity = 0;
	sp->top = 0;
}
void StackPrint(ST* sp)//打印
{
	assert(sp);
	int i = 0;
	while (i < sp->top)
	{
		printf("%d ", sp->a[i]);
		i++;
	}
	printf("\n");
}
void StackPush(ST* ps, STData x)//入栈
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int as = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STData* s = (STData*)realloc(ps->a, as * sizeof(STData));
		if (s == NULL)
			return;
		ps->a = s;
		ps->capacity = as;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)//出栈
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
STData StackTop(ST* sp)//返回栈顶的值
{
	assert(sp);
	return sp->a[sp->top - 1];
}
int StackSize(ST* sp)//栈的元素个数
{
	assert(sp);
	return sp->top;
}
bool StackEmpty(ST* ps)//栈是否为空
{
	assert(ps);
	return ps->top == 0;
}
#endif

