#define _CRT_SECURE_NO_WARNINGS 1
#include "binlstest001.h"
//#include "btntestls.h"

//void test01()
//{
//	//int a[17] = { 'A','B','D','#','#' ,'E' ,'#' ,'H' ,'#' ,'#' ,'C' ,'F','#','#','G','#','#' };
//	int a[17] = { 'A','B','C','D','E' ,'F' ,'G','#','#','#' };
//
//	int als = 0;
//	BinaryTreeNode* ls = BinaryTreeDestory(a, &als);
//	BinaryTreePrevOrder(ls);
//	std::cout << std::endl;
//	std::cout << BinaryTreeSize(ls) << std::endl;
//	std::cout << BinaryTreeLeafSisze(ls)<< std::endl;
//	std::cout << BinaryTreeLevelKSize(ls,2) << std::endl;
//	BinaryTreeDestory(&ls);
//}
//void test02()
//{
//	Heap ls;
//	hp_init(&ls);
//
//	hp_push(&ls, 50);
//	hp_push(&ls, 30);
//	hp_push(&ls, 40);
//	hp_push(&ls, 120);
//	hp_push(&ls, 60);
//	hp_push(&ls, 70);
//	hp_push(&ls, 240);
//
//	//hp_destory(&ls);
//	hp_push(&ls, 90);
//	hp_pop(&ls);
//	for (int i = 0; i < ls.size; i++)
//	{
//		std::cout << ls.a[i] << " ";
//	}
//	std::cout << std::endl;
//	std::cout << hp_top(&ls) << std::endl;
//	std::cout << hp_size(&ls) << std::endl;
//}

void lst(int * a,int h,int k)
{
	assert(a);
	//创建堆
	int* al = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k ;i++)//写入起始数据
	{
		al[i] = a[i];
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)//通过向下调整算法调整为小堆
	{
		hp_down(al, k, i);
	}

	for (int i = k; i < h; i++)//用剩下h-k个数进行比较
	{
		if (a[i] > al[0])//大于堆头元素则替换，并重新向下调整
		{
			al[0] = a[i];
			hp_down(al, k, 0);//向下调整算法
		}
	}

	for (int i = 0; i < k; i++)//打印
	{
		std::cout << al[i] << " ";
	}
}
void test03()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int als = sizeof(a) / sizeof(a[0]);
	//lst(a, als, 10);
	HP ls;
	hp_init(&ls);
	for (int i = 0; i < als; i++)
	{
		hp_push(&ls, a[i]);
	}
	int i = ls.size;
	while (--i >= 0)
	{
		std::cout << ls.a[i] << " ";
	}
	hp_sort(&ls);
	printf("\n");
	i = ls.size;
	while (--i >= 0)
	{
		std::cout << ls.a[i] << " ";
	}
	//int a[17] = { 1,2,0,5,0,0,6,7,7,0,0,0,2,0,0 };
	//int  p = 0;
	//BTNode* ls = CreatBinaryTree(a, &p);
	//printfbtn(ls);
	//levelOrder(ls);
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}