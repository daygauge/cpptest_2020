#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.h"

void speech::speechhost()
{
	//第一轮比赛
	this->inicsh();//初始化
	//抽签
	this->drawlots();
	//比赛
	this->match();
	//显示晋级
	this->riseinrank();
	//第二轮比赛
	this->indxs++;
	//抽签
	this->drawlots();
	//比赛
	this->match();
	//显示晋级
	this->riseinrank();

	//保存分数
	this->savefile();
	
	//重置容器
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m.clear();
	this->mfile.clear();
	this->indxs = 1;
	//更新往届分数
	this->readfile();
}