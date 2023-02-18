#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define CSH 3
#define ZJ 3


typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;//顺序表
	size_t size;//顺序表个数
	size_t capacity; // 内存个数
}SeqList;

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps);//初始化
void SeqListPrint(SeqList* ps);//顺序列表打印

void charsju(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);//尾部插入数据
void SeqListPushFront(SeqList* ps, SLDateType x);//头部插入数据
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);// 顺序表在pos位置插入x

void sancu(SeqList* ps);
void SeqListPopFront(SeqList* ps);//头部删除数据
void SeqListPopBack(SeqList* ps);//尾部删除数据
void SeqListErase(SeqList* ps, size_t pos);// 顺序表删除pos位置的值

int SeqListFind(SeqList* ps, SLDateType x);// 顺序表查找
void SeqListDestroy(SeqList* ps);//销毁
void xgai(SeqList* ps);//修改
