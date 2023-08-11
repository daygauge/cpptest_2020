#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <malloc.h>
#include <algorithm>
#include <string>
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
//TreeNode* testcs(vector<int> &v,int &j)
//{
//    if (j >= v.size() || !v[j]) {
//        j++;
//        return NULL;
//    }
//    TreeNode* t = new TreeNode(v[j]);
//    j++;
//    t->left = testcs(v, j);
//    t->right = testcs(v, j);
//    return t;
//}
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
//void test2()
//{
//    vector<int> v1 = { 3,4,1,0,0,2,0,0,5};
//    int i = 0;
//    TreeNode* t = testcs(v1,i);
//    vector<int> v2 = {4,1};
//    i = 0;
//    TreeNode* t1 = testcs(v2, i);
//
//    Solution106 s;
//    cout << s.isSubStructure(t, t1) << endl;
//
//}

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
//class Solution {
//public:
//    vector<int> levelOrder(TreeNode* root) {
//
//        queue<TreeNode*> q;
//        vector<int> v;
//        if (root == NULL) return v;
//        q.push(root);
//        while (q.size())
//        {
//            v.push_back(q.front()->val);
//            if (q.front()->left) q.push(q.front()->left);
//            if (q.front()->right) q.push(q.front()->right);
//            q.pop();
//        }
//        return v;
//    }
//};

//剑指 Offer 32II
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        queue<TreeNode*> q1;
//        queue<TreeNode*> q2;
//        vector<int> v1;
//        vector<vector<int>> v;
//        if (!root) return v;
//        q1.push(root);
//        while (q1.size() || q2.size())
//        {
//            if (!q1.size())
//            {
//                q1 = q2;
//                while (q2.size()) q2.pop();
//                v.push_back(v1);
//                v1.clear();
//            }
//            if (q1.front()->left) q2.push(q1.front()->left);
//            if (q1.front()->right) q2.push(q1.front()->right);
//            v1.push_back(q1.front()->val);
//            q1.pop();
//        }
//        v.push_back(v1);
//        return v;
//    }
//};




//剑指 Offer 32III
class Solution0010 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1;
        vector<vector<int>> mtp;
        if (!root) return mtp;
        q1.push(root);
        int st = -1;
        while (q1.size())
        {
            vector<int> v;
            vector<int> s;
            int cs = q1.size();
            for (int i = 0; i < cs; i++)
            {
                s.push_back(q1.front()->val);
                if (q1.front()->left) q1.push(q1.front()->left);
                if (q1.front()->right) q1.push(q1.front()->right);
                q1.pop();
            }
            if (st == 0)
            {
                for (st = s.size() - 1; st >= 0; st--)
                {
                    v.push_back(s[st]);
                }
            }
            else
            {
                for (st = 0; st < s.size(); st++)
                {
                    v.push_back(s[st]);
                }
                st = 0;
            }
            mtp.push_back(v);
        }
        return mtp;
    }
};
class Solution1010 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> d;
        vector<vector<int>> mtp;
        if (!root) return mtp;
        d.push_back(root);
        int j = 0;

        while (d.size())
        {
            j++;
            vector<int> v;
            int cs = d.size();
            for (int i = 0; i < cs; i++)
            {
                if (j % 2)
                {
                    v.push_back(d.front()->val);
                    if (d.front()->left) d.push_back(d.front()->left);
                    if (d.front()->right) d.push_back(d.front()->right);
                    d.pop_front();
                }
                else
                {
                    v.push_back(d.back()->val);
                    if (d.back()->right) d.push_front(d.back()->right);
                    if (d.back()->left) d.push_front(d.back()->left);
                    d.pop_back();
                }
            }

            mtp.push_back(v);
        }
        return mtp;
    }
};


struct treenode {
     int val;
     treenode *left;
     treenode *right;
     treenode() : val(0), left(nullptr), right(nullptr) {}
     treenode(int x) : val(x), left(nullptr), right(nullptr) {}
     treenode(int x, treenode *left, treenode *right) : val(x), left(left), right(right) {}
};
 
//剑指 Offer 34
class Solution2010 {
public:
    vector<vector<int>> tmp;
    vector<vector<int>> pathSum(treenode* root, int target) {
        vector<int> s;
        test(root, target,s);
        return tmp;
    }
    void test(treenode* root, int target, vector<int> v)
    {
        if (target == 0)
        {
            tmp.push_back(v);
            return;
        }
        if (!root || target < 0) return;
        v.push_back(root->val);
        target -= root->val;
        test(root->left, target, v);
        test(root->right, target, v);
    }
};
treenode* test(int** i)
{
    if (**i == NULL)
    {
        (*i)++;
        return NULL;
    }
    treenode* t = new treenode(**i);
    (*i)++;
    t->left = test(i);
    t->right = test(i);
    return t;
}
void printfTreenode(treenode* t)
{
    queue<treenode*> q;
    q.push(t);
    while (q.size())
    {
        cout << q.front()->val << " ";
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
    }
}
void test810()
{
    
    vector<int> v = {5,4,11,7,0,0,2,0,0,0,8,13,0,0,4,5,0,0,1,0,0};
    int* i = (int*)malloc(v.size() * sizeof(int));
    int is1 = 0;
    for (int is = 0; is < v.size(); is++) (*(i + is)) = v[is1++];
    treenode* t = test(&i);
    //printfTreenode(t);
    Solution2010 s;
    vector<vector<int>> vs = s.pathSum(t, 22);
    for (int i = 0; i < vs.size(); i++) {
        for (int j = 0; j < vs[i].size(); j++) {
            cout << vs[i][j] << " ";
        }
    }
}

