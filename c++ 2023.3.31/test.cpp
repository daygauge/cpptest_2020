#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>



class Person
{
public:
	Person(int a, string b)
	{
		this->m_a = a;
		this->m_b = b;
	}

	int m_a;
	string m_b;
};

template<class T1 , class T2>
bool test01(T1 &a , T2 &b)
{
	return a == b;
}
template<> bool test01(Person& a, Person& b)
{
	return a.m_a == b.m_a && a.m_b == b.m_b;
}

void testcs01()
{
	Person pertest1(20, "张三");
	Person pertest2(21, "张三");
	cout << test01(pertest1, pertest2) << endl;
}

template<class T1,class T2>
class Person1
{
public:
	Person1(T1 a, T2 b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	void test()
	{
		cout << m_a << " " << m_b << endl;
	}
	T1 m_a;
	T2 m_b;
};
void testcs02()
{
	Person1<int ,string> Per1test(20, "张三");
	Per1test.test();
}

template<class T>
class Person2
{
public:
	Person2()
	{
		m_a = 10;
	}
	T m_a;
};
template<class T1,class T2>
class jcPerson2 : public Person2<T2>
{
public:
	jcPerson2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T1).name() << endl;
	}
	void cstesths()
	{
		cout << Person2<T2>::m_a << endl;
	}
};
void testcs03()
{
	jcPerson2<int, int>jcpertest;
	jcpertest.cstesths();
}

template<class T>
class Person3
{
public:
	Person3(T a);
	void cstestlc();
	T m_a;
};
template<class T>
Person3<T>::Person3(T a)
{
	this->m_a = a;
}
template<class T>
void Person3<T>::cstestlc()
{
	cout << this->m_a << endl;
}
void testcs04()
{
	Person3<int> Percstest(100);
	Percstest.cstestlc();
}


template<class T> 
class Person4;

template<class T> 
void Pertest1(Person4<T>& s);

template<class T>
class Person4
{
	friend void Pertest(Person4<T> &s)
	{
		cout << s.m_a << endl;
	}
	friend void Pertest1<>(Person4<T>& s);
public:
	Person4(T a)
	{
		this->m_a = a;
	}
	T m_a;
};
template<class T>
void Pertest1(Person4<T>& s)
{
	cout << s.m_a << endl;
}

void testcs05()
{
	Person4<int> csPer(100);
	//Pertest(csPer);
	Pertest1(csPer);
}

template<class T=int>
class cstest
{
public:
	cstest(T a)
	{
		this->a = a;
	}
	T a;
};
int main()
{
	cstest<string> cate("as");
	//cout << cate.a << endl;
	//testcs01();
	//testcs02();
	//testcs03();
	//testcs04();
	//testcs05();

	return 0;
}
