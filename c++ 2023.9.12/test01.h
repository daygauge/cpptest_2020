#include <vector>
using namespace std;
#include <algorithm>
#include <iostream>
#include <queue>
// 剑指 Offer 40
class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        quickSort(arr, 0, arr.size() - 1);
        vector<int> v(arr.begin(), arr.begin() + k);
        return v;
    }
    void quickSort(vector<int> &arr, int left, int right)
    {
        if (left >= right)
            return;
        int L = left, R = right;
        while (L < R)
        {
            while (L < R && arr[R] >= arr[left])
                R--;
            while (L < R && arr[L] <= arr[left])
                L++;
            swap(arr[L], arr[R]);
        }
        swap(arr[left], arr[L]);
        // arr[L] = arr[left];
        quickSort(arr, left, L - 1);
        quickSort(arr, L + 1, right);
    }
    vector<int> quickSort01(vector<int> &arr, int left, int right, int k)
    {
        int L = left, R = right;
        while (L < R)
        {
            while (L < R && arr[R] >= arr[left])
                R--;
            while (L < R && arr[L] <= arr[left])
                L++;
            swap(arr[L], arr[R]);
        }
        swap(arr[left], arr[L]);
        if (L > k)
            return quickSort01(arr, left, L - 1, k);
        else if (L < k)
            return quickSort01(arr, L + 1, right, k);
        vector<int> v(arr.begin(), arr.begin() + k);
        return v;
    }
};
class printfor
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};
void test02();
void test01();

// 剑指 Offer 41
class MedianFinder
{
public:
    /** initialize your data structure here. */
    vector<int> a;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (a.size() == 0)
        {
            a.push_back(num);
            return;
        }
        a.push_back(num);
        int i = a.size() - 1;
        while (i > 0 && a[i - 1] > a[i])
        {
            swap(a[i - 1], a[i]);
            i--;
        }
        return;
    }
    double findMedian()
    {
        if (a.size() % 2)
            return a[a.size() / 2];
        return (a[a.size() / 2.0 - 1] + a[a.size() / 2.0]) / 2.0;
    }
};
class MedianFinder1
{
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> a;
    priority_queue<int, vector<int>, less<int>> b;
    MedianFinder1()
    {
    }
    void addNum(int num)
    {
        if (a.size() == b.size())
        {
            b.push(num);
            a.push(b.top());
            b.pop();
        }
        else
        {
            a.push(num);
            b.push(a.top());
            a.pop();
        }
    }
    double findMedian()
    {
        return a.size() == b.size() ? (a.top() + b.top()) / 2.0 : a.top();
    }
};

// 剑指 Offer 45
class Solution913
{
public:
    string minNumber(vector<int> &nums)
    {
        vector<string> v;
        for (int i = 0; i < nums.size(); i++)
            v.push_back(to_string(nums[i]));
        quickSort(v, 0, v.size() - 1);
        string ls;
        for (string s : v)
            ls.append(s);
        return ls;
    }
    void quickSort(vector<string> &v, int left, int right)
    {
        if (left >= right)
            return;
        int L = left, R = right;
        while (L < R)
        {
            while (v[R] + v[left] >= v[left] + v[R] && L < R)
                R--;
            while (v[L] + v[left] <= v[left] + v[L] && L < R)
                L++;

            swap(v[L], v[R]);
        }
        swap(v[left], v[L]);
        quickSort(v, left, L - 1);
        quickSort(v, L + 1, right);
    }

    void quickSort1(vector<string> &strs, int l, int r)
    {
        if (l >= r)
            return;
        int i = l, j = r;
        while (i < j)
        {
            while (strs[j] + strs[l] >= strs[l] + strs[j] && i < j)
                j--;
            while (strs[i] + strs[l] <= strs[l] + strs[i] && i < j)
                i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[l]);
        quickSort(strs, l, i - 1);
        quickSort(strs, i + 1, r);
    }
};

// 剑指 Offer 61
class Solution9132
{
public:
    bool isStraight(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), less<int>());
        int i = 0;
        while (nums[i] == 0)
            i++;
        for (int s = i; s < nums.size() - 1; s++)
            if (nums[s] == nums[s + 1])
                return false;
        return nums[nums.size() - 1] - nums[i] < 5 ? true : false;
    }
};