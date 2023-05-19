#define _CRT_SECURE_NO_WARNINGS 1
//#include "binlstest001.h"
#include "btntestls.h"

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

void test03()
{
	int a[17] = { 1,2,0,5,0,0,6,7,7,0,0,0,2,0,0 };
	int  p = 0;
	BTNode* ls = CreatBinaryTree(a, &p);
	//printfbtn(ls);
	levelOrder(ls);

}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}