#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.h"
using namespace std;

speech::speech()
{
	this->initia();//初始化参数
	this->InitialSelect();//初始化选手
}
speech::~speech()
{

}
void speech::initia()
{
	this->m.clear();
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->fallDue = 1;
}
void speech::InitialSelect()//初始化选手
{
	string name = "ABCDEFGHLNRS";
	for (int i = 0; i < 12; i++)
	{
		string namels = "选手";
		selecthand ls(namels + name[i], 0.0);

		this->v1.push_back(10001 + i);
		this->m.insert(make_pair(v1[i],ls));
	}
}
void speech::title()
{
	cout << "************************************" << endl;
	cout << "*********  演讲比赛相同  **********" << endl;
	cout << "********* 1.开始演讲比赛 ************" << endl;
	cout << "********* 2.查看往届比赛 ***********" << endl;
	cout << "********* 3.清空比赛记录 ***********" << endl;
	cout << "********* 0.退出比赛重新 ***********" << endl;
	cout << "************************************" << endl;
}

void speech::randomls()//洗牌
{
	cout << "第" << this->fallDue << "轮比赛选手正在抽签" << endl;
	cout << "------------------" << endl;
	if (this->fallDue == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it1 = this->v1.begin(); it1 != this->v1.end(); it1++)
		{
			cout << *it1 << " ";
		}
		cout << endl;
	}
    else
    {
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it2 = this->v2.begin(); it2 != this->v2.end(); it2++)
		{
			cout << *it2 << " ";
		}
		cout << endl;
	}
	cout << "------------------" << endl;
	system("pause");
	cout << endl;
}
class lsmappx
{
public:
	bool operator()(double n1, double n2) const
	{
		return n1 > n2;
	}
};
void speech::divGroup()//分组.打印
{
	//int a = 0;
	//int da = 1;
	//vector<int> v;
	//if (this->fallDue == 1)
	//{
	//	v = this->v1;
	//}
	//else
	//{
	//	v = this->v2;
	//}
	//for (map<int, selecthand>::iterator it = this->m.begin(); it != this->m.end(); it++)
	//{
	//	if (a % 6 == 0)
	//	{
	//		cout << endl;
	//		cout << "第"<< da <<"组选手" << endl;
	//		da++;
	//	}
	//	a++;
	//	cout << "选手编号:" << it->first <<" "<< it->second.m_name << " 得分" << it->second.m_divide << endl;
	//}
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	if (a % 6 == 0)
	//    {
	//	    cout << endl;
	//	    cout << "第"<< da <<"组选手" << endl;
	//	    da++;
	//    }
	//	a++;
	//	map<int, selecthand>::iterator mls = this->m.find(*it);//通过键值查找
	//	cout <<"选手编号:" << mls->first << " " << mls->second.m_name << endl;
	//}

	cout << "--------------------第" << this->fallDue << "轮比赛正式开始-------------------" << endl;

	multimap<double, int, lsmappx> mmp;//临时map容器
	int lsmapf = 0;
	vector<int> v;//临时容器计入当前场次
	if (this->fallDue == 1)
	{
		v = this->v1;
	}
	else
	{
		v = this->v2;
	}
	
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)//以当前容器循环
	{
		lsmapf++;//检测6人小组
		//评委打分
		deque<double> dls;
		for (int i = 0; i < 10; i++)
		{
			double douls = (rand() % 401 + 600) / 10.f;
			dls.push_back(douls);
		}

		//去头去尾
		sort(dls.begin(), dls.end(), greater<double>());
		dls.pop_back();
		dls.pop_front();

		//获取平均分
		double lsf = accumulate(dls.begin(), dls.end(), 0.0);
		double f = lsf / dls.size();

		//m容器选手添加分数
		//this->m[*it].m_divide = f;
		map<int, selecthand>::iterator mls = this->m.find(*it);
		mls->second.m_divide = f;

		mmp.insert(make_pair(f, *it));//临时map容器方便排序赋值

		//for (multimap<double, int, lsmappx>::iterator ls = mmp.begin(); ls != mmp.end(); ls++)
		//{
		//	cout << ls->first << " " << ls->second << endl;
		//}

		if (lsmapf % 6 == 0)//一次记录一组
		{
			cout << "第" << lsmapf / 6 << "小组比赛成绩:" << endl;

			//打印每组数据
			for (multimap<double, int, lsmappx>::iterator itmap = mmp.begin(); itmap != mmp.end(); itmap++)
			{
				cout << "选手编号：" << itmap->second
					<< " 姓名:" << (this->m.find(itmap->second))->second .m_name
					<< " 分数" << itmap->first << endl;
			}
			cout << endl;

			//将小组前三记录下一个容器中
			multimap<double, int, lsmappx>::iterator itmap = mmp.begin();
			for (int i = 0 ; i < 3 ;i++)
			{
				if (this->fallDue == 1)
				{
					v2.push_back(itmap->second);
				}
				else
				{
					v3.push_back(itmap->second);
				}
				itmap++;
			}
			mmp.clear();//清空一组数据

		}
	}
	cout << "--------------------第" << this->fallDue << "轮比赛完毕-------------------" << endl;
	system("pause");
}
void speech::showScore()
{
	cout << "--------------------第" << this->fallDue << "轮晋级选手-------------------" << endl;
	vector<int> v;
	if (this->fallDue == 1)
	{
		v = this->v2;
	}
	else
	{
		v = this->v3;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号:" << *it
			<< " 姓名:" << (this->m.find(*it))->second.m_name
			<< " 分数:" << (this->m.find(*it))->second.m_divide << endl;
	}
	system("pause");
	system("cls");
	this->title();
}
void speech::saveRecrd()
{
	ofstream ofs;
	ofs.open("speechs.csv", ios::app);
	for (vector<int>::iterator it = this->v3.begin(); it != this->v3.end(); it++)
	{
		ofs << (this->m.find(*it))->first
			<< "," << (this->m.find(*it))->second.m_divide << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "比赛记录已经保存,可前往根目录speechs文件查看" << endl;
}
void speech::loadRecord()
{
	fstream ifs("speechs.csv", ios::in);

	//判断文件是否不存在
	if (!ifs.is_open())
	{
		ifs.close();
		cout << "文件不存在" << endl;
		return;
	}
	//判断文件是否为空
	char ls;//读走一个字符用于判断是否为末尾
	ifs >> ls;
	if (ifs.eof())
	{
		ifs.close();
		cout << "文件为空" << endl;
		return;
	}
	ifs.putback(ls);//读回原来的字符


}
void speech::grade()//评分
{
	vector<int> v;
	if (this->fallDue == 1)
	{
		v = this->v1;
	}
	else
	{
		v = this->v2;
	}

	deque<double> f;
	for (vector<int>::iterator its = v.begin(); its != v.end(); its++)//循环评分
	{
		for (int i = 0; i < 10; i++)
		{
			f.push_back((rand() % 401 + 600) / 10.f);
		}

		sort(f.begin(), f.end());//排序后去头去尾
		f.pop_back();
		f.pop_front();

		map<int, selecthand>::iterator mls = this->m.find(*its);//通过键值查找并赋予分数
		mls->second.m_divide = (accumulate(f.begin(), f.end(), 0.f) / f.size());
	}
}
void speech::printgrade()
{
	int a = 0;
	int da = 1;
	vector<int> v;
	if (this->fallDue == 1)
	{
		v = this->v1;
	}
	else
	{
		v = this->v2;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (a % 6 == 0)
		{
			cout << endl;
			cout << "第" << da << "组选手" << endl;
			da++;
		}
		a++;
		map<int, selecthand>::iterator mls = this->m.find(*it);//通过键值查找
		cout << "选手编号:" << mls->first << " " << mls->second.m_name <<" 选手得分:"<< mls->second.m_divide << endl;
	}
}