#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
 


//class Solution0 {
//public:
//    int strToInt(string str) {
//        if (!str.size()) return 0;
//        int i = 0;
//        while (str[i] == ' ') i++;
//
//        int ls = 0;
//        if (str[i] == '+' || str[i] == '-')
//        {
//            if (str[i] == '-') ls++;
//            i++;
//        }
//
//        double a = 0;
//        while (i < str.size() && str[i] >= '0' && str[i] <= '9')
//        {
//            if (ls)
//            {
//                a -= (str[i] - 48);
//            }
//            else
//            {
//                a += (str[i] - 48);
//            }
//
//            if (a > INT_MAX|| a < INT_MIN)
//            {
//                a > INT_MAX ? a = INT_MAX : a = INT_MIN;
//                break;
//            }
//            i++;
//            if (i < str.size() && str[i] >= '0' && str[i] <= '9')a *= 10;
//        }
//        return a;
//    }
//};
//class Solution1 {
//public:
//    int strToInt(string str) {
//        int ssize = str.size();
//        int i = 0, pos = 1;
//        double sls = 0;
//        if (!ssize) return 0;//Ϊ��
//        while (str[i] == ' ')i++;//ȥ����ͷ�ո�
//
//        if (str[i] == '+' || str[i] == '-')//��ͷ����
//        {
//            if (str[i] == '-') pos = -1;
//            i++;
//        }
//
//        while (i < ssize && str[i] >= '0' && str[i] <= '9')
//        {
//            sls = sls * 10 + str[i] - 48;
//            if (sls > INT_MAX)
//            {
//                sls = INT_MAX;
//                return sls * pos;
//            }
//            i++;
//        }
//        return sls * pos;
//    }
//};
//void test01()
//{
//    string a = "-91283472332";
//    Solution0 s;
//    cout << s.strToInt(a);
//}
//
//void test02()
//{
//    int n = 45;
//    int a = 0;
//    double b = 1;
//    for (int i = 2; i <= n; i++)
//    {
//        int num = a;
//        a = b;
//        b = num + a;
//    }
//    cout << b;
//}
//int ls(int n)
//{
//    if (n == 0 || n == 1)return n;
//    int cs = ls(n - 1) + ls(n - 2);
//    return cs;
//}
//void test03()
//{
//    int n =5;
//    cout<< ls(n);
//}
//
//// ���뵰��۸��б� priceList ��������Ϊ n ���������ۼ�
//int maxCakePrice01(int n, vector<int> priceList) {
//    if (n <= 1) return priceList[n]; // �������� <= 1 ʱֱ�ӷ���
//    int f_n = 0;
//    for (int i = 0; i < n; i++)      // �� n �������ѡ������ۼ۵������Ϊ f(n)
//        f_n = max(f_n, maxCakePrice01(i, priceList) + priceList[n - i]);
//    return f_n;                      // ���� f(n)
//}
//// ���뵰��۸��б� priceList ��������Ϊ n ���������ۼ�
//int maxCakePrice(int n, vector<int> priceList, vector<int> &dp) {
//    if (n <= 1) return priceList[n]; // �������� <= 1 ʱֱ�ӷ���
//    int f_n = 0;
//    for (int i = 0; i < n; i++) {    // �� n �������ѡ������ۼ۵������Ϊ f(n)
//        int f_i = dp[i] != 0 ? dp[i] : maxCakePrice(i, priceList, dp);
//        f_n = max(f_n, f_i + priceList[n - i]);
//    }
//    dp[n] = f_n;                     // ��¼ f(n) �� dp ����
//    return f_n;                      // ���� f(n)
//}
//void test04()
//{
//    int n = 4;
//    vector<int> v = { 0,2,3,6,7,11 };
//    vector<int> dp(n + 1, 0);
//    cout << maxCakePrice(n, v,dp);
//}
//
////��ָ Offer 19. �������ʽƥ��
//class Solution001019 {
//public:
//    bool lst(string& s, string& p, int i, int j)
//    {
//        if (s.size() == i && p.size() == j) return true;//�����ַ�����Ϊ����ƥ��ɹ�
//        if (s.size() != i && p.size() == j) return false;//p�ַ��������Ϊ����ƥ��ʧ��
//
//        if (p.size() > j && p[j + 1] != '*')
//        {
//            if (s[i] == p[j] || (i < s.size() && p[j] == '.'))
//                return lst(s, p, i + 1, j + 1);
//            else
//                return false;
//        }
//        else
//        {
//            if (s[i] == p[j] || (i < s.size() && p[j] == '.'))
//                return lst(s, p, i, j + 2) || lst(s, p, i + 1, j);
//            else
//                return lst(s, p, i, j + 2);
//        }
//    }
//    bool isMatch(string s, string p) {
//        int i = 0, j = 0;
//        return lst(s, p, i, j);
//    }
//};
////void testtest()
////{
////    Solution s;
////    string a = "aaa";
////    string b = "ab*.*";
////    cout << s.isMatch(a, b) << endl;
////}
//
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        int n = s.size() + 1, m = p.size() + 1;
//
//        vector<vector<bool>> dp(n, vector<bool>(m, false));
//        dp[0][0] = true;
//
//        for (int i = 2; i < m; i += 2)
//            dp[0][i] = dp[0][i - 2] && p[i-1] == '*';
//
//        for (int i = 1; i < n; i++)
//        {
//            for (int j = 1; j < m; j++)
//            {
//                if (p[j - 1] == '*')
//                {
//                    if (dp[i][j - 2]) dp[i][j] = true;
//                    else if (dp[i - 1][j] && s[i - 1] == p[j - 2]) dp[i][j] = true;
//                    else if (dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;
//                }
//                else
//                {
//                    if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) dp[i][j] = true;
//                    else if (dp[i - 1][j - 1] && p[j - 1] == '.') dp[i][j] = true;
//                }
//            }
//        }
//        return dp[n - 1][m - 1];
//    }
//};
//
//void test19()
//{
//    string s = "aa";
//    string p = "a*";
//    Solution Sol;
//    cout << Sol.isMatch(s, p) << endl;
//}


