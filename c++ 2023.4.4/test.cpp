#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
using namespace std;
#include <iostream>

void printVector(vector<int> &a)
{
	for (vector<int>::iterator vs = a.begin(); vs != a.end(); vs++)
	{
		cout << *vs << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	printVector(v);

	vector<int> v1(5, 100);
	vector<int> v2(v1.begin(), v1.end());
	vector<int> v3(v1);
	printVector(v1);
	printVector(v2);
	printVector(v3);
}
void test02()
{
	vector<int> v(5, 100);
	vector<int> v1(5, 50);
	printVector(v1);
	//v1 = v;
	//printVector(v1);
	v1.assign(v.begin(), v.end());
	printVector(v1);
	v1.assign(5, 120);
	printVector(v1);
}
void test03()
{
	vector<int> v(5, 20);
	cout << v.empty() << endl;
	cout << v.capacity() << endl;
	//v.resize(10);
	v.resize(20,6);
	cout << v.capacity() << endl;
	cout << v.size() << endl;
	printVector(v);
}

void test04()
{
	vector<int> v(5, 20);

	v.pop_back();
	v.insert(v.begin(), 80);
	vector<int>::iterator vs = v.begin();
	vs++;
	v.erase(vs);
	//v.erase(v.begin(), v.end());
	v.clear();
	cout << v.empty() << endl;

	printVector(v);
}
void test05()
{
	vector<int> v(5, 10);
	vector<int> v1(5, 3);
	//cout<<v.at(1)<<endl;
	//cout << v[1] << endl;
	//cout << v.front() << endl;
	//cout << v.back() << endl;
	printVector(v);
	printVector(v1);

	//v.swap(v1);
	//printVector(v);
	//printVector(v1);
	v.reserve(100);
	cout<< v.capacity() <<endl;
	cout << v.size() << endl;
}

void test06()
{

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