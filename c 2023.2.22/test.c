#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS 1



//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    if (list1 == NULL)
//        if (list2 == NULL)
//            return NULL;
//        else
//            return list2;
//    if (list2 == NULL)
//        return list1;
//    struct ListNode* n1 = list1, * n2 = list2, * n3 = NULL, * n4 = NULL;
//    n3 = n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    while (n1 && n2) {
//        if (n1->val < n2->val) {
//            n4->next = n1;
//            n1 = n1->next;
//        }
//        else {
//            n4->next = n2;
//            n2 = n2->next;
//        }
//        n4 = n4->next;
//    }
//    if (n1)
//        n4->next = n1;
//    if (n2)
//        n4->next = n2;
//    return n3->next;
//}
// struct ListNode {
//      int val;
//      struct ListNode *next;
// };
// 
//struct ListNode* middleNode(struct ListNode* head)
//{
//    if (head == NULL)
//        return NULL;
//    struct ListNode* n1 = head, * n2 = head;
//    while (n2->next)
//    {
//        n1 = n1->next;
//        n2 = n2->next->next;
//    }
//    return n1;
//}

//#include <stdio.h>
//struct ListNode {
//    int val;
//    struct ListNode *next;
//};
//
//int chkPalindrome(struct ListNode* A)
//{
//        struct ListNode* n1 = A, * n2 = A;
//        while (n2 && n2->next)
//        {
//            n1 = n1->next;
//            n2 = n2->next->next;
//        }
//        struct ListNode* l1 = n1, * l2 = n1->next, * l3 = n1->next->next;
//        while (l2->next)
//        {
//            l2->next = l1;
//            l1 = l2;
//            l2 = l3;
//            l3 = l3->next;
//        }
//        while (l2->next == n1 && A->next != n1)
//        {
//            if (l2->val != A->val)
//                return 0;
//            l2 = l2->next;
//            A = A->next;
//        }
//        return 1;
//}
//int main()
//{
//    struct ListNode* a1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* a2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* a3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* a4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* a5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* a6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    a1->next = a2;
//    a2->next = a3;
//    a3->next = a4;
//    a4->next = a5;
//    a5->next = a6;
//    a6->next = 0;
//    a1->val = 1;
//    a2->val = 2;
//    a3->val = 3;
//    a4->val = 3;
//    a5->val = 2;
//    a6->val = 1;
//    printf("%d", chkPalindrome(a1));
//    return 0;
//}

//class PalindromeList {
//public:
//    bool chkPalindrome(ListNode* A) {
//        ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));//哨兵结点
//        dummy->next = A;
//        ListNode* fast = dummy;
//        ListNode* slow = dummy;
//        while (fast && fast->next)  //获取中间结点
//        {
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//
//        ListNode* cur = slow->next; //反转链表
//        ListNode* next = cur->next;
//        ListNode* pre = slow;
//        slow->next = NULL; //防止形成环！！！！！
//        while (1)
//        {
//            cur->next = pre;
//            pre = cur;
//            if (next == NULL) //注意判断的是next而不是cur->next
//                break;
//            cur = next;
//            next = cur->next;
//        }
//
//        ListNode* head = A;
//        ListNode* tail = cur;
//        while (tail != slow)
//        {
//            if (head->val != tail->val)
//                return false;
//            tail = tail->next;
//            head = head->next;
//        }
//        return true;
//    }
//};
int main()
{

}