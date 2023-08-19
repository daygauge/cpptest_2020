<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>

class forprint
{
public:
    void operator()(int a)
    {
        cout << a << " ";
    }
    void operator()(string a)
    {
        cout << a << " ";
    }
};

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 class Codec {
 public:
     string serialize(TreeNode* root) {
         if (root == NULL) return "[]";
         string s = "[";
         queue<TreeNode*> q;
         q.push(root);
         while (q.size())
         {
             TreeNode* tmp = q.front();
             q.pop();
             if (tmp != NULL)
             {
                 s += (to_string(tmp->val) + ',');
                 q.push(tmp->left);
                 q.push(tmp->right);
             }
             else s += "null,";
         }
         s.pop_back();
         s += "]";
         return s;
     }
     TreeNode* deserialize(string data) {
         if (data == "[]")return NULL;
         vector<string> v = datastr(data.substr(1,data.size()-2));
         queue<TreeNode*> q;
         TreeNode* tmp = new TreeNode(stoi(v[0]));
         q.push(tmp);
         int i = 1;
         while (i < v.size())
         {
             if (v[i] != "null")
             {
                 q.front()->left = new TreeNode(stoi(v[i]));
                 q.push(q.front()->left);
             }
             i++;
             if (!(i < v.size())) return tmp;
             if (v[i] != "null")
             {
                 q.front()->right = new TreeNode(stoi(v[i]));
                 q.push(q.front()->right);
             }
             i++;
             q.pop();
         }
         return tmp;
     }
     //vector<int> datastr(string a)
     //{
     //    a.pop_back();
     //    a += ',';
     //    int an = a.size();
     //    vector<int> v;
     //    int i = 1;
     //    while (i < an)
     //    {
     //        int it = a.find(',', i)-i;
     //        if (a.substr(i, it) != "null") v.push_back(stoi(a.substr(i, it)));
     //        else v.push_back(2000);
     //        i += it + 1;
     //    }
     //    return v;
     //}
     vector<string> datastr(string a)
     {
         vector<string> v;
         int i = 0, j = 0, an = a.size();
         while (i < an)
         {
             int j = i;
             while (j < an && a[j] != ',')
                 j++;
             v.push_back(a.substr(i, j - i));
             i = ++j;
         }
         return v;
     }
};
//[1,2,3,null,null,4,5]
 void printcode(TreeNode* s)
 {
     if (s == NULL) return;
     cout << s->val << " ";
     printcode(s->left);
     printcode(s->right);
}
 void printcode(TreeNode* s,int)
 {
     if (s == NULL) return;
     printcode(s->left);
     cout << s->val << " ";
     printcode(s->right);
 }
void test()
{
    Codec c;
    string a = "[-1,0,1]";
    TreeNode* t = c.deserialize(a);
    printcode(t);

    cout << endl;

    string as = c.serialize(t);
    cout << as << endl;
}
void test2(string a)
{
    
    if (a.substr(7, ',') != "null") cout << 10 << endl;
    else cout << 20 << endl;
}
//class Solution0012 {
//public:
//    vector<string> permutation(string s) {
//        vector<string> v;
//        int sn = s.size();
//        for (int i = 0; i < sn; i++)
//        {
//            string st = s;
//            st[i] = st[0];
//            st[0] = s[i];
//            for (int j = 0; j < sn; j++)
//            {
//                char cs = st[1];
//                v.push_back(st[0] + mysort(st.substr(1, st.size() - 1)) + cs);
//            }
//        }
//        return v;
//    }
//    string mysort(string st)
//    {
//        int i = 0;
//        while (++i < st.size())
//        {
//            st[i - 1] = st[i];
//        }
//        st.pop_back();
//        return st;
//    }
//};


