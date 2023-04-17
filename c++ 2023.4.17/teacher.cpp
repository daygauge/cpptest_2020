#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#include "fileclass.h"

void teacher::title()
{
	cout << "-----------------------" << endl;
	cout << "1.查看所有预约        " << endl;
	cout << "4.审核预约        " << endl;
	cout << "0.注销登入        " << endl;
	cout << "-----------------------" << endl;
}
bool teacher::login()//登入
{
	//用于对比密码是否正确
	string n1;
	string n2;
	string n3;

	string a1;
	string a2;
	string a3;
	fstream fs(LSHI, ios::in);

	cout << "请输入职工号:";
	cin >> n1;
	cout << "请输入姓名:";
	cin >> n2;
	cout << "请输入密码:";
	cin >> n3;

	//判断是否有匹配的账号密码
	while (fs >> a1 && fs >> a2 && fs >> a3)
	{
		if (n1 == a1 && n2 == a2 && n3 == a3)
		{
			system("cls");
			cout << "登入成功..." << endl;
			fs.close();
			return true;
		}
	}
	fs.close();
	cout << "账号或密码错误" << endl;
	system("pause");
	system("cls");
	return false;
}
void teacher::ViewApp()
{

}
void teacher::toExamineacs()
{

}