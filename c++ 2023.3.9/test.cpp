#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
using namespace std;




class Person
{
public:
	//Person operator+ (Person &n1)
	//{
	//	Person ls;
	//	ls.m_a = m_a + n1.m_a;
	//	ls.m_b = m_b + n1.m_b;
	//	return ls;
	//}
	Person operator+ (Person& n1)
	{
		Person ls;
		ls.m_a = m_a - n1.m_a;
		ls.m_b = m_b - n1.m_b;
		return ls;
	}

	int m_a = 0;
	int m_b = 0;
};
//Person operator+ (Person& n1, Person& n2)
//{
//	Person ls;
//	ls.m_a = n2.m_a + n1.m_a;
//	ls.m_b = n2.m_b + n1.m_b;
//	return ls;
//}

void test()
{
	Person ss;
	ss.m_a = 10;
	ss.m_b = 10;
	Person ss1;
	ss1.m_a = 10;
	ss1.m_b = 10;

	//Person ss2 = ss + ss1;
	//Person ss2 = operator+(ss, ss1);
	Person ss2 = ss.operator+(ss1);

	cout << ss2.m_a <<" "<< ss2.m_b << endl;
}


class Person1
{
	friend ostream& operator<<(ostream& cout, Person1 ls);
public:
private:
	int a = 0;
	int b = 0;
};

ostream& operator<<(ostream& cout, Person1 ls)
{
	cout << ls.a <<" "<< ls.b << endl;
	return cout;
}

void test1()
{
	Person1 ss;

	cout << ss << endl;
}


class Person2
{
public:

	Person2& operator++()
	{
		a++;
		return *this;
	}

	Person2 operator++(int)
	{
		Person2 ls;
		ls.a = this->a;
		this->a++;
		return ls;
	}

	Person2& operator--()
	{
		a--;
		return *this;
	}

	Person2 operator--(int)
	{
		Person2 ls;
		ls.a = this->a;
		this->a--;
		return ls;
	}

	int a = 0;
};
ostream& operator<<(ostream& couts,Person2 ss)
{
	couts << ss.a;
	return cout;
}
void test2()
{
	Person2 ss;
	//cout << ++ss << endl;
	//cout << ss << endl;
	//cout << --ss << endl;
	//cout << ss << endl;
	//cout << ss-- << endl;
	//cout << ss << endl;

}
void test20()
{
	Person2 ss;
	cout << ++(++ss) << endl;
	cout << ss << endl;

}
int main()
{
	//test();
	//test1();
	//test2();
	test20();
	return 0;
}