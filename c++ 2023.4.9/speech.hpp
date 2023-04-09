#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>
#define FSTXS "speechcontest.csv"
class selecthand
{
public:
	selecthand():m_number(0), m_name("0"), m_scmre(0) {}
	selecthand(int number,string name,int scmer):m_number(number),m_name(name),m_scmre(scmer){}
	//选手号
	int m_number;
	//选手名
	string m_name;
	//选手分
	double m_scmre;
};
bool prinpaixu(selecthand a1,selecthand a2)
{
	return a1.m_scmre > a2.m_scmre;
}
void printsele(selecthand a)
{
	cout << a.m_name << " 选手编号: " << a.m_number << endl;
}
void printselef(selecthand a)
{
	cout << a.m_name << " 选手编号: " << a.m_number << " 选手分数: " << a.m_scmre << endl;
}
class lsdx
{
public:
	selecthand operator()(selecthand a)
	{
		return a;
	}
};

class speech
{
public:

	speech();
	~speech();
	void kickoff();

	void pradd();//prder++
	//打印标题
	void title();

	//查看之前记录
	void takenotes();

	//初始化比赛选手信息
	void initial(vector<selecthand> &v);

	//评委打分
	void grade(deque<double>& ls, vector<selecthand>::iterator &a);

	//当前获奖选手
	void equalorder();

	//计入文件
	void Includeinfile();

	//清空文件
	void emptys();


	int prder;
	selecthand champion;//冠军
	selecthand secondplace;//亚军
	selecthand thirdwinnerincontest;//季军

};
void speech::emptys()
{
	ofstream ofs;
	ofs.open(FSTXS, ios::out);
	ofs.close();
	ofs.open("test.txt", ios::out);
	int a = 0;
	ofs << a;
}

void speech::takenotes()
{
	ifstream ifs;
	ifs.open(FSTXS, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件为空" << endl;
		return;
	}

	int testls = 1;
	//届数
	string js;
	//选手号
	int m_numbers;
	//选手名
	string m_names;
	//选手分
	double m_scmres;
	string lss;
	while ( ifs>>js && ifs >> m_names && ifs >> m_numbers && ifs >> m_scmres && ifs >> lss)
	{
		cout << js << endl;
		cout << m_names << " 序号:" << m_numbers << " 成绩:" << m_scmres << " "<< lss << endl;
		if (ifs >> m_names && ifs >> m_numbers && ifs >> m_scmres && ifs >> lss)
		{
			cout << m_names << " 序号:" << m_numbers << " 成绩:" << m_scmres << " " << lss << endl;
			if (ifs >> m_names && ifs >> m_numbers && ifs >> m_scmres && ifs >> lss)
			{
				cout << m_names << " 序号:" << m_numbers << " 成绩:" << m_scmres << " " << lss << endl;
				testls = 0;
			}
		}
	}
	if (testls)
	{
		cout << "文件为空" << endl;
		return;
	}
}
void speech::title()
{
	cout << "****************************" << endl;
	cout << "****  欢迎参加演讲比赛  *****" << endl;
	cout << "*****  1.开始演讲比赛  *****" << endl;
	cout << "*****  2.查看比赛记录  *****" << endl;
	cout << "*****  3.清空比赛记录  *****" << endl;
	cout << "*****  4.退出比赛记录  *****" << endl;
	cout << "****************************" << endl;
}
speech::speech()
{
	srand((unsigned int)time(NULL));
	this->prder = 0;
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		this->prder = 0;
	}
	else
	{
		int ls = ifs.get() - 48;
		this->prder = ls;
	}
	ifs.close();
}
speech::~speech()
{
	pradd();
}
void speech::pradd()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << this->prder;
	ofs.close();
}
void speech::Includeinfile()
{
	ofstream ofs;
	ofs.open(FSTXS, ios::app);
	ofs<< "第" << prder << "届" << endl;
	ofs << this->champion.m_name << " " << this->champion.m_number << " " << this->champion.m_scmre <<" 冠军 "<< endl;
	ofs << this->secondplace.m_name << " " << this->secondplace.m_number << " " << this->secondplace.m_scmre <<" 亚军 "<< endl;
	ofs << this->thirdwinnerincontest.m_name << " " << this->thirdwinnerincontest.m_number << " " << this->thirdwinnerincontest.m_scmre <<" 季军 "<< endl;
	ofs.close();
}
void speech::equalorder()
{
	cout << endl;
	cout << "-----冠军-----" << endl;
	cout << this->champion.m_name << " 序号:" << this->champion.m_number << " 成绩:" << this->champion.m_scmre << endl;
	cout << "-----亚军-----" << endl;
	cout << this->secondplace.m_name << " 序号:" << this->secondplace.m_number << " 成绩:" << this->secondplace.m_scmre << endl;
	cout << "-----季军-----" << endl;
	cout << this->thirdwinnerincontest.m_name << " 序号:" << this->thirdwinnerincontest.m_number << " 成绩:" << this->thirdwinnerincontest.m_scmre << endl;
}
void speech::initial(vector<selecthand>& v)
{
	string namecs = "vQWERTYUIOPAS";
	for (int i = 1; i <= 12; i++)
	{
		string name = "选手";
		selecthand ls(i + 10000, name + namecs[i], 0.0);
		v.push_back(ls);
	}
	random_shuffle(v.begin(), v.end());//打乱信息;
}
void speech::grade(deque<double> &ls ,vector<selecthand>::iterator &a)
{
	for (int i = 0; i < 6; i++)//小组1打分
	{
		for (int i = 0; i < 10; i++)
		{
			ls.push_back(rand() % 40 + 60.0);
		}
		//取平均分
		sort(ls.begin(), ls.end());
		ls.pop_back();
		ls.pop_front();
		int fsoeef = accumulate(ls.begin(), ls.end(), 0);
		a->m_scmre = fsoeef / 8.0;
		a++;
		ls.clear();
	}
}

