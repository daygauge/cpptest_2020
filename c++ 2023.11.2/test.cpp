#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
using namespace std;
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
//class Solution {
//public:
//    int countPoints(string rings) {
//        vector<vector<int>> v(10, vector<int>(3, 0));
//        for (int i = 0; i < rings.size(); i += 2)
//        {
//            int rgb = 0;
//            if (rings[i] == 'R') rgb = 0;
//            else rgb = rings[i] == 'G' ? 1 : 2;
//
//            v[(rings[i + 1] - '0')][rgb] = 1;
//        }
//        int val = 0;
//        for (auto lsv : v)
//        {
//            if (lsv[0] + lsv[1] + lsv[2] >= 3) val++;
//        }
//        return val;
//    }
//};

//class Node {
//public:
//    int val;
//    Node* left;
//    Node* right;
//    Node* next;
//
//    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
//
//    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
//
//    Node(int _val, Node* _left, Node* _right, Node* _next)
//        : val(_val), left(_left), right(_right), next(_next) {}
//};
//
//class Solution {
//public:
//    Node* connect(Node* root) {
//        if (!root) return root;
//        queue<Node*> q;
//        queue<Node*> q1;
//        q.push(root);
//        while (q.size() || q1.size())
//        {
//            if (q.size())
//            {
//                Node* leftls = NULL;
//                while (q.size())
//                {
//
//                    Node* ls = q.front();
//                    q.pop();
//                    if (ls->left) q1.push(ls->left);
//                    if (ls->right) q1.push(ls->right);
//
//                    leftls == NULL ? leftls = ls : leftls->next = ls;
//                    leftls = ls;
//                }
//            }
//            else
//            {
//                Node* leftls = NULL;
//                while (q1.size())
//                {
//                    Node* ls = q1.front();
//                    q1.pop();
//                    if (ls->left) q.push(ls->left);
//                    if (ls->right) q.push(ls->right);
//
//                    leftls == NULL ? leftls = ls : leftls->next = ls;
//                    leftls = ls;
//
//                }
//            }
//        }
//        return root;
//    }
//};
//void printNode(Node* ls)
//{
//    queue<Node*> q;
//    q.push(ls);
//    while (q.size())
//    {
//        Node* n = q.front();
//        q.pop();
//        if (n)
//        {
//            cout << n->val << " ";
//            q.push(n->left);
//            q.push(n->right);
//        }
//        else
//        {
//            cout << "# ";
//        }
//    }
//}
//void printNext(Node* ls)
//{
//    while (ls)
//    {
//        Node* lsn = ls;
//        while (lsn)
//        {
//            cout << lsn->val << " ";
//            lsn = lsn->next;
//        }
//        cout << "# ";
//        ls = ls-> left;
//    }
//}
void test()
{

    //string s = "B0B6G0R6R0R6G9";
    //Node* n1 = new Node(1);
    //Node* n2 = new Node(2);
    //Node* n3 = new Node(3);
    //Node* n4 = new Node(4);
    //Node* n5 = new Node(5);
    //Node* n6 = new Node(7);
    //n1->left = n2;
    //n1->right = n3;
    //n2->left = n4;
    //n2->right = n5;
    //n3->right = n6;
    ////printNode(n1);

    //Solution S1;
    //S1.connect(n1);
    //printNext(n1);


    //cout<<sl.countPoints(s)<<endl;
}

//class Solution {
//public:
//    int findMaximumXOR(vector<int>& nums) {
//        int x = 0;
//        for (int k = 31; k >= 0; --k)
//        {
//            unordered_set<int> seen;
//            for (int num : nums) 
//                seen.insert(num >> k);
//
//            int x_next = x * 2 + 1;
//            bool found = false;
//
//            for (int num : nums) 
//            {
//                if (seen.count(x_next ^ (num >> k))) 
//                {
//                    found = true;
//                    break;
//                }
//            }
//
//            if (found) x = x_next;
//            else x = x_next - 1;
//        }
//        return x;
//    }
//};

