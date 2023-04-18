#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#include "fileclass.h"

extern vector<MachineRoom*> m;
extern multimap<string, macyys> macyy;

void student::title()
{
	cout << "-------------------------------" << endl;
	cout << "当前账号信息" << " 学号:" << this->test1 << " 姓名:" << this->test2 << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看我的预约" << endl;
	cout << "3.查看所有预约    " << endl;
	cout << "4.取消预约        " << endl;
	cout << "0.注销登入        " << endl;
	cout << "------------------------------" << endl;
}
bool student::login()
{
	//用于对比密码是否正确
	string n1;
	string n2;
	string n3;

	string a1;
	string a2;
	string a3;
	fstream fs(XSHENG, ios::in);

	cout << "请输入学号:";
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
			this->test1 = n1;
			this->test2 = n2;
			return true;
		}
	}
	fs.close();
	cout << "账号或密码错误" << endl;
	system("pause");
	system("cls");
	return false;
}
void student::applyformac()
{
	int date = 0;//星期
	int shi = 0;//上下午
	int mac = 0;//机房号
	string datetest;//写入星期
	string shitest;//写入上下午
	string mactest;//写入机房号

	do
	{
		cout << "请选择预约日期" << endl;
		cout << "1.星期一" << endl;
		cout << "2.星期二" << endl;
		cout << "3.星期三" << endl;
		cout << "4.星期四" << endl;
		cout << "5.星期五" << endl;
		cout << endl;
		cin >> date;
	} while (date>5||date<1);
	switch (date)
	{
	case 1:
		datetest = "星期一";
		break;
	case 2:
		datetest = "星期二";
		break;
	case 3:
		datetest = "星期三";
		break;
	case 4:
		datetest = "星期四";
		break;
	case 5:
		datetest = "星期五";
		break;
	default:
		break;
	}

	do
	{
		cout << "请选择预约时间" << endl;
		cout << "1.上午/2.下午" << endl;
		cin >> shi;
	} while (shi > 2 || shi < 1);
	switch (shi)
	{
	case 1:
		shitest = "上午";
		break;
	case 2:
		shitest = "下午";
		break;
	default:
		break;
	}

	do
	{
		cout << "请选择机房" << endl;
		cout << "当前可用机房为:" << endl;
		manage().viewmac();//管理员类机房打印接口

		cin >> mac;
	} while (mac<1 || mac>m.size());
	switch (shi)
	{
	case 1:
		mactest = "1号机房";
		break;
	case 2:
		mactest = "2号机房";
		break;
	default:
		break;
	}

	ofstream ofs(DATE, ios::app);
	ofs << datetest << endl;
	ofs << shitest << endl;
	ofs << mactest << endl;
	//记录身份信息
	ofs << test1 << endl;
	ofs << test2 << endl; 
	ofs << TOEX << endl;//预约状态
	cout << "预约添加成功,审核中.." << endl;
	system("pause");
	system("cls");
}
void student::viewmac()
{
	bool i = true;//判断预约是否为空
	//打印预约信息
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		if (it->first == this->test2)
		{
			cout << " 预约时间:" << it->second.mac_date << " " << it->second.mac_shi
				<< " 预约机房:" << it->second.mac_mac
				<< " 预约状态:" << it->second.m_state << endl;
			i = false;
		}
	}
	if (i)
	{
		cout << "目前暂无预约" << endl;
		return;
	}
	system("pause");
	system("cls");
}
void student::viewmacs()
{
	if (macyy.begin() == macyy.end())
	{
		cout << "目前暂无预约" << endl;
		return;
	}
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		cout <<"学号:"<< it->second.m_stuid
			<<" 姓名:"<< it->second.m_name
			<< " 预约时间:" << it->second.mac_date << " " << it->second.mac_shi
			<< " 预约机房:" << it->second.mac_mac
			<< " 预约状态:" << it->second.m_state << endl;
	}
	system("pause");
	system("cls");
}
void student::cancellmac()
{
	int i = 0;//记录当前预约总数
	int age = 0;
	//打印预约信息
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		if (it->first == this->test2)
		{
			cout <<i<<" "
				<< " 预约时间:" << it->second.mac_date << " " << it->second.mac_shi
				<< " 预约机房:" << it->second.mac_mac
				<< " 预约状态:" << it->second.m_state << endl;
			i++;
		}
	}
	if (!i)
	{
		cout << "目前暂无预约..." << endl;
		return;
	}
	cout << endl;
	cout << "请输入需要取消的预约序号:";
	cin >> age;
	if (age >= i || age < 0)
	{
		cout << "序号错误或不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	//更改预约容器中的信息
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		if (it->first == this->test2)
		{
			if (age == 0)
			{
				it->second.m_state = CANC;
			}
			age--;
		}
	}
	this->renew();//更新文件
	cout << "取消成功" << endl;
	system("pause");
	system("cls");
}
void student::renew()
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