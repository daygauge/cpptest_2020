#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        if (!s2.size() && !s1.size())return -1;
        if (s2.size())
        {
            int i = s2.top();
            s2.pop();
            return i;
        }
        else
        {
            while (s1.size())
            {
                int i1 = s1.top();
                s1.pop();
                s2.push(i1);
            }
            int i = s2.top();
            s2.pop();
            return i;
        }
    }
};

//class Solution {
//public:
//    bool isNumber(string s) 
//    {
//        int i = 0;
//        int lsd = 1;
//        int lse = 1;
//        while (s[i] == ' ')i++;//Ìø¹ý¿Õ¸ñ
//
//        if ((s[i] == '+' || s[i] == '-'))i++;//ÅÐ¶Ï¿ªÍ·×Ö·û
//        else if (s[i] >= 0 + 48 && s[i] < 10 + 48);
//        else if (s[i] == '.' && (s[i + 1] >= 0 + 48 && s[++i] < 10 + 48)) lsd=0;
//        else return false;
//
//        if ((s[i] >= 0 + 48 && s[i] < 10 + 48)||s[i]=='.')
//        {
//            while (i < s.size())
//            {
//                if (s[i] >= 0 + 48 && s[i] < 10 + 48)
//                {
//
//                }
//                else if (s[i] == 'e' || s[i] == 'E')
//                {
//                    if (lse) lse = 0;
//                    else return false;
//
//                    if (i == s.size() - 1)return false;
//                    if ( (s[i - 1] >= 0 + 48 && s[i - 1] < 10 + 48) )
//                    {
//
//                        if (s[i + 1] >= 0 + 48 && s[i + 1] < 10 + 48)
//                        {
//
//                        }
//                        else if (s[i + 1] == '-')
//                        {
//                            if (s[i + 2] >= 0 + 48 && s[i + 2] < 10 + 48)
//                                i++;
//                        }
//                        else
//                        {
//                            return false;
//                        }
//                    }
//                    else
//                    {
//                        return false;
//                    }
//                }
//                else if (s[i] == '.')
//                {
//                    if (!lse) return false;
//                    if(lsd) lsd = 0;
//                    else return false;
//
//                    if (i + 1 == s.size())
//                    {
//                        if ((s[i - 1] >= 0 + 48 && s[i - 1] < 10 + 48)) return true;
//                        else return false;
//                    }
//                    else if ((s[i - 1] >= 0 + 48 && s[i - 1] < 10 + 48));
//                    else if (s[i + 1] >= 0 + 48 && s[i + 1] < 10 + 48);
//                    else if (s[i + 1] == ' ');
//                    else return false;
//                }
//                else if (s[i] == ' ')
//                {
//                    while (s[i] == ' ' && i < s.size())i++;
//                    if (i == s.size()) return true;
//                    else return false;
//                }
//                else
//                {
//                    return false;
//                }
//                i++;
//            }
//        }
//        else
//        {
//            return false;
//        }
//        return true;
//    }
//};
// 
// 
class Solution01 {
public:
    bool isNumber(string s)
    {
        if (!s.size())return false;//ÅÐ¿Õ
        int i = 0;
        while (s[i] == ' ')++i;//Ìø¹ý¿Õ¸ñ
        bool sbf = fjjc(s, i);//ÅÐ¶Ï¿ªÍ··ûºÅºÍÊý×Ö·ûºÅ

        if (s[i] == '.')//ÅÐ¶Ïµã
        {
            ++i;

            sbf = prints(s, i) || sbf;//»òÌø¹ýµãºó×Ö·û
        }

        if (s[i] == 'e' || s[i] == 'E')//ÅÐ¶Ïe
        {
            ++i;
            sbf = fjjc(s, i) && sbf;//²¢Ìø¹ýeºó×Ö·û
        }

        while (s[i] == ' ')++i;//½áÊø¿Õ¸ñ
        return sbf && i == s.size();
    }
    bool fjjc(string& s, int& i)//¿ªÍ··ûºÅÅÐ¶Ï
    {
        if (s[i] == '+' || s[i] == '-')++i;
        return prints(s, i);
    }
    bool prints(string& s, int& i)//Êý×Ö·ûºÅÅÐ¶Ï
    {
        int pos = i;
        while (i != s.size() && s[i] >= '0' && s[i] <= '9')++i;
        return pos < i;
    }
};


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution121 {
public:
    ListNode* dls(ListNode* head, ListNode* headls)
    {
        if (head->next == NULL) return head;

        headls->val = (dls(head->next, headls)->val);
        headls = headls->next;

    }
    ListNode* reverseList(ListNode* head) {
        ListNode* headls = new ListNode(0);
        while (head != NULL)
        {
            head = head->next;
            headls->next = new ListNode(0);
        }
        dls(head, headls);
        return headls;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        ListNode* lsgead = new ListNode(0);
        ListNode* lsc = lsgead;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            lsgead->val = v[i];
            if (!i) lsgead->next = new ListNode(0);
            lsgead = lsgead->next;
        }
        return lsc;
    }
};
void ListNodepush(int i, ListNode * a)
{
    while (a->next != NULL)
    {
        a = a->next;
    }
    ListNode* ls = new ListNode(i);
    a->next = ls;
}
void test01()
{
    ListNode* ls = new ListNode(1);
    ListNodepush(2, ls);
    ListNodepush(3, ls);
    ListNodepush(4, ls);
    ListNodepush(5, ls);

    Solution sls;
    ListNode* ls01 = sls.reverseList(ls);

    while (ls01 != NULL)
    {
        cout << ls01->val << " ";
        ls01 = ls01->next;

    }



    //Solution01 sols;
    //cout << sols.isNumber("-1E-16") << endl;
    //vector<int> bv;
    //bv.push_back(1);
    //Solution s;
    //cout << s.isNumber("7.e-.") << endl;
    //CQueue c;
    //c.appendTail(3);
    //c.deleteHead();
    //c.deleteHead();
    //c.deleteHead();



	//vector<int> bv;
	//bv.push_back(1);


	return;
}
void testcs()
{
    int i = 0;
    if (i >= 0&&i<10)
    {
        cout << "true" << endl;
    }
}
int main()
{
	test01();
    //testcs();
	return 0;
}