//剑指 Offer 36


class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution0011 {
public:
    deque<Node*> d;
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return root;
        test(root);
        Node* cs = d.front();
        root = d.front();
        d.push_back(d.front());
        d.pop_front();
        while (d.front() != cs)
        {
            Node* n = root;
            root->right = d.front();
            root = root->right;
            root->left = n;
            d.push_back(d.front());
            d.pop_front();
        }
        cs->left = root;
        root->right = cs;
        return cs;
    }
    void test(Node* root)
    {
        if (root == NULL) return;
        test(root->left);
        d.push_back(root);
        test(root->right);
    }
};

class Solution1011 {
public:
    Node* treeToDoublyList(Node* root) {
        dfs(root);
        n2->left = n1;
        n1->right = n2;
        return n2;
    }
    Node* n1, * n2;
    void dfs(Node* cmp)
    {
        if (cmp == NULL) return;
        dfs(cmp->left);
        if (n1 != NULL) n1->right = cmp;
        else n2 = cmp;
        cmp->left = n1;
        n1 = cmp;
        dfs(cmp->left);
    }
};

// 剑指 Offer 37
 struct TreeNode11 {
     int val;
     TreeNode11 *left;
     TreeNode11 *right;
     TreeNode11(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Codec0011 {
 public:
     // Encodes a tree to a single string.
     string serialize(TreeNode11* root) {
         queue<TreeNode11*> q;
         TreeNode11* n = root;
         string s;
         q.push(root);
         while (q.size())
         {
             if (q.front())q.push(q.front()->left);
             if (q.front())q.push(q.front()->right);
             if (q.front()) s += (char)(48 + (q.front()->val));
             else s += '0';
             q.pop();
         }
         string s1 = s;
         return s1;
     }
     // Decodes your encoded data to tree.
     TreeNode11* deserialize(string data) {
         queue<TreeNode11*> q;
         int n = data.size();
         int i = 1;
         TreeNode11* r = new TreeNode11(((int)(data[0])) - 48);
         q.push(r);
         while (i < n)
         {
             if (data[i] != '0')
             {
                 q.front()->left = new TreeNode11(data[i] - 48);
                 q.push(q.front()->left);
             }
             else
             {
                 q.front()->left = NULL;
             }
             i++;
             if (!(i < n)) return r;
             if (data[i] != '0')
             {
                 q.front()->right = new TreeNode11(data[i] - 48);
                 q.push(q.front()->right);
             }
             else
             {
                 q.front()->right = NULL;
             }
             i++;
             q.pop();
         }
         TreeNode11* s = r;
         q.empty();
         return s;
     }
 };

 class Codec1011 {
 public:
     // Encodes a tree to a single string.
     string serialize(TreeNode* root) {
         string s = "[";
         if (root == NULL) return "[]";
         queue<TreeNode*> q;
         TreeNode* n = root;

         q.push(root);
         while (q.size())
         {
             if (q.front())q.push(q.front()->left);
             if (q.front())q.push(q.front()->right);

             if (!q.front() && q.front()->val < 0)
             {
                 s += '-';
                 int a = (q.front()->val) * -1;
                 while (a % 10)
                 {
                     s += (a % 10) + 48;
                     a /= 10;
                 }
             }
             else if (!q.front() && q.front()->val > 9)
             {
                 int a = q.front()->val;
                 while (a % 10)
                 {
                     s += (a % 10) + 48;
                     a /= 10;
                 }
             }
             else if (!q.front())
             {
                 s += (char)(48 + (q.front()->val));
             }
             else
             {
                 s += '0';
             }
             q.pop();
         }
         s += ']';
         return s;
     }
     // Decodes your encoded data to tree.
     TreeNode* deserialize(string data) {
         if (data == "[]") return NULL;
         queue<TreeNode*> q;
         int n = data.size();
         int i = 2;
         TreeNode* r = new TreeNode(((int)(data[1])) - 48);
         q.push(r);
         while (i < n - 1)
         {
             if (data[i] != '0')
             {
                 q.front()->left = new TreeNode(data[i] - 48);
                 q.push(q.front()->left);
             }
             else
             {
                 q.front()->left = NULL;
             }
             i++;
             if (!(i < n)) return r;
             if (data[i] != '0')
             {
                 q.front()->right = new TreeNode(data[i] - 48);
                 q.push(q.front()->right);
             }
             else
             {
                 q.front()->right = NULL;
             }
             i++;
             q.pop();
         }

         return r;
     }
 };

 void printcs(TreeNode11* s)
 {
     if (!s) return;
     cout << s->val << " ";
     printcs(s->left);
     printcs(s->right);
 }
 //void test0011()
 //{
 //    string a = "1230045";

 //    //Codec c;
 //    TreeNode11* s = c.deserialize(a);
 //    printcs(s);
 //    cout<< c.serialize(s);
 //    

 //}
int main()
{
    //test0011();
    //string a = "-12ss";
    int a = -1;
    string s = to_string(a);
    int a1 = stoi(s);
    cout << a1 << endl;
    //cout << s << endl;
    bool lst = true;
	return 0;
}




