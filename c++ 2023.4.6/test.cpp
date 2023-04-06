#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <map>
using namespace std;
struct a
{
	int a;
	struct a* s;
};
void test01()
{
	struct a test = { 1,NULL };
	//cout << test.a << endl;
	struct a tes1 = { 2,NULL };
	test.s = &tes1;
	//cout << test.s->a << endl;

	struct a* cs = &test;
	while (cs!=NULL)
	{
		cout << cs->a << " ";
		cs = cs->s;
	}
}

void printlist(list<int>& a)
{
	for (list<int>::iterator li = a.begin(); li != a.end(); li++)
	{
		cout << *li << " ";
	}
	cout << endl;
}
void test02()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	list<int> l1(4, 10);
	printlist(l);
	printlist(l1);

	//l.swap(l1);
	printlist(l);
	printlist(l1);

	l1.remove(10);
	cout << l1.size() << endl;
	printlist(l1);

}

class Person
{
public:
	Person(string name,int age,double height):m_name(name),m_age(age),m_height(height){}
	string m_name;
	int m_age;
	double m_height;
};
void Personc(list<Person> &testcs)
{
	//while (namecs[i])
	//{
	//	Person ls(namecs[i] + "person", i + 20, i * 1.5);
	//	i++;
	//	testcs.push_back(ls);
	//}
	Person te1("张三", 25, 1.72);
	testcs.push_back(te1);
	Person te2("李四", 20, 1.62);
	testcs.push_back(te2);
	Person te3("王五", 20, 1.72);
	testcs.push_back(te3);
	Person te4("男枪", 30, 1.82);
	testcs.push_back(te4);
	Person te5("啊的", 22, 1.92);
	testcs.push_back(te5);
}
bool cs(Person n1, Person n2)
{
	if (n1.m_age == n2.m_age)
	{
		return n1.m_height > n2.m_height;
	}
	else
	{
		return n1.m_age < n2.m_age;
	}
}
void printlistcs(list<Person> cs)
{
	for (list<Person>::iterator cls = cs.begin(); cls != cs.end(); cls++)
	{
		cout << cls->m_age << " " << cls->m_name << " " << cls->m_height << endl;
	}
}
void test03()
{
	list<Person> test;
	Personc(test);//5个人员
	test.sort(cs);
	printlistcs(test);
}
void printset(const set<int>& s)
{
	for (set<int>::const_iterator s1 = s.begin(); s1 != s.end(); s1++)
	{
		cout << *s1 << " ";
	}
	cout << endl;
}
void test04()
{
	set<int> s;
	s.insert(10);
	s.insert(30);
	s.insert(20);
	s.insert(50);
	s.insert(40);

	printset(s);

	set<int>::iterator s1 = s.find(50);
	if (s1 == s.end())
	{
		cout << "找不到" << endl;
	}
	else
	{
		cout << "找到了" << endl;
	}

}
void testo5()
{
	set<int> s;
	pair<set<int>::iterator,bool> lsdz = s.insert(1);
	if (lsdz.second == true)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}
	lsdz = s.insert(1);
	if (lsdz.second == true)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}
	multiset<int> ms;
	ms.insert(2);
	ms.insert(2);
	ms.insert(9);
	ms.insert(4);
	for (multiset<int>::iterator ms1 = ms.begin(); ms1 != ms.end(); ms1++)
	{
		cout << *ms1 << " ";
	}
	cout << endl;
}
class Person_s
{
public:
	Person_s(int ms, string ms1) :age(ms), name(ms1) {}
	int age;
	string name;
};
class csste
{
public:
	//bool operator()(const int a, const int b) const
	//{
	//	return a > b;
	//}
	bool operator()(const Person_s a1,const Person_s a2) const
	{
		return a1.age < a2.age;
	}
};
void test06()
{
	//pair<int, string> p(1, "你好");
	pair<int, string> p = make_pair(1, "你好");
	cout << p.first << " " << p.second << endl;
	//set<int,csste> s;
	//s.insert(1);
	//s.insert(2);
	//s.insert(3);
	//s.insert(4);
	//s.insert(5);
	//for (set<int, csste>::iterator s1 = s.begin(); s1 != s.end(); s1++)
	//{
	//	cout << *s1 << " ";
	//}
	//cout << endl;
	Person_s a(20, "张三");
	Person_s a1(25, "李四");
	Person_s a2(23, "王五");
	set<Person_s, csste> s;
	s.insert(a);
	s.insert(a1);
	s.insert(a2);

	for (set<Person_s, csste>::iterator ls = s.begin(); ls != s.end(); ls++)
	{
		cout << ls->age << " " << ls->name << endl;
	}
}

