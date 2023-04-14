#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.h"


void test01()
{
	srand((unsigned int)time(nullptr));
	speech ls;
	int a = 0;
	do
	{
		ls.title();
		cin >> a;
		switch (a)
		{
		case 0:
			exit(0);
			break;
		case 1:
			ls.speechhost();
			break;
		case 2:
			ls.filerecord();
			break;
		case 3:
			ls.empty();
		}
	} while (a);
	//for (vector<int>::iterator it = ls.v2.begin(); it != ls.v2.end(); it++)
	//{
	//	cout << *it << " " << ls.m[*it].m_name << " " << ls.m[*it].m_score << endl;
	//}
	//for (map <int, selecthand>::iterator it = ls.m.begin(); it != ls.m.end(); it++)
	//{
	//	cout << it->first << " " << it->second.m_name << " " << it->second.m_score << endl;
	//}
}
int main()
{
	test01();
	return 0;
}