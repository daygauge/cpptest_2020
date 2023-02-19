#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

void ches1()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void btdy()
{
	printf("***********************************\n");
	printf("***** 1.位置插入 2.头插 3.尾插 ****\n");
	printf("***** 4.位置删除 5.头删 6.尾删 ****\n");
	printf("***** 7.查找     8.修改 9.打印 ****\n");
	printf("*****-1.销毁     0.退出        ****\n");
	printf("***********************************\n");
}
void xxingbasdbos()
{
	//ches1();
	SeqList ss;
	int a = 0;
	int i = 0, j = 0;
	SeqListInit(&ss);
	do
	{
		btdy();
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("请输入插入位置与插入内容: ");
			scanf("%d %d", &i, &j);
			SeqListInsert(&ss, i, j);
			break;
		case 2:
			printf("请输入插入的内容: ");
			scanf("%d", &i);
			SeqListPushFront(&ss, i);
			break;
		case 3:
			printf("请输入插入的内容: ");
			scanf("%d", &i);
			SeqListPushBack(&ss, i);
			break;
		case 4:
			printf("请输入需要删除数据的位置: ");
			scanf("%d", &i);
			SeqListErase(&ss, i);
			break;
		case 5:
			SeqListPopFront(&ss);
			break;
		case 6:
			SeqListPopBack(&ss);
			break;
		case 7:
			printf("输入需要查找的值: ");
			scanf("%d", &i);
			SeqListFind(&ss, i);
			break;
		case 8:
			xgai(&ss);
			break;
		case 9:
			SeqListPrint(&ss);
			break;
		case 0:
			break;
		case -1:
			SeqListDestroy(&ss);
			break;
		default:
			printf("输入错误");
			break;
		}



	} while (a);
}
//int main()
//{
//	xxingbasdbos();
//
//
//	return 0;
//}

#define N 100
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType array[N];
	size_t size;
}SeqList;

typedef struct SeqList
{
	SLDataType* array; 
	size_t size; 
	size_t capicity; 
}SeqList;
int main()
{


	return 0;
}