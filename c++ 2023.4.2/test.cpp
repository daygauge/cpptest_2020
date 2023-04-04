#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include "test.hpp"
#include <string>

void testcs(int a)
{
	cout<< a << endl;
}
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	//vector<int>::iterator it = v.begin();
	//cout<< *++it <<endl;
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}
	for_each(v.begin(), v.end(), testcs);
}
class test
{
public:
	test(int a,string b)
	{
		this->a = a;
		this->b = b;
	}

	int a;
	string b;
};
void test02()
{
	vector<test> vt;
	test a1(10, "q1");
	test a2(20, "q2");
	test a3(30, "q3");
	test a4(40, "q4");

	vt.push_back(a1);
	vt.push_back(a2);
	vt.push_back(a3);
	vt.push_back(a4);



	for (vector<test>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		cout << it->a << " " << it->b << endl;
	}

}
void test03()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	v1.push_back(10);
	v2.push_back(20);
	v3.push_back(30);
	v4.push_back(40);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator its = (*it).begin(); its != (*it).end(); its++)
		{
			cout << *its << endl;
		}
	}
}

void test04()
{
	//string a = "qq";
	//string b = "sssss";
	//string c(10,'a');
	//cout << c << endl;

	string a = "abcd";
	//string b("hiaoya", 3);
	a.assign("hihaouya", 4);
	a.assign(5, 'c');
	cout << a << endl;

}
void testcsz()
{
	my_string a("abcder");
	my_string a1(a);
	my_string a2("ppspp");
	my_string a3("abcder");
	//a1 = 'a';
	//a1 += "ttt";
	//a1 += 't';
	//a += a2;
	//a.append(a2, 1, 2);
	//int ai = a.my_find(&a3);
	//int ai = a.my_comare(a3);
	//a[3] = 'c';

	//cout << a.my_insert(3, "ssssssssss") <<endl;
	//cout << a.my_insert(3, a2) << endl;
	cout << a.my_erase(2,3 ) << endl;

	//cout << a[3] << endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	testcsz();
	return 0;
}