//剑指 Offer 55 - I
class Solution00815 {
public:
    int i = 0;
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return i;
    }
    void dfs(TreeNode* root1, int i)
    {
        if (!root1)
        {
            if (i - 1 > this->i) this->i = i - 1;
            return;
        }
        dfs(root1->left, i + 1);
        dfs(root1->right, i + 1);
    }
};
class Solution10815 {
public:
    int i = 0;
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*
                 1
            2          2
         3     3    3      3  
       4  4   4 4  4 4  
      5 5

*/ 
class Solution20815 {
public:
    int max = INT_MIN;
    int min = INT_MAX;
    bool isBalanced(TreeNode* root) {
        dfs(root, 1);
        return max == min || max - 1 == min ? true : false;
    }
    void dfs(TreeNode* root, int s)
    {
        if (!root)
        {
            if (s - 1 > this->max) this->max = s - 1;
            if (s - 1 < this->min) this->min = s - 1;
            return;
        }
        dfs(root->left, s + 1);
        dfs(root->right, s + 1);

    }
};
//剑指 Offer 55 - II
class Solution30815 {
public:
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1 ? true : false;
    }
    int recur(TreeNode* root)
    {
        if (!root) return 0;
        int left = recur(root->left);
        if (left == -1) return -1;
        int right = recur(root->right);
        if (right == -1) return -1;
        return abs(left - right) >= 2 ? -1 : max(left, right) + 1;
    }
};
class Solution40815 {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 &&
            isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* root)
    {
        if (!root) return 0;
        return max(depth(root->left), depth(root->left)) + 1;
    }
};
class Solution50815 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};
/*
*        1
    null     2
null    3
*/
void cs1()
{

}
void c815(TreeNode* cs)
{
    Solution40815 s;
    cout << s.isBalanced(cs) << endl;
    
 }
//void test815()
//{
//    int a = abs(5-7);
//    cout << a << endl;
//}
//剑指 Offer 68 - I
class Solution00816 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if ((p->val > root->val && q->val < root->val) ||
            (q->val > root->val && p->val < root->val) ||
            (p->val == root->val || q->val == root->val)) return root;

        if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
    }
};

class Solution10816 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL)
        {
            if (p->val > root->val && q->val > root->val) root = root->right;
            else if (p->val < root->val && q->val < root->val) root = root->left;
            else break;
        }
        return root;
    }
};

//剑指 Offer 68 - II
class Solution00817 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL) return right;
        if (right == NULL) return left;
        return root;
    }
};
TreeNode* testcs(TreeNode* a,int b)
{
    if (a == NULL) return NULL;
    if (a->val == b) return a;
    TreeNode* n1 = testcs(a->left,b);
    TreeNode* n2 = testcs(a->right,b);
    return n1 ? n1:n2;
}
/*
*               3,
             5,     1
        6,     2    0,  8,
  null,null   7 4
*/
void TreeNode_dfs(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (q.size())
    {
        if (q.front())
        {
            q.push(q.front()->left);
            q.push(q.front()->right);
            cout << q.front()->val << " ";
        }
        else cout << "null" << " ";
        q.pop();
    }
}

class Solution00818 {
public:
    TreeNode* t;
    int i = 0;
    int is = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) return NULL;
        int i = 0;
        t = new TreeNode(preorder[i]);
        dfs(t, preorder, inorder, 0);
        return t;
    }
    void dfs(TreeNode* ts, vector<int>& preorder, vector<int>& inorder, int j)
    {
        if (i == preorder.size()) return;//遍历到底
        i++;
        ts->left = new TreeNode(preorder[i]);//在前中序i数值不相同的情况下开辟新节点，将数值放到left
        if (preorder[i] == inorder[is])
        {
            is = i + 1;
            return;//前序中序位置数值相同
        }

        dfs(ts->left, preorder, inorder, j + 1);//放入left后往left方向递归
        if (i < preorder.size() && j == 0)//未被遍历到底并且需要返回的节点位j为0则往right方向递归
        {
            ts->right = new TreeNode(preorder[i]);//创建right方向节点
            i++;
            dfs(ts->right, preorder, inorder,j + 1);//并开始递归
        }
    }
};

