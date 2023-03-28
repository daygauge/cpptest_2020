#pragma once
using namespace std;
#include <iostream>
#include <fstream>

class staffandworkers;
class menu
{
public:
	menu();
	~menu();
	int ofpeoples;
	staffandworkers** s_staffandworkers;
	//标题
	void menus();
	//添加职工
	void add();
	//保存当前文件职工内容
	void WriteF();
	//统计人数
	int NOP();
	//查询文件内容
	void FileM();
	//初始化职工
	void LnitEmp();
	//显示职工信息
	void DisplayInformation();
	//删除职工
	void DeleteEmployee();

	bool cs();
	//查找职工
	void FindEmployees();
	//修改职工
	void xg();
	//按照编号排序
	void paixu();
	//清空所有文档
	void delWD();
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

class handle :public staffandworkers//经理
{
public:
	handle(int id, string name, int deptid);
	virtual void showstaff();//显示个人信息
	virtual string post();//获取岗位

};

class boss :public staffandworkers//总裁
{
public:
	boss(int id, string name, int deptid);
	virtual void showstaff();//显示个人信息
	virtual string post();//获取岗位
};

