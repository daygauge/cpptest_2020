#pragma once
#include <stddef.h> 

template<class T>
class MyArrar
{
public:
	MyArrar(int M_cs)
	{
		//cout << "构造1" << endl;
		this->M_testcssz = new T[M_cs];
		this->M_testszdax = M_cs;
		this->M_testszgs = 0;
	}
	MyArrar(MyArrar& cs)
	{
		//cout << "构造2" << endl;
		this->M_testcssz = new T[cs.M_testszdax];
		this->M_testszdax = cs.M_testszdax;
		this->M_testszgs = cs.M_testszgs;
		for (int i = 0; i < cs.M_testszgs; i++)
		{
			this->M_testcssz[i] = cs.M_testcssz[i];
		}
	}
	~MyArrar()
	{
		//cout << "析构" << endl;
		if (this->M_testcssz != NULL)
		{
			delete[] this->M_testcssz;
			this->M_testcssz = NULL;
			this->M_testszdax = 0;
			this->M_testszgs = 0;
		}
	}

	MyArrar& operator=(MyArrar& cs)
	{
		//cout << "operator=" << endl;
		if (this->M_testcssz != NULL)
		{
			delete[] this->M_testcssz;
			this->M_testcssz = NULL;
			this->M_testszdax = 0;
			this->M_testszgs = 0;
		}
		this->M_testcssz = new T[cs.M_testszdax];
		this->M_testszdax = cs.M_testszdax;
		this->M_testszgs = cs.M_testszgs;
		for (int i = 0; i < cs.M_testszgs; i++)
		{
			this->M_testcssz[i] = cs.M_testcssz[i];
		}
		return *this;
	}
	//尾插尾删
	void Tailinsertion(T s)
	{
		if (this->M_testszgs < this->M_testszdax)
		{
			this->M_testcssz[this->M_testszgs] = s;
			this->M_testszgs++;
		}
	}
	void Taildeletion(T s)
	{
		if (this->M_testszgs > 0)
		{
			this->M_testcssz[this->M_testszgs] = 0;
			this->M_testszgs--;
		}
		else
		{
			cout << "数组为空" << endl;
		}
	}
	//下标访问
	T& operator[](int a)
	{
		return this->M_testcssz[a];
	}
	//void SubscriptAccess(int a)
	//{
	//	if (a >= 0 && a < this->M_testszgs)
	//	{
	//		cout << this->M_testcssz[a] << endl;
	//	}
	//	else
	//	{
	//		cout << "下标越界" << endl;
	//		return;
	//	}
	//}
	//获取元素个数与容量
	void gainnumbervolume()
	{
		cout << "元素个数为:" << this->M_testszgs<<endl
			<< "当前最大容量为:" << this->M_testszdax << endl;
	}

public:
	T* M_testcssz;
	int M_testszgs;
	int M_testszdax;

};