#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.hpp"
#define CASE break;case

void test01()
{
	speech s;
	int a = 1;
	while (a)
	{
		s.title();
		cin >> a;
		switch (a)
		{
		case 1 :
		    s.kickoff();
		CASE 2 :
		    s.takenotes();
		CASE 3 :
		    s.emptys();
		CASE 4 :
			return;
		default:
			cout << "输入错误,请重新输入" << endl;
			break;
		}
	}
}
int main()
{
	test01();
	return 0;
}