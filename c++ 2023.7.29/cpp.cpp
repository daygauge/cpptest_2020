#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
#include <vector>
#include <algorithm>



class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int i = 1;
        for (; i < dp.size(); i++)
        {
            int ls = dp[i - 1] * 5;
            for (int j = 0; j < i; j++)
            {

                if (2 * dp[j] > dp[i - 1])
                    if (2 * dp[j] < ls) ls = 2 * dp[j];

                if (3 * dp[j] > dp[i - 1])
                    if (3 * dp[j] < ls) ls = 3 * dp[j];

                if (5 * dp[j] > dp[i - 1])
                    if (5 * dp[j] < ls) ls = 5 * dp[j];

            }
            dp[i] = ls;
        }
        return dp[i - 1];
    }
};
//void test()
//{
//    Solution s;
//    cout << s.nthUglyNumber(1407) << endl;
//}


class Solution1 {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0 / 6.0);

        for (int i = 2; i <= n; i++)
        {
            vector<double> tmp(i * 5 + 1, 0);
            for (int j = 0; j < dp.size(); j++) {
                for (int k = j; k < j + 6; k++) {
                    tmp[k] += dp[j] / 6.0;
                }
            }
            dp = tmp;
        }
        return dp;
    }
};

class testlst {
public:
    void operator()(double a)
    {
        cout << a << " ";
    }
};
void test1()
{
    Solution1 ls;
    vector<double> v = ls.dicesProbability(2);
    for_each(v.begin(), v.end(), testlst());
}

int main()
{
	test1();
	return 0;
}




