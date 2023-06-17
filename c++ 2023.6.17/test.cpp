#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;





class Solution0 {
public:
    int strToInt(string str) {
        if (!str.size()) return 0;
        int i = 0;
        while (str[i] == ' ') i++;

        int ls = 0;
        if (str[i] == '+' || str[i] == '-')
        {
            if (str[i] == '-') ls++;
            i++;
        }

        double a = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9')
        {
            if (ls)
            {
                a -= (str[i] - 48);
            }
            else
            {
                a += (str[i] - 48);
            }

            if (a > INT_MAX|| a < INT_MIN)
            {
                a > INT_MAX ? a = INT_MAX : a = INT_MIN;
                break;
            }
            i++;
            if (i < str.size() && str[i] >= '0' && str[i] <= '9')a *= 10;
        }
        return a;
    }
};
class Solution1 {
public:
    int strToInt(string str) {
        int ssize = str.size();
        int i = 0, pos = 1;
        double sls = 0;
        if (!ssize) return 0;//为空
        while (str[i] == ' ')i++;//去除开头空格

        if (str[i] == '+' || str[i] == '-')//开头符号
        {
            if (str[i] == '-') pos = -1;
            i++;
        }

        while (i < ssize && str[i] >= '0' && str[i] <= '9')
        {
            sls = sls * 10 + str[i] - 48;
            if (sls > INT_MAX)
            {
                sls = INT_MAX;
                return sls * pos;
            }
            i++;
        }
        return sls * pos;
    }
};
void test01()
{
    string a = "-91283472332";
    Solution0 s;
    cout << s.strToInt(a);
}
int main()
{
	//test01();
    int a = INT_MAX;
    //int a = INT_MIN;
    a *= -1;
    cout << a << endl;
	return 0;
}