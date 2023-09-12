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