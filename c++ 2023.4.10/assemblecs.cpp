#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.h"
//void printmap(map<int, selecthand>::iterator ls)
//{
//	cout << "选手编号:" << ls->first << " " << ls->second.m_name << " 分数:" << ls->second.m_divide << endl;
//}
//void speech::operator()(map<int, selecthand>::iterator ls)
//{
//	cout << "选手编号:" << ls->first << " " << ls->second.m_name << " 分数:" << ls->second.m_divide << endl;
//}
// 
// 
// 
void speech::assemblecs()
{
	randomls();//抽签
	divGroup();//开始比赛
	showScore();//显示晋级选手
	this->fallDue++;//比赛轮数增加
	randomls();
	divGroup();
	showScore();

	saveRecrd();//保存文件
}
//void speech::assemblecs()
//{
//	cout << "-----------第" << this->fallDue << "届演讲比赛正式开始------------" << endl;
//	////初始化选手
//	//InitialSelect();
//	//cout << "以下为参赛选手:" << endl;
//	//for (map<int, selecthand>::iterator it1 = this->m.begin(); it1 != this->m.end(); it1++)
//	//{
//	//	cout << "选手编号;" << it1->first <<" " << it1->second.m_name<< endl;
//	//}
//	
//	//洗牌
//	//random_shuffle(v1.begin(), v1.end());
//	//cout << "按任意键继续..." << endl;
//	//cin.ignore();
//	randomls();
//
//	//分组
//	//cout << "比赛将分为两个小组进行，每个小组为6名选手:" << endl;
//	//cout << "随机分组后成员如下：..." << endl;
//	//divGroup();
//	//cout << "按任意键继续..." << endl;
//	//cin.ignore();
//
//	////评委评分
//	//grade();
//	//cout << "当前选手分数如下:" << endl;
//	//printgrade();
//	//获取前三晋级第二轮
//
//	//洗牌
//
//	//评委评分
//
//	//获取前三
//}