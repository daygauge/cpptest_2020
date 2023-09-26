#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <map>


class LRUCache {
public:
    map<int, int> m;
    list<int> l;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        return key;
    }
    void put(int key, int value) {
        if (m.find(key) == m.end())
        {
            m.insert(pair<int, int>(key, value));
            l.push_front(key);
            if (m.size() > n)
            {
                m.erase(l.back());
                l.pop_back();
            }
        }
        else
        {
            m[key] = value;
            for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
            {
                if (*it == key)
                {
                    l.erase(it);
                    break;
                }
            }
            l.push_front(key);
        }
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() + nums2.size() == 1) return nums1.size() ? nums1[0] : nums2[0];
        int n = (nums1.size() + nums2.size()) / 2 + 1;
        vector<int> v;
        int s = 0, i = 0, j = 0;
        while (s < n)
        {
            if (i < nums1.size() && nums1[i] <= nums2[j]) v.push_back(nums1[i++]);
            else v.push_back(nums2[j++]);
            s++;
        }
        return (nums1.size() + nums2.size()) % 2 ? v[v.size() - 1] : (v[v.size() - 1] + v[v.size() - 2]) / 2.0;
    }
};
class Solution1 {
public:
    vector<int> findLeftRight(string& s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return { left + 1,right - 1 };
    }
    string longestPalindrome(string s) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            vector<int> v = findLeftRight(s, i, i);
            if (v[1] - v[0] > s2 - s1)
            {
                s1 = v[0];
                s2 = v[1];
            }

            v = findLeftRight(s, i, i + 1);
            if (v[1] - v[0] > s2 - s1)
            {
                s1 = v[0];
                s2 = v[1];
            }
        }

        return s.substr(s1, s2 - s1 + 1);
    }
};

void test()
{
    string s = "babad";
    Solution1 s1;
    cout << s1.longestPalindrome(s) << endl;

    //vector<int> v1 = { 1,3 };
    //vector<int> v2 = { 2 };
    //Solution s;
    //cout << s.findMedianSortedArrays(v1, v2) << endl;
    //list<int> l;
    //l.push_back(1);
    //l.push_back(2);
    //l.push_back(3);
    //map<list<int>::const_iterator, int> m;
    //m.insert(pair<list<int>::const_iterator, int>(l.begin(), 10));
    //cout << m[l.begin()] << endl;
    //LRUCache lsr(2);
    //lsr.put(1, 1);
    //lsr.put(2, 2);
    //lsr.get(1);
    //lsr.put(3, 3);
    //lsr.get
}
int main()
{
	test();
	return 0;
}

