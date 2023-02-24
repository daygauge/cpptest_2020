#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void congdsi()
{
	ListNode* zhansd = ListCreate();
	ListPushBack(zhansd, 1);
	ListPushBack(zhansd, 2);
	ListPushBack(zhansd, 3);
	ListPushBack(zhansd, 4);
	ListPrint(zhansd);

	ListPopBack(zhansd);
	ListPopBack(zhansd);
	ListPrint(zhansd);

	ListPushFront(zhansd, 1);
	ListPushFront(zhansd, 2);
	ListPushFront(zhansd, 3);
	ListPushFront(zhansd, 4);
	ListPrint(zhansd);

	ListPopFront(zhansd);
	ListPopFront(zhansd);
	ListPopFront(zhansd);
	ListPopFront(zhansd);
	ListPrint(zhansd);

	ListInsert(ListFind(zhansd, 2),3);
	ListInsert(ListFind(zhansd, 2), 3);
	ListInsert(ListFind(zhansd, 2), 3);
	ListInsert(ListFind(zhansd, 2), 3);
	ListPrint(zhansd);

	ListErase(ListFind(zhansd, 2));
	ListPrint(zhansd);

}
congdsi2()
{
	ListNode* zhansd = ListCreate();
	ListPushBack(zhansd, 1);
	ListPushBack(zhansd, 2);
	ListPushBack(zhansd, 3);
	ListPushBack(zhansd, 4);
	ListPushBack(zhansd, 5);
	ListPushBack(zhansd, 6);
	ListPushBack(zhansd, 7);
	ListPrint(zhansd);

	ListPopFront(zhansd);
	ListPopFront(zhansd);
	ListPopFront(zhansd);
	ListPrint(zhansd);

	ListPopBack(zhansd);
	ListPopBack(zhansd);
	ListPrint(zhansd);

	ListPushFront(zhansd, 9);
	ListPushFront(zhansd, 9);
	ListPushBack(zhansd, 8);
	ListPushBack(zhansd, 8);
	ListPrint(zhansd);

	ListDestory(zhansd);
	ListPushBack(zhansd, 7);
	ListPrint(zhansd);
}
//int main()
//{
//	//congdsi();
//	//congdsi2();
//	return 0;
//}



// struct Node 
// {
//      int val;
//    struct Node *next;
//    struct Node *random;
//};
// 
//struct Node* copyRandomList(struct Node* head) 
//{
//	 if (head == NULL)
//		 return NULL;
//	 struct Node* n1 = head;
//	 //合并两个链表val赋值
//	 while (n1)
//	 {
//		 struct Node* n2 = n1->next;
//		 struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
//		 n3->val = n1->val;
//		 n1->next = n3;
//		 n3->next = n2;
//		 n1 = n2;
//	 }
//	 //random复制
//	 struct Node* w1 = head, * w2 = head->next;
//	 while (w1)
//	 {
//		 if (w1->random)
//			 w2->random = w1->random->next;
//		 else
//			 w2->random = w1->random;
//		 if (w2->next)
//			 w2 = w2->next->next;
//		 w1 = w1->next->next;
//	 }
//	 //断开并连接新链表
//	 struct Node* t1 = head->next, * t2 = head->next;
//	 struct Node* t3 = t2->next->next;
//	 while (t2->next)
//	 {
//		 t2->next = t3;
//		 t2 = t2->next;
//		 if (t2->next)
//			 t3 = t3->next->next;
//	 }
//	 return t1;
//}
//
//int main()
//{
//	struct Node* s1 = (struct Node*)malloc(sizeof(struct Node));
//	s1->next = NULL;
//	s1->val = -1;
//	s1->random = NULL;
//
//	copyRandomList(s1);
//
//	return 0;
//}
//
//struct Node* copyRandomList(struct Node* head) {
//	if (head == NULL)
//		return NULL;
//	struct Node* n1 = head;
//	//合并两个链表val赋值
//	while (n1)
//	{
//		struct Node* n2 = n1->next;
//		struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
//		n3->val = n1->val;
//		n1->next = n3;
//		n3->next = n2;
//		n1 = n2;
//	}
//	//random复制
//	struct Node* w1 = head, * w2 = head->next;
//	while (w1)
//	{
//		if (w1->random)
//			w2->random = w1->random->next;
//		else
//			w2->random = w1->random;
//		if (w2->next)
//			w2 = w2->next->next;
//		w1 = w1->next->next;
//	}
//	//断开并连接新链表
//	struct Node* ss1 = head->next, * ss2 = head->next, * ss3 = head->next->next;
//	while (ss3)
//	{
//		ss3 = ss3->next;
//		ss2->next = ss3;
//		ss2 = ss2->next;
//		ss3 = ss3->next;
//	}
//	return ss1;
//}