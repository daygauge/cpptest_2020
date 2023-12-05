#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
#include <deque>
#include <functional>

void test()
{
	//unordered_map<int, vector<int>> index;
	//for (int i = 0; i < 10; i++)
	//{
	//	index[i].push_back(i);
	//}
	////for(unordered_map<int,int>::iterator it = um.begin();it != um.end();it++)
	////{
	////	cout << it->second << " ";
	////}
	//for (auto &&[_, arr] : index)
	//{
	//}
	//unordered_map<int, int> u;
	//map<int, int> m;
	//m.insert(pair<int, int>(10, 20));
}

//class SmallestInfiniteSet {
//public:
//	vector<int> v;
//	SmallestInfiniteSet() {
//		for (int i = 0; i < v.size(); i++)
//		{
//			v.push_back(i + 1);
//		}
//	}
//
//	int popSmallest() {
//		int i = 0;
//		while (i < v.size() && !v[i]) i++;
//		v[i] = 0;
//		return i - 1;
//	}
//
//	void addBack(int num) {
//		if (!v[num - 1])v[num - 1] = num;
//	}
//};
//
//int main()
//{
//	SmallestInfiniteSet s;
//	s.addBack(2);
//	s.popSmallest();
//	s.popSmallest();
//	s.popSmallest();
//	s.addBack(1);
//	s.popSmallest();
//	s.popSmallest();
//	s.popSmallest();
//
//	return 0;
//}

//class Solution {
//public:
//	int maxScore(vector<int>& cardPoints, int k) {
//		int i = 0, j = cardPoints.size() - k - 1, min_window = 0;
//		int val = 0;
//		for (int n = 0; n < cardPoints.size(); n++)
//		{
//			val += cardPoints[n];
//			if (n == j) min_window = val;
//		}
//		int min_windowls = min_window;
//		while (j < cardPoints.size())
//		{
//			min_windowls += cardPoints[j] - cardPoints[i];
//			min_window = min(min_window, min_windowls);
//			i++;
//			j++;
//		}
//		return val - min_window;
//	}
//};

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> g(roads.size() + 1);
        for (auto& e : roads) {
            int x = e[0], y = e[1];
            g[x].push_back(y); // 记录每个点的邻居
            g[y].push_back(x);
        }

        long long ans = 0;
        function<int(int, int)> dfs = [&](int x, int fa) -> int {
            int size = 1;
            for (int y : g[x]) {
                if (y != fa) { // 递归子节点，不能递归父节点
                    size += dfs(y, x); // 统计子树大小
                }
            }
            if (x) { // x 不是根节点
                ans += (size - 1) / seats + 1; // ceil(size/seats)
            }
            return size;
        };
        dfs(0, -1);
        return ans;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> v{ {3,1},{3,2},{1,0},{0,4},{0,5},{4,6} };
    cout << s.minimumFuelCost(v, 2) << endl;
}