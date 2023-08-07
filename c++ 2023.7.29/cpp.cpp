#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
#include <vector>
#include <algorithm>
#include <queue>


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



struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution006 {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool cs = false;
        test(A, B, cs);
        return cs;
    }
    void test2(TreeNode* As, TreeNode* Bs, bool& cs)
    {
        if (Bs == NULL) {
            cs = true;
            return;
        }
        else if (As == NULL)
        {
            return;
        }
        test2(As->left, Bs->left, cs);
        test2(As->right, Bs->left, cs);
    }
    void test(TreeNode* As, TreeNode* Bs, bool& cs)
    {
        if (cs == true) return;
        if (As->val == Bs->val) test2(As, Bs, cs);
        if (cs == true) return;
        if (As == NULL) return;
        test(As->left, Bs, cs);
        test(As->right, Bs, cs);
    }
};
class Solution106 {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return test(A, B);
    }
    int cs = false;
    bool test(TreeNode* A, TreeNode* B)
    {
        if (A == NULL || B == NULL || A->val == B->val)
        {
            if (A == NULL && B == NULL) return true;
            else if(A == NULL || B == NULL) return false;
            cs = test(A->left, B->left);
            cs = test(A->right, B->right);
        }
        else
        {
            if (A == NULL) return false;
            cs = test(A->left, B);
            cs = test(A->right, B);
        }
        return cs;
    }
};
TreeNode* testcs(vector<int> &v,int &j)
{
    if (j >= v.size() || !v[j]) {
        j++;
        return NULL;
    }
    TreeNode* t = new TreeNode(v[j]);
    j++;
    t->left = testcs(v, j);
    t->right = testcs(v, j);
    return t;
}
void printffbtn(TreeNode* t)
{
    if (t == NULL) return;
    cout << t->val << " ";
    printffbtn(t->left);
    printffbtn(t->right);
}
void levelorder(TreeNode* t)
{
    queue<TreeNode*> q;
    q.push(t);
    while (q.size())
    {
        q.push(q.front()->left);
        q.push(q.front()->right);
        cout << q.front()->val << " ";
        q.pop();
    }
}
void test2()
{
    vector<int> v1 = { 3,4,1,0,0,2,0,0,5};
    int i = 0;
    TreeNode* t = testcs(v1,i);
    vector<int> v2 = {4,1};
    i = 0;
    TreeNode* t1 = testcs(v2, i);

    Solution106 s;
    cout << s.isSubStructure(t, t1) << endl;

}

//剑指 Offer 27
class Solution007 {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        return recur(root);
    }
    TreeNode* recur(TreeNode* test)
    {
        if (test == NULL) return NULL;
        TreeNode* t = test->left;
        test->left = test->right;
        test->right = t;
        recur(test->left);
        recur(test->right);
        return test;
    }
};
class Solution107 {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
class Solution207 {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
    }
};
//剑指 Offer 28
class Solution307 {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || recur(root->left, root->right);
    }
    bool recur(TreeNode* L, TreeNode* R)
    {
        if (L == NULL && R == NULL) return true;
        if (L == NULL || R == NULL || L->val != R->val) return false;
        return recur(L->left, R->right) && recur(L->right, R->left);
    }
};
//剑指 Offer 32 
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        vector<int> v;
        if (root == NULL) return v;
        q.push(root);
        while (q.size())
        {
            v.push_back(q.front()->val);
            if (q.front()->left) q.push(q.front()->left);
            if (q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        return v;
    }
};

//剑指 Offer 32
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        vector<int> v1;
        vector<vector<int>> v;
        if (!root) return v;
        q1.push(root);
        while (q1.size() || q2.size())
        {
            if (!q1.size())
            {
                q1 = q2;
                while (q2.size()) q2.pop();
                v.push_back(v1);
                v1.clear();
            }
            if (q1.front()->left) q2.push(q1.front()->left);
            if (q1.front()->right) q2.push(q1.front()->right);
            v1.push_back(q1.front()->val);
            q1.pop();
        }
        v.push_back(v1);
        return v;
    }
};
int main()
{
	test2();
    bool lst = true;
	return 0;
}




