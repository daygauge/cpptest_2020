#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>


class test01
{
public:
	void test1()
	{
		std::cout << "上面标题" << std::endl;
	}	
	void test2()
	{
		std::cout << "左边的标题" << std::endl;
	}
	void test3()
	{
		std::cout << "下面的标题" << std::endl;
	}

private:
	int b;
};

class t1:public test01
{
public:
	void t1s()
	{
		std::cout << "c语言" << std::endl;
	}
};
class t2 :public test01
{
public:
	void t2s()
	{
		printf("c++语言");
	}
};
class t3 :public test01
{
public:
	void t3s()
	{
		printf("c#语言");
	}
};

void test()
{
	//test01 ls;
	//ls.test1();
	//ls.test2();
	//ls.test3();
	//t1 ls1;
	//ls1.a = 200;
	//ls1.test1();
	//ls1.test2();
	//ls1.test3();
	//t2 ls2;
	//ls2.a = 200;
	//ls2.test1();
	//ls2.test2();
	//ls2.test3();
	test01 ls;
	ls.test1();
	ls.test2();
	ls.test3();
	printf("------------------------------\n");
	t1 ls1;
	ls1.test1();
	ls1.test2();
	ls1.test3();
	ls1.t1s();
	printf("------------------------------\n");
	t2 ls2;
	ls2.test1();
	ls2.test2();
	ls2.test3();
	ls2.t2s();

	printf("------------------------------\n");
	t3 ls3;
	ls3.test1();
	ls3.test2();
	ls3.test3();
	ls3.t3s();


}

class dw
{
public:
	dw()
	{
		a = 100;
	}
	void cs()
	{
		std::cout << a << std::endl;
	}
	int a;
};
class yang :public dw
{
public:
	yang()
	{
		a = 50;
	}
	void cs()
	{
		std::cout << a << std::endl;
	}
	int a;
};
class tuo :public dw
{
public:
	tuo()
	{
		a = 30;
	}
	int a;
};

void test01s()
{
	yang test1;
	tuo test2;
	std::cout<< test1.a <<std::endl;
	std::cout << test2.a << std::endl;

	test1.cs();
	test1.dw::cs();

}


class cs1
{
public:
	void cs()
	{
		std::cout << a << std::endl;
	}
	void cs(int)
	{
		std::cout << a << std::endl;
	}
	 static int a;
};
int cs1::a = 100;
class cs2:public cs1
{
public:
	void cs()
	{
		std::cout << a << std::endl;
	}
	static int a;
};
int cs2::a = 200;
class cs3:public cs1
{
public:
	void cs()
	{
		std::cout << a << std::endl;
	}
	static int a;
};
int cs3::a = 300;
void testkt()
{
	cs1 cs01;
	cs2 cs02;
	cs3 cs03;
	std::cout<< cs01.a <<std::endl;
	std::cout << cs02.cs1::a << std::endl;
	std::cout << cs03.cs1::a << std::endl;
	std::cout << cs1::a << std::endl;
	printf("__________________________\n");
	cs01.cs();
	cs02.cs();
	cs03.cs1::cs(100);
}


class dccs
{
public:
	dccs()
	{
		a = 100;
	}
	void hans()
	{
		std::cout << a << std::endl;
	}
	int a;
};

class tt1 :virtual public dccs
{
public:
	tt1()
	{
		a = 300;
	}
};
class tt2 :virtual public dccs
{
public:
	tt2()
	{
		a = 200;
	}
};


class zj :public tt1, public tt2
{

};
void testcs()
{
	dccs cs;
	cs.a = 100;
	tt1 ss1;
	tt2 ss2;

	zj ss;
	ss.tt1::hans();
	ss.tt2::hans();
	ss.hans();

}
int main()
{
	testcs();
	//testkt();
	//test01s();
	//test();
	return 0;
}