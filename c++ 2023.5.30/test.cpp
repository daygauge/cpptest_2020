#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <map>
#include <bitset>



 

//void test01()
//{
//	//vector<int> v;
//	//v.push_back(10);
//	//v.push_back(20);
//	//v.push_back(30);
//	//v.push_back(40);
//
//	////vector<int> ::iterator it;
//	//for (auto it = v.begin(); it != v.end(); it++)
//	//{
//	//	cout << *it << " ";
//	//}
//	map<string, int> m;
//	m.insert(make_pair("mls1", 10));
//	m.insert(make_pair("mls2", 20));
//	m.insert(make_pair("mls3", 30));
//	m.insert(make_pair("mls4", 40));
//	//for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
//	//{
//	//	cout << it->first << "," << it->second << endl;
//	//}
//	for (auto it : m)
//	{
//		cout << it.first << "," << it.second << endl;
//	}
//}
//void test02()
//{
//	//bitset<8> b;
//	//b = 1000;
//	//cout << b << endl; 
//	constexpr int n = 1e3+7;
//	bitset<n> b= 0;
//	cout <<b[10]<< endl;
//}


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
constexpr int n = 1e3;
class Solutions {
	bitset<n> bit;
	vector<TreeNode*> v;
	TreeNode* vls(TreeNode* root)
	{
		if (root == nullptr) return nullptr;

		if (root->left != nullptr)root->left = vls(root->left);
		if (root->right != nullptr)root->right = vls(root->right);

		if (bit[root->val])
		{
			if (root->left != nullptr) v.emplace_back(root->left);
			if (root->right != nullptr)v.emplace_back(root->right);
			root = nullptr;
		}

		return root;
	}
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		for (auto it : to_delete) bit[it] = 1;
		root = vls(root);
		if (root != nullptr)v.emplace_back(root);
		return v;
	}
};
class Solution2{
public:
	int averageValue(vector<int>& nums) {
		int n = 0, i = 0;
		for (auto it : nums)
			if (!(it % 3) && !(it % 2))
			{
				n += it;
				i++;
			}
		return n ? n / i : n;
	}
};
class Solution01 {
public:
	vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
		vector<int> v(queries.size(), 0);
		for (int i = 0; i < queries.size(); i++)
		{
			for (int j = queries[i][0]; j <= queries[i][1]; j++)
			{
				if ((words[j][0] == 'a' || words[j][0] == 'e' || words[j][0] == 'i' || words[j][0] == 'o' || words[j][0] == 'u')
					&& (words[j][((words[j]).size() - 1)] == 'a' || words[j][((words[j]).size() - 1)] == 'e'
						|| words[j][((words[j]).size() - 1)] == 'i' || words[j][((words[j]).size() - 1)] == 'o'
						|| words[j][((words[j]).size() - 1)] == 'u'))
				{
					v[i]++;
				}
			}
		}
		return v;
	}
};
class Solution02 {
public:
	int test(char ls)
	{
		return ls == 'a' || ls == 'e' || ls == 'i' || ls == 'o' || ls == 'u';
	}
	vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
		int w = words.size(),q = queries.size();
		vector<int> wls(w, 0);
		for (int i = 0; i < w; i++)
		{
			wls[i] = test(words[i][0]) + test(words[i][(words[i].size()-1)]) == 2 ? 1 : 0;
		}
		vector<int> ls(q,0);
		for (int i = 0; i < q; i++)
		{
			for (int j = queries[i][0]; j <= queries[i][1]; j++)
			{
				ls[i] += wls[j];
			}
		}
		return ls;
	}
};
class Solution0012 {
public:
	int check(char ls)
	{
		return ls == 'a' || ls == 'e' || ls == 'i' || ls == 'o' || ls == 'u';
	}
	vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
		int n = words.size(), m = queries.size();
		vector<int> res(m), sum(n + 1);
		for (int i = 0; i < n; i++)
		{//遍历wprds中每一个string元素,如果头尾均为元音,将sum[i + 1]赋值为1；
			sum[i + 1] = (int)(check(words[i][0]) && check(words[i].back()));
		}

		for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];//把sum数组更新为前缀和数组

		for (int i = 0; i < m; i++)
		{
			int l = queries[i][0] + 1, r = queries[i][1] + 1;
			res[i] = sum[r] - sum[l - 1];//通过前缀和算出区间
		}
		return res;
	}
};
//#define M_A(L,R) (L?v2[R]-v2[L-1]:v2[R])
//void t1()
//{
//	vector<int> v1 = { 3,6,2,8,9,1 };
//	vector<int> v2(v1.size());
//	for (int i = 1 ; i < v1.size();i++)
//	{
//		v2[i] = v1[i] + v2[i - 1];
//	}
//	
//	cout << M_A(2, 5) << endl;
//}

int main()
{
	//t1();
	//return 0;

	//vector<int> v;
	//v.push_back(1);
	Solution sls;
	//vector<string> vls = { "vigplemkoni","krdrlctodtmprpxwditvcps",
	//	"gqjwokkskrb","bslxxpabivbvzkozzvdaykaatzrpe","qwhzcwkchluwdnqjwhabroyyxbtsrsxqjnfpadi",
	//	"siqbezhkohmgbenbkikcxmvz","ddmaireeouzcvffkcohxus","kjzguljbwsxlrd","gqzuqcljvcpmoqlnrxvzqwoyas",
	//	"vadguvpsubcwbfbaviedr","nxnorutztxfnpvmukpwuraen","imgvujjeygsiymdxp" };
	vector<string> vls = { "aba", "bcb", "ece", "aa", "e" };
	vector<vector<int>> vls2 = { {0,2},{1,4},{1,1} };
	cout << (sls.vowelStrings(vls, vls2))[0] << endl;
	cout << (sls.vowelStrings(vls, vls2))[1] << endl;
	cout << (sls.vowelStrings(vls, vls2))[2] << endl;
	return 0;

}