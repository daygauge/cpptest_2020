#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* xned = (struct ListNode*)malloc(sizeof(struct ListNode));
//    xned->next = head;
//    struct ListNode* css = xned;
//
//
//    while (css->next)
//    {
//        if (css->next->val == val)
//        {
//            struct ListNode* cssbr = css->next;
//            css->next = css->next->next;
//            free(cssbr);
//        }
//        else
//        {
//            css = css->next;
//        }
//    }
//    return xned->next;
//}

void csahos1()
{
	SListNode* ls = NULL;
	SListPushBack(&ls, 1);
	SListPushBack(&ls, 2);
	SListPushBack(&ls, 3);
	SListPushBack(&ls, 4);
	SListPrint(ls);

	SListPushFront(&ls, 1);
	SListPushFront(&ls, 2);
	SListPushFront(&ls, 3);
	SListPushFront(&ls, 4);
	SListPrint(ls);

	SListPopBack(&ls);
	SListPopBack(&ls);
	SListPopBack(&ls);
	SListPopBack(&ls);
	SListPopBack(&ls);
	SListPopBack(&ls);
	SListPopBack(&ls);
	SListPopBack(&ls);
	SListPopBack(&ls);
	SListPrint(ls);

}
void csahos2()
{
	SListNode* ls = NULL;
	SListPushFront(&ls, 1);
	SListPushFront(&ls, 2);
	SListPushFront(&ls, 3);
	SListPushFront(&ls, 4);
	SListPrint(ls);

	SListPopFront(&ls);
	SListPopFront(&ls);
	SListPopFront(&ls);
	SListPopFront(&ls);
	SListPopFront(&ls);
	SListPrint(ls);
}
void csahos3()
{
	SListNode* ls = NULL;
	SListPushFront(&ls, 1);
	SListPushFront(&ls, 2);
	SListPushFront(&ls, 3);
	SListPushFront(&ls, 4);
	SListPrint(ls);

	SListInsertAfter(SListFind(ls, 3),29);
	SListInsertAfter(SListFind(ls, 1), 22);
	SListInsertAfter(SListFind(ls, 22), 21);
	SListInsertAfter(SListFind(ls, 29), 11);
	SListPrint(ls);

	SListEraseAfter(SListFind(ls, 22));
	SListPrint(ls);
	SListDestroy(&ls);
	SListPrint(ls);

	SListPushFront(&ls, 1);
	SListPushFront(&ls, 2);
	SListPushFront(&ls, 3);
	SListPushFront(&ls, 4);
	SListPrint(ls);
}

int main()
{
	//csahos1();
	//csahos2();
	csahos3();

	return 0;
}