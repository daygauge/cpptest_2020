#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
#include <vector>
using namespace std;


//class Solution {
//public:
//    int minNumberOfFrogs(string croakOfFrogs) {
//        vector<int> v;
//        char ls = 'c';
//        for (int i = 0; i < croakOfFrogs.size(); i++)
//            v.push_back(croakOfFrogs[i]);
//        for (int i = 0; i < v.size(); i++)
//        {
//            if (v[i] == ls)
//            {
//                ls = 'r';
//                for (int j = i + 1; j < v.size(); j++)
//                {
//                    if (v[j] == ls)
//                    {
//                        ls = 'o';
//                        v[j] = '0';
//                    }
//                    else if(v[j] == ls)
//                    {
//                         ls = 'a';
//                         v[j] = '0';
//                    }
//                    else if (v[j] == ls)
//                    {
//                        v[j] = '0';
//                        break;
//                    }
//                }
//            }
//            else if (v[i] == '0')
//            {
//                i++;
//            }
//            else
//            {
//                return -1;
//            }
//            if (ls != 'a')
//                return -1;
//            ls = 'c';
//        }
//    }
//};

//class Solution {
//public:
//    int minNumberOfFrogs(string croakOfFrogs) {
//        vector<int> v;
//        for (int i = 0; i < croakOfFrogs.size(); i++)
//        {
//            if (croakOfFrogs[i] == 'c')
//            {
//                if (find(v.begin(), v.end(), 'k') == v.end())
//                    v.push_back(croakOfFrogs[i]);
//                else
//                    *(find(v.begin(), v.end(), 'k')) = croakOfFrogs[i];
//            }
//            else if (croakOfFrogs[i] == 'r')
//            {
//                if (find(v.begin(), v.end(), 'c') == v.end())
//                    return -1;
//                else
//                    *(find(v.begin(), v.end(), 'c')) = croakOfFrogs[i];
//            }
//            else if (croakOfFrogs[i] == 'o')
//            {
//                if (find(v.begin(), v.end(), 'r') == v.end())
//                    return -1;
//                else
//                    *(find(v.begin(), v.end(), 'r')) = croakOfFrogs[i];
//            }
//            else if (croakOfFrogs[i] == 'a')
//            {
//                if (find(v.begin(), v.end(), 'o') == v.end())
//                    return -1;
//                else
//                    *(find(v.begin(), v.end(), 'o')) = croakOfFrogs[i];
//            }
//            else if (croakOfFrogs[i] == 'k')
//            {
//                if (find(v.begin(), v.end(), 'a') == v.end())
//                    return -1;
//                else
//                    *(find(v.begin(), v.end(), 'a')) = croakOfFrogs[i];
//            }
//        }
//        for (int i = 0; i < v.size(); i++)
//        {
//            if (v[i] != 'k')
//                return -1;
//        }
//        return v.size();
//    }
//};

//class Solution {
//public:
//    int minNumberOfFrogs(string croakOfFrogs) {
//        vector<int> v = { 0,0,0,0,0 };
//        char ls;
//        for (int i = 0; i < croakOfFrogs.size(); i++)
//        {
//            ls = croakOfFrogs[i];
//            if (ls == 'c')
//            {
//                v[0]++;
//                if (v[4] > 0)
//                    v[4]--;
//            }
//            else if (ls == 'r')
//            {
//                v[1]++;
//                if (v[0] > 0)
//                    v[0]--;
//                else
//                    return -1;
//            }
//            else if (ls == 'o')
//            {
//                v[2]++;
//                if (v[1] > 0)
//                    v[1]--;
//                else
//                    return -1;
//            }
//            else if (ls == 'a')
//            {
//                v[3]++;
//                if (v[2] > 0)
//                    v[2]--;
//                else
//                    return -1;
//            }
//            else if (ls == 'k')
//            {
//                v[4]++;
//                if (v[3] > 0)
//                    v[3]--;
//                else
//                    return -1;
//            }
//        }
//        if (v[0] == 0 && v[1] == 0 && v[2] == 0 && v[3] == 0)
//            return v[4];
//        else
//            return -1;
//    }
//};

//class Solution {
//public:
//    int hardestWorker(int n, vector<vector<int>>& logs) {
//        int ls = logs[0][1];
//        int age = logs[0][0];
//        for (int i = 1; i < logs.size(); i++)
//        {
//            if (ls < logs[i][1] - logs[i - 1][1])
//            {
//                ls = logs[i][1] - logs[i - 1][1];
//                age = logs[i][0];
//
//            }
//            else if (ls == logs[i][1] - logs[i - 1][1]) {
//                if (logs[i][0] < age)
//                    age = logs[i][0];
//
//            }
//        }
//        return age;
//    }
//};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid[0][1] == 1 && grid[1][1] == 1 && grid[1][0] == 1)
        {
            return -1;
        }
        int i = 0, j = 0;
        int ls = grid.size();
        int rls = 1;
        while (j != ls - 1 && i != ls - 1)
        {
            if (j != ls - 1 && grid[i][j + 1] == 0)
            {
                j++;
            }
            else if (j != ls - 1 && i != ls - 1 && grid[i + 1][j + 1] == 0)
            {
                i++;
                j++;
            }
            else if (i != ls - 1 && grid[i + 1][j] == 0)
            {
                i++;
            }
            else if (i != ls - 1 && j != 0 && grid[i + 1][j - 1] == 0)
            {
                i++;
                j--;
            }
            else if (i != 0 && j != ls - 1 && grid[i - 1][j + 1] == 0 && i != 0)
            {
                i--;
                j++;
            }
            else if (j != 0 && grid[i][j - 1] == 0)
            {
                j--;
            }
            else if (i != 0 && grid[i - 1][j] == 0)
            {
                i--;
            }
            else {
                return-1;
            }
            rls++;
        }
        return rls;
    }
};

void test01()
{
	vector<int> c;
	while (1)
	{
		
	}
}
int main()
{
	test01();
	return 0;
}