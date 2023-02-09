#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

void cshua(sywbbxz* sywbb, sywzb* zb)
{
	sywbb->sywji = (syw*)calloc(CSGS, sizeof(syw));
	if (sywbb->sywji != NULL)
	{
		sywbb->sfkp = CSGS;
		sywbb->gs = 0;
		jiazwj(sywbb,zb);
		return;
	}
	perror("内存不足");
}
void jiazwj(sywbbxz* sywbb, sywzb* zb)
{
	FILE* jiazd = fopen("sywbaoc.gfse", "r");
	if (jiazd == NULL)
	{
		perror("jiazwjs");
		return;
	}
	syw wj = { 0 };
	while (fwrite(&wj, sizeof(syw), 1, jiazd))
	{
		kuor(sywbb);
		sywbb->sywji[sywbb->gs] = wj;
		sywbb->gs++;
	}
	fclose(jiazd);
	jiazd = NULL;
}
void baocuen(sywbbxz* sywbb, sywzb* zb)
{
	FILE* baoc = fopen("sywbaoc.gfse", "w");
	if (baoc == NULL)
	{
		perror("baocuens");
		return;
	}
	for (int i = 0; i < sywbb->gs; i++)
		fwrite(sywbb->sywji+i, sizeof(syw), 1, baoc);
	fclose(baoc);
	baoc = NULL;
}
void chakanbeibao(sywbbxz* sywbb)
{
	printf("%-10s %-10s %-30s \n", "圣遗物种类", "当前等级", "属性");
	for (int i = 0; i < sywbb->gs; i++)
	{
		printf("%-10s %-10d %.2f  %.2f  %.2f  %.2f",sywbb->sywji[i].sywmz,sywbb->sywji[i].sywdj,
			sywbb->sywji[i].sywsx[0],
			sywbb->sywji[i].sywsx[1],
			sywbb->sywji[i].sywsx[2],
			sywbb->sywji[i].sywsx[3]);
		printf("\n");
	}
}
void cshuamb(sywbbxz* sywbb)
{
	for (int i = 0; i < SYWSX; i++)
	{
		int a = (rand() % 6) + 1;
		switch (a)
		{
		case 1:
			sywbb->sywji[sywbb->gs].sywsx[i] = 3.9f;
			break;
		case 2:
			sywbb->sywji[sywbb->gs].sywsx[i] = 7.8f;
			break;
		case 3:
			sywbb->sywji[sywbb->gs].sywsx[i] = 5.4f;
			break;
		case 4:
			sywbb->sywji[sywbb->gs].sywsx[i] = 2.3f;
			break;
		case 5:
			sywbb->sywji[sywbb->gs].sywsx[i] = 1.1f;
			break;
		case 6:
			sywbb->sywji[sywbb->gs].sywsx[i] = 10.1f;
			break;
		}
	}
}
int kuor(sywbbxz* sywbb)
{
	if (sywbb->sfkp == sywbb->gs)
	{
		syw* kr = realloc(sywbb->sywji, sywbb->sfkp + FL);
		if (kr != NULL)
		{
			printf("内存扩容成功\n");
			sywbb->sfkp += FL;
			return 1;
		}
		perror("内存扩容失败");
		return 0;
	}
	return 1;
}
void xzbt()
{
	printf("***************************************\n");
	printf("****   1.如雷   2.平雷  3.磐岩    ****\n");
	printf("****   4.流星   5.魔女  6.渡火    ****\n");
	printf("****   7.染血   8.宗室  9.千岩    ****\n");
	printf("****  10.绝缘  11.海染 12.深林    ****\n");
	printf("****            0.退出            ****\n");
	printf("**************************************\n");
}

