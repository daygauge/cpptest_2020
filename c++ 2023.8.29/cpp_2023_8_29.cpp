#include <iostream>
using namespace std;
// #include "max.h"
#include <vector>
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
            return 1;
        double res = 1;
        long i = n;
        if (i < 0)
        {
            i = -i;
            x = 1 / x;
        }
        while (i > 0)
        {
            if (i % 2 == 1)
                res *= x;

            x *= x;
            i >>= 1;
        }
        return res;
    }
};

class Solution1
{
public:
    vector<int> printNumbers(int n)
    {
        int s = 1;
        while (n--)
        {
            s *= 10;
        }
        vector<int> v(s - 1, 0);
        if (n == 0)
            return v;
        myPrint(v, 1, s);
        return v;
    }
    void myPrint(vector<int> &v, int left, int right)
    {
        if (right - left < 9)
            return;
        myPrint(v, left, right / 2);
        myPrint(v, right / 2, right);
        for (; left < right; left++)
            v[left - 1] = left;
    }
};
int main()
{
    Solution1 s;
    s.printNumbers(2);

    // int a = 20, b = 10;
    // cout << "hello"
    //  << " " << max(a, b) << endl;
    return 0;
}