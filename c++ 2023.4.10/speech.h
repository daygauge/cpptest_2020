#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <deque>
#include <numeric>
#include <fstream>
using namespace std;



class selecthand
{
public:
	selecthand(string name,double divide):m_name(name),m_divide(divide){}
	string m_name;
	double m_divide;
};

class speech
{
public:
	//构造
	speech();
	//析构
	~speech();
	void initia();
	//初始化选手
	void InitialSelect();
	//整体流程
	void assemblecs();

	//标题
	void title();
	//洗牌
	void randomls();
	//分组
	void divGroup();
	//显示比赛分数
	void showScore();
	//保存分数文件
	void saveRecrd();
	//查看记录
	void loadRecord();
	map<int, vector<string>> mload;//临时过往记录容器
	void printindxs();//记录打印
	void clearls();//清空重置

	//评分
	void grade();
	void printgrade();

	int  fallDue;
	vector<int> v1;//第1场 12人
	vector<int> v2;//第2场 6人
	vector<int> v3;//第3场 3人
	map<int, selecthand> m;//选手
};

