#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define TLSVAI 10
#include <math.h>


int My_find(int n[], int le, int ri, int s)
{
	if (le > ri) return -1;
	int ls = (le + ri) / 2;
	if (s > n[ls]) My_find(n, ls + 1, ri, s);
	else if (s < n[ls]) My_find(n, le, ls - 1, s);
	else return ls;
}
void My_sort(int a[], int n)
{
	for (int i = 0; i < n/ 2; i++)
	{
		int als = a[i];
		a[i] = a[n - i];
		a[n - i] = als;
	}
}
void ls1(char a)
{
	printf("%c", a);
}

double fun(int x)
{
	double y = 0;
	if (x == 1) return 1;
	else y = pow(x, x) + fun(x-1);
	return y;
}


int main()
{



	//int year, yer;
	//scanf("%d", &year);
	//if (year % 4 == 0 && year % 100 != 0) yer = 1;
	//else if (!year % 400) yer = 1;
	//else yer = 0;
	//printf("%d ", yer);


	//char c = "a";
	//printf("%d", sizeof(c));

	//char  n;
	//scanf("%c", &n);
	//switch (n)
	//{
	//case 's':
	//	printf("%d", 100);
	//	break;
	//}

	//char x[][20] = { "Beijing","Shanghai","Guangzhou","Shenzhen" }, * p;
	//printf("%s", x[0]);
	//for (int i = 0; i < 4; i++)
	//{
	//	p = x[i];
	//	if (i % 2) printf("%s ", p);
	//}
	



	//printf("%6.0f\n", fun(3));


	//char s[2][10];
	//strcpy(s[0], "Tom");
	//strcpy(s[1], "Jerry!");
	////printf("%s and %s\n", s[0], s[1]);
	//char a[10] = { 'q','w','s','a','s','!' };
	//printf("%s", a);

	//int a[10] = { 1,2,3,4,5 }, * p = a;
	//printf("%d", *(p + 2));



	//printf("%c%d", 'A', 'A');


	//int a;
	//float b = 3.6;
	//char c = 97;
	//a = b + c;
	//printf("%d", a);
	//char a[] = "\\Welcome\\";
	//printf("%d", sizeof(a));


	//printf("%d\n", (int)3.9);
	//FILE* p = fopen("data3.txt", "r");
	//if (p == NULL) printf("92");
	//int a = fclose(p);
	//printf("%d", a);


	//char a[] = "hap\npy";
	//printf("%d", strlen(a));
	//ls1(65);

	//int a[3][3] = { 1,2,3,4,5,6,7 };
	//printf("%d", a[1][1]);


	//int a[] = { 9,8,7,6,5,4,3,2,1 };
	//int als = (sizeof(a) / sizeof(int))-1;
	//My_sort(a, als);

	//printf("%d \n", My_find(a, 0, als, 1));


	//int* a;
	////a = (int*)malloc(TLSVAI * sizeof(int));
	//a = (int*)calloc(TLSVAI, sizeof(int));
	//for (int i = 0; i < TLSVAI; i++)
	//{
	//	*(a+i) = i;
	//}
	//for (int i = 0; i < TLSVAI; i++)
	//{
	//	printf("%d  ", *(a + i));
	//}
	//free(a);
	//a = NULL;
	return 0;
}