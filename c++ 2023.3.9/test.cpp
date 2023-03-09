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

int main()
{
	test();
	return 0;
}