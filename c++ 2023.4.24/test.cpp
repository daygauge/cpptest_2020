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

//void s(int** a, int** b)
//{
//	int* as;
//	as = *a; *a = *b; *b = as;
//}
//int main()
//{
//	int a = 1, b = 2;
//	int* ap = &a;
//	int* bp = &b;
//	s(&ap, &bp);
//	cout << *ap << *bp << endl;
//	return 0;
//}

struct ls
{

};
class cs
{
public:
	cs(int c)
	{
		this->c = c;
	}
	void operator==(int a)
	{
		this->c = a;
	}
	int c = 0;
};
void s()
{
	cs csls = 10;
	cout << csls.c << endl;
	//csls == 60;
	csls.operator==(60);
	cout << csls.c << endl;

}
void test001(int n)
{
	cout << n << " ";
}
void test01(string n1,vector<int> n2)
{
	//for_each(n2.begin(), n2.end(), test001);
	for (vector<int>::iterator it = n2.begin(); it != n2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << n1 << endl;
}
void test02(vector<int> &ls)
{
	cout << ls.size() << endl;
}
int main()
{
	//s();
	string ls1 = "abcd";
	vector<int> ls;
	ls.push_back(10);
	ls.push_back(20);
	ls.push_back(30);
	//test01(ls1, ls);
	test02(ls);
	return 0;
}