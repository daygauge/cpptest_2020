#define _CRT_SECURE_NO_WARNINGS 1



//
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
// 
//
//
// struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
//     struct ListNode* n1 = head;
//     struct ListNode* n2 = head;
//     while (--k)
//         n2 = n2->next;
//     while (n2->next)
//     {
//         n2 = n2->next;
//         n1 = n1->next;
//     }
//     return n1;
// }
//
//int main()
//{
//
//	return 0;
//
//}
//
///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//#include <cstddef>
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        if (pHead == NULL)
//            return NULL;
//        struct ListNode* n1 = pHead, * n2 = pHead->next;
//        while (n2->next)
//        {
//            n1 = n1->next;
//            n2 = n2->next;
//            if (n2->val == x)
//            {
//                if (n2->next)
//                {
//                    n1->next = n1->next->next;
//                    n2->next = pHead;
//                }
//                else
//                {
//                    n1->next = NULL;
//                    n2->next = pHead;
//                }
//                pHead = n2;
//            }
//        }
//
//        while (n2->val != x && n2->next)
//        {
//            n1 = n1->next;
//            n2 = n2->next;
//        }
//
//
//
//        if (n2->next)
//        {
//            n1->next = n1->next->next;
//            n2->next = pHead;
//        }
//        else
//        {
//            n1->next = NULL;
//            n2->next = pHead;
//        }
//        return n2;
//
//    }
//};

//#include <cstddef>
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        if (pHead == NULL)
//            return NULL;
//        struct ListNode* n1 = pHead, * n2 = pHead->next, * nn = pHead;
//        while (nn->val != x && nn->next)
//            nn = nn->next;
//        if (nn->next == NULL)
//            return pHead;
//        while (n1->next)
//        {
//
//            if (n2->val < x)
//            {
//                if (n2->next)
//                {
//                    n1->next = n1->next->next;
//                    n2->next = pHead;
//                    pHead = n2;
//                    if (n1->next)
//                        n2 = n1->next;
//                }
//                else
//                {
//                    n1->next = NULL;
//                    n2->next = pHead;
//                    pHead = n2;
//                }
//            }
//            else
//            {
//                n1 = n1->next;
//                n2 = n2->next;
//            }
//
//        }
//
//        return pHead;
//
//    }
//};


//
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        if (pHead == NULL)
//            return NULL;
//        struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
//        //创建链表表头
//
//        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        struct ListNode* cur = pHead;
//        while (cur)
//        {
//            //小于x的尾插到lessTail
//            if (cur->val < x)
//            {
//                lessTail->next = cur;
//                lessTail = lessTail->next;
//            }
//            //大于等于x的尾插到greaterTail
//            else
//            {
//                greaterTail->next = cur;
//                greaterTail = greaterTail->next;
//            }
//            cur = cur->next;
//        }
//        //链接两个链表
//        lessTail->next = greaterHead->next;
//        greaterTail->next = NULL;
//        //获取表头
//        pHead = lessHead->next;
//        free(lessHead);
//        free(greaterHead);
//
//        return pHead;
//    }
//};
//#include <cstddef>
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        if (pHead == NULL)
//            return NULL;
//        struct ListNode* n1s, * n2s, * m1s, * m2s;
//        n1s = n2s = (struct ListNode*)malloc(sizeof(struct ListNode));
//        m1s = m2s = (struct ListNode*)malloc(sizeof(struct ListNode));
//        struct ListNode* cm = pHead;
//        while (cm)
//        {
//            if (cm->val < x)
//            {
//                n2s->next = cm;
//                n2s = n2s->next;
//            }
//            else
//            {
//                m2s->next = cm;
//                m2s = m2s->next;
//            }
//            cm = cm->next;
//        }
//        n2s->next = m1s->next;
//        m2s->next = NULL;
//        pHead = n1s->next;
//        free(n1s);
//        free(m1s);
//
//        return pHead;
//    }
//};
//
//struct ListNode {
//      int val;
//      struct ListNode *next;
//};
// 
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    if (list1)
//        return list2;
//    if (list2)
//        return list1;
//    struct ListNode* n1 = list1, * n2 = list2;
//    struct ListNode* ls = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* lss = ls;
//    while (n1->next && n2->next)
//    {
//        if (n1->val <= n2->val)
//        {
//            ls->next = n1->next;
//            n1 = n1->next;
//        }
//        else
//        {
//            ls->next = n2->next;
//            n2 = n2->next;
//        }
//        ls = ls->next;
//    }
//    if (n1->next)
//    {
//        ls->next = n1;
//    }
//    if (n2->next)
//    {
//        ls->next = n2;
//    }
//    return lss->next;
//}
//int main()
//{
//    struct ListNode* s1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* s2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* s3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    s1->val = 1;
//    s1->next = s2;
//    s2->val = 2;
//    s2->next = s3;
//    s3->val = 4;
//
//
//
//    return 0;
//}
#include <cstddef>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* partition(struct ListNode* pHead, int x) {
        if (pHead == NULL)
            return NULL;
        struct ListNode* n1s, * n2s, * m1s, * m2s;
        n1s = n2s = (struct ListNode*)malloc(sizeof(struct ListNode));
        m1s = m2s = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* cm = pHead;
        while (cm)
        {
            if (cm->val < x)
            {
                n2s->next = cm;
                n2s = n2s->next;
            }
            else
            {
                m2s->next = cm;
                m2s = m2s->next;
            }
            cm = cm->next;
        }
        n2s->next = m1s->next;
        m2s->next = NULL;
        pHead = n1s->next;
        free(n1s);
        free(m1s);

        return pHead;
}

int main()
{


    return 0;

}