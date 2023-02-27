#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

typedef char STDatatype;
typedef struct Stack
{
    STDatatype* a;
    int top;        // 栈顶
    int capacity;
}ST;
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDatatype x);
void StackPop(ST* ps);
bool StackEmpty(ST* ps);
int StackSize(ST* ps);
STDatatype StackTop(ST* ps);

void StackInit(ST* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->top = 0; // -1
    ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
    assert(ps);
    if (ps->a)
    {
        free(ps->a);
    }
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}
void StackPush(ST* ps, STDatatype x)
{
    assert(ps);


    // 检查空间够不够，不够就增容
    if (ps->top == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDatatype* tmp = realloc(ps->a, sizeof(STDatatype) * newcapacity);
        if (tmp == NULL)
        {
            printf("rellaoc fail\n");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }


    ps->a[ps->top] = x;
    ps->top++;
}
void StackPop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));


    --ps->top;
}
bool StackEmpty(ST* ps)
{
    assert(ps);


    return ps->top == 0;
}
int StackSize(ST* ps)
{
    assert(ps);


    return ps->top;
}
STDatatype StackTop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));


    return ps->a[ps->top - 1];
}