class Solution10818 {
public:
    int i = 0;
    int is = 0;
    TreeNode* t;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        t = new TreeNode(preorder[i]);
        dfs(t, preorder, inorder, 0);
        return t;
    }
    void dfs(TreeNode* ts, vector<int>& preorder, vector<int>& inorder, int is1)
    {
        if (i - 1 == preorder.size()) return;

        if (preorder[i] != inorder[is])
        {
            i++;
            ts->left = new TreeNode(preorder[i]);
            dfs(ts->left, preorder, inorder, is1 + 1);
        }
        else is = i + 1;
        if (is1 == 0 && i < preorder.size()-1)
        {
            i++;
            ts->right = new TreeNode(preorder[i]);
            dfs(ts->right, preorder, inorder, is1);
        }

    }
};
/*
          3                     
     9         20
 null null  15    7        

                       3
              9                 7
         20       null     null     null
      15      null   
     7   null
null null

*/

int main(void)
{

    Solution10818 s;
    //vector<int> v1 = { 3,9,20,15,7 };
    //vector<int> v2 = { 9,3,15,20,7 };
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {2,3,1};
    TreeNode* a = s.buildTree(v1, v2);
    //printcode(a,0);
    TreeNode_dfs(a);

    //Codec c;
    //string as = "[3,5,1,6,2,0,8,null,null,7,4]";
    //TreeNode* ls = c.deserialize(as);
    //Solution00817 s8;
    //TreeNode* ls1 = ls;
    //
    //cout << s8.lowestCommonAncestor(ls, testcs(ls1, 5), testcs(ls1, 1))->val << endl;

    //s8.lowestCommonAncestor();

    //c815(ls);
    //test815();
    //string s = "abc";

    //Solution0012 ss;
    //vector<string> v = ss.permutation(s);
    //for_each(v.begin(), v.end(), forprint());
    //string s1 = s;
    //s[2] = s[0];
    //cout << s;
	//test();
    //string a = "[1,2,3,null,null,4,5]";
    //int i = a.find(',', 7);
    //cout << i << endl;
    //cout << a.substr(7, i-7);
    //test2(a);
	return 0;
}
//abcd
//
=======
#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>

class forprint
{
public:
    void operator()(int a)
    {
        cout << a << " ";
    }
    void operator()(string a)
    {
        cout << a << " ";
    }
};

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 class Codec {
 public:
     string serialize(TreeNode* root) {
         if (root == NULL) return "[]";
         string s = "[";
         queue<TreeNode*> q;
         q.push(root);
         while (q.size())
         {
             TreeNode* tmp = q.front();
             q.pop();
             if (tmp != NULL)
             {
                 s += (to_string(tmp->val) + ',');
                 q.push(tmp->left);
                 q.push(tmp->right);
             }
             else s += "null,";
         }
         s.pop_back();
         s += "]";
         return s;
     }
     TreeNode* deserialize(string data) {
         if (data == "[]")return NULL;
         vector<string> v = datastr(data.substr(1,data.size()-2));
         queue<TreeNode*> q;
         TreeNode* tmp = new TreeNode(stoi(v[0]));
         q.push(tmp);
         int i = 1;
         while (i < v.size())
         {
             if (v[i] != "null")
             {
                 q.front()->left = new TreeNode(stoi(v[i]));
                 q.push(q.front()->left);
             }
             i++;
             if (!(i < v.size())) return tmp;
             if (v[i] != "null")
             {
                 q.front()->right = new TreeNode(stoi(v[i]));
                 q.push(q.front()->right);
             }
             i++;
             q.pop();
         }
         return tmp;
     }
     //vector<int> datastr(string a)
     //{
     //    a.pop_back();
     //    a += ',';
     //    int an = a.size();
     //    vector<int> v;
     //    int i = 1;
     //    while (i < an)
     //    {
     //        int it = a.find(',', i)-i;
     //        if (a.substr(i, it) != "null") v.push_back(stoi(a.substr(i, it)));
     //        else v.push_back(2000);
     //        i += it + 1;
     //    }
     //    return v;
     //}
     vector<string> datastr(string a)
     {
         vector<string> v;
         int i = 0, j = 0, an = a.size();
         while (i < an)
         {
             int j = i;
             while (j < an && a[j] != ',')
                 j++;
             v.push_back(a.substr(i, j - i));
             i = ++j;
         }
         return v;
     }
};
//[1,2,3,null,null,4,5]
 void printcode(TreeNode* s)
 {
     if (s == NULL) return;
     cout << s->val << " ";
     printcode(s->left);
     printcode(s->right);
}
 void printcode(TreeNode* s,int)
 {
     if (s == NULL) return;
     printcode(s->left);
     cout << s->val << " ";
     printcode(s->right);
 }
