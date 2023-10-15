#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <set>

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        unordered_map<int, int> um;
        set<int> day;
        vector<int> ans(rains.size(), 1);
        for (int i = 0; i < rains.size(); i++)
        {
            int r = rains[i];
            if (!r)
            {
                day.insert(i);
                continue;
            }
            else if (um.find(r) != um.end())
            {
                auto ls = day.lower_bound(um[r]);
                if (ls == day.end())
                    return {};
                ans[*ls] = r;
                day.erase(ls);
            }
            um[r] = i;
            ans[i] = -1;
        }
        return ans;
    }
};
class Solution1
{
public:
    int singleNumber(vector<int> &nums)
    {
        vector<int> v(32, 0);
        int r = 0;
        for (int n : nums)
        {
            for (int i = v.size() - 1; i >= 0; i--)
            {
                v[i] += n & 1;
                n >>= 1;
            }
        }
        for (int i : v)
        {
            r <<= 1;
            if (i % 3)
                r++;
        }
        return r;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1, 2, 0, 0, 2, 1};
    vector<int> ls = s.avoidFlood(v);
    for (int i : ls)
        cout << i << " ";

    // set<int> s = {1, 2, 3, 5, 6};
    // set<int>::iterator it = s.lower_bound(4);
    // cout << *it << endl;
    // int a = 10;
    // int b = 6;
    // int c = 0;

    // c = a ^ b;
    // c = c ^ a;
    // cout << c << endl;

    return 0;
}
