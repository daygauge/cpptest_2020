#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

typedef int STData;
typedef struct ss
{
	STData* a;
	int top;
	int capacity;
}ST;


void StacKInit(ST* sp);
void StacKDestroy(ST* sp);;
void StackPrint(ST* sp);
void StackPush(ST* ps, STData x);
void StackPop(ST* ps);
STData StackTop(ST* sp);
int StackSize(ST* sp);
bool StackEmpty(ST* ps);

