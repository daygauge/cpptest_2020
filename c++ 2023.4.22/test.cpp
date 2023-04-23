#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <map>

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        vector<int> m(128, 0);
//        int maxlen = 0;
//        int head = 0;
//        for (int i = 0; i < s.size(); i++) {
//            head = max(head, m[s[i]]);
//            m[s[i]] = i + 1;
//            maxlen = max(maxlen, i - head + 1);
//        }
//        return maxlen;
//    }
//};
//int main()
//{
//    Solution ls;
//    //vector<int> name = { 3,6,9,12 };
//    string cs = "pwwkew";
//    std::cout << ls.lengthOfLongestSubstring(cs) << std::endl;
//    return 0;
//}

//class Solution {
//public:
//    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
//        int as = arrivalTime + delayedTime;
//        return as % 24;
//    }
//};

//class Solution {
//public:
//    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
//        vector<int> vs;
//        for (int i = 0; i < nums.size() - k+1; i++)
//        {
//            int cst = 0;
//            vector<int> ls;
//            for (int j = i; j < k+i; j++)
//            {
//                ls.push_back(nums[i+cst++]);
//            }
//            sort(ls.begin(), ls.end());
//            vs.push_back((ls[x - 1] > 0 ? 0 : ls[x - 1]));
//        }
//        return vs;
//    }
//};
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> vs;
        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            vector<int> ls(nums.begin() + i, nums.begin() + i + k);
            sort(ls.begin(), ls.end());
            vs.push_back((ls[x - 1] > 0 ? 0 : ls[x - 1]));
        }
        return vs;
    }
};
void printvector(int n)
{
    cout << n << " ";
}
int main()
{
    //vector<int> m;
    //m.push_back(1);
    //vector<int> v = { 1,-2,-3,-4,-5 };
    vector<int> v = { 1,-1,-3,-2,3 };

    Solution ls;
    vector<int> cs = ls.getSubarrayBeauty(v, 3, 2);
    for_each(cs.begin(), cs.end(), printvector);
    return 0;
}