void diaoy(sywbbxz* sywbb , char* ap)
{
	if (kuor(sywbb))
	{
		strcpy(sywbb->sywji[sywbb->gs].sywmz,ap);
		sywbb->sywji[sywbb->gs].sywdj = 1;
		cshuamb(sywbb);
		sywbb->gs++;
		printf("已存入背包\n");
	}
	else
		printf("电脑内存不足\n");
}
void huoqusyw(sywbbxz* sywbb)
{
	int a = 0;
	xzbt();
	do
	{
		printf("选择需要获取的圣遗物\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			diaoy(sywbb, "如雷");
			break;
		case 2:
			diaoy(sywbb, "平雷");
			break;
		case 3:
			diaoy(sywbb, "磐岩");
			break;
		case 4:
			diaoy(sywbb, "流星");
			break;
		case 5:
			diaoy(sywbb, "魔女");
			break;
		case 6:
			diaoy(sywbb, "渡火");
			break;
		case 7:
			diaoy(sywbb, "染血");
			break;
		case 8:
			diaoy(sywbb, "宗室");
			break;
		case 9:
			diaoy(sywbb, "千岩");
			break;
		case 10:
			diaoy(sywbb, "绝缘");
			break;
		case 11:
			diaoy(sywbb, "海染");
			break;
		case 12:
			diaoy(sywbb, "深林");

			break;
		case 0:
			break;
		default:
			printf("选择错误,请重新选择");
			break;
		}

	} while (a);
}

void shenyiwusj(sywbbxz* sywbb)
{
	int a = 1;
	chakanbeibao(sywbb);
	while (a)
	{
		printf("请选择需要升级的圣遗物序号(退出请输入0)\n");
		scanf("%d", &a);
		int b = a - 1;
		if (a <= sywbb->gs + 1 && a > 0)
		{
			if (sywbb->sywji[b].sywdj != 20)
			{
				
				sywbb->sywji[b].sywdj++;
				printf("升级成功,当前等级 %d \n", sywbb->sywji[b].sywdj);
			}
			else
			{
				printf("此圣遗物等级已达上限\n");
			}
			
		}
		
	}
}
void zbaa(sywbbxz* sywbb)
{
	printf("***********************\n");
	printf("****  1.花   2.羽  ****\n");
	printf("****  3.沙   4.杯  ****\n");
	printf("****  5.头   0.退出   **\n");
	printf("**********************\n");
}
void zuangbeisyw(sywbbxz* sywbb, sywzb* zb)
{
	int a = 0, b = 0;
	float sxlb[SYWSX] = { 0 };
	do
	{
		printf("当前人物面板\n");
		for (int i = 0; i < SYWSX; i++)
		{
			if (i == 0)
				printf("1花面板 2羽面板 3沙面板 4杯面板 5头面板 \n");
			printf("%.2f   %.2f   %.2f   %.2f   %.2f  \n", zb->hua[i], zb->ymao[i], zb->shalo[i], zb->beiz[i], zb->to[i]);
		}
		zbaa(sywbb);
		chakanbeibao(sywbb);
		printf("请选择需要(装备/替换)的圣遗物以及位置\n");
		printf("格式：装备的圣遗物序号 装备位置\n");
		scanf("%d %d", &a, &b);
		if (a <= sywbb->gs && (b <= 5 || b >= 1))
		{
			sxlb[0] = sywbb->sywji[a].sywsx[0];
			sxlb[1] = sywbb->sywji[a].sywsx[1];
			sxlb[2] = sywbb->sywji[a].sywsx[2];
			sxlb[3] = sywbb->sywji[a].sywsx[3];
			printf("装备成功");
			switch (b)
			{
			case 1:
				zb->hua[0] = sxlb[0];
				zb->hua[1] = sxlb[1];
				zb->hua[2] = sxlb[2];
				zb->hua[3] = sxlb[3];
				break;
			case 2:
				zb->ymao[0] = sxlb[0];
				zb->ymao[1] = sxlb[1];
				zb->ymao[2] = sxlb[2];
				zb->ymao[3] = sxlb[3];
				break;
			case 3:
				zb->shalo[0] = sxlb[0];
				zb->shalo[1] = sxlb[1];
				zb->shalo[2] = sxlb[2];
				zb->shalo[3] = sxlb[3];
				break;
			case 4:
				zb->beiz[0] = sxlb[0];
				zb->beiz[1] = sxlb[1];
				zb->beiz[2] = sxlb[2];
				zb->beiz[3] = sxlb[3];
				break;
			case 5:
				zb->to[0] = sxlb[0];
				zb->to[1] = sxlb[1];
				zb->to[2] = sxlb[2];
				zb->to[3] = sxlb[3];
				break;
			default:
				break;
			}
		}
	} while (a);
}

