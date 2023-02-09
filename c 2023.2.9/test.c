#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


//查看圣遗物背包
//查看人物装备圣遗物
//升级背包圣遗物
//获取圣遗物
//保存文件
//查看当前装备圣遗物



void biaot()
{
	printf("*********************************************\n");
	printf("****  1.查看圣遗物背包   2.查看人物装备  ****\n");
	printf("****  3.升级背包圣遗物   4.获取圣遗物    ****\n");
	printf("****             0.退出并保存            ****\n");
	printf("*********************************************\n");
}

enum MyEnum
{
	BCTC,
	BEIB,
	ZBEI,
	SHENJI,
	CHAKAN,
};
int main()
{
	sywbbxz sywbbb;
	sywzb zb = { 0 };
	int a = 0;
	cshua(&sywbbb,&zb);
	do
	{
		biaot();
		scanf("%d", &a);
		switch (a)
		{
		case BEIB://查看圣遗物背包
			chakanbeibao(&sywbbb);
			break;
		case ZBEI://人物装备
			zuangbeisyw(&sywbbb,&zb);
			break;
		case SHENJI://升级背包圣遗物
			shenyiwusj(&sywbbb);
			break;
		case CHAKAN://获取圣遗物
			huoqusyw(&sywbbb);
			break;
		case BCTC://退出并保存
			baocuen(&sywbbb,&zb);
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	} while (a);
}