#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//class Solution {
//public:
//    bool isValid(string s) {
//        int i = 0;
//        char ls = 'a';
//        vector<char> v;
//
//        for (int i = 0; i < s.size(); i++)
//        {
//            v.push_back(s[i]);
//        }
//
//        while (i < v.size())
//        {
//            if (v[i] == 'a')
//            {
//                ls = 'b';
//                for (int j = i + 1; j < v.size(); j++)
//                {
//                    if (v[j] == ls)
//                    {
//                        v[j] = 's';
//                        if (ls == 'c')
//                        {
//                            ls = 'a';
//                            break;
//                        }
//                        else
//                        {
//                            ls = 'c';
//                        }
//                    }
//                }
//                if (ls != 'a')
//                    return false;
//                i++;
//            }
//            else if (v[i] == 's')
//            {
//                i++;
//            }
//            else
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        if (s[0] != 'a')
            return false;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (st.size() == 0 && s[i] == 'b' || st.size() == 0 && s[i] == 'c')
                return false;
            if (s[i] == 'a') st.push(s[i]);
            else if (s[i] == 'b' && st.top() == 'a') st.push(s[i]);
            else if (s[i] == 'b' && st.top() != 'a') return false;
            else if (s[i] == 'c' && st.top() == 'b') st.push(s[i]);
            else if (s[i] == 'c' && st.top() != 'b') return false;
            if (s[i] == 'c')
            {
                st.pop();
                st.pop();
                st.pop();
            }

        }
        return st.empty();
    }
};
void test02()
{
    Solution ls;
    cout << ls.isValid("aabcbc") << endl;
}
void test01()
{
	vector<int>v;
	while (true)
	{
		v.push_back(1);
		break;
   }
}
int main()
{
    test02();
	//test01();
	return 0;
}