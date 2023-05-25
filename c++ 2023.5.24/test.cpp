#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


void jcsp0(ls &s)
{
	s.m_wait();//申请资源
	cout << "使用资源" << endl;
	//jcsp0(s);
	s.m_signal();//释放资源
}
void jcps01(ls01& s1)
{
	s1.m_wait1();
	cout << "使用资源" << endl;
	s1.m_signal1();
}
void jcps01s(ls01& s1)
{
	if (s1.m_q.size() == 0)
		jcps01(s1);
	else
	{
		cout << "使用队列资源" << endl;
		s1.m_signal1();
		s1.m_q.pop();
	}
}
void test01()
{
	//ls lscs(1);
	//jcsp0(lscs);


	ls01 ls01cs(1);
	jcps01s(ls01cs);
	ls01cs.m_wait1();// 1
	ls01cs.m_wait1();// 2
	ls01cs.m_wait1();// 3
	ls01cs.m_wait1();// 4

	jcps01s(ls01cs); // 3
	jcps01s(ls01cs); // 2
	jcps01s(ls01cs); // 1
	jcps01s(ls01cs); // 0

}

//class Solution {
//public:
//	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
//		vector<int> vls(20000);
//		int data = 0;
//		int dals = 0;
//		for (int i = 0; i < values.size(); i++)
//		{
//			if (dals >= numWanted)
//				return data;
//			if (vls[labels[i]] < useLimit)
//			{
//				dals++;
//				vls[labels[i]]++;
//				data += values[i];
//			}
//		}
//		return data;
//	}
//};
class lsss
{
public:
	bool da(int a, int b)
	{
		return a > b;
	}
};
//class Solution {
//public:
//	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
//		vector<int> vls(20000);//记录相同标签
//		multimap<int, int,greater<int>> m;//从大到小排序
//		int data1 = 0;//记录总个数
//		int data2 = 0;//记录和
//		for (int i = 0; i < values.size(); i++)//初始化m;
//		{
//			m.insert(make_pair(values[i], labels[i]));
//		}
//		for (multimap<int,int, greater<int>>::iterator ls = m.begin();ls!=m.end();ls++)
//		{
//			if (data1 >= numWanted)//numWanted满了则直接返回
//				return data2;
//			if (vls[ls->second] < useLimit)
//			{
//				data1++;//目前个数
//				vls[ls->second]++;//记录标签个数
//				data2 += ls->first;
//			}
//		}
//		return data2;
//	}
//};

class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
		unordered_map<int,int> vls;//记录相同标签
		multimap<int, int,greater<int>> m;//从大到小排序
		int data1 = 0;//记录总个数
		int data2 = 0;//记录和
		for (int i = 0; i < values.size(); i++)//初始化m;
		{
			m.insert(make_pair(values[i], labels[i]));
		}
		for (multimap<int,int, greater<int>>::iterator ls = m.begin();ls!=m.end();ls++)
		{
			if (data1 >= numWanted)//numWanted满了则直接返回
				return data2;
			if (vls[ls->second] < useLimit)
			{
				data1++;//目前个数
				vls[ls->second]++;//记录标签个数
				data2 += ls->first;
			}
		}
		return data2;
	}
};
void test02()
{
	//vector<int> v1 = { 5,4,3,2,1 };
	//vector<int> v2 = { 1,1,2,2,3 };
	//int a = 3;
	//int b = 1;
	//vector<int> v1 = { 9 };
	//vector<int> v2 = { 2 };
	//int a = 1;
	//int b = 1;

	vector<int> v1 = { 5,4,3,2,1 };
	vector<int> v2 = { 1,3,3,3,2 };
	int a = 3;
	int b = 2;

	Solution ls;
	cout << ls.largestValsFromLabels(v1, v2, a, b) << endl;
}
int main()
{
	//test01();
	test02();
	return 0;
}