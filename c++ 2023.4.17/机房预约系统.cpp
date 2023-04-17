#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#define CASE break;case
#include "fileclass.h"
vector<string> stuv1;//学生账号存储容器
vector<string> teav2;//老师账号存储容器
vector<MachineRoom*> m;//机房信息

void students(student * ls)//学生
{
	if (!ls->login())
		return;

	int a = 0;
	do
	{
		ls->title();
		cin >> a;
		switch (a)
		{
		case 1:
			ls->applyformac();
			CASE 2 :
			ls->viewmac();
			CASE 3 :
			ls->viewmacs();
			CASE 4:
			ls->cancellmac();
			CASE 0:
			system("cls");
			return;
			break;
		default:
			system("cls");
			break;
		}
	} while (a);
}

void teachers(teacher* ls)//老师
{
	if (!ls->login())
		return;

	int a = 0;
	do
	{
		ls->title();
		cin >> a;
		switch (a)
		{
		case 1:
			ls->ViewApp();
		CASE 2 :
			ls->toExamineacs();
		CASE 0:
		    system("cls");
			return;
			break;
		default:
			system("cls");
			break;
		}
	} while (a);
}

void manges(manage* ls)//管理员
{
	if (!ls->login())
		return;

	int a = 0;
	do
	{
		ls->title();
		cin >> a;
		switch (a)
		{
		case 1:
			ls->addna();
		CASE 2 :
			ls->viewna();
		CASE 3 :
		 	ls->viewmac();
		CASE 4:
			ls->emptymac();
		CASE 0:
		    system("cls");
			return;
			break;
		default:
			system("cls");
			break;
		}
	} while (a);
}
void titlestest()
{
	cout << "-----------------------" << endl;
	cout << "请登入身份..." << endl;
	cout << "  1.学生" << endl;
	cout << "  2.老师" << endl;
	cout << "  3.管理员" << endl;
	cout << "-----------------------" << endl;
}
void jiaz()//加载初始信息
{
	string ls;
	fstream fs(XSHENG, ios::in);
	while (fs >> ls)
	{
		stuv1.push_back(ls);
		ls.clear();
	}
	fs.close();

	ls.clear();
	fstream fs1(LSHI, ios::in);
	while (fs1 >> ls)
	{
		teav2.push_back(ls);
		ls.clear();
	}
	fs1.close();

	 m.push_back(new MachineRoom(1, 50));
     m.push_back(new MachineRoom(2, 100));
}
int main()
{
	jiaz();
	int a = 0;
	student ls;
	teacher ls1;
	manage ls2;
	do
	{
		titlestest();
		cin >> a;
		switch (a)
		{
		case 1:
			students(&ls);
			CASE 2 :
			teachers(&ls1);
			CASE 3 :
			manges(&ls2);
			break;
		default:
			break;
		}
	} while (a);
	return 0;
}