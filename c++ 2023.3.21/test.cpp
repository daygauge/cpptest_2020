#define _CRT_SECURE_NO_WARNINGS 1
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

void test01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "ÄÉÎ÷æ§ÄãºÃÑ½" << endl;
	ofs.close();
}
void test02()
{
	fstream ofs;
	ofs.open("test.txt", ios::in);
	if (!ofs.is_open())
	{
		return;
	}
	//char a[1042] = { 0 };
	//while (ofs >> a)
	//{
	//	cout << a ;
	//}
	// 
	char a[1042] = { 0 };
	while (ofs.getline(a, sizeof(a)))
	{
		cout << a  << endl;
	}

	//char c;
	//while ((c = ofs.get())!=EOF)
	//{
	//	cout<<c;
	//}
	//ofs.close();
}

class test11
{
public:
	char a;
	int b;
};
void test03()
{
	ofstream cs("test1.txt", ios::out | ios::binary);
	test11 p;
	p.a = 'c';
	p.b = 10;
	cs.write((const char*)&p, sizeof(p));
	cs.close();
}
void test04()
{
	fstream cs("test1.txt", ios::in | ios::binary);
	if (!cs.is_open())
	{
		return;
	}
	test11 p1;
	cs.read((char*)&p1, sizeof(p1));
	cout << p1.a << p1.b << endl;
	
}
int main()
{
	//test01();
	//test02();
	test03();
	test04();
	return 0;
}