#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <random>
#include <numeric>
#include <deque>
#include <fstream>

class selecthand
{
public:
	string m_name;
	double m_score;
};

class speech
{
public:
	speech();
	~speech();
	void title();
	//初始化
	void inicsh();
	//主流程
	void speechhost();
	//抽签
	void drawlots();
	//比赛
	void match();
	//显示晋级
	void riseinrank();
	//保存文件
	void savefile();
	//读取文件
	void readfile();
	//显示往届记录
	void filerecord();
	//清空文件
	void empty();
	bool isfile;//判断文件
	map<int,vector<string>> mfile;//往届记录
	int indxs;//当前比赛轮数
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	map <int, selecthand> m;
};