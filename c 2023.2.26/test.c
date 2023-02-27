#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"




void chse1()
{
	ST ss;
	StacKInit(&ss);
	StackPush(&ss, 1);
	StackPush(&ss, 2);

	printf("%d\n", StackTOP(&ss));
	StackPop(&ss);

	StackPush(&ss, 3);
	StackPush(&ss, 4);
	StackPrint(&ss);

	printf("%d\n", StackTOP(&ss));
	StackPop(&ss);

	printf("%d\n", StackEmpty(&ss));

	printf("%d\n", StackTOP(&ss));
	StackPop(&ss);

	printf("%d\n", StackTOP(&ss));
	StackPop(&ss);

	printf("%d\n", StackEmpty(&ss));

}
int main()
{
	chse1();

	return 0;
}