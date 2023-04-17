#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#include "fileclass.h"

extern vector<string> stuv1;
extern vector<string> teav2;
extern vector<MachineRoom*> m;

manage::manage()
{
	//this->ml = new MachineRoom(1, 50);
	//this->m2 = new MachineRoom(2, 100);
	//this->m.push_back(new MachineRoom(1, 50));
	//this->m.push_back(new MachineRoom(2, 100));
}
void manage::title()
{
	cout << "-----------------------" << endl;
	cout << "1.添加账号    " << endl;
	cout << "2.查看账号    " << endl;
	cout << "3.查看机房    " << endl;
	cout << "4.清空预约    " << endl;
	cout << "0.注销登入    " << endl;
	cout << "-----------------------" << endl;
}

bool manage::login()//登入
{
	//用于对比密码是否正确
	string n1;
	string n2;

	string a1;
	string a2;

	fstream fs(GUANLI, ios::in);
	fs >> n2;
	fs >> a2;
	fs.close();

	cout << "请输入账号:";
	cin >> n1;
	cout << "请输入密码:";
	cin >> a1;

	if (n2 == n1 && a1 == a2)
	{
		system("cls");
		cout << "登入成功..." << endl;
		return true;
	}
	cout << "账号或密码错误" << endl;
	system("pause");
	system("cls");
	return false;

}
void manage::addna()//添加账号
{
	cout <<"--------------------------------" << endl;
	cout << "请选择需要添加的账号类型" << endl;
	cout << "1.学生代表账号" << endl;
	cout << "2.老师账号" << endl;
	cout << "0.返回" << endl;
	cout << "--------------------------------" << endl;
	int a = 0;
	cin >> a;
	if (a == 0)
	{
		system("cls");
		return;
	}
		
	if (a == 1)
	{
		string n1;
		string n2;
		string n3;

		cout << "请输入学号: ";
		cin >> n1;
		cout << "请输入姓名: ";
		cin >> n2;
		cout << "请输入密码:" << endl;
		cin >> n3;

		ofstream ofs(XSHENG, ios::app);
		ofs << n1 << endl;
		ofs << n2 << endl;
		ofs << n3 << endl;
		ofs.close();

		cout << "账号添加成功" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		string n1;
		string n2;
		string n3;

		cout << "请输入职工号: " ;
		cin >> n1;
		cout << "请输入姓名: ";
		cin >> n2;
		cout << "请输入密码:" << endl;
		cin >> n3;

		ofstream ofs(LSHI, ios::app);
		ofs << n1 << endl;
		ofs << n2 << endl;
		ofs << n3 << endl;
		ofs.close();

		cout << "账号添加成功" << endl;
		system("pause");
		system("cls");
	}

	//重新加载所有账号密码信息
	stuv1.clear();
	teav2.clear();
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
}
void manage::viewna()//查看账号
{
	int i = 0;
	cout << "学生代表账号" << endl;
	if (stuv1.begin() == stuv1.end())
		cout << "暂无学生账号" << endl;
	for (vector<string>::iterator it = stuv1.begin(); it != stuv1.end();)
	{
		cout << i << " 学号:" << *it << " 姓名:" << *(it + 1) << " 密码:" << *(it + 2) << endl;
		it += 3;
		i++;
	}

	i = 0;
	cout << "教师账号" << endl;
	if (teav2.begin() == teav2.end())
		cout << "暂无学生账号" << endl;
	for (vector<string>::iterator it = teav2.begin(); it != teav2.end();)
	{
		cout << i << " 职工号:" << *it << " 姓名:" << *(it + 1) << " 密码:" << *(it + 2) << endl;
		it += 3;
		i++;
	}
	system("pause");
}
void manage::viewmac()//查看机房
{
	for (vector<MachineRoom*>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "编号:" << (*it)->m1ls << " 容量:" << (*it)->m2ls << endl;
	}
}
void manage::emptymac()//清空预约
{
	ofstream n1(DATE1, ios::out);
	n1.close();
	ofstream n2(DATE2, ios::out);
	n2.close();
	ofstream n3(DATE3, ios::out);
	n3.close();
	ofstream n4(DATE4, ios::out);
	n4.close();
	ofstream n5(DATE5, ios::out);
	n5.close();
	cout << "已清空所有预约" << endl;
	system("pause");
	system("cls");
}