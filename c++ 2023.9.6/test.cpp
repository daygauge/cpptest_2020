#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(0, nums.size() - 1, nums, tmp);
    }
private:
    int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
        // 终止条件
        if (l >= r) return 0;
        // 递归划分
        int m = (l + r) / 2;
        int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
        // 合并阶段
        int i = l, j = m + 1;
        for (int k = l; k <= r; k++)
            tmp[k] = nums[k];
        for (int k = l; k <= r; k++) {
            if (i == m + 1)
                nums[k] = tmp[j++];
            else if (j == r + 1 || tmp[i] <= tmp[j])
                nums[k] = tmp[i++];
            else {
                nums[k] = tmp[j++];
                res += m - i + 1; // 统计逆序对
            }
        }
        return res;
    }
};
class Solution01 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        mergeSort(arr,0, arr.size());
        vector<int> arrs(arr.begin(), arr.begin() + k);
        return arrs;
    }
    void mergeSort(vector<int>& arr, int left, int right)
    {
        if (left >= right-1) return;
        int m = (left + right) / 2;
        mergeSort(arr, left, m);
        mergeSort(arr, m, right);
        int i = left, j = m;
        for (int k = left; k < right; k++)
        {
            if (i == m || arr[i] >= arr[j])
            {
                int ls = arr[k];
                arr[k] = arr[j];
                arr[j] = ls;
                j++;
            }
            else if (j == right|| arr[i] <= arr[j])
            {
                int ls = arr[k];
                arr[k] = arr[i];
                arr[i] = ls;
                i++;
            }
        }
    }
};
class print
{
public:
    void operator()(int as)
    {
        cout << as << " ";
    }
};
void test()
{
    //vector<int> v = {7,5,6,4};

    //Solution s;
    //cout << s.reversePairs(v) << endl;
    Solution01 s;
    vector<int> v{ 3,2,1 };
    vector<int> z = s.getLeastNumbers(v, 2);
    for_each(z.begin(), z.end(), print());

}

int main()
{
	test();
	return 0;
}