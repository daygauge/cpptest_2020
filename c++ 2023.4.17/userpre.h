#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#include <fstream>


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

	string test1;
	string test2;
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