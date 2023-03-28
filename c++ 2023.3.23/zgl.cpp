#define _CRT_SECURE_NO_WARNINGS 1
#include "testcs.h"

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