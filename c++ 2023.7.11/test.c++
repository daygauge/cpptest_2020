#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>;
using namespace std;
#include <map>


//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        if (s.size() == 1) return 1;
//        map<int, int> m;
//        int value = 0, test = 0;
//        for (int i = 0,j = 0; i <= s.size(); i++)
//        {
//            if (value < test) value = test;
//            m[s[i]]++;
//            if (m[s[i]] > 1)
//            {
//                while (m[s[i]] > 1)
//                {
//                    m[s[j++]]--;
//                    test--;
//                }
//            }
//            test++;
//        }
//        return value;
//    }
//};

/*  2  3  4  5  6  8  9  10  12   
2   3   5
4   6   10
6   9   15
8   12
10  15
12
14



*/


//class Solution {
//public:
//    int nthUglyNumber(int n) {
//        int s = 1;
//        for (int i = 1; i < n; i++)
//        {
//            while (s++)
//            {
//                if (!(s%2) || !(s%3) || !(s%5))
//                    break;
//            }
//        }
//        return s;
//    }
//};


//class Solution {
//public:
//    int nthUglyNumber(int n) {
//        int a = 0, b = 0, c = 0;
//        int dp[10];
//        dp[0] = 1;
//        for (int i = 1; i < n; i++) {
//            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
//            dp[i] = min(min(n2, n3), n5);
//            if (dp[i] == n2) a++;
//            if (dp[i] == n3) b++;
//            if (dp[i] == n5) c++;
//        }
//        return dp[n - 1];
//    }
//};











int main(void)
{
    
	return 0;
}



