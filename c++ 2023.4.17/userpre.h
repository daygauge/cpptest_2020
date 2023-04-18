#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#include <fstream>
void ls();

class MachineRoom
{
public:
	MachineRoom(int a, int b) :m1ls(a), m2ls(b){}
	//机房编号容量
	int m1ls;
	int m2ls;
	map<int, int> M;
	//编号,预约信息
};

class macyys
{
public:
	macyys(){}
	macyys(string date, string shi, string mac, string stuid, string name, string state = "审核中") :
		mac_date(date),mac_shi(shi),mac_mac(mac),m_stuid(stuid),m_name(name),m_state(state){}
	
	string mac_date;//星期
	string mac_shi;//时间
	string mac_mac;//机房
	string m_stuid;//学号
	string m_name;//姓名
	string m_state;//当前预约状态
};
//学生
class student
{
public:
	void title();
	//登入
	bool login();
	//申请预约
	void applyformac();
	//查看我的预约
	void viewmac();
	//查看所有预约
	void viewmacs();
	//取消预约
	void cancellmac();
	void renew();//更新预约文件内容


	string test1;//学号
	string test2;//姓名
};

//老师
class teacher
{
public:
	void title();
	//登入
	bool login();
    //查看所有预约
	void ViewApp();
	//审核预约
	void toExamineacs();
	void renew();//更新预约文件内容
};

//管理员
class manage
{
public:
	manage();
	void title();

	//登入
	bool login();
	//添加账号
	void addna();
	//查看账号
	void viewna();
	//查看机房
	void viewmac();
	//清空预约
	void emptymac();
};

