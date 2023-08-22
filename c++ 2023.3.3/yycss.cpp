#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
using namespace std;



void hans(const int& a)
{
	//a = 100;
	cout << a << "\n";
}
//int main()
//{
//	//int a = 10;
//	////int& b = a;
//	////b = 20;
//	////cout << a << "\n";
//	////cout << b << "\n";
//	////cout << a << "\n";
//	////int s =  hans(a) = 1000;
//	////cout << a << "\n";
//	////cout << s << "\n";
//	//const int& b = 100;
//	//cout << b <<"\n";
//
//	int a = 10;
//	system("pause");
//}
//int main()
//{
//	int a = 10;
//
//	cout << a << endl;
//	h(a);
//	cout << a << endl;
//
//	system("pause");
//}

int& h(int a)
{
	a = 100;
	return a;
}
int main()
{
	const int& a = 10;
	cout << a << endl;

	system("pause");
	return 0;
}