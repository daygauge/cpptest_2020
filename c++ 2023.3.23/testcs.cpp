#pragma once
#include "testcs.h"
menu::menu()
{
	this->ofpeoples = 0;
	this->s_staffandworkers = NULL;
}
menu::~menu()
{

}

void menu::menus()//标题
{
	cout << " 0.退出管理程序 " << endl;
	cout << " 1.增加职工信息  " << endl;
	cout << " 2.显示职工信息 " << endl;
	cout << " 3.删除离职职工 " << endl;
	cout << " 4.修改职工信息 " << endl;
	cout << " 5.查找职工信息 " << endl;
	cout << " 6.按照编号排序 " << endl;
	cout << " 7.清空所有文档 " << endl;
	cout << endl;
}

void menu::add()//添加职工
{
	int ls = 0;
	staffandworkers** ls0;
	cout << "输入需要添加的职工数量" << endl;
	cin >> ls;
	if (ls > 0)
	{
		//开辟动态内存
		int cs = this->ofpeoples + ls;
		ls0 = new staffandworkers * [cs];
		if (this->s_staffandworkers != NULL)
		{
			int i = 0;
			while (i < this->ofpeoples)
			{
				ls0[i] = this->s_staffandworkers[i];
				i++;
			}
		}
		int i = 0;//添加的职工个数
		while (i < ls)
		{
			int ids = 0;
			string names;
			int s = 0;
			cout << "请输入第" << i + 1 << "个职工的编号" << endl;
			cin >> ids;
			cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
			cin >> names;
			while (true)
			{
				cout << "请选择第" << i + 1 << "个职工的岗位" << endl
					<< "1.员工" << endl << "2.经理" << endl << "3.总裁" << endl;
				cin >> s;

				staffandworkers* lscs = NULL;
				switch (s)
				{
				case 1:
					lscs = new staff(ids, names, s);
					break;
				case 2:
					lscs = new handle(ids, names, s);
					break;
				case 3:
					lscs = new boss(ids, names, s);
					break;
				default:
					break;
				}
				if (lscs == NULL)
				{
					cout << "选择错误" << endl;
				}
				else
				{
					ls0[this->ofpeoples + i] = lscs;
					break;
				}
			}
			i++;
		}
		//释放原有空间
		if (this->s_staffandworkers != NULL)
		{
			delete[] this->s_staffandworkers;
		}

		this->s_staffandworkers = ls0;//更改新空间指向
		this->ofpeoples = cs;//更新新的个数
		cout << "添加成功" << ls << "名新职工" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}