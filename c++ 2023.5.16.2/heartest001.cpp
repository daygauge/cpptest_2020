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

void hp_up(lsdata* ls, int child)//向上调整,ls为堆数组，child为数组最大下标
{
	assert(ls);
	int chlidls = (child - 1) / 2;//获取父节点
	while (child > 0)
	{
		if (ls[child] < ls[chlidls])//小堆 新节点是否小于父节点
		{
			swap(ls[child], ls[chlidls]);//交换两个节点中的1值
			child = chlidls;//更新新节点
			chlidls = (chlidls - 1) / 2;//更新父节点
		}
		else
		{
			break;
		}
	}
}

void hp_down(lsdata* ls, int size, int child)//向下调整,ls为堆数组,size为最大索引，child为开始索引
{
	assert(ls);
	int childls = 2 * child + 1;//获取子节点
	while (childls < size)//子节点下标 < 最大节点下标则循环
	{
		if (childls + 1 < size && ls[childls + 1] < ls[childls])//小堆 如果右节点比左节点小，则往右节点替换
		{
			childls++;//通过下标++获取到右节点
		}

		if (ls[child] > ls[childls])//小堆，父节点大于子节点情况
		{
			swap(ls[childls], ls[child]);//交换父节点和子节点
			child = childls;//父节点更新到子节点位置
			childls = 2 * child + 1;//子节点更新
		}
		else//找到合适位置就退出
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

void hp_pop(HP* ls)//删除堆顶
{
	assert(ls && ls->a);
	swap(ls->a[0], ls->a[ls->size - 1]);//交换第一个元素和最后一个元素
	ls->size--;//元素个数--
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
void hp_down1(lsdata* ls, int size, int child)
{
	int z = child * 2 + 1;//获取子节点
	while (z < size)
	{
		if (z + 1 < size && ls[z+1] < ls[z])//大堆 替换左右节点较大的值
		{
			z++;
		}

		if (ls[z] < ls[child])//大堆 子节点大于父节点则替换
		{
			swap(ls[z], ls[child]);
			//更新父子节点
			child = z;
			z = child * 2 + 1;
		}
		else
		{
			break;
		}

	}
}
void hp_sort(HP* ls)//堆排序
{
	int n = ls->size;
	while (n > 0)
	{
		swap(ls->a[0], ls->a[n-1]);//交换第一个和最后一个值
		n--;//最后一个值看做从堆中移出
		hp_down1(ls->a, n, 0);
	}
}