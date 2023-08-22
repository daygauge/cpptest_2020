#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

//int main()
//{
//	int a = 0;
//	a++;
//	cout << "a = " << a << endl;
//
//	string num = "hailo wolid";
//	cout << num << endl;
//	char as = 's';
//	cout << as << "\n";
//
//	int ss = 0;
//	cin >> ss;
//	cout << ss;
//
//	return 0;
//}


//int main()
//{
//
//	int a = 0, b = 0, c = 0;
//	cin >> a;
//	cin >> b;
//	cin >> c;
//
//	if (a > b&&a>c)
//	{
//		cout << a << endl;
//	}
//	else if (b>a&&b>c)
//	{
//		cout << b << endl;
//	}
//	else
//	{
//		cout << c << endl;
//	}
//
//
//	return 0;
//}
//int main()
//{
//	int i = 100;
//	int a, b, c;
//	do
//	{
//		a = i % 10;
//		b = i / 10 % 10;
//		c = i / 100 % 10;
//		if (i==((a*a*a)+(b*b*b)+(c*c*c)))
//		{
//			cout << i << endl;
//		}
//
//	} while (++i<1000);
//	return 0;
//}\


int main()
{
	for (int i = 1; i <= 100; i++)
	{
		if ((i % 10 == 7) || (i % 100 / 10 == 7) || (i % 7==0))
		{
			cout << i << endl;
		}
	}


	return 0;
}