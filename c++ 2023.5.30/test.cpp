#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <map>
#include <bitset>



 

void test01()
{
	//vector<int> v;
	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);

	////vector<int> ::iterator it;
	//for (auto it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	map<string, int> m;
	m.insert(make_pair("mls1", 10));
	m.insert(make_pair("mls2", 20));
	m.insert(make_pair("mls3", 30));
	m.insert(make_pair("mls4", 40));
	//for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	//{
	//	cout << it->first << "," << it->second << endl;
	//}
	for (auto it : m)
	{
		cout << it.first << "," << it.second << endl;
	}
}
void test02()
{
	//bitset<8> b;
	//b = 1000;
	//cout << b << endl; 
	constexpr int n = 1e3+7;
	bitset<n> b= 0;
	cout <<b[10]<< endl;
}


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
class Solution {
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
int main()
{
	return 0;

}