#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#include "fileclass.h"

extern multimap<string, macyys> macyy;
void teacher::title()
{
	cout << "-----------------------" << endl;
	cout << "1.查看所有预约        " << endl;
	cout << "2.审核预约        " << endl;
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
	if (macyy.begin() == macyy.end())
	{
		cout << "目前暂无预约" << endl;
		return;
	}
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		cout << "学号:" << it->second.m_stuid
			<< " 姓名:" << it->second.m_name
			<< " 预约时间:" << it->second.mac_date << " " << it->second.mac_shi
			<< " 预约机房:" << it->second.mac_mac
			<< " 预约状态:" << it->second.m_state << endl;
	}
	system("pause");
	system("cls");
}
void teacher::toExamineacs()
{
	int i = 0;//记录当前预约总数
	int age = 0;

	if (macyy.begin() == macyy.end())
	{
		cout << "目前暂无预约" << endl;
		return;
	}

	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		cout <<i<<" "
			<< "学号:" << it->second.m_stuid
			<< " 姓名:" << it->second.m_name
			<< " 预约时间:" << it->second.mac_date << " " << it->second.mac_shi
			<< " 预约机房:" << it->second.mac_mac
			<< " 预约状态:" << it->second.m_state << endl;
		i++;
	}

	cout << "请选择需要审批的预约序号:";
	cin >> age;
	if (age >= i || age < 0)//判断序号是否存在
	{
		cout << "序号不存在" << endl;
		return;
	}

	for (multimap<string, macyys>::iterator its = macyy.begin(); its != macyy.end(); its++)
	{
		if (age == 0)
		{
			if (its->second.m_state == CANC || its->second.m_state == TDLS1 || its->second.m_state == TDLS2)
			{
				cout << "此预约已被取消或已被审批" << endl;
				return;
			}
			while (true)
			{
				cout << "------------------" << endl;
				cout << "1.通过预约申请" << endl;
				cout << "2.驳回预约申请" << endl;
				cout << "------------------" << endl;
				cout << "请选择:";
				cin >> age;
				if (age == 1)
				{
					its->second.m_state = TDLS1;
					renew();
					system("pause");
					system("cls");
					return;
				}
				else if (age == 2)
				{
					its->second.m_state = TDLS2;
					renew();
					system("pause");
					system("cls");
					return;
				}
				cout << "选择错误,请重新选择" << endl;
			}
		}
		age--;
	}

}

void teacher::renew()
{
	//更新文件中所有内容为macyy机房信息
	ofstream ofs(DATE, ios::out);
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		ofs << it->second.mac_date << endl;
		ofs << it->second.mac_shi << endl;
		ofs << it->second.mac_mac << endl;
		ofs << it->second.m_stuid << endl;
		ofs << it->second.m_name << endl;
		ofs << it->second.m_state << endl;
	}
}