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


class Solution001 {
public:
    bool test(vector<vector<char>>& board, string word, int cs, int i, int j)
    {
        bool ts = false;
        if ((board.size() > i && i >= 0 && board[0].size() > j && j >= 0) && board[i][j] == word[cs])
        {
            if (cs == word.size() - 1) return true;
            board[i][j] = '/0';
            ts =  test(board, word, cs+1, i, j + 1) ||test(board, word, cs+1, i + 1, j) ||
                  test(board, word, cs+1, i - 1, j) ||test(board, word, cs+1, i, j - 1);
            if (!ts) board[i][j] = word[cs];
            return ts;
        }
        else
        {

            return false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int cs = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[cs]) if (test(board, word, cs, i, j)) return true;
            }
        }
        return false;
    }
};
class Solution002 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0]) if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k)
    {
        if (i < 0 || i >= board.size() || j<0 || j>=board[0].size() || board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;
        board[i][j] = '/0';
        bool test = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);

        board[i][j] = word[k];
        return test;
    }
};

//void prints(vector<vector<char>>& s)
//{
//    vector<char> v1 = { 'A','B','C','E' };
//    s.push_back(v1);
//    vector<char> v2 = { 'S','F','C','S' };
//    s.push_back(v2);
//    vector<char> v3 = { 'A','D','E','E' };
//    s.push_back(v3);
//
//}
//void test2()
//{
//    Solution001 ls;
//    vector<vector<char>> v;
//    prints(v);
//    cout << ls.exist(v,"SEE") << endl;
//}
//
class Solution52 {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> v(m, vector<bool>(n, false));
        return dfs(0, 0, 0, 0, v, m, n, k);
    }
    int dfs(int i, int j, int si, int sj, vector<vector<bool>>& v, int m, int n, int k)
    {
        if (i >= m || j >= n || si + sj > k || v[i][j]) return 0;
        v[i][j] = true;
        return 1 + dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj, v, m, n, k) +
            dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8, v, m, n, k);
    }
};

void test2()
{

}
int main()
{
	test2();
    bool lst = true;
	return 0;
}




