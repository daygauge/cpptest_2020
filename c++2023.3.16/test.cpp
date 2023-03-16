#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>






//
//class A
//{
//public:
//	void ls1()
//	{
//		std::cout << "头部" << std::endl;
//	}
//	void ls2()
//	{
//		std::cout << "尾部" << std::endl;
//	}
//	void ls3()
//	{
//		std::cout << "左则列表" << std::endl;
//	}
//};
//class b:public A
//{
//public:
//	void ls0()
//	{
//		std::cout << "b内容" << std::endl;
//	}
//};
//class c :public A
//{
//public:
//	void ls0()
//	{
//		std::cout << "c内容" << std::endl;
//	}
//};
//
//
//void test01()
//{
//	b test1;
//	test1.ls1();
//	test1.ls2();
//	test1.ls3();
//	test1.ls0();
//
//	c test2;
//	test2.ls1();
//	test2.ls2();
//	test2.ls3();
//	test2.ls0();
//}


//class A
//{
//
//};
//class B :public A
//{
//
//};

//class A
//{
//public:
//	int a;
//protected:
//	int b;
//private:
//	int c;
//};
//class B :private A
//{
//};


//class ls1
//{
//public:
//	ls1()
//	{
//		std::cout << "父类构造" << std::endl;
//	}
//	~ls1()
//	{
//		std::cout << "父类析构" << std::endl;
//	}
//};
//class ls2:public ls1
//{
//public:
//	ls2()
//	{
//		std::cout << "子类构造" << std::endl;
//	}
//	~ls2()
//	{
//		std::cout << "子类析构" << std::endl;
//	}
//};
//int main()
//{
//	ls2 ls;
//
//	//std::cout << sizeof(b) << std::endl;
//	return 0;
//}

//
//class f
//{
//public:
//	f():a(10)
//	{
//
//	}
//	int a;
//};
//class z:public f
//{
//public:
//	z() :a(20)
//	{
//
//	}
//	int a;
//};
//class A
//{
//public:
//	int a = 0;
//};
//class B
//{
//public:
//	int a = 0;
//};
//class C :public A, public B
//{
//
//};
//
//class A
//{
//public:
//	int a = 0;
//};
//class B :virtual public A  {};
//class C :virtual public A {};
//class D :public B, public C
//{
//
//};
//
//int main()
//{
//	D d;
//	std::cout << d.a << std::endl;
//	return 0;
//}

class Animai
{
public:
     virtual void speak()
	{
		std::cout << "动物在说话" << std::endl;
	}
};
class Cat:public Animai
{
public:
	void speak()
	{
		std::cout << "喵在说话" << std::endl;
	}
};
class Dog :public Animai
{
public:
	void speak()
	{
		std::cout << "狗在说话" << std::endl;
	}
};
void test(Animai& test)
{
	test.speak();
}




class Counter
{
public:
	virtual int count(int a,int b)
	{
		return 0;
	}
};
class add:public Counter
{
public:
	int count(int a, int b)
	{
		return a + b;
	}
};
class subtract :public Counter
{
public:
	int count(int a, int b)
	{
		return a - b;
	}
};
class ride :public Counter
{
public:
	int count(int a, int b)
	{
		return a * b;
	}
};
class getridof :public Counter
{
public:
	int count(int a, int b)
	{
		return a / b;
	}
};
void test01(Counter & js)
{
	int a = 10;
	int b = 5;
	std::cout << js.count(a, b) << std::endl;
}
int main()
{
	add add1;
	subtract subtract1;
	ride ride1;
	getridof getridof1;
	test01(add1);
	test01(subtract1);
	test01(ride1);
	test01(getridof1);
	//Cat cat;
	//Dog dog;
	//test(dog);
	return 0;
}
