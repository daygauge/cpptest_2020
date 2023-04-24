#define _CRT_SECURE_NO_WARNINGS 1
//#include <malloc.h>
//struct ls
//{
//	int a;
//	struct ls* b;
//};
//
//void lisics(struct ls* a , int b)
//{
//	struct ls* c = (struct ls*)malloc(sizeof(struct ls));
//	c->a = b;
//	c->b = NULL;
//	while (a->b)
//	{
//		a = a->b;
//	}
//	a->b = c;
//}
//void test01()
//{
//	struct ls a = { 5 };
//	lisics(&a, 20);
//	struct ls* ap = &a;
//	while (ap->b)
//	{
//		ap = ap->b;
//	}
//}
//int main()
//{
//	test01();
//	return 0;
//}

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

//void test01()
//{
//	int a = 10;
//	//printf("%d", a);
//	//std::cout << a << std::endl;
//
//}

//bool test01(char* a, char* b)
//{
//	int i = 0, j = 0;
//	while (a[i])
//	{
//		if (a[i] == b[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = 0;
//			i++;
//		}
//		if (!b[j])
//			return true;
//	}
//	return false;
//}
//int main()
//{
//	char a[10] = "aababcsss";
//	char b[4] = "aba";
//	if (test01(a, b))
//		cout << "相等" << endl;
//	else 
//		cout << "不相等" << endl;
//	return 0;
//}