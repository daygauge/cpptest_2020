#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#include <vector>
#include <numeric>

class pf
{
public:
	void operator()(int n)
	{
		cout << n << " ";
	}
};
int pfs(int n)
{
	return n;
}
void test01()
{
	vector<int> v;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i + 10);
	}
	for_each(v.begin(), v.end(), pf());
	cout << endl;
	for_each(v1.begin(), v1.end(), pf());
	cout << endl;
	vector<int> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), pfs);
	for_each(v2.begin(), v2.end(), pf());
	//cout << endl;
}
class cs1
{
public:
	bool operator()(int n)
	{
		return n >= 20;
	}
};
class Per
{
public:
	Per(string name,int age):m_name(name),m_age(age){}
	string m_name;
	int m_age;
};
class cs2
{
public:
	bool operator()(Per nc)
	{
		return nc.m_age > 20;
	}
};
void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator it = find(v.begin(), v.end(), 40);
	if (it == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了: " << *it << endl;
	}
	vector<int>::iterator it1 = find_if(v.begin(), v.end(), cs1());
	if (it == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了: " << *it1 << endl;
	}

	Per p1("张三", 25);
	Per p2("李四", 23);
	Per p3("王五", 30);
	vector<Per> v2;
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	vector<Per>::iterator it2 = find_if(v2.begin(), v2.end(), cs2());
	if (v2.end() == it2)
	{
		cout << "找不到" << endl;
	}
	else
	{
		cout <<"名字:"<<it2->m_name<<" 年龄:" << it2->m_age << endl;
	}
	vector<int> v3;
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(3);
	v3.push_back(4);
	v3.push_back(4);
	v3.push_back(6);
	v3.push_back(7);
	vector<int>::iterator it3 = adjacent_find(v3.begin(), v3.end());
	if (v3.end() == it3)
	{
		cout << "没有相邻元素" << endl;
	}
	else
	{
		cout << *it3 << " " << *(it3++) << endl;
	}

	vector<int> v4;
	//for (int i = 0; i < 10; i++)
	//{
	//	v4.push_back(i);
	//}
	v4.push_back(1);
	v4.push_back(3);
	v4.push_back(5);
	v4.push_back(5);
	v4.push_back(5);
	v4.push_back(9);
	v4.push_back(30);
	v4.push_back(22);
	v4.push_back(134);

	sort(v4.begin(), v4.end());
	bool b_cs = binary_search(v4.begin(), v4.end(), 5);
	if (b_cs)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "找不到" << endl;
	}
	int in_cs = count(v4.begin(), v4.end(), 5);
	cout << in_cs << endl;

	int in_cs1 = count_if(v4.begin(), v4.end(), cs1());
	cout << in_cs1 << endl;
}
class csprint
{
public:
	void operator()(int n)
	{
		cout << n << " ";
	}
};
void test03()
{
	vector<int> v;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v2.push_back(i + 5);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), csprint());
	sort(v.begin(), v.end());
	cout << endl;
	for_each(v.begin(), v.end(), csprint());
	vector<int> v3;
	v3.resize(v.size() + v2.size());
	merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	cout << endl;
	for_each(v3.begin(), v3.end(), csprint());
	reverse(v3.begin(), v3.end());
	cout << endl;
	for_each(v3.begin(), v3.end(), csprint());
}

void printcsv(int n)
{
	cout << n << " ";
}
class wzv1
{
public:
	bool operator()(int n)
	{
		return n > 2000;
	}
};
void test04()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(3);
		v.push_back(i);
	}
	vector<int>::iterator it = v.begin();
	it += 7;
	vector<int> v1;
	//v1.resize(v.size()-3);
	v1.resize(v.size());
	copy(v.begin(), it, v1.begin());
	for_each(v1.begin(), v1.end(), printcsv);
	cout << endl;
	replace(v.begin(), v.end(), 3, 30000);
	for_each(v.begin(), v.end(), printcsv);

	replace_if(v.begin(), v.end(), wzv1(), 9000);
	cout << endl;
	for_each(v.begin(), v.end(), printcsv);
	cout << endl;
	cout << "_____________________________" << endl;
	for_each(v.begin(), v.end(), printcsv);
	cout << endl;
	for_each(v1.begin(), v1.end(), printcsv);
	cout << endl;
	cout << "_____________________________" << endl;
	swap(v, v1);
	for_each(v.begin(), v.end(), printcsv);
	cout << endl;
	for_each(v1.begin(), v1.end(), printcsv);
}
void test05()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), printcsv);
	cout << endl;
	int acc_cs = accumulate(v.begin(), v.end(), 100);
	cout << acc_cs << endl;
	cout << endl;
	fill(v.begin(), v.end(), 10000);
	for_each(v.begin(), v.end(), printcsv);
}
class printzueiho
{
public:
	void operator()(int n)
	{
		cout << n << " ";
	}
};
void test06()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> v3;
	//v3.resize(min(v1.size(), v2.size()));
	//vector<int>::iterator itszh = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	//for_each(v3.begin(), itszh, printzueiho());
	//v3.resize(v1.size() + v2.size());
	//vector<int>::iterator itss = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	//for_each(v3.begin(), itss, printzueiho());
	v3.resize(v2.size());
	//vector<int>::iterator it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	vector<int>::iterator it = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for_each(v3.begin(), it, printzueiho());
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}