#define _CRT_SECURE_NO_WARNINGS 1;
#include "text.h"

void bti()
{
	printf("********************************************\n");
	printf("*******1.添加联系人   2,查找联系人  ********\n");
	printf("*******3.修改联系人   4.删除联系人  ********\n");
	printf("*******5.联系人列表   6.排序通讯录  ********\n");
	printf("**************   0.退出   ******************\n");
	printf("********************************************\n");
}
enum ze
{
	kuong,
	tianjia,
	chazao,
	xgai,
	shanc,
	sclbiao,
	paixu,

};
int main()
{
	int a = 0;
	hj hjjs;
	chushihua(&hjjs);
	do
	{
		bti();
		scanf("%d", &a);
		switch (a)
		{
		case tianjia:
	     	tianjiahs(&hjjs);
			break;
		case chazao:
			chazaos(&hjjs);
			break;
		case xgai:
			xgailxr(&hjjs);
			break;
		case shanc:
			shanchus(&hjjs);
			break;
		case sclbiao:
			ckanlbiaos(&hjjs);
			break;
		case paixu:
			paixulianxir(&hjjs);
			break;
		case kuong:
			break;
		 default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (a);
	
}