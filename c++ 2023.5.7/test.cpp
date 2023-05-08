#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <malloc.h>


//bool kmptest(vector<char> &yuan , vector<char> &ls,vector<int> &next)
//{
//	int i = 1,j = 1;
//	while (i <= yuan.size() && j <= ls.size())
//	{
//		if (j == 0 || yuan[i] == ls[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	if (j > ls.size())
//		return true;
//	else
//		return false;
//}
//bool kmptest(string s,string t,int next[])
//{
//	int i = 1,j = 1;
//	while (i<s.size()&&j<t.size())
//	{
//		if (j == 0 || s[i] == t[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	return j == t.size();
//}
//void test01()
//{
//	string n1 = "ababcdaa";
//	string n2 = "0baa";
//	int next[] = { 0,0,0,0 };
//	cout << kmptest(n1, n2, next) << endl;
//	//ababcdaa
//	//     baa
//	//vector<char> vls = { 'a','b','a','b','c','d','a','a' };
//	//vector<char> lscs = { 'b','a','a' };
//	//vector<int> kmpcs = { 0,0,0,0   };
//	//cout << kmptest(vls, lscs, kmpcs) << endl;
//}

//class Solution {
//public:
//    int numPairsDivisibleBy60(vector<int>& time) {
//        int a = 0;
//        int ls = 0;
//        for (int i = 0; i < time.size(); i++)
//        {
//            a = time[i];
//            for (int j = i + 1; j < time.size(); j++)
//            {
//                if (a % 60 == 0)
//                {
//                    ls++;
//                }
//                else if ((a + time[j]) % 60 == 0)
//                {
//                    ls++;
//                }
//            }
//        }
//        return ls;
//    }
//};

//class Solution {
//public:
//    int numPairsDivisibleBy60(vector<int>& time) {
//        vector<int> cnt(60);
//        for (int t : time) {
//            cnt[t % 60]++;
//        }
//        long long res = 0;
//        for (int i = 1; i < 30; i++) {
//            res += cnt[i] * cnt[60 - i];
//        }
//        res += (long long)cnt[0] * (cnt[0] - 1) / 2 + (long long)cnt[30] * (cnt[30] - 1) / 2;
//        return (int)res;
//    }
//};

//void test01()
//{
//    Solution ls;
//    vector<int> v = { 418,204,77,278,239,457,284,263,372,279,476,416,360,18 };
//    cout << ls.numPairsDivisibleBy60(v) << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}


typedef struct ls
{
	int data;
	ls* lchild, * rchild;
}ls;

void lssu(ls* a)
{
	cout << a->data << endl;
}
void printfls(ls* a)
{
	if (a != NULL)
	{
		lssu(a);
		printfls(a->lchild);
		printfls(a->rchild);
	}
}
//void pushls(ls *c,int a)
//{
//	ls* n1 = (ls*)malloc(sizeof(ls));
//	n1->data = a;
//	n1->lchild = n1->rchild = NULL;
//
//	ls* cls = &(*c);
//	while (cls->lchild != NULL||cls->rchild != NULL)
//	{
//		if (cls->lchild == NULL)
//		{
//			cls->lchild = n1;
//			break;
//		}
//		else if (cls->rchild == NULL)
//		{
//			cls->rchild = n1;
//			break;
//		}
//		cls = cls->lchild;
//	}
//	cls->lchild = n1;
//}//-+a*b-d.ef   a+b*c-d-/ef  
void test()
{
	ls cs = { 5,NULL,NULL };
	//pushls(&cs, 4);
	//pushls(&cs, 3);
	//pushls(&cs, 2);
	//pushls(&cs, 1);
	ls cs1 = { 4,NULL,NULL };
	ls cs2 = { 3,NULL,NULL };
	ls cs3 = { 2,NULL,NULL };
	ls cs4 = { 1,NULL,NULL };
	cs.lchild = &cs1;
	cs.rchild = &cs2;
	cs.lchild->lchild = &cs3;
	cs.lchild->rchild = &cs4;
	printfls(&cs);
}
int main()
{
	test();
	return 0;
}