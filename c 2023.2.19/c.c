#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


void SeqListInit(SeqList* ps)//初始化
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListPrint(SeqList* ps)//顺序列表打印
{
	int as = 0;
	while (as < ps->size)
	{
		printf("%d ", ps->a[as]);
		as++;
	}
	printf("\n");
		
}
void kr(SeqList* ps)//顺序表扩容
{
	if (ps->capacity == ps->size)
	{
		int lskai = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDateType* zjdz = (SLDateType*)realloc(ps->a, lskai * sizeof(SLDateType));
		if (zjdz != NULL)
		{
			ps->a = zjdz;
			ps->capacity = lskai ;
		}
	}
}
void SeqListPushBack(SeqList* ps, SLDateType x)//尾插
{
	SeqListInsert(ps, ps->size, x);
}
void SeqListPushFront(SeqList* ps, SLDateType x)//头插
{
	SeqListInsert(ps, 0, x);
}
void SeqListInsert(SeqList* ps, int pos, SLDateType x)// 顺序表在pos位置插入x
{
	assert(pos >= 0 && pos <= ps->size);
	kr(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListPopBack(SeqList* ps)//尾删
{
	SeqListErase(ps, ps->size-1);
}
void SeqListPopFront(SeqList* ps)//头删
{
	SeqListErase(ps, 0);
}
void SeqListErase(SeqList* ps, int pos)// 顺序表删除pos位置的值
{
	assert(pos >= 0 && pos <= ps->size);
	int as = pos;
	while (as<=ps->size)
	{
		ps->a[as] = ps->a[as + 1];
		as++;
	}
	ps->size--;
}
int SeqListFind(SeqList* ps, SLDateType x)// 顺序表查找
{
	for (int i = 0; i < ps->size; i++)
		if (ps->a[i] == x)
			return ps->a[i];
	return -1;
}

void SeqListDestroy(SeqList* ps)//销毁
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void xgai(SeqList* ps)
{
	int as = 0;
	int zi = 0;
	scanf("%d %d", &as, &zi);
	if (as <= ps->size)
		ps->a[as] = zi;
}