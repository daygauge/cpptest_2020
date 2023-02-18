#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
#define CASE break;case

bt()
{
	printf("***********************************************\n");
	printf("*******   1 销毁顺序表   2 顺序列表打印 *******\n");
	printf("*******   3 插入数据     4 删除数据     *******\n");
	printf("*******   5 顺序表查找   6 修改顺序表   *******\n");
	printf("*******              0.退出             *******\n");
	printf("***********************************************\n");
}
enum MyEnum
{
	TC,
	XH,
	DAY,
	CR,
	SC,
	CZ,
	XG,
};
int main()
{
	int a = 0;
	int b = 0;
	SeqList ss;
	SeqListInit(&ss);
	do
	{
		bt();
		scanf("%d", &a);
		switch (a)
		{
		case TC:
			CASE XH:
			SeqListDestroy(&ss);
			CASE DAY:
			SeqListPrint(&ss);
			CASE CR:
			charsju(&ss);
			CASE SC:
			sancu(&ss);
			CASE CZ:
			printf("输入查找的值:");
			scanf("%d", &b);
			SeqListFind(&ss,b);
			CASE XG:
			xgai(&ss);
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	} while (a);
	return 0;
}