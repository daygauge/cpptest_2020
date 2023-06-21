#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;





class Solution0 {
public:
    int strToInt(string str) {
        if (!str.size()) return 0;
        int i = 0;
        while (str[i] == ' ') i++;

        int ls = 0;
        if (str[i] == '+' || str[i] == '-')
        {
            if (str[i] == '-') ls++;
            i++;
        }

        double a = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9')
        {
            if (ls)
            {
                a -= (str[i] - 48);
            }
            else
            {
                a += (str[i] - 48);
            }

            if (a > INT_MAX|| a < INT_MIN)
            {
                a > INT_MAX ? a = INT_MAX : a = INT_MIN;
                break;
            }
            i++;
            if (i < str.size() && str[i] >= '0' && str[i] <= '9')a *= 10;
        }
        return a;
    }
};
class Solution1 {
public:
    int strToInt(string str) {
        int ssize = str.size();
        int i = 0, pos = 1;
        double sls = 0;
        if (!ssize) return 0;//为空
        while (str[i] == ' ')i++;//去除开头空格

        if (str[i] == '+' || str[i] == '-')//开头符号
        {
            if (str[i] == '-') pos = -1;
            i++;
        }

        while (i < ssize && str[i] >= '0' && str[i] <= '9')
        {
            sls = sls * 10 + str[i] - 48;
            if (sls > INT_MAX)
            {
                sls = INT_MAX;
                return sls * pos;
            }
            i++;
        }
        return sls * pos;
    }
};
void test01()
{
    string a = "-91283472332";
    Solution0 s;
    cout << s.strToInt(a);
}

void test02()
{
    int n = 45;
    int a = 0;
    double b = 1;
    for (int i = 2; i <= n; i++)
    {
        int num = a;
        a = b;
        b = num + a;
    }
    cout << b;
}
int ls(int n)
{
    if (n == 0 || n == 1)return n;
    int cs = ls(n - 1) + ls(n - 2);
    return cs;
}
void test03()
{
    int n =5;
    cout<< ls(n);
}

// 输入蛋糕价格列表 priceList ，求重量为 n 蛋糕的最高售价
int maxCakePrice01(int n, vector<int> priceList) {
    if (n <= 1) return priceList[n]; // 蛋糕重量 <= 1 时直接返回
    int f_n = 0;
    for (int i = 0; i < n; i++)      // 从 n 种组合种选择最高售价的组合作为 f(n)
        f_n = max(f_n, maxCakePrice01(i, priceList) + priceList[n - i]);
    return f_n;                      // 返回 f(n)
}
// 输入蛋糕价格列表 priceList ，求重量为 n 蛋糕的最高售价
int maxCakePrice(int n, vector<int> priceList, vector<int> &dp) {
    if (n <= 1) return priceList[n]; // 蛋糕重量 <= 1 时直接返回
    int f_n = 0;
    for (int i = 0; i < n; i++) {    // 从 n 种组合种选择最高售价的组合作为 f(n)
        int f_i = dp[i] != 0 ? dp[i] : maxCakePrice(i, priceList, dp);
        f_n = max(f_n, f_i + priceList[n - i]);
    }
    dp[n] = f_n;                     // 记录 f(n) 至 dp 数组
    return f_n;                      // 返回 f(n)
}
void test04()
{
    int n = 4;
    vector<int> v = { 0,2,3,6,7,11 };
    vector<int> dp(n + 1, 0);
    cout << maxCakePrice(n, v,dp);
}

//剑指 Offer 19. 正则表达式匹配
class Solution {
public:
    bool lst(string& s, string& p, int i, int j)
    {
        if (s.size()==i && p.size()==j) return true;//两个字符串都为空则匹配成功
        if (s.size()!=i && p.size()==j) return false;//p字符串如果先为空则匹配失败

        if (p.size() > j && p[j + 1] != '*')
        {
            if (s[i] == p[j] || (i < s.size() && p[j] == '.'))
                return lst(s, p, i + 1, j + 1);
            else
                return false;
        }
        else
        {
            if (s[i] == p[j] || (i < s.size() && p[j] == '.'))
                return lst(s, p, i, j + 2) || lst(s, p, i + 1, j);
            else
                return lst(s, p, i, j + 2);
        }
    }
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        return lst(s, p, i, j);
    }
};

void testtest()
{
    Solution s;
    string a = "aa";
    string b = "a";
    cout << s.isMatch(a, b) << endl;

}
int main()
{
    testtest();
    //test04();
    //test03();
    //test02();
	////test01();
 //   int a = INT_MAX;
 //   //int a = INT_MIN;
 //   a *= -1;
 //   cout << a << endl;
	return 0;
}