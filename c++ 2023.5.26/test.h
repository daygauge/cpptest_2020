#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <map>

//
//typedef struct Collections
//{
//	coll* m_left;
//	coll* m_right;
//	coll* m_top;
//	int a;
//}coll;
//
void testlscs()
{
	map<int, int> m;
	m.insert(make_pair(1, 1));
	vector<int> av;
	av.push_back(1);
	return;
}

//class Solution {
//public:
//    vector<double> sampleStats(vector<int>& count) {
//        double a = 255, b = 0, c = 0, d = 0, e = 0;//最小,最大值,平均值,中间值,采样
//        vector<int> v;
//        for (int i = 0; i < count.size(); i++)
//        {
//            if (count[i] != 0)
//            {
//                if (count[i] < a)
//                    a = count[i];
//                if (count[i] > b)
//                    b = count[i];
//                c += count[i];
//                v.push_back(count[i]);
//            }
//        }
//        c /= v.size();
//        int ls = 0;
//        if (v.size() % 2)
//        {
//            ls = v.size() % 2;
//            d = count[ls];
//        }
//        else
//        {
//            ls = v.size() % 2;
//            d = (count[ls] + count[ls + 1]) / 2.0;
//        }
//        vector<int> vls(225);
//        for (int i = 0; i < v.size(); i++)
//            vls[v[i]]++;
//        int vlscs = 0;
//        for (int i = 0; i < vls.size(); i++)
//        {
//            if (vls[i] > vlscs)
//            {
//                vlscs = vls[i];
//                e = i;
//            }
//        }
//        vector<double> vlsy = { a,b,c,d,e };
//        return vlsy;
//    }
//};
class Solution {
public:
	vector<double> sampleStats(vector<int>& count) {
		double minimum = 0, maximum = 0, mean = 0, median = 0, mode = 0;
		vector<int> v;
		int ls_mode = 0, ls_m = 0;
		for (int i = 0; i < count.size(); i++)//展开count,记录mode出现最多的值
			if (count[i] != 0)
			{
				for (int j = 0; j < count[i]; j++)
					v.push_back(i);
				if (count[i] > ls_m)
				{
					ls_m = count[i];
					ls_mode = i;
				}
			}
		mode = ls_mode;

		minimum = v[0];//最小元素
		maximum = v[v.size() - 1];// 最大元素

		for (int i = 0; i < v.size(); i++)//平均值
			mean += v[i];
		mean /= v.size();

		double ls = 0;
		if (v.size() % 2)//中间值
		{
			ls = v[(v.size() / 2 + 1)-1];
			median = ls;
		}
		else
		{
			ls = v[(v.size() / 2) - 1] + v[v.size() / 2 ];
			median = ls / 2;
		}
		vector<double> vls = { minimum,maximum,mean,median,mode };
		return vls;
	}
};