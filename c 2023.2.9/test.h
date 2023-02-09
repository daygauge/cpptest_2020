#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MICSS 20
#define SYWSX 4
#define CSGS 3
#define FL 2
typedef struct sywbeibao
{

	char sywmz[MICSS];//名字
	int sywdj;//等级
	float sywsx[SYWSX];//属性
}syw;
typedef struct sywb
{
	syw* sywji;
	int sfkp;
	int gs;
}sywbbxz;

typedef struct dqrwzt
{
	float hua[SYWSX];
	float ymao[SYWSX];
	float shalo[SYWSX];
	float beiz[SYWSX];
	float to[SYWSX];
}sywzb;


void cshua(sywbbxz* sywbb, sywzb* zb);//初始化

void chakanbeibao(sywbbxz* sywbb);//圣遗物背包

void huoqusyw(sywbbxz* sywbb);//获取圣遗物

void cshuamb(sywbbxz* sywbb);//初始化圣遗物属性;

void diaoy(sywbbxz* sywbb, char* ap);//初始化圣遗物值

int kuor(sywbbxz* sywbb);//内存扩容

void shenyiwusj(sywbbxz* sywbb);//圣遗物升级

void zuangbeisyw(sywbbxz* sywbb, sywzb* zb);//装备圣遗物
void zbaa(sywbbxz* sywbb);

void baocuen(sywbbxz* sywbb, sywzb* zb);//保存
void jiazwj(sywbbxz* sywbb, sywzb* zb);//加载文件