void test()
{
    Codec c;
    string a = "[-1,0,1]";
    TreeNode* t = c.deserialize(a);
    printcode(t);

    cout << endl;

    string as = c.serialize(t);
    cout << as << endl;
}
void test2(string a)
{
    
    if (a.substr(7, ',') != "null") cout << 10 << endl;
    else cout << 20 << endl;
}
//class Solution0012 {
//public:
//    vector<string> permutation(string s) {
//        vector<string> v;
//        int sn = s.size();
//        for (int i = 0; i < sn; i++)
//        {
//            string st = s;
//            st[i] = st[0];
//            st[0] = s[i];
//            for (int j = 0; j < sn; j++)
//            {
//                char cs = st[1];
//                v.push_back(st[0] + mysort(st.substr(1, st.size() - 1)) + cs);
//            }
//        }
//        return v;
//    }
//    string mysort(string st)
//    {
//        int i = 0;
//        while (++i < st.size())
//        {
//            st[i - 1] = st[i];
//        }
//        st.pop_back();
//        return st;
//    }
//};


//剑指 Offer 55 - I
class Solution00815 {
public:
    int i = 0;
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return i;
    }
    void dfs(TreeNode* root1, int i)
    {
        if (!root1)
        {
            if (i - 1 > this->i) this->i = i - 1;
            return;
        }
        dfs(root1->left, i + 1);
        dfs(root1->right, i + 1);
    }
};
class Solution10815 {
public:
    int i = 0;
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*
                 1
            2          2
         3     3    3      3  
       4  4   4 4  4 4  
      5 5

*/ 
class Solution20815 {
public:
    int max = INT_MIN;
    int min = INT_MAX;
    bool isBalanced(TreeNode* root) {
        dfs(root, 1);
        return max == min || max - 1 == min ? true : false;
    }
    void dfs(TreeNode* root, int s)
    {
        if (!root)
        {
            if (s - 1 > this->max) this->max = s - 1;
            if (s - 1 < this->min) this->min = s - 1;
            return;
        }
        dfs(root->left, s + 1);
        dfs(root->right, s + 1);

    }
};
//剑指 Offer 55 - II
class Solution30815 {
public:
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1 ? true : false;
    }
    int recur(TreeNode* root)
    {
        if (!root) return 0;
        int left = recur(root->left);
        if (left == -1) return -1;
        int right = recur(root->right);
        if (right == -1) return -1;
        return abs(left - right) >= 2 ? -1 : max(left, right) + 1;
    }
};
class Solution40815 {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 &&
            isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* root)
    {
        if (!root) return 0;
        return max(depth(root->left), depth(root->left)) + 1;
    }
};
class Solution50815 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};
/*
*        1
    null     2
null    3
*/
void cs1()
{

}
void c815(TreeNode* cs)
{
    Solution40815 s;
    cout << s.isBalanced(cs) << endl;
    
 }
//void test815()
//{
//    int a = abs(5-7);
//    cout << a << endl;
//}
//剑指 Offer 68 - I
class Solution00816 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if ((p->val > root->val && q->val < root->val) ||
            (q->val > root->val && p->val < root->val) ||
            (p->val == root->val || q->val == root->val)) return root;

        if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
    }
};

class Solution10816 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL)
        {
            if (p->val > root->val && q->val > root->val) root = root->right;
            else if (p->val < root->val && q->val < root->val) root = root->left;
            else break;
        }
        return root;
    }
};