void speech::kickoff()
{
	//初始化比赛选手信息
	vector<selecthand> v;
	initial(v);//选手初始化

	//分组
	vector<selecthand> v1;
	vector<selecthand> v2;
	vector<selecthand>::iterator it = v.begin();
	for (int i = 0; i < 12 && it!=v.end() ; i++)
	{
		if (i < 6)
			v1.push_back(*it);
		else
			v2.push_back(*it);
		it++;
	}
	cout << "目前选手列表" << endl;
	cout << "小组1：" << endl;
	for_each(v1.begin(), v1.end(), printsele);
	cout << "小组2：" << endl;
	for_each(v2.begin(), v2.end(), printsele);
	system("pause");

	//评委打分
	deque<double> ls;
	vector<selecthand>::iterator v1ls = v1.begin();
	grade(ls, v1ls);
	vector<selecthand>::iterator v2ls = v2.begin();
	grade(ls, v2ls);

	cout << "-----------------------------------------" << endl;
	cout << "评委打分：" << endl;
	sort(v1.begin(), v1.end(), prinpaixu);
	sort(v2.begin(), v2.end(), prinpaixu);
	cout << endl;
	cout << "小组1：" << endl;
	for_each(v1.begin(), v1.end(), printselef);
	cout << "小组2：" << endl;
	for_each(v2.begin(), v2.end(), printselef);

	//淘汰一半选手
	for (int i = 0; i < 3; i++)
	{
		v1.pop_back();
		v2.pop_back();
	}
	system("pause");
	cout << "已晋级一半的选手，现在开始第二轮比赛" << endl;
	system("pause");

	//显示晋级选手
	cout << "当前已晋级选手为:" << endl;
	v.clear();
	v.resize(v1.size() + v2.size());
	vector<selecthand>::iterator itzh = transform(v1.begin(), v1.end(), v.begin(), lsdx());
	transform(v2.begin(), v2.end(), itzh, lsdx());//第二轮打分前
	for_each(v.begin(), v.end(), printsele);
	system("pause");
	cout << "-----------------------------------------" << endl;
	cout << "评委打分" << endl;
	system("pause");
	for_each(v.begin(), v.end(), printselef);//第二轮打分后
	system("pause");

	//冠军亚军季军诞生
	sort(v.begin(), v.end(), prinpaixu);//排序后去除前三
	v.pop_back();
	v.pop_back();
	v.pop_back();

	cout << "前三名诞生:" << endl;
	this->champion = v[0];
	this->secondplace = v[1];
	this->thirdwinnerincontest = v[2];
	equalorder();//打印前三名
	this->prder++;
	pradd();//记录当前届数
	Includeinfile();//计入文件
	system("pause");
}