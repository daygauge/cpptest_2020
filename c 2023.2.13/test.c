#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//#define C 1 
//#define DEBUG 1;
//int main()
//{
//	int c = 0;
//#if defined C
//#ifdef DEBUG
//	printf("%d", c);
//#endif // DEBUG
//#endif
//
//	return 0;
//
//}
//#define S(n) (((n) & 0x55555555) << 1 | ((n) & 0xaaaaaaaa) >> 1)
//int main()
//{
//	int a = 0;
//	a =S(5);
//	printf("%d", a);
//}
//#define H(K,J) (((char*)J)-((char*)K))
//#define SSS(K,J)  (int*)&(((K*)0)->J)
//struct MyStruct
//{
//	int a;
//	int b;
//	int c;
//}ss;
//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//
//}dd;
//int main()
//{
//	int a = 0;
//	//a = H(&ss, &ss.c);
//	//a = H((&dd), &dd.a);
//	a = SSS(struct A, c);
//	printf("%d", a);
//}

//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//}
//#define CASE break;case 
//int main()
//{
//	switch ( )
//	{
//	case 1:
//	CASE 2:
//	CASE 3:
//	CASE 4:
//	}
//}
//#define SQUARE(x) x * x
//int main()
//{
//	int a = SQUARE(5);
//	return 0;
//}
//#define SS(X) printf("ssss "#X" ssss%d\n",X)
//int main()
//{
//	int a = 10;
//	SS(a);
//	int b = 20;
//	SS(b);
//	int c = 30;
//	SS(b);
//}

//#define X(s,b) a##s + b
//int main()
//{
//	int a5 = 10;
//	int b = X(5, 10);
//	printf("%d", b);
//}
//
//
//
//#define MAX(a, b) ( (a) > (b) ? (a) : (b) )
//int main()
//{
//	int x = 5;
//	int y = 8;
//	int z = MAX(x++, y++);
//	printf("x=%d y=%d z=%d\n", x, y, z);
//}
//
//#define MAX(a, b) ( (a) > (b) ? (a) : (b) )
//int main()
//{
//	int x = 5;
//	int y = 8;
//	int z = ((x++) > (y++) ? (x++) : (y++));
//	printf("x=%d y=%d z=%d\n", x, y, z);
//}

//#define MALLOC(num, type) (type *)malloc(num * sizeof(type))
//int main()
//{
//	int* a = MALLOC(10, int);
//}
//#define AA 5
//int main()
//{
//	int a = AA;
//#undef AA
//	int b = AA;
//
//}

//#include <stdio.h>
//int main()
//{
//	int array[ARRAY_SIZE];
//	int i = 0;
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		array[i] = i;
//	}
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//	return 0;
//}
//#define A 1
//#define B 0
//int main()
//{
//#if B
//	printf("B");
//#elif A
//	printf("A");
//#else
//	printf("");
//#endif
//	return 0;
//}
//#define W
//int main()
//{
//#ifdef  W
//	printf("s");
//#endif
//}