//剑指 Offer 68 - II
class Solution00817 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL) return right;
        if (right == NULL) return left;
        return root;
    }
};
TreeNode* testcs(TreeNode* a,int b)
{
    if (a == NULL) return NULL;
    if (a->val == b) return a;
    TreeNode* n1 = testcs(a->left,b);
    TreeNode* n2 = testcs(a->right,b);
    return n1 ? n1:n2;
}
/*
*               3,
             5,     1
        6,     2    0,  8,
  null,null   7 4
*/
void TreeNode_dfs(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (q.size())
    {
        if (q.front())
        {
            q.push(q.front()->left);
            q.push(q.front()->right);
            cout << q.front()->val << " ";
        }
        else cout << "null" << " ";
        q.pop();
    }
}

class Solution00818 {
public:
    TreeNode* t;
    int i = 0;
    int is = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) return NULL;
        int i = 0;
        t = new TreeNode(preorder[i]);
        dfs(t, preorder, inorder, 0);
        return t;
    }
    void dfs(TreeNode* ts, vector<int>& preorder, vector<int>& inorder, int j)
    {
        if (i == preorder.size()) return;//遍历到底
        i++;
        ts->left = new TreeNode(preorder[i]);//在前中序i数值不相同的情况下开辟新节点，将数值放到left
        if (preorder[i] == inorder[is])
        {
            is = i + 1;
            return;//前序中序位置数值相同
        }

        dfs(ts->left, preorder, inorder, j + 1);//放入left后往left方向递归
        if (i < preorder.size() && j == 0)//未被遍历到底并且需要返回的节点位j为0则往right方向递归
        {
            ts->right = new TreeNode(preorder[i]);//创建right方向节点
            i++;
            dfs(ts->right, preorder, inorder,j + 1);//并开始递归
        }
    }
};

class Solution10818 {
public:
    int i = 0;
    int is = 0;
    TreeNode* t;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        t = new TreeNode(preorder[i]);
        dfs(t, preorder, inorder, 0);
        return t;
    }
    void dfs(TreeNode* ts, vector<int>& preorder, vector<int>& inorder, int is1)
    {
        if (i - 1 == preorder.size()) return;

        if (preorder[i] != inorder[is])
        {
            i++;
            ts->left = new TreeNode(preorder[i]);
            dfs(ts->left, preorder, inorder, is1 + 1);
        }
        else is = i + 1;
        if (is1 == 0 && i < preorder.size()-1)
        {
            i++;
            ts->right = new TreeNode(preorder[i]);
            dfs(ts->right, preorder, inorder, is1);
        }

    }
};
/*
          3                     
     9         20
 null null  15    7        

                       3
              9                 7
         20       null     null     null
      15      null   
     7   null
null null

*/

int main(void)
{

    Solution10818 s;
    //vector<int> v1 = { 3,9,20,15,7 };
    //vector<int> v2 = { 9,3,15,20,7 };
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {2,3,1};
    TreeNode* a = s.buildTree(v1, v2);
    //printcode(a,0);
    TreeNode_dfs(a);

    //Codec c;
    //string as = "[3,5,1,6,2,0,8,null,null,7,4]";
    //TreeNode* ls = c.deserialize(as);
    //Solution00817 s8;
    //TreeNode* ls1 = ls;
    //
    //cout << s8.lowestCommonAncestor(ls, testcs(ls1, 5), testcs(ls1, 1))->val << endl;

    //s8.lowestCommonAncestor();

    //c815(ls);
    //test815();
    //string s = "abc";

    //Solution0012 ss;
    //vector<string> v = ss.permutation(s);
    //for_each(v.begin(), v.end(), forprint());
    //string s1 = s;
    //s[2] = s[0];
    //cout << s;
	//test();
    //string a = "[1,2,3,null,null,4,5]";
    //int i = a.find(',', 7);
    //cout << i << endl;
    //cout << a.substr(7, i-7);
    //test2(a);
	return 0;
}
//abcd
//
>>>>>>> 3ac2d08 (c++ 2023.8.12)
