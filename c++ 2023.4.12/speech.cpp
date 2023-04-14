#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.h"


speech::speech()
{
	this->m.clear();
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->indxs = 1;

	this->isfile = true;//默认文件为空
	this->readfile();//加载记录
}
speech::~speech()
{

}
void speech::title()
{
	cout << "*****************************" << endl;
	cout << "*****  1.开始演讲比赛  ******" << endl;
	cout << "*****  2.查看往届记录  ******" << endl;
	cout << "*****  3.清空比赛记录  ******" << endl;
	cout << "*****  0.退出          ******" << endl;
	cout << "*****************************" << endl;

}
void speech::inicsh()
{
	string namels = "QWERTYUIOPAS";
	
	for (int i = 0; i < namels.size(); i++)
	{
		//初始化选手类
		int dfls = 10001 + i;
		string namels1 = "选手";
		namels1 += namels[i];
		selecthand ls;
		ls.m_name = namels1;
		ls.m_score = 0;

		//写入选手类
		this->v1.push_back(dfls);
		this->m.insert(make_pair(dfls, ls));
	}
}
void speech::drawlots()
{
	cout << "第" << this->indxs << "轮选手开始抽签" << endl;
	cout << "抽签结果如下" << endl;
	cout << "--------------------------------" << endl;
	if (indxs == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
	system("pause");
}
void speech::match()
{
	cout << "-----------第" << this->indxs << "轮比赛正式开始------------" << endl;
	cout << "评委正在打分" << endl;

	map<double, int,greater<double>> ls;//临时选手容器,(分数,编号)
	vector<int> v;//临时比赛容器
	if (this->indxs == 1)
	{
		v = this->v1;
	}
	else
	{
		v = this->v2;
	}

	int mls = 0;//记录当前选手位置
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		mls++;

		//获取平均分
		deque<double> vs;
		for (int i = 0; i < 10; i++)
		{
			vs.push_back((rand() % 410 + 600) / 10.f);
		}
		sort(vs.begin(), vs.end());
		vs.pop_back();
		vs.pop_front();
		double n = accumulate(vs.begin(), vs.end(), 0);

		//写入平均分
		ls.insert(make_pair(n / vs.size(), *it));//临时容器
		this->m[*it].m_score = n / vs.size();//容器m

		if (mls % 6 == 0)//6人一组
		{
			//打印选手
			cout << "第" << mls / 6 << "小组" << endl;
			for (map<double, int>::iterator lsm = ls.begin(); lsm != ls.end(); lsm++)
			{
				cout << lsm->second
					<< " 姓名:" << this->m[lsm->second].m_name
					<< " 得分:" << lsm->first << endl;
			}
			cout << endl;

			//写入前三
			map<double, int>::iterator lsm = ls.begin();
			for (int i = 0 ; i < 3 ; i++)
			{
				if (this->indxs == 1)
				{
					this->v2.push_back(lsm->second);
				}
				else
				{
					this->v3.push_back(lsm->second);
				}
				
				lsm++;
			}
			ls.clear();
		}
	}
	cout << "-----------------------------------------" << endl;
	system("pause");
}

void speech::riseinrank()
{
	cout << "-----------------第" << this->indxs << "轮晋级选手为-----------------" << endl;
	if (this->indxs == 1)
	{
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << *it
				<< " 姓名:" << this->m[*it].m_name
				<< " 得分:" << this->m[*it].m_score 
				<< endl;
		}
	}
	else
	{
		for (vector<int>::iterator it = this->v3.begin(); it != this->v3.end(); it++)
		{
			cout << *it
				<< " 姓名:" << this->m[*it].m_name
				<< " 得分:" << this->m[*it].m_score
				<< endl;
		}
	}
	system("pause");
	system("cls");
}

void speech::savefile()
{
	ofstream ofs("speech.csv", ios::app);

	ofs << this->v3[0] << "," << this->m[this->v3[0]].m_score << ","
		<< this->v3[1] << "," << this->m[this->v3[1]].m_score << ","
		<< this->v3[2] << "," << this->m[this->v3[2]].m_score << "," << endl;
	ofs.close();
}
void speech::readfile()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())//判断文件是否不存在
	{
		this->isfile = true;
		return;
	}

	char ls;
	ifs >> ls;
	if (ifs.eof())//判断文件是否为空
	{
		this->isfile = true;
		return;
	}

	//写入文件到this->mfile容器
	this->isfile = false;
	ifs.putback(ls);
	string filels;
	int inx = 0;
	while (ifs >> filels)
	{
		vector<string> v;
		int n1 = 0;
		int n2 = -1;
		while (true)
		{

			n2 = filels.find(",", n1);
			if (n2 == -1)
			{
				break;
			}
			string ls = filels.substr(n1, n2 - n1);
			v.push_back(ls);
			n1 = n2 + 1;
		}
		this->mfile.insert(make_pair(inx, v));
		inx++;
	}
	ifs.close();
}
void speech::filerecord()
{
	if (this->isfile)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		for (map<int, vector<string>>::iterator it = this->mfile.begin(); it != this->mfile.end(); it++)
		{
			cout << "第" << it->first+1 << "届"
				<< " 冠军编号:" << it->second[0] << " 分数:" << it->second[1]
				<< " 亚军编号:" << it->second[2] << " 分数:" << it->second[3]
				<< " 季军编号:" << it->second[4] << " 分数:" << it->second[5] << endl;
		}

	}
}
void speech::empty()
{
	this->isfile = true;
	this->mfile.clear();
	ofstream ofs("speech.csv", ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;

}