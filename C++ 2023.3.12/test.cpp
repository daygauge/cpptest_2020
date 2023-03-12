#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
using namespace std;
#include <iostream>


class ls
{
public:
	ls(int num1)
	{
		this->num1 = new int(num1);
	}
	~ls()
	{
		delete num1;
		num1 = NULL;
	}

	ls& operator=(ls& num1)
	{
		if (this->num1 != NULL)
		{
			delete this->num1;
			this->num1 = NULL;
		}
		this->num1 = new int(*num1.num1);

		return *this;
	}


	int* num1;
};
ostream& operator<<(ostream& num1, ls& num2)
{
	num1 << *num2.num1;
	return num1;
}

void test01()
{
	ls ls1(10);
	ls ls2(16);
	ls ls3(17);

	ls3 = ls2 = ls1;


	cout << ls1 << endl;
	cout << ls2 << endl;
	cout << ls3 << endl;

}

class ls2
{
public:
	ls2(int a)
	{
		this->a = a;
	}
	~ls2()
	{

	}
	bool operator==(ls2 ss)
	{
		if (this->a == ss.a)
		{
			return true;
		}
		return false;
	}
	bool operator!=(ls2 ss)
	{
		if (this->a == ss.a)
		{
			return false;
		}
		return true;
	}
	int a;
};

void test02()
{
	ls2 ls01(10);
	ls2 ls02(20);
	if (ls01 == ls02)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
	if (ls01 != ls02)
	{
		cout << "不相等" << endl;
	}
	else
	{
		cout << "相等" << endl;
	}
}


class ls3
{
public:
	ls3(int a)
	{
		this->a = a;
	}
	~ls3()
	{

	}
	void operator()(int a)
	{
		cout << a;
	}

	int a;
};
void test03()
{
	ls3 ls03(10);
	ls03(10);
}
int main()
{
	test01();
	//test02();
	//test03();
	return 0;
}

class Person
{
public:
	Person()
	{
		a = 10;
	}
	Person operator+(Person& ls)
	{
		Person ls1;
		ls1.a = this->a + ls.a;
		return ls1;
	}
	int a;
};
int main()
{
	Person ls1;
	Person ls2;
	Person ls3 = ls1+(ls2);
	cout << ls3.a << endl;
	return 0;
}


class Person1
{
public:
	Person1()
	{
		a = 10;
	}
	int a;
};
ostream& operator<<(ostream& cout, Person1& ls)
{
	cout << ls.a;
	return cout;
}

int main()
{
	Person1 ls;
	cout << ls << endl;
	return 0;
}

class Person2
{
public:
	Person2()
	{
		a = 10;
	}
	Person2& operator++()
	{
		this->a++;
		return *this;
	}
	Person2 operator++(int)
	{
		Person2 ls = *this;
		this->a++;
		return ls;
	}
	int a;
};
ostream& operator<<(ostream& cout, Person2 ls)
{
	cout << ls.a;
	return cout;
}

int main()
{
	Person2 ls;
	cout << ++ls << endl;
	cout << ls++ << endl;

	return 0;
}


class Person3
{
public:
	Person3(int a)
	{
		this->a = new int(a);
	}
	~Person3()
	{
		delete a;
	}
	Person3& operator=(Person3& ls)
	{
		if (this->a != NULL)
		{
			delete a;
			a = NULL;
		}
		this->a = new int(*ls.a);
		return *this;
	}
	int* a;
};

ostream& operator<<(ostream& cout, Person3& ls)
{
	cout << *ls.a;
	return cout;
}

int main()
{
	Person3 ls1(10);
	Person3 ls2(20);
	Person3 ls3(30);
	ls3 = ls1 = ls2;
	cout << ls3 << endl;
	return 0;
}

class Person4
{
public:
	Person4(int a)
	{
		this->a = a;
	}
	bool operator==(Person4 ss)
	{
		if (this->a == ss.a)
		{
			return true;
		}
		return false;
	}
	bool operator!=(Person4 ss)
	{
		if (this->a == ss.a)
		{
			return false;
		}
		return true;
	}
	int a;
};

int main()
{
	Person4 ls1(10);
	Person4 ls2(20);
	if (ls1 == ls2)
	{
		cout << "相等" << endl;
	}
	else if(ls1 != ls2)
	{
		cout << "不相等" << endl;
	}
	return 0;
}

class Person5
{
public:
	void operator()(string a)
	{
		cout << a;
	}
};
void main()
{
	Person5 ls;
	ls("张三");
}