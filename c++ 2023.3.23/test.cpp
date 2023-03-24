#define _CRT_SECURE_NO_WARNINGS 
#include "testcs.h"

#define CASE break;case

//void test01()
//{
//	staffandworkers* cs = new staff(1, "张三", 1);
//	cs->show();
//	cout << cs->post() << endl;
//
//	staffandworkers* cs1 = new handle(2, "李四", 2);
//	cs1->show();
//	cout << cs1->post() << endl;
//
//	staffandworkers* cs2 = new boss(3, "王五", 3);
//	cs2->show();
//	cout << cs2->post() << endl;
//}
int main()
{
	menu test;
	//test01();
	int a = 0;
	do
	{
		test.menus();
		cout << "请输入需要执行的命令" << endl;
		cin >> a;
		switch (a)
		{
		case 0:
			cout << "欢迎下次使用" << endl;
			CASE 1:
			test.add();
			CASE 2 :
			CASE 3 :
			CASE 4 :
			CASE 5 :
			CASE 6 :
			CASE 7 :
			CASE 8 :
		default:
			system("cls");
			break;
		}
	} while (a);
	system("pause" );
	return 0;
}