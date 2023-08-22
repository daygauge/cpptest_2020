#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "test.h"


//int main()
//{
//	const int a = 10;
//
//	const int& a1 = a;
//	a1 = 100;
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int a1 = 10;
//	//int& b;
//	int& c = a;
//	&c = a1;
//}
//void test1(int& b)
//{
//	b = 100;
//}
//int main()
//{
//	int a = 10;
//	test1(a);
//	std::cout << a << std::endl;
//	return 0;
//}


//int& test(int a)
//{
//	int b = a;
//	return b;
//}
//int main()
//{
//	int& b = test(10);
//	std::cout << "hello world" << std::endl;
//	std::cout << b << std::endl;
//	return 0;
//}

//void test(int a)
//{
//	std::cout << a << std::endl;
//}
//void test(int a, int b)
//{
//	std::cout << (a + b) << std::endl;
//}
//void test(char a)
//{
//	std::cout << a << std::endl;
//}
//void test(double a)
//{
//	std::cout << a << std::endl;
//}
//int main()
//{
//	int a = 10;
//	test(a);
//	test(a, a);
//	test('a');
//	test(3.14);
//	return 0;
//}
#include <string>
using namespace std;
//class xshen
//{
//public:
//	string name;
//	int xh;
//	void names()
//	{
//		cout << name << endl;
//	}
//	void xhs()
//	{
//		cout << xh << endl;
//	}
//};
//
//int main()
//{
//	xshen s;
//	s.names();
//	s.xhs();
//
//
//	return 0;
//}


//class lfti
//{
//public:
//	void ckg (int a, int b, int c)
//	{
//		cang = a;
//		kuan = b;
//		gao = c;
//	}
//	int mianj()
//	{
//		return (cang + kuan)*6;
//	}
//	int tiji()
//	{
//		return cang * kuan * gao;
//	}
//private:
//	int cang;
//	int kuan;
//	int gao;
//
//};
//bool sfxd(lfti a, lfti b)
//{
//	return a.mianj() == b.mianj();
//}
//int main()
//{
//	lfti test1;
//	test1.ckg(10, 10, 10);
//	cout << test1.mianj() << endl;
//	cout << test1.tiji() << endl;
//	lfti test2;
//	test2.ckg(10, 67, 10);
//	cout << sfxd(test1, test2) << endl;
//	return 0;
//}

//class tes
//{
//public:
//	int as;
//	tes()
//	{
//		cout << "tes构造函数调用" << endl;
//	}
//	tes(int a)
//	{
//		cout << "tes有参构造函数调用" << endl;
//	}
//	tes(const tes & te)
//	{
//		as = te.as;
//		cout << "tes拷贝构造函数调用" << endl;
//	}
//
//	~tes()
//	{
//		cout << "tes析构函数调用" << endl;
//	}
//};
//tes test2()
//{
//	tes sd;
//	cout << &sd << endl;
//	return sd;
//}
//
//void test1()
//{
//	tes ss = test2();
//	cout << &ss << endl;
//
//}
//int main()
//{
//	test1();
//
//	return 0;
//}\

//class sji
//{
//public:
//	sji(string a)
//	{
//		sjxhao = a;
//	}
//	string sjxhao;
//	~sji()
//	{
//		cout << "sji析构调用" << endl;
//	}
//};
//
//class rendss
//{
//
//public:
//	rendss(string name, string ssj):neme(name),sj(ssj)
//	{
//
//	}
//	~rendss()
//	{
//		cout << "rend析构调用" << endl;
//	}
//	void hans()
//	{
//		cout << neme << sj.sjxhao << endl;
//	}
//
//	string neme;
//	sji sj;
//};
//void testss()
//{
//	rendss names("纳西妲","可爱");
//	names.hans();
//}
//int main()
//{
//	testss();
//
//	return 0;
//}

//class testls
//{
//public:
//	testls()
//	{
//		cout << "testls构造调用" << endl;
//	}
//	~testls()
//	{
//		cout << "testls析构调用" << endl;
//	}
//	int a;
//	static int a1;
//	void cs2()
//	{
//		cs();
//	}
//
//private:
//	static void cs()
//	{
//		a1 = 111;
//	}
//};
//int testls::a1 = 1000;
//void test1()
//{
//	testls ss;
//	ss.a = 100;
//	ss.a1 = 500;
//	ss.cs2();
//	cout << ss.a << endl << ss.a1 << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}
//class test
//{
//public:
//	int a;
//
//	static int b;
//	void ls()
//	{
//		int b = 0;
//	}
//};
//
//int main()
//{
//	cout<< sizeof(test) <<endl;
//	return 0;
//}

//class test
//{
//public:
//	test(int a)
//	{
//		this->a = a;
//	}
//	test& hs(test &p)
//	{
//		this->a += p.a;
//		return *this;
//	}
//	int a;
//};
//void test1()
//{
//	test ss(10);
//	cout << "a = " << ss.a << endl;
//
//	test ss1(10);
//	//ss1.hs(ss).hs(ss).hs(ss).hs(ss);
//	//ss1.hs(ss1.hs(ss1.hs(ss1.hs(ss))));
//	cout << "a = " << ss1.a << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}

//class test
//{
//public:
//	test()
//	{
//		a = 10;
//	}
//	void ss()
//	{
//		if (this == NULL)
//			return ;
//		cout << this->a << endl;
//	}
//	int a;
//};
//
//void tests1()
//{
//	test* ass = NULL;
//	ass->ss();
//}
//
//int main()
//{
//	tests1();
//	return 0;
//}

class test
{
public:

	void sds(int sd) const
	{
		b = sd;
	}

	void sdss(int asd)
	{
		//this->a = asd;
	}
	mutable int b;
	int a;
};

void test1()
{
	 test ss;
	//ss.a = 100;
	 ss.sds(20);
	 cout<< ss.b <<endl;

}
int main()
{

	test1();
	return 0;
}