class fanmao
{
public:
	bool operator()(const int n1, const int n2) const
	{
		return n1 > n2;
	}
};

void printmao(map<int, int, fanmao> a)
{
	for (map<int, int, fanmao>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << it->first << " " << (*it).second << endl;
	}
}
void printmao(map<int, int> a)
{
	for (map<int, int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << it->first << " " << (*it).second << endl;
	}
}
void test07()
{
	map<int, int,fanmao> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	printmao(m);
	cout << m.size() << endl;
	cout << m.empty() << endl;

	map<int, int> m1;
	m1.insert(pair<int, int>(5, 50));
	m1.insert(pair<int, int>(6, 60));
	m1.insert(pair<int, int>(7, 70));
	m1.insert(pair<int, int>(8, 80));
	printmao(m1);
}

class teststaff
{
public:
	teststaff(string na,int sa,int Dn):name(na),salary(sa),Dnumber(Dn){}
	string name;
	int salary;
	int Dnumber;
};
void printvector(vector<teststaff> &v)
{
	for (vector<teststaff>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->name << " 工资：" << it->salary << " 部门编号" << it->Dnumber << endl;
	}
}
void putest(vector<teststaff>& v)
{
	string name = "ABCDEFGHLJ";
	for (int i = 0; i < name.size(); i++)
	{
		string csname = "员工";
		teststaff cs(csname+name[i], rand() % 10000 + 5000, rand() % 3 + 1);
		v.push_back(cs);
	}
}
void printmulti(multimap<int, teststaff>& ms)
{
	//for (multimap<int, teststaff>::iterator it = ms.begin(); it != ms.end(); it++)
	//{
	//	if (it->first == 1)
	//	{
	//		cout << "策划 ";
	//	}
	//	else if (it->first == 2)
	//	{
	//		cout << "美术 ";
	//	}
	//	else
	//	{
	//		cout << "研发 ";
	//	}
	//	cout << "姓名:" << it->second.name << " 工资:" << it->second.salary << endl;
	//}
	// 
	//打印各个部门
	cout << "策划: " << endl;
	int cs = ms.count(1);//编号为1的个数
	multimap<int, teststaff>::iterator it = ms.begin();//迭代器记录首元素
	int beguncs = 0;//用于打印判断不超过1的个数
	while (beguncs < cs && it != ms.end())
	{
		cout << "姓名:" << it->second.name << " 工资:" << it->second.salary << endl;
		it++; beguncs++;
	}
	cout << "---------------------------" << endl;
	cout << "美术: " << endl;
	cs = ms.count(2);
	it = ms.find(2);//查找到元素为2的位置,返回位置的迭代器给it
	beguncs = 0;
	while (beguncs < cs && it != ms.end())
	{
		cout << "姓名:" << it->second.name << " 工资:" << it->second.salary << endl;
		it++; beguncs++;
	}
	cout << "---------------------------" << endl;
	cout << "研发: " << endl;
	cs = ms.count(3);
	it = ms.find(3);
	beguncs = 0;
	while (beguncs < cs && it != ms.end())
	{
		cout << "姓名:" << it->second.name << " 工资:" << it->second.salary << endl;
		it++; beguncs++;
	}
}
void test08()
{
	srand(time(NULL));
	vector<teststaff> v;
	putest(v);//写入员工分配部门和工资
	//printvector(v);
	multimap<int, teststaff> m;

	for (int i = 0; i < v.size(); i++)
	{
		m.insert(pair<int, teststaff>(v[i].Dnumber, v[i]));
	}
	printmulti(m);
}
int main()
{
	//test01();
	//test02();
	//test03();	
	//test04();
	//testo5();
	//test06();
	//test07();
	test08();
	return 0;
}