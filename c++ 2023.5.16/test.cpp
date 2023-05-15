#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <malloc.h>

//typedef struct ls
//{
//	int a;
//	ls* xian;
//	ls* ho;
//}ls;
////void qianls(int a)
////{
////	cout<<
////}
//void printls(ls* s)
//{
//	if (s != NULL)
//	{
//		printls(s->ho);
//		cout << s->a << " ";
//		printls(s->xian);
//	}
//}
//void test01()
//{
//	ls n1 = { 1,NULL,NULL };
//
//	ls* n2 = (ls*)malloc(sizeof(ls));
//	n2->a = 2;
//	n2->ho = n2->xian = NULL;
//	ls* n3 = new ls{ 3,NULL,NULL };
//	ls* n4 = new ls{ 4,NULL,NULL };
//	ls* n5 = new ls{ 5,NULL,NULL };
//	ls* n6 = new ls{ 6,NULL,NULL };
//
//	n1.ho = n2;
//	n1.xian = n3;
//	n1.ho->ho = n4;
//	n1.ho->xian = n5;
//	n1.xian->ho = n6;
//	//   1
//	//2   3 
////   4 5 6
//	printls(&n1);
//}
////int main()
////{
////	test01();
////	return 0;
////}


typedef struct test
{
	int ls;
	test* n1, * n2;
	int s1, s2;
}test;
test* testp()
{
	test* t1 = new test{ 1,NULL,NULL,0,0 };
	test* t2 = new test{ 2,NULL,NULL,0,0 };
	test* t3 = new test{ 3,NULL,NULL,0,0 };
	test* t4 = new test{ 4,NULL,NULL,0,0 };
	test* t5 = new test{ 5,NULL,NULL,0,0 };
	test* t6 = new test{ 6,NULL,NULL,0,0 };

	t1->n1 = t2;
	t2->n1 = t3;
	t2->n2 = t4;
	t1->n2 = t5;
	t5->n2 = t6;
	return t1;
}
//test* pre = NULL;
//void zxu(test* ls)
//{
//	if (ls->ls == 6)
//		cout << pre->ls << endl;
//	else
//		pre = ls;
//}
//void printf01if(test* l1)
//{
//	if (l1->n1 == NULL)
//	{
//		l1->n1 = pre;
//		l1->s1 = 1;
//	}
//	pre = l1;
//}
//void printf02if(test* ls)
//{
//	test* l1 = ls;
//	while (l1->n1 != l1 && l1->n1 != NULL);
//	{
//		l1 = l1->n1;
//	}
//	while (l1->n2 != NULL)
//	{
//		l1 = l1->n2;
//	}
//}

//void visit(test* ls)
//{
//	if (ls->n1 == NULL)
//	{
//		ls->n1 = pre;
//		ls->s1 = 1;
//	}
//	if (pre != NULL && pre->n2 == NULL)
//	{
//		pre->n2 = ls;
//		pre->s2 = 1;
//	}
//	pre = ls;
//}
//test* pre = NULL;
void printflstest01(test* ls)
{
	test* ls1 = ls;
	while (!ls1->s1)
	{
		ls1 = ls1->n1;
	}
	while (ls1 != NULL)
	{
		cout << ls1->ls << " ";
		ls1 = ls1->n2;
	}
}
//void printftest(test* ls,test* &pre)//中序
//{
//	if(ls!=NULL)
//	{
//
//	    printftest(ls->n1,pre);
//		if (ls->n1 == NULL)
//		{
//			ls->n1 = pre;
//			ls->s1 = 1;
//		}
//		if (pre != NULL && pre->n2 == NULL)
//		{
//			pre->n2 = ls;
//			pre->s2 = 1;
//		}
//		pre = ls;
//		printftest(ls->n2,pre);
//	}
//}
void printftest(test* ls, test*& pre)//先序
{
	if (ls != NULL)
	{
		if (ls->n1 == NULL)
		{
			ls->n1 = pre;
			ls->s1 = 1;
		}
		if (pre != NULL && pre->n2 == NULL)
		{
			pre->n2 = ls;
			pre->s2 = 1;
		}
		pre = ls;
		if (ls->s1 == 0)
		    printftest(ls->n1, pre);
		printftest(ls->n2, pre);
	}
}
void yintestls(test* ls)
{
	test* pre = NULL;
	if (ls != NULL)
	{
		printftest(ls,pre);
		if (pre->n2 == NULL)
			pre->s2 = 1;
	}
}

//test* Firs(test* ls)//中序后继遍历
//{
//	while (ls->s1 == 0)
//		ls = ls->n1;
//	return ls;
//}
//test* Nex(test* ls)
//{
//	if (ls->n2 == 0)
//		return Firs(ls->n2);
//	return ls->n2;
//}
//void Iorder(test* T)
//{
//	for (test* ls = Firs(T); ls != NULL; ls = Nex(ls))
//	{
//		cout << ls->ls << " ";
//	}
//}

test* Firs(test* ls)//中续前驱遍历
{
	while (ls->s2 == 0)
		ls = ls->n2;
	return ls;
}
test* Nex(test* ls)
{
	if (ls->s1 == 0)
		return Firs(ls->n1);
	return ls->n1;
}
void Iorder(test* T)
{
	for (test* ls = Firs(T); ls != NULL; ls = Nex(ls))
	{
		cout << ls->ls << " ";
	}
}

test* rearls(test* ls)//先序后继遍历
{
	if (ls->s1 == 0)
		return ls->n1;
	return ls->n2;
}
void first(test* T)
{
	for (test* p = T; p != NULL; p = rearls(p))
	{
		cout << p->ls << " ";
	}
}
void test001()
{
	test* t01 = testp();
	yintestls(t01);//线索化
	//printflstest01(t01);
	//Iorder(t01);
	first(t01);
}
int main()
{
	test001();
	return 0;
}