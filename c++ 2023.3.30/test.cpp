#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

template<typename T>
void test(T &a , T &b)
{
	T ls = a;
	a = b;
	b = ls;
}

template<class T>
void xzpx(T a[],int b)
{
	for (int i = 0; i < b; i++)
	{
		int cs = i;
		for (int j = i+1; j < b; j++)
		{
			if (a[cs] < a[j])
			{
				cs = j;
			}
		}
		if (cs != i)
		{
			test(a[cs], a[i]);
		}
	}
}

template<class T>
void day(T a[],int b)
{
	for (int i = 0; i < b; i++)
	{
		std::cout << a[i] << " " ;
	}
}



template<class T>
void cs(T a, T b)
{
	std::cout << a + b+10 << std::endl;
}
void cs(int a, int b)
{
	std::cout << a + b << std::endl;
}

class Person
{
public:
	Person(int a, string b)
	{
		this->a = a;
		this->b = b;
	}
	int a;
	string b;
};

template<class T>
bool csPerson(T a,T b)
{
	return a == b;
}
template<> bool csPerson(Person a, Person b)
{
	if (a.a == b.a && a.b == b.b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	Person csP1(10, "abc");
	Person csP2(10, "abc");
	if (csPerson(csP1,csP2))
	{
		cout << "==" << endl;
	}
	else
	{
		cout << "!=" << endl;
	}
}

template<class m_i = string, class m_s = int>
class Person1
{
public:
	Person1(m_i a, m_s b)
	{
		this->a = a;
		this->b = b;
	}
	m_i a;
	m_s b;
};

void test02()
{
	Person1<>s("你好", 200);
	cout << s.a << " " << s.b << endl;
}



template<class T>
class Person3
{
public:
	T m_a;
};
template<class T1,class T2>
class Person03:public Person3<T1>
{
public:
	Person03(T1 a, T2 b)
	{
		this->Person3<T1>::m_a = a;
		this->m_b = b;
	}

	T2 m_b;
};
void test03()
{
	Person03<int, string> Pcs(100, "你好");
	cout << Pcs.m_a << " " << Pcs.m_b << endl;
}

template<class T1, class T2>
class Person04;

template<class T1, class T2>
void testprint(Person04<T1, T2>& p);

template<class T1,class T2>
class Person04
{
	//friend void testprint(Person04<T1,T2> &p )
	//{
	//	cout << p.m_age << " " << p.m_name << endl;
	//}
	friend void testprint(Person04<T1, T2>& p);

public:
	Person04(T1 a, T2 b)
	{
		this->m_name = a;
		this->m_age = b;
	}
	T1 m_name;
	T2 m_age;
};

template<class T1, class T2>
void testprint(Person04<T1, T2>& p)
{
	cout << p.m_age << " " << p.m_name << endl;
}

void test04()
{
	Person04<string, int> lstest("张三", 20);
	//testprint(lstest);
	testprint<string,int>(lstest);
}
int main()
{

	test04();
	//test03();
	//test02();
	//test01();
	//int a[5] = { 1,2,3,4,5 };
	//int n = sizeof(a) / sizeof(int);
	//xzpx(a, n);
	//day(a, 5);
	//int a = 10;
	//int b = 20;
	//test(a, b);
	//std::cout << a << b << std::endl;
	return 0;
}