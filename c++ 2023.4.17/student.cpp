#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#include "fileclass.h"

extern vector<MachineRoom*> m;
void student::title()
{
	cout << "-----------------------" << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看我的预约" << endl;
	cout << "3.查看所有预约    " << endl;
	cout << "4.取消预约        " << endl;
	cout << "0.注销登入        " << endl;
	cout << "-----------------------" << endl;
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
	
	do
	{
		cout << "请选择预约时间" << endl;
		cout << "1.上午/2.下午" << endl;
		cin >> shi;
	} while (shi > 2 || shi < 1);
	
	do
	{
		cout << "请选择机房" << endl;
		cout << "当前可用机房为:" << endl;
		manage().viewmac();//管理员类机房打印接口

		cin >> mac;
	} while (mac<1 || mac>m.size());
	
	//记录文件
	ofstream ofs;
	switch(date)
	{
	case 1:
		ofs.open(DATE1, ios::app);
		break;
	case 2:
		ofs.open(DATE2, ios::app);
		break;
	case 3:
		ofs.open(DATE3, ios::app);
		break;
	case 4:
		ofs.open(DATE4, ios::app);
		break;
	case 5:
		ofs.open(DATE5, ios::app);
		break;
	}
	ofs << date;
	ofs << shi;
	ofs << mac;
	ofs << endl;
	//记录身份信息
	ofs << test1 << endl;
	ofs << test2 << endl;
	cout << "预约添加成功,审核中.." << endl;
	system("pause");
	system("cls");
}
void student::viewmac()
{

}
void student::viewmacs()
{

}
void student::cancellmac()
{

}