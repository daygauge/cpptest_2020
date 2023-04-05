#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <deque>
using namespace std;
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

void printdeque(const deque<int> &td)
{
	for (deque<int>::const_iterator di = td.begin(); di != td.end(); di++)
	{
		cout << *di << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);

	printdeque(d);
}

void test02()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(3);
	d.push_back(2);
	d.push_back(8);
	d.push_back(5);

	//deque<int> d1(d.begin(), d.end());
	printdeque(d);
	sort(d.begin(), d.end());
	printdeque(d);
}

class Person
{
public:
	Person(int a,string m_names):m_divide(a),m_name(m_names){}
	string m_name;
	int m_divide;
};
void printxs(vector<int> c)
{
	for (vector<int>::iterator di = c.begin(); di != c.end(); di++)
	{
		cout << *di << " ";
	}
	cout << endl;
}
void test03()
{
	//Person xctest1(0, "选手A");
	//vector<Person> v;
	//v.push_back(xctest1);
	vector<int> v;
	int s = 0;
	cin >> s;
	while (s--)
	{
		deque<int> d;

		int is = 0;
		for (int i = 0; i < 10; i++)
		{
			//cin >> is;
			//d.push_back(is);
			d.push_back(i);
		}
		sort(d.begin(), d.end());
		d.pop_front();
		d.pop_back();
		int cs = d.size();
		int i = 0;
		for (deque<int>::iterator di = d.begin(); di != d.end(); di++)
		{
			i += *di;
		}
		//cout << (i / cs) << endl;
		v.push_back((i / cs));
	}
	printxs(v);

}

class Person1
{
public:
	Person1(string name,int f):m_name(name),m_divide(f){}
	string m_name;
	int m_divide;
};
void grade(deque<int> &d)
{
	for (int i = 0; i < 10; i++)
	{
		d.push_back(rand() % 41 + 60);
	}
}
void printdeq(deque<int> &d)
{
	for (deque<int>::iterator di = d.begin(); di != d.end(); di++)
	{
		cout << *di << " ";
	}
	cout << endl;
}
int AcraGe(deque<int> &dpw)
{
	//int c = 0;
	//d.pop_front();
	//d.pop_back();
	//for (deque<int>::iterator di = d.begin(); di != d.end(); di++)
	//{
	//	c += *di;
	//}
	//return c / d.size();

	sort(dpw.begin(), dpw.end());
	dpw.pop_front();
	dpw.pop_back();
	int ls = 0;
	for (deque<int>::iterator it = dpw.begin();it!=dpw.end();it++)
	{
		ls += *it;
	}
	return ls / dpw.size();
}
void dividecs(vector<Person1> &v)
{
	string member = "ABCDE";
	for (int i = 0; i < member.size(); i++)
	{
		string name = "选手";
		name += member[i];
		Person1 Ps(name, 0);
		v.push_back(Ps);
	}
}
void printvector(vector<Person1>& v)
{
	for (vector<Person1>::iterator vi = v.begin(); vi != v.end(); vi++)
	{
		cout << "选手名：" << vi->m_name <<" " << "选手分数:" << vi->m_divide << endl;
	}
}
void test04()
{
	srand(time(nullptr));

	deque<int> dpw;//记录评委分数
	vector<Person1> v;//选手
	dividecs(v);//创建5个选手类并赋予name

	for (vector<Person1>::iterator vi = v.begin();vi!=v.end();vi++)
	{
		grade(dpw);//打分10个随机数
		vi->m_divide = AcraGe(dpw);//返回dqw中10个评分的平均值
		dpw.clear();
	}
	printvector(v);//打印


	//printdeq(dpw);

}
void test05()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.size() << endl;
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	cout << s.size() << endl;
}
void test06()
{
	queue<char> q;
	q.push('a');
	q.push('b');
	q.push('c');
	q.push('d');
	q.push('e');
    int qs = q.size();
	//for (int i = 0; i < qs; i++)
	//{
	//	//cout << q.back() << " ";
	//	cout << q.front() << " ";
	//	q.pop();
	//}
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}


}
void printlist(const list<int> lcs)
{
	for (list<int>::const_iterator cs1 = lcs.begin(); cs1 != lcs.end(); cs1++)
	{
		cout << *cs1 << " ";
	}
	cout << endl;
}
void test07()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	printlist(l);
	printlist(l1);
	l.swap(l1);
	printlist(l);
	printlist(l1);
	l.reverse();
	printlist(l);
	l.sort();
	printlist(l);
}
int main()
{ 
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
}