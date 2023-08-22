#define _CRT_SECURE_NO_WARNINGS 1
#include "tests.h"
//struct  xs
//{
//	string mane;
//	int fs;
//};
//struct  ls
//{
//	string mane;
//	struct  xs ddxs[5];
//};
//void cshua(struct ls ss[], int a)
//{
//	string lsz = "ABCDE";
//	for (int i = 0; i < a; i++)
//	{
//		ss[i].mane = "meisdz_";
//		ss[i].mane += lsz[i];
//		for (int j = 0; j < 5; j++)
//		{
//			ss[i].ddxs[j].mane = "xzname_";
//			ss[i].ddxs[j].mane += lsz[j];
//			int s = rand() % 61 + 40;
//			ss[i].ddxs[j].fs = s;
//		}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	struct ls ss[3];
//	int csdx = sizeof(ss) / sizeof(ss[0]);
//	cshua(ss,csdx);
//	for (int i = 0; i < csdx; i++)
//	{
//		cout <<"老师名称:"<< ss[i].mane << "\n";
//		for (int j = 0; j < 5; j++)
//		{
//			cout <<"\t学生名称:" << ss[i].ddxs[j].mane << " ";
//			cout << ss[i].ddxs[j].fs << "\n";
//		}
//	}
//	return 0;
//}
#define CASE break; case


//void cs()
//{
//	Books txr;
//	txr.dqgs = 0;
//	AddContacts(&txr);
//	AddContacts(&txr);
//	AddContacts(&txr);
//
//	ShowContacts(&txr);
//
//	DeleteContacts(&txr);
//
//	ShowContacts(&txr);
//
//
//	system("pause");
//	system("cls");
//}


void dabt()
{
	cout << "******************************************************\n";
	cout << "*************1   添加联系人      *********************\n";
	cout << "*************2   显示联系人      *********************\n";
	cout << "*************3   删除联系人      *********************\n";
	cout << "*************4   查找联系人      *********************\n";
	cout << "*************5   修改找联系人    *********************\n";
	cout << "*************6   销毁联系人列表  *********************\n";
	cout << "******************************************************\n";

}
//int main()
//{
//	Books txr;
//	txr.dqgs = 0;
//	int a = 0;
//	do
//	{
//		dabt();
//		cout << "请输入需要执行的命令：";
//		cin >> a;
//		switch (a)
//		{
//		case 1:AddContacts(&txr);
//		CASE 2:ShowContacts(&txr);
//		CASE 3:DeleteContacts(&txr);
//		CASE 4:SeekContacts(&txr);
//		CASE 5:ReviseContacts(&txr);
//		CASE 6:EmptyContacts(&txr);
//		default:
//		cout << "输入错误请重新输入";
//			break;
//		}
//	} while (a);
//
//	return 0;
//}