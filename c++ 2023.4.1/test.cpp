#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include "test.hpp"

void test01()
{
	MyArrar <int>cs(10);
	cs.Tailinsertion(3);
	cs.Tailinsertion(4);
	cs.Tailinsertion(5);
	cs.Tailinsertion(6);
	cs.Tailinsertion(7);
	cs.Tailinsertion(8);
	cs.Tailinsertion(9);
	cs.gainnumbervolume();
}
void day(MyArrar <int>& a)
{
	for (int i = 0; i < a.M_testszgs; i++)
	{
		cout << a[i]+1 << endl;
	}
}
void test02()
{
	MyArrar <int>cs1(5);
	for (int i = 0; i < cs1.M_testszdax ; i++)
	{
		cs1.Tailinsertion(i);
	}
	day(cs1);
}

//template<class T1 = int ,class T2 = string>
//class mysj
//{
//public:
//	mysj(T1 a , T2 b)
//	{
//		this->m_a = a;
//		this->m_b = b;
//	}
//	T1 m_a;
//	T2 m_b;
//};

class mysj
{
public:
	mysj()
	{

	}
	mysj(int a, string b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	int m_a;
	string m_b;
};

void test03s(MyArrar <mysj>& a)
{
	for (int i = 0; i < a.M_testszgs; i++)
	{
		cout << a[i].m_a<< " " << a[i].m_b << endl;
	}
}
void test03()
{
	mysj test1(20, "张三");
	mysj test2(20, "李四");
	mysj test3(20, "王五");
    
	MyArrar <mysj>testcs(10);
	testcs.Tailinsertion(test1);
	testcs.Tailinsertion(test2);
	testcs.Tailinsertion(test3);
	test03s(testcs);
	testcs.gainnumbervolume();
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}