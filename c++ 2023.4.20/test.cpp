#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
//        int s = 0;//记录替换的次数
//        for (vector<int>::iterator it = arr1.begin(); it != arr1.end(); it++)
//        {
//            if ((it + 1) != arr1.end() && *it >= *(it + 1))
//            {
//                int i = 1000000000;
//                int ls = 0;
//                for (vector<int>::iterator it2 = arr2.begin(); it2 != arr2.end(); it2++)
//                {
//                    if (*(it+1) > *it2)
//                    {
//                        if(i > *it2)
//                        i = *it2;
//                        ls = 1;
//                    }
//                }
//                if (ls == 0)
//                    return -1;
//                s++;
//                *it = i;
//            }
//        }
//        return s;
//
//    }
//};
#include <algorithm>
//class Solution {
//public:
//    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
//    {
//        sort(arr2.begin(), arr2.end());
//        int ls = 0;
//        for (int i = 0 ;i < arr1.size(); i++)//遍历arr1
//        {
//            bool cs = false;
//            if (i != 0 && i != arr1.size() - 1 && arr1[i] > arr1[i - 1] && arr1[i] < arr1[i + 1])
//                ;
//            else
//                if (i != arr1.size() - 1 && arr1[i] < arr1[i + 1])//是否需要替换
//                {
//                    for (int j = 0; j < arr2.size(); j++)//遍历arr2
//                    {
//                        cs = true;
//                        if (i != 0 && i != arr1.size())//i的位置是否不在头尾
//                        {
//                            if (arr1[i] > arr2[j] && arr1[i - 1]<arr2[j] && arr1[i + 1]>arr2[j])
//                            {
//                                int a = arr1[i];
//                                arr1[i] = arr2[j];
//
//                            }
//                        }
//                        else if (i == 0)//i是否在头
//                        {
//                            if (arr1[i] > arr2[j] && arr1[i + 1] < arr2[j])
//                            {
//                                int a = arr1[i];
//                                arr1[i] = arr2[j];
//                            }
//                        }
//                    }
//                }
//                else if (i == arr1.size() - 1)
//                {
//                    if (arr1[i] > arr1[i - 1])
//                    {
//                        return ls;
//                    }
//                }
//            if (cs)
//            {
//                ls++;
//            }
//            if (ls == 0)
//            {
//                return - 1;
//            }
//        }
//    }
//};

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
    {
        int test = 0;
        bool cs = false;
        for (int i = 0; i < arr1.size(); i++)
        {
            cs = false;
            if (i == 0 || i == arr1.size() - 1)//判断是否在头或尾
            {
                if (i == 0)//在头
                {
                    if (arr1[i] >= arr1[i + 1])//换
                    {
                        for (int j = 0; j < arr2.size(); j++)
                        {
                            if (arr2[j] < arr1[i + 1] && arr2[j] < arr1[i])
                            {
                                cs = true;
                                int n = arr1[i];
                                arr1[i] = arr2[j];
                                arr2[j] = n;
                            }
                        }
                        test++;
                    }
                    else
                    {
                        cs = true;
                    }
                }
                else//在尾
                {
                    if (arr1[i] <= arr1[i - 1])//换
                    {
                        for (int j = 0; j < arr2.size(); j++)
                        {
                            if (arr2[j] < arr1[i - 1] && arr2[j] < arr1[i])
                            {
                                cs = true;
                                int n = arr1[i];
                                arr1[i] = arr2[j];
                                arr2[j] = n;
                            }
                        }
                        test++;
                    }
                    else
                    {
                        cs = true;
                    }

                }
                if (!cs)
                    return -1;
            }
            else
            {
                if (arr1[i] > arr1[i - 1] && arr1[i] < arr1[i + 1])//不换
                {
                    cs = true;
                    ;
                }
                else //换
                {
                    for (int j = 0; j < arr2.size(); j++)
                    {
                        if (arr2[j] > arr1[i - 1] && (arr2[j] < arr1[i] || arr2[j] < arr1[i+1]))
                        {
                            cs = true;
                            int n = arr1[i];
                            arr1[i] = arr2[j];
                            arr2[j] = n;
                        }
                
                    }
                    test++;
                }
                if (!cs)
                    return -1;
            }  
        }
        if (cs)
            return test;
        return -1;
    }
};
int main()
{
    Solution a;
    vector<int> s1{ 1, 5, 3, 6, 7 };
    vector<int> s2{ 4,3,1 };
    cout << a.makeArrayIncreasing(s1, s2) << endl;

	return 0;
}