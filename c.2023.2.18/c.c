#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


void SeqListInit(SeqList* ps)
{
	int* ap = (int *)calloc(CSH, sizeof(int));
	ps->a = ap;
	ps->size = 0;
	ps->capacity = 3;
}

void SeqListPrint(SeqList* ps)
{
	for (int i = 0; i < ps->size;i++)
	{
		printf("%d: %d \n",i, *(ps->a + i));
	}
}

void sjbt()
{
	printf("1.尾部插入数据 ** 2.头部插入数据 ** 3.选择位置插入数据 ** 0,退出\n ");
}
void charsju(SeqList* ps)
{
	sjbt();
	int a = 0;
	int cr = 0;
	int wz = 0;
		scanf("%d", &a);
		switch (a) 
		{
		case 0:
			break;
		case 1:
			printf("\n插入:");
			scanf("%d", &cr);
			SeqListPushBack(ps, cr);
			break;
		case 2:
			printf("\n插入:");
			scanf("%d", &cr);
			SeqListPushFront(ps,cr);
			break;
		case 3:
			printf("位置:");
			scanf("%d", &wz);
			printf("\n插入:");
			scanf("%d", &cr);
			printf("\n");
			SeqListInsert(ps,wz,cr);
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
}
void kr(SeqList* ps)
{
	if (ps->capacity == ps->size)
	{
		int* zjdz = (int*)realloc(ps->a, ps->capacity + ZJ*sizeof(int));
		if (zjdz != NULL)
		{
			ps->a = zjdz;
			ps->capacity += ZJ;
			printf("扩容成功\n");
		}
	}
}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	kr(ps);
	ps->a[ps->size]= x;
	ps->size++;
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	kr(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	kr(ps);
	int asp = ps->size - pos;
	if (pos < ps->size)
	{
		for (int i = ps->size; i > asp; i--)
		{
			ps->a[i] = ps->a[i - 1];
		}
		ps->a[pos] = x;
		ps->size++;
	}
}

void dascbt()
{
	printf("1.尾部删除数据 ** 2.头部删除数据 ** 3.选择位置删除数据 ** 0,退出\n ");
}
void sancu(SeqList* ps)
{
	dascbt();
	int a = 0;
	int wz = 0;
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		break;
	case 1:
		SeqListPopBack(ps);
		break;
	case 2:
		SeqListPopFront(ps);
		break;
	case 3:
		printf("位置:");
		scanf("%d", &wz);
		SeqListErase(ps,wz);
		break;
	default:
		printf("输入错误\n");
		break;
	}
}
void SeqListPopBack(SeqList* ps)
{
	ps->a[ps->size - 1] = 0;
	ps->size--;
}
void SeqListPopFront(SeqList* ps)
{
	for (int i = 0; i<ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->a[ps->size - 1] = 0;
	ps->size--;
}
void SeqListErase(SeqList* ps, size_t pos)
{
	for (int i = pos-1; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->a[ps->size - 1] = 0;
	ps->size--;
}
int SeqListFind(SeqList* ps, SLDateType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			printf("序号:%d %d\n",i, ps->a[i]);
		}
	}
}

void SeqListDestroy(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	SeqListInit(ps);
}

void xgai(SeqList* ps)
{
	int as = 0;
	int zi = 0;
	printf("输入下标和修改后的值:");
	scanf("%d %d", &as,&zi);
	if (as <= ps->size)
	{
		ps->a[as] = zi;
	}
	else
	{
		printf("输入错误\n");
	}
}