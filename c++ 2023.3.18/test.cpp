#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//class A
//{
//public :
//	A()
//	{
//		this->a = new int(10);
//	}
//	virtual void cs()
//	{
//		cout << "A"<< *a << endl;
//	}
//	virtual~A()
//	{
//		delete a;
//		a = NULL;
//		cout << "析构" << endl;
//	}
//	int* a;
//};
//
//class cat:public A
//{
//	virtual void cs()
//	{
//		cout << "我是猫"<< *a << endl;
//	}
//};
//class dog :public A
//{
//	virtual void cs()
//	{
//		cout << "我是狗"<< *a << endl;
//	}
//};
//
//void test()
//{
//	A* a = new cat;
//	a->cs();
//	delete a;
//
//	//A* a1 = new dog;
//	//a1->cs();
//	//delete a1;
//}
//int main()
//{
//	test();
//	return 0;
//}

//class diningroom//餐厅
//{
//public:
//	virtual void test()
//	{
//		cout << "餐厅" << endl;
//	}
//};
//class ChineseRestaurant:public diningroom//中餐厅
//{
//public:
//	void test()
//	{
//		cout << "筷子" << endl;
//	}
//};
//class westernRestaurant :public diningroom//西餐厅
//{
//public:
//	void test()
//	{
//		cout << "叉子" << endl;
//	}
//};
//
//void test()
//{
//	diningroom* ls1 = new ChineseRestaurant;
//	ls1->test();
//	delete ls1;
//
//	diningroom* ls2 = new westernRestaurant;
//	ls2->test();
//	delete ls2;
//}



//class A
//{
//public:
//	virtual void ls()
//	{
//		cout << "A" << endl;
//	}
//};
//class B :public A
//{
//	void ls()
//	{
//		cout << "B" << endl;
//	}
//};
//int main()
//{
//	A* a = new B;
//	a->ls();
//	return 0;
//}


//class jsq
//{
//public:
//	jsq():n1(0),n2(0){}
//    virtual int test()
//	{
//		return 0;
//	}
//
//	int n1;
//	int n2;
//};
//class jia :public jsq
//{
//	int test()
//	{
//		return n1 + n2;
//	}
//};
//class jian :public jsq
//{
//	int test()
//	{
//		return n1 - n2;
//	}
//};
//
//
//int main()
//{
//	jsq* js = new jia;
//	js->n1 = 10;
//	js->n2 = 5;
//	cout << js->test() << endl;
//
//	jsq* jss = new jian;
//	jss->n1 = 10;
//	jss->n2 = 5;
//	cout << jss->test() << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void test() = 0;
//};
//class b:public A
//{
//public:
//	virtual void test()
//	{
//
//	}
//};
//
//int main()
//{
//	A a;
//	return 0;
//}

class A
{
public:
	virtual void ls(int) = 0;
	virtual ~A()
	{
		cout << "A析构" << endl;
	}
};
class B :public A
{
public:
	void ls(int a)
	{
		this->a = new int(a);
		cout << a << endl;
	}
	virtual ~B()
	{
		cout << "B析构" << endl;
	}
	int* a = NULL;
};
int main()
{
	A* a = new B;
	a->ls(10);
	delete a;
	return 0;
}