#define _CRT_SECURE_NO_WARNINGS 1
#include "binlstest001.h"

void swap(lsdata& a, lsdata& b)
{
	lsdata t = a;
	a = b;
	b = t;
}

void hp_init(HP* ls)//初始化
{
	assert(ls);
	ls->capacity = ls->size = 0;
	ls->a = NULL;
}

void hp_destory(HP* ls)//销毁
{
	assert(ls);
	assert(ls->a);
	free(ls->a);
	hp_init(ls);
}

void hp_up(lsdata* ls, int child)//向上调整
{
	assert(ls);
	int chlidls = (child - 1) / 2;//获取父节点
	while (child > 0)
	{
		if (ls[child] < ls[chlidls])//小堆 交换父子节点
		{
			swap(ls[child], ls[chlidls]);
			child = chlidls;
			chlidls = (chlidls - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void hp_push(HP* ls, lsdata a)//插入
{
	assert(ls);

	if (ls->capacity == ls->size)//如果容量已满则扩容
	{
		int capacityls = ls->capacity == 0 ? ls->capacity = 4 : ls->capacity *= 2;
		lsdata* csl = (lsdata*)realloc(ls->a, sizeof(lsdata) * capacityls);
		if (csl == NULL)
			exit(-1);

		ls->a = csl;
		ls->capacity = capacityls;
	}
	ls->a[ls->size++] = a;
	hp_up(ls->a, ls->size - 1);
}
void hp_down(lsdata* ls, int size, int child)//向下调整
{
	assert(ls);
	int childls = 2 * child + 1;
	while (childls < size)
	{
		if (childls + 1 < size && ls[childls+1] < ls[childls])//小堆 如果右节点比左节点小，则往右节点替换
		{
			childls++;
		}

		if (ls[child] > ls[childls])
		{
			swap(ls[childls], ls[child]);
			child = childls;
			childls = 2 * child + 1;
		}
		else
		{
			break;
		}
	}
}
void hp_pop(HP* ls)//删除堆顶
{
	assert(ls && ls->a);
	swap(ls->a[0], ls->a[ls->size - 1]);
	ls->size--;
	hp_down(ls->a, ls->size, 0);
}

lsdata hp_top(HP* ls)//取堆顶数据
{
	return ls->a[0];
}

int hp_size(HP* ls)//堆数据个数
{
	return ls->size;
}