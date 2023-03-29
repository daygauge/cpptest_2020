#pragma once
#include "testcs.h"
#define DILEL "EmployeeD.txt"
#include <iostream>
menu::menu()
{
	this->ofpeoples = 0;
	this->s_staffandworkers = NULL;
	this->FileM();

	int i = this->NOP();
	cout << "导入成功当前职工个数为:" << i << endl;
	this->ofpeoples = i;
	this->s_staffandworkers = new staffandworkers * [this->ofpeoples];

	this->LnitEmp();

	for (int s = 0; s < this->ofpeoples; s++)
	{
		cout << this->s_staffandworkers[s]->id << " "
			<< this->s_staffandworkers[s]->name << " "
			<< this->s_staffandworkers[s]->deptid << endl;
	}
}
menu::~menu()
{
	for (int i = 0; i < this->ofpeoples; i++)
	{
		delete this->s_staffandworkers[i];
	}
	if (this->s_staffandworkers != NULL)
	{
		delete[] this->s_staffandworkers;
	}
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
			bool bool_s = false;
			while (true)
			{
				if (bool_s)
				{
					break;
				}
				cout << "请输入第" << i + 1 << "个职工的编号" << endl;
				cin >> ids;
				int m_i = 0;
				if (this->ofpeoples)
				{
					while (m_i < this->ofpeoples + i )
					{
						if (ls0[m_i]->id == ids)
						{
							m_i++;
							break;
						}
						m_i++;
					}
					if (ls0[m_i-1]->id == ids)
					{
						cout << "职工编号已存在,请重新输入" << endl;
					}
					else
					{
						bool_s = true;
					}
				}
				else
				{
					if (i)
					{
						while (m_i < i)
						{
							if (ls0[m_i]->id == ids)
							{
								m_i++;
								break;
							}
							m_i++;
						}
						if (ls0[m_i-1]->id == ids)
						{
							cout << "职工编号已存在,请重新输入" << endl;
						}
						else
						{
							bool_s = true;
						}
					}
					else
					{
						bool_s = true;
					}
				}
			}
			while (true)
			{
				cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
				cin >> names;
				if (names.find(' ') == string::npos)
				{
					break;
				}
				else
				{
					cout << "请不要在名称中带有空格" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
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
		this->WriteF();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

void menu::WriteF()
{
	ofstream ofs;
	ofs.open(DILEL, ios::out);
	for (int i = 0; i < this->ofpeoples; i++)
	{
		ofs << this->s_staffandworkers[i]->id << " "
			<< this->s_staffandworkers[i]->name << " "
			<< this->s_staffandworkers[i]->deptid << endl;
	}
	ofs.close();
}

void menu::FileM()
{
	//文件不存在
	ifstream ifs;
	ifs.open(DILEL, ios::in);
	if (!ifs.is_open())
	{
		this->ofpeoples = 0;
		this->s_staffandworkers = NULL;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//文件存在但是为空
	char cs;
	ifs >> cs;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->ofpeoples = 0;
		this->s_staffandworkers = NULL;
		ifs.close();
		return;
	}
	ifs.close();
}

void menu::LnitEmp()//文件存在并不为空
{

	ifstream ifs;
	ifs.open(DILEL, ios::in);

	int id = 0;
	string id1;
	int id2;

	int cs = 0;
	while (ifs >> id && ifs >> id1 && ifs >> id2)
	{
		staffandworkers* ls = NULL;
		if (id2 == 1)
		{
			ls = new staff(id, id1, id2);
		}
		else if (id2 == 2)
		{
			ls = new handle(id, id1, id2);
		}
		else
		{
			ls = new boss(id, id1, id2);
		}
		this->s_staffandworkers[cs] = ls;
		cs++;
	}
	ifs.close();
}

int menu::NOP()
{
	ifstream ifs;
	ifs.open(DILEL, ios::in);
	int i = 0;
	int id = 0;
	string id1;
	int id2;
	while (ifs >> id && ifs >> id1 && ifs >> id2)
	{
		i++;
	}
	ifs.close();
	return i;
}

void menu::DisplayInformation()
{
	for (int i = 0; i < this->ofpeoples; i++)
	{
		cout << "职工编号:" << this->s_staffandworkers[i]->id
			<< "\t职工姓名:" << this->s_staffandworkers[i]->name
			<< "\t岗位:" << this->s_staffandworkers[i]->deptid
			<< endl;
	}
	system("pause");
}

int cszgongI;
void menu::DeleteEmployee()
{
	if (this->ofpeoples == 0)
	{
		cout << "当前职工列表为空" << endl;
		return;
	}
	int i = 0;
	if (cs())
	{
		i = cszgongI;
		for (; i < this->ofpeoples - 1; i++)
		{
			this->s_staffandworkers[i] = this->s_staffandworkers[i + 1];
		}
		this->ofpeoples--;
		this->WriteF();
		cout << "删除成功" << endl;
		system("pause");
		return;
	}
	cout << "找不到职工编号" << endl;
	system("pause");
}
void menu::FindEmployees()
{
	bool cs = false;
	int cs1 = 0;
	if (this->ofpeoples == 0)
	{
		cout << "当前职工列表为空" << endl;
		return;
	}

	int m_id;
	string m_name;
	int i = 0;
	cout << "选择查找的方法:1.按照编号查找,0按照姓名查找:";
	cin >> cs1;
	if (cs1)
	{
		cout << "请输入职工编号用于查找:" << endl;
		cin >> m_id;
		while (i < this->ofpeoples)
		{
			if (this->s_staffandworkers[i]->id == m_id)
			{
				cszgongI = i;
				cs = true;
			}
			i++;
		}
	}
	else
	{
		cout << "请输入职工姓名用于查找:" << endl;
		cin >> m_name;
		while (i < this->ofpeoples)
		{
			if (this->s_staffandworkers[i]->name == m_name)
			{
				cszgongI = i;
				cs = true;
			}
			i++;
		}
	}
	if (cs)
	{
		cout << "职工编号:" << this->s_staffandworkers[cszgongI]->id
			<< "\t职工姓名:" << this->s_staffandworkers[cszgongI]->name
			<< "\t岗位:" << this->s_staffandworkers[cszgongI]->deptid
			<< endl;
		system("pause");
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
bool menu::cs()
{
	if (this->ofpeoples == 0)
	{
		cout << "当前职工列表为空" << endl;
		return false;
	}
	int m_id;
	int i = 0;
	cout << "请输入职工编号用于查找:" << endl;
	cin >> m_id;
	while (i < this->ofpeoples)
	{
		if (this->s_staffandworkers[i]->id == m_id)
		{
			cszgongI = i;
			return true;
		}
		i++;
	}
	return false;
}
void menu::xg()
{
	if (this->ofpeoples == 0)
	{
		cout << "当前职工列表为空" << endl;
		return;
	}
	int i = 0;
	if (cs())
	{
		i = cszgongI;
		cout << "需要修改的职工编号: ";
		cin >> this->s_staffandworkers[i]->id;
		cout << "需要修改的职工姓名:" ;
		cin >> this->s_staffandworkers[i]->name;
		while (true)
		{
			cout << "需要修改的职工岗位" << endl;
			cout << "1.员工" << endl << "2.经理" << endl << "3.总裁" << endl;
			cin >> this->s_staffandworkers[i]->deptid;
			if (this->s_staffandworkers[i]->deptid > 0 && this->s_staffandworkers[i]->deptid < 4)
			{
				break;
			}
		}
		if (this->s_staffandworkers[i]->deptid == 1)
		{
			staffandworkers* css = new staff(this->s_staffandworkers[i]->id,
				this->s_staffandworkers[i]->name, this->s_staffandworkers[i]->deptid);
			this->s_staffandworkers[i] = css;
		}
		else if (this->s_staffandworkers[i]->deptid == 2)
		{
			staffandworkers* css = new handle(this->s_staffandworkers[i]->id,
				this->s_staffandworkers[i]->name, this->s_staffandworkers[i]->deptid);
			this->s_staffandworkers[i] = css;
		}
		else
		{
			staffandworkers* css = new boss(this->s_staffandworkers[i]->id,
				this->s_staffandworkers[i]->name, this->s_staffandworkers[i]->deptid);
			this->s_staffandworkers[i] = css;
		}
		this->WriteF();
		cout << "修改成功" << endl;
		system("pause");
	}
}
void menu::paixu()
{
	if (this->ofpeoples == 0)
	{
		cout << "当前职工列表为空" << endl;
		return;
	}
	staffandworkers** lspx = new staffandworkers * [this->ofpeoples];
	for (int s = 0; s < this->ofpeoples; s++)
	{
		if (this->s_staffandworkers[s]->deptid = 1)
		{
			lspx[s] = new staff(this->s_staffandworkers[s]->id,
				this->s_staffandworkers[s]->name, this->s_staffandworkers[s]->deptid);
		}
		else if (this->s_staffandworkers[s]->deptid = 2)
		{
			lspx[s] = new handle(this->s_staffandworkers[s]->id,
				this->s_staffandworkers[s]->name, this->s_staffandworkers[s]->deptid);
		}
		else
		{
			lspx[s] = new boss(this->s_staffandworkers[s]->id,
				this->s_staffandworkers[s]->name, this->s_staffandworkers[s]->deptid);
		}
	}
	staffandworkers* lxc;
	for (int i = 0; i < this->ofpeoples-1; i++)
	{
		for(int j = 0;j<this->ofpeoples-i-1;j++)
		{
			if (lspx[j]->id > lspx[j+1]->id)
			{
				lxc = lspx[j];
		     	lspx[j] = lspx[j + 1];
				lspx[j + 1] = lxc;
			}
		}
	}
	cout << "排序后的职工列表为:" << endl;
	for (int i = 0; i < this->ofpeoples; i++)
	{
		cout << "职工编号:" << lspx[i]->id
			<< "\t职工姓名:" << lspx[i]->name
			<< "\t岗位:" << lspx[i]->deptid
			<< endl;
	}
	int num;
	cout << "是否更新职工列表为排序结果（1.true,0.false）:";
	cin >> num;
	cout << endl;
	if (num)
	{
		for (int i = 0; i < this->ofpeoples; i++)
		{
			delete this->s_staffandworkers[i];
		}
		delete[] this->s_staffandworkers;
		this->s_staffandworkers = lspx;
		this->WriteF();
		cout << "更新成功" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < this->ofpeoples; i++)
	{
		delete lspx[i];
	}
	delete[] lspx;
	system("pause");
}
void menu::delWD()
{
	if (this->ofpeoples == 0)
	{
		cout << "当前职工列表为空" << endl;
		return;
	}

	cout << "是否清空文件:1,true,0.false" << endl;
	int cs1 = 0;
	cin >> cs1;
	if (!cs1)
	{
		return;
	}

	for (int i = 0; i < this->ofpeoples; i++)
	{
		delete this->s_staffandworkers[i];
	}
	delete[] this->s_staffandworkers;
	this->ofpeoples = 0;
	this->s_staffandworkers = NULL;

	ofstream ofs(DILEL, ios::trunc);
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}