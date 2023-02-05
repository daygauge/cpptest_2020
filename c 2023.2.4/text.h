#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define XM 20
#define DZ 20
#define DH 20
#define TXRDX 200
#define XB 5

#define CSNC 3
#define JA 2
typedef struct zrxx
{
	char xmin[XM];
	char xinb[XB];
	int nianling;
	char dianhua[DH];
	char dizhi[DZ];

}hej;
//typedef struct txr
//{
//	hej ji[TXRDX];
//	int su;
//}hj;

typedef struct txr
{
	hej *ji;
	int jic;
	int su;
}hj;


void chushihua(hj *txrs);//初始化

void tianjiahs(hj* txrs);//添加

void ckanlbiaos(hj* txrs);//打印列表

int chazaos(hj* txrs);//查找

void xgailxr(hj* txrs);//修改

void shanchus(hj* txrs);//删除

void paixulianxir(hj* txrs);//排序