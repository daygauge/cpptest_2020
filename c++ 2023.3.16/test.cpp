#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
using namespace std;





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
//int main()
//{
//	add add1;
//	subtract subtract1;
//	ride ride1;
//	getridof getridof1;
//	test01(add1);
//	test01(subtract1);
//	test01(ride1);
//	test01(getridof1);
//	//Cat cat;
//	//Dog dog;
//	//test(dog);
//	return 0;
//}




class MakeDrinks
{
public:
	virtual void Step1() = 0;
	virtual void Step2() = 0;
	virtual void Step3() = 0;

	virtual void realize() = 0;
};

class coffee:public MakeDrinks
{
public:
	virtual void Step1()
	{
		cout << "煮开水" << endl;
	}
	virtual void Step2()
	{
		cout << "冲泡咖啡" << endl;
	}
	virtual void Step3()
	{
		cout << "加入糖和牛奶" << endl;
	}

	virtual void realize()
	{
		Step1();
		Step2();
		Step3();
	}
};

class maketea :public MakeDrinks
{
public:
	virtual void Step1()
	{
		cout << "煮开水" << endl;
	}
	virtual void Step2()
	{
		cout << "将开水倒入杯中" << endl;
	}
	virtual void Step3()
	{
		cout << "加入茶叶" << endl;
	}

	virtual void realize()
	{
		Step1();
		Step2();
		Step3();
	}
};

void test02()
{
	MakeDrinks* testMakeDrinks = new coffee;
	MakeDrinks* testmaketea = new maketea;
	testMakeDrinks->realize();
	cout << "-------------------------" << endl;
	testmaketea->realize();
	delete testMakeDrinks;
	delete testmaketea;
}
class CPUs
{
public:
	virtual void caloulate() = 0;
};
class VideoCards
{
public:
	virtual void display() = 0;
};
class Memorys
{
public:
	virtual void storage() = 0;
};

class Inters :public CPUs, public VideoCards, public Memorys
{
public:
	virtual void caloulate()
	{
		cout << "Inter CPU" << endl;
	}
	virtual void display()
	{
		cout << "Inter VideoCard" << endl;
	}
	virtual void storage()
	{
		cout << "Inter Memory" << endl;
	}
};
class Computers:public Inters
{
public:
	void zg()
	{
		caloulate();
		display();
		storage();
	}
};
void test03()
{
	CPUs* cpu = new Inters;
	//Computers ss;
}


class CPU
{
public:
	virtual void caloulate() = 0;
};
class VideoCard
{
public:
	virtual void display() = 0;
};
class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* cpus,VideoCard* videoCards,Memory* memory)
	{
		my_cpu = cpus;
		my_videCard = videoCards;
		my_memory = memory;
	}
	void my_Computers()
	{
		my_cpu->caloulate();
		my_videCard->display();
		my_memory->storage();
	}
	~Computer()
	{
		if (my_cpu != NULL)
		{
			delete my_cpu;
			my_cpu = NULL;
		}
		if (my_videCard != NULL)
		{
			delete my_videCard;
			my_videCard = NULL;
		}
		if (my_memory != NULL)
		{
			delete my_memory;
			my_memory = NULL;
		}
	}
private:
	CPU* my_cpu;
	VideoCard* my_videCard;
	Memory* my_memory;
};
//Inter
class InterCPU:public CPU
{
public:
	virtual void caloulate()
	{
		cout << "Intercpu" << endl;
	}
};
class InterVideoCard:public VideoCard
{
public:
	virtual void display()
	{
		cout << "InterVideoCard" << endl;
	}
}; 
class InterMemory:public Memory
{
public:
	virtual void storage()
	{
	    cout << "InterMemory" << endl;
	}
};
//ROG
class ROGCPU :public CPU
{
public:
	virtual void caloulate()
	{
		cout << "ROGcpu" << endl;
	}
};
class ROGVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "ROGVideoCard" << endl;
	}
};
class ROGMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "ROGMemory" << endl;
	}
};
void test04()
{
	CPU* cpu = new InterCPU;
	VideoCard* Cideocard = new InterVideoCard;
	Memory* memory = new InterMemory;

	Computer computer(cpu, Cideocard, memory);
	computer.my_Computers();

	cout << "_____________________________________" << endl;

	Computer* Computer2 = new Computer(new ROGCPU, new ROGVideoCard, new ROGMemory);
	Computer2->my_Computers();
}
int main()
{
	//test03();
	//test02();
	test04();
	return 0;
}