//class Solution {
//public:
//    int maxProduct(vector<string>& words) {
//        int x = 0;
//        for (int i = 0; i < words.size() - 1; i++)
//        {
//            for (int j = i + 1; j < words.size(); j++)
//            {
//                bool fn = true;
//                for (int n1 = 0; fn && n1 < words[i].size(); n1++) {
//                    for (int n2 = 0; fn && n2 < words[j].size(); n2++) {
//                        if (words[i][n1] == words[j][n2]) fn = false;
//                        if (!fn) break;
//                    }
//                    if (!fn) break;
//                }
//                if (fn)
//                {
//                    if (x < (words[i].size() * words[j].size()))
//                        x = (words[i].size() * words[j].size());
//                }
//            }
//        }
//        return x;
//    }
//};

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();
        vector<int> v(length);
        for (int i = 0; i < length; i++)
        {
            string s = words[i];
            int sLength = s.size();
            for (int j = 0; j < sLength; j++)
                v[i] |= 1 << (s[j] - 'a');
        }

        int nval = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((v[i] & v[j]) == 0)
                    nval = max(nval, int(words[i].size() * words[j].size()));
            }
        }
        return nval;
    }
};

class Solution1 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        vector<string> vret;
        vector<int> v(26, 0);
        int i = 0, j = 10;
        for (int k = 0; k < j; k++)
            v[s[k] - 'A']++;

        while (j < s.size())
        {
            if (j - i < 10) return vret;
            int vtr = true;
            for (int vn : v) if (vn && vn < 2) vtr = false;

            if (vtr)
            {
                string vls;
                vls.append(s, i, 10);
                for (string vfind : vret)
                    if (vfind == vls) vtr = false;
                if (vtr) vret.push_back(vls);

                if (s.size() - j < 10) return vret;
                i = j;
                j += 10;
                for (int& vnls : v) vnls = 0;
                for (int k = i; k < j; k++)
                    v[s[k] - 'A']++;
            }
            else
            {
                v[s[i] - 'A']--;
                i++;
                j++;
                v[s[j - 1] - 'A']++;
            }

        }
        return vret;
    }
};
class Solution2 {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();
        vector<int> v(length);
        for (int i = 0; i < length; i++)
        {
            string s = words[i];
            int sLength = s.size();
            for (int j = 0; j < sLength; j++)
                v[i] |= 1 << (s[j] - 'a');
        }

        int nval = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((v[i] & v[j]) == 0)
                    nval = max(nval, int(words[i].size() * words[j].size()));
            }
        }
        return nval;
    }
};
void test1()
{
    vector<string> v = { "abcw","baz","foo","bar","xtfn","abcdef" };
    string s = "baz";


    //vector<string> v = { "ade","fce","abchi" };
    //Solution s;
    //cout << s.maxProduct(v);



    //Solution s;
    //vector<int> v = { 3,10,5,25,2,8 };
    //cout << s.findMaximumXOR(v) << endl;
}
class Solution118 {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        bool k = false;
        for (int i = 0; i < s.size(); i++)
        {
            int n = i % (numRows-1);
            if (n == 0 && k) k = false;
            else if (n == 0 && !k) k = true;
            if (k)
            {
                v[n] += s[i];
            }
            else
            {
                v[numRows - n - 1] += s[i];
            }
        }
        string re;
        for (string rns : v)
        {
            re += rns;
        }
        return re;
    }
};

int main()
{
    Solution118 s;
    string str = "PAYPALISHIRING";
    cout << s.convert(str, 3) << endl;




    //string a;
    //for (int i = 0; i < a.size() - 9 ; i++)
    //{
    //    cout << "1";
    //}

    //string s = "abcdefgl";
    //string s1;
    //s1.append(s, 2, 4);
    //cout << s1;

    //s.clear();
    //multimap<int,int>


    //string s1;
    //s1.append(s,2, 5);
    //cout << s1 << endl;

    //test1();
    // 
    // 
    // 
    //unordered_set<int> s;
    //s.insert(1);
    //s.insert(1);
    //s.insert(2);
    //s.insert(2);
    //s.insert(3);
    //cout << s.count(3) << endl;

    //test1();


	//test();

	return 0;
}