//void fortestls(char a)
//{
//    cout << a << " ";
//}
//void test27()
//{
//    int a = 114514;
//
//    string s = to_string(a);
//    cout << s << endl;
//    for_each(s.begin(), s.end(), fortestls);
//}

//��ָ0ffer 47
//class Solution {
//public:
//    int translateNum(int num) {
//        string nums = to_string(num);
//        int a = 1, b = 1;
//        for (int i = 2; i <= nums.size(); i++)
//        {
//            string ls = nums.substr(i - 2, 2);
//            int c = ls.compare("10") >= 0 && ls.compare("25") <= 0 ? a + b : a;
//            b = a;
//            a = c;
//        }
//        return a;
//    }
//};
//class Solution {
//public:
//    int translateNum(int num) {
//        int a = 1, b = 1;
//        while (num > 9)
//        {
//            int c = num%100>=10 && num % 100 <= 25 ? a + b : a;
//            num /= 10;
//            b = a;
//            a = c;
//        }
//        return a;
//    }
//};

//��ָOffer 47;
//class Solution {
//public:
//    int maxValue(vector<vector<int>>& grid) {
//        int n = grid.size(), m = grid[0].size();
//        vector<vector<int>> vls(n, vector<int>(m, 0));
//        vls[0][0] = grid[0][0];
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (i == 0 && j)
//                    vls[i][j] = vls[i][j - 1] + grid[i][j];
//                else if (i && j == 0)
//                    vls[i][j] = vls[i - 1][j] + grid[i][j];
//                else if (i && j)
//                    vls[i][j] = max(vls[i - 1][j] + grid[i][j], vls[i][j - 1] + grid[i][j]);
//            }
//        }
//        return vls[n - 1][m - 1];
//    }
//};
//class Solution {
//public:
//    int maxValue(vector<vector<int>>& grid) {
//        int n = grid.size(), m = grid[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (i == 0 && j)
//                    grid[i][j] = grid[i][j - 1] + grid[i][j];
//                else if (i && j == 0)
//                    grid[i][j] = grid[i - 1][j] + grid[i][j];
//                else if (i && j)
//                    grid[i][j] = max(grid[i - 1][j] + grid[i][j], grid[i][j - 1] + grid[i][j]);
//            }
//        }
//        return grid[n - 1][m - 1];
//    }
//};

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        if (!s.size()) return 0;
//        vector<int> v(127, 0);
//        int i = 0, j = 0;
//        int ls = 1, lsz = 0;
//        for (; j < s.size(); j++)
//        {
//            if (v[s[j]] == 0)
//            {
//                v[s[j]]++;
//                ls++;
//            }
//            else
//            {
//                v[s[j]]++;
//                while (v[s[j]] == 2)
//                {
//                        v[s[i++]]--;
//                        ls--;
//                }
//                lsz = max(ls, lsz);
//            }
//        }
//        lsz = max(ls, lsz);
//        return lsz;
//    }
//};

//void test27()
//{
//    Solution ls;
//    cout<< ls.lengthOfLongestSubstring("pwwkew");
//
//
//    //vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
//    //cout << ls.maxValue(grid);
//
//    //cout << ls.translateNum(6216) << endl;
//
//}
//void testcs()
//{
//    
//}
//int test1(int a)
//{
//    a = 10;
//    printf("%d", a);
//    return a;
//}
//void test()
//{
//    void (*test)(int) = test1;
//    (*test)(5);
//}


int a()
{
    return 0;
}
void test()
{
    decltype(a()) sum = 10;
    cout << sum << endl;
}


int main()
{
    test();
    //testcs();
    // test27();
    //test19();
    //testtest();
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