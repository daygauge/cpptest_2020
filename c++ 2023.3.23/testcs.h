#pragma once
using namespace std;
#include <iostream>

class menu
{
public:
	int ofpeoples;
	staffandworkers** s_staffandworkers;

	void menus();//标题

	void add();//添加职工



};



class staffandworkers//职工
{
public:
	virtual void showstaff() = 0;//显示个人信息
	virtual string post() = 0;//获取岗位

	int id = 0;
	string name;
	int deptid = 0;
};

class staff :public staffandworkers//员工
{
public:
	staff(int id, string name, int deptid);
	virtual void showstaff();//显示个人信息
	virtual string post();//获取岗位
};
staff::staff(int id, string name, int deptid)
{
	this->id = id;
	this->name = name;
	this->deptid = deptid;
}

void staff::showstaff()
{
	cout << "职工编号:" << this->id
		<< "\t职工姓名:" << this->name
		<< "\t岗位:" << this->deptid
		<< "\t岗位职责:完成经理交接的任务" << endl;
}
string staff::post()
{
	return "员工";
}

class handle :public staffandworkers//经理
{
public:
	handle(int id, string name, int deptid);
	virtual void showstaff();//显示个人信息
	virtual string post();//获取岗位

};
handle::handle(int id, string name, int deptid)
{
	this->id = id;
	this->name = name;
	this->deptid = deptid;
}
void handle::showstaff()
{
	cout << "职工编号:" << this->id
		<< "\t职工姓名:" << this->name
		<< "\t岗位:" << this->deptid
		<< "\t岗位职责:分配总裁交接的任务" << endl;
}
string handle::post()
{
	return "经理";
}

class boss :public staffandworkers//总裁
{
public:
	boss(int id, string name, int deptid);
	virtual void showstaff();//显示个人信息
	virtual string post();//获取岗位

};
boss::boss(int id, string name, int deptid)
{
	this->id = id;
	this->name = name;
	this->deptid = deptid;
}
void boss::showstaff()
{
	cout << "职工编号:" << this->id
		<< "\t职工姓名:" << this->name
		<< "\t岗位:" << this->deptid
		<< "\t岗位职责:发布任务" << endl;
}
string boss::post()
{
	return "总裁";
}
