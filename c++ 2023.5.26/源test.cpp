#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

class Pro;
int zmls_ina = 0;
vector<Pro> lsa;
class Pro
{
public:
	Pro(int a = 0, int b = 0, bool c = true) :m_ina(a), m_stor(b){}
	int m_ina;//预约数据
	int m_stor;//已申请的数据
};
bool forlspr(Pro& ls1, Pro& ls2)
{
	return &ls1 == &ls2;
}
void lsreyirsn(Pro& ls)
{
	if (ls.m_ina == ls.m_stor)//归还资源
	{
		zmls_ina += ls.m_ina;
		cout << "归还资源" << endl;
	}
	return;
}
void applsf(Pro& ls, int storls)//申请
{
	int a = 0;
		if (storls > zmls_ina)
		{
			cout << "申请失败,资源不足" << endl;//无法申请数据while(zmls_ina < ls.m_ina - ls.m_stor)
			return;
		}
		if (storls + ls.m_stor < ls.m_ina)//申请数据 < 预约数据
		{
			for (int i = 0; i < lsa.size(); i++)
				if (zmls_ina - storls < lsa[i].m_ina - lsa[i].m_stor)//是否会进入不安全状态
				{
					a++;
				}
			if (a >= (lsa.size() - 1))
			{
				cout << "申请失败，会进入不安全状态" << endl;
				return;
			}
			else
			{
				ls.m_stor += storls;
				zmls_ina -= storls;
				cout << "申请成功" << endl;
				lsreyirsn(ls);
			}
		}
		else if (storls + ls.m_stor == ls.m_ina)
		{
			ls.m_stor += storls;
			zmls_ina -= storls;
			cout << "申请成功" << endl;
			lsreyirsn(ls);
		}
		else
			cout << "申请失败" << endl;
	    return;
}
void test01()
{
	Pro a1(5);
	Pro a2(4);
	Pro a3(6);
	Pro a4(8);
	lsa.push_back(a1);
	lsa.push_back(a2);
	lsa.push_back(a3);
	lsa.push_back(a4);
	
	zmls_ina = 10;
	applsf(lsa[0], 2);
	applsf(lsa[1], 1);
	applsf(lsa[2], 3);
	applsf(lsa[0], 3);
	applsf(lsa[3], 2);

}
int main()
{
	//test01();
	vector<int> v = { 0, 1, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Solution ls;
	vector<double> vdls = ls.sampleStats(v);
	for (int i = 0; i < vdls.size(); i++)
	{
		cout << vdls[i] << "  ";
	}
	return 0;

}