#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.h"
using namespace std;
void test01()
{
	speech sp;
	int a = 0;
	do
	{
		sp.title();
		cin >> a;
		switch (a)
		{
		case 1:
			sp.assemblecs();
			break;
		case 2:
			sp.loadRecord();
			break;
		case 3:
			break;
		case 0:
			exit(0);
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	} while (a);


	//for (map<int, selecthand>::iterator it = sp.m.begin(); it != sp.m.end(); it++)
	//{
	//	//cout << it->first << " " << it->second.m_name<<" "<<it->second.m_divide << endl;
	//	for (int i = 0; i < 6; i++)
	//	{
	//		if (it->first == sp.v2[i])
	//		{
	//			cout << it->first << " " << it->second.m_name << " " << it->second.m_divide << endl;
	//			break;
	//		}
	//	}
	//}

}

int main()
{
	test01();
	return 0;
}