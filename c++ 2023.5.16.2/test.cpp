#define _CRT_SECURE_NO_WARNINGS 1
#include "binlstest001.h"


void test01()
{
	int a[17] = { 'A','B','D','#','#' ,'E' ,'#' ,'H' ,'#' ,'#' ,'C' ,'F','#','#','G','#','#' };
	int als = 0;
	BinaryTreeNode* ls = BinaryTreeDestory(a, &als);
	BinaryTreePrevOrder(ls);
	std::cout << std::endl;
	std::cout << BinaryTreeSize(ls) << std::endl;
	std::cout << BinaryTreeLeafSisze(ls)<< std::endl;
	std::cout << BinaryTreeLevelKSize(ls,2) << std::endl;
	BinaryTreeDestory(&ls);
}
void test02()
{
	Heap ls;
	hp_init(&ls);

	hp_push(&ls, 50);
	hp_push(&ls, 30);
	hp_push(&ls, 40);
	hp_push(&ls, 120);
	hp_push(&ls, 60);
	hp_push(&ls, 70);
	hp_push(&ls, 240);

	//hp_destory(&ls);
	hp_push(&ls, 90);
	hp_pop(&ls);
	for (int i = 0; i < ls.size; i++)
	{
		std::cout << ls.a[i] << " ";
	}
	std::cout << std::endl;
	std::cout << hp_top(&ls) << std::endl;
	std::cout << hp_size(&ls) << std::endl;

	
	
}
int main()
{
	//test01();
	test02();
	return 0;
}