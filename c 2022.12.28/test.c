#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//int gbs(int A, int B)
//{
//	int s = 0;
//	if (A > B) 
//	{
//		s = A;
//		while (s % B)
//		{
//			s += A;
//		}
//		return s;
//	}
//	else if (A < B)
//	{
//		s = B;
//		while (s % A)
//		{
//			s += B;
//		}
//		return s;
//	}
//	return A;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("%d", gbs(a, b));
//}

//int hs(int a, int b)
//{
//	int s = 0;
//	if (a > b)
//	{
//		s = a;
//		while (s % b)
//		{
//			s += a;
//		}
//		return s;
//	}
//	else if (a < b) 
//	{
//		s = b;
//		while (s % a)
//		{
//			s += b;
//		}
//		return s;
//	}
//	return a;
//}
//
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d %d", &a, &b);
//	printf("%d", hs(a,b));
//}


//void asdd(char* ap)
//{
//	char* ar = *ap;
//	while (*ap)
//	{
//		while (*ar != ' ' && *ar != '\0')
//		{
//			ar++;
//		}
//		asdao(ap, ar);
//		ap = ar;
//	}
//}

//void asdao(char* ap, char* aps)
//{
//	while (ap < aps)
//	{
//		char as = *ap;
//		*ap = *aps;
//		*aps = as;
//
//		ap++;
//		aps--;
//	}
//}
//int main()
//{
//	char a[100] = { 0 };
//	gets(a);
//	int as = strlen(a);
//	asdao(a, a + as - 1);
//
//	char* ap = a;
//	while (*ap)
//	{
//		char* app = ap;
//		while (*app != ' ' && *app != '\0')
//		{
//			app++;
//		}
//		asdao(ap, app - 1);
//		ap = app + 1;
//	}
//	printf("%s", a);
//}

//int main()
//{
//	int a = 1234;
//	printf("%X", a);
//}

//int main() {
//    char a = 0;
//    int b = 0;
//    double c = 0;
//    scanf("%c\n%d\n%f", &a, &b, &c);
//}

//int main() {
//    int a = 0;
//    int b = 0;
//    int c = 0;
//
//    scanf("%d %d %d", &a, &b, &c);
//    printf("%8d%8d%8d", a, b, c);
//}


//int main()
//{
//	int yh[10][10] = { 1 };
//
//	for (int i = 1; i < 10; i++)
//	{
//		yh[i][0] = 1;
//		for (int j = 1;j < 10;j++) 
//		{
//			yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10;j++) {
//			if(yh[i][j]!=0)
//			printf("%d   ", yh[i][j]);
//		}
//		printf("\n");
//	}
//}

//int main(){
//	char x = 'a';
//	while (1){
//		if (x != 'a' && x == 'c' && (x == 'd' || x != 'd')) {
//			printf("%c", x);
//			break;
//		}
//		x++;
//	}
//}

//int main()
//{
//	int x = 0;
//	for ( x='a';x<='d'; x++)
//	{
//		if ((x != 'a') + (x == 'c') + (x == 'd') + (x != 'd') == 3) {
//			printf("%c", x);
//		}
//	}
//}
//
//int main() 
//{
//	int a, b, c, d, e;
//	while (1)
//	{
//		a = rand() % 5 + 1;
//		b = rand() % 5 + 1;
//		c = rand() % 5 + 1;
//		d = rand() % 5 + 1;
//		e = rand() % 5 + 1;
//
//		if (b == 2 || a == 3) {//a;
//			if (b == 2 || e == 4) {//b
//				if (c == 1 || d == 2) {//c
//					if (c == 5 || d == 3) {//d
//						if (e == 4 || a == 1){//e
//							printf("a=%d b=%d c=%d d=%d e=%d", a, b, c, d, e);
//							break;
//						}
//					}
//				}
//			}
//		}
//	}
//}

//int main()
//{
//	int a[] = { 1,2,3,4,5 };
//	int b[] = { 5,6,7,8,9 };
//	int* c[] = { a,b };
//	printf("%d", c[1][2]);
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5};
//	int b[5] = { 1,2,3,4,5 };
//	int* c[2] = { a,b };
//	for (int i = 0;i < 2;i++) {
//		for (int j = 0;j < 5;j++) {
//			printf("%d ", c[i][j]);
//		}
//		printf("\n");
//	}
//}

//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//void print(struct Stu* ps)
//{
//	printf("name = %s   age = %d\n", (*ps).name, (*ps).age);
//	//使用结构体指针访问指向对象的成员
//	printf("name = %s   age = %d\n", ps->name, ps->age);
//}
//
//int main()
//{
//	struct Stu s = { "zhangsan", 20 };
//	print(&s);//结构体地址传参
//	return 0;
//}
//
//struct S
//{
//	int data[1000];
//	int num;
//};
//
//
////结构体传参
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////结构体地址传参
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//
//int main()
//{
//	struct S s = { {1,2,3,4}, 1000 };
//	print1(s);
//	print2(&s);
//	return 0;
//}

//void tia(int (* a)[5])
//{
//	for (int i = 0; i < 3;i++)
//	{
//		for (int j = 0; j < 5;j++)
//		{
//			printf("%d ", *(* (a + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int a[3][5] = { 1,2,3,4,5 ,1,2,3,4,5 ,1,2,3,4,5 };
//	tia(a);
//}

//int check_sys()
//{
//	int i = 1;
//	return (* (char*) &i);
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}
//
////int main()
//{
//	int i = 1;
//}

//
//int main()
//{
//	char a[1000];
//	int i;
//
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//
//	printf("%d", strlen(a));
//	return 0;
//}
//int main()
//{
//	char a = 128;
//	printf("%d\n", a);
//	printf("%u\n", a);
//	return 0;
//}

//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}


//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}



//diao(int (*a)[5])
//{
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", *(*(a + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int a[3][5] = { 1,2,3,4,5 ,2,3,4,5,6, 3,4,5,6,7 };
//	diao(a);
//}


//int jia(int a, int b)
//{
//	return a + b;
//}
//int jian(int a, int b)
//{
//	return a - b;
//}
//int chen(int a, int b)
//{
//	return a * b;
//}
//int cu(int a, int b)
//{
//	return a/b;
//}
//void bt()
//{
//	printf("1,jia  2,jian\n");
//	printf("3,chen 4,cu  \n");
//	printf("     0,tueic \n");
//}
//
//int main()
//{
//	int s = 0;
//	int a = 0;
//	int b = 0;
//	int(*hs[5])(int,int) = {NULL,jia,jian,chen,cu};
//	do
//	{
//		bt();
//		scanf("%d", &s);
//		if (s != 0&&s<6) {
//			printf("请输入操作数: ");
//			scanf("%d %d", &a, &b);
//			int k = (hs[s])(a, b);
//			printf("%d\n", k);
//		}
//		else if (s > 5) {
//			printf("输入错误,请重新输入\n");
//		}
//	} while (s);
//}

//int pdhs(char* a, char* b,int d)
//{
//	int s = 0;
//		while (d--)
//		{
//			if (*a == *b)
//			{
//				a++;
//				b++;
//				s++;
//			}
//			else
//			{
//				a++;
//			}
//		}
//		return s == d;
//
//}
//
//int main()
//{
//	char a[] = { 0 };
//	char b[] = { 0 };
//	scanf("%c %c", a,b);
//	int d = sizeof(a) / sizeof(a[0]);
//	printf("%d\n", pdhs(a, b, d));
//}
//
//int hs(char* ap, char* bp,int c )
//{
//	int d = 0;
//	int i = 0;
//	char s[200] = { 0 };
//	strcpy(s, ap);
//	strcat(s, ap);
//	while (d<c)
//	{
//		if (s[i] == *bp)
//		{
//			i++;
//			bp++;
//			d++;
//		}
//		else
//		{
//			i++;
//			d = 0;
//		}
//		if (s[i] == '\0')
//			break;
//	}
//	if (d == c)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	char a[20] = { 0 };
//	char b[20] = { 0 };
//	scanf("%s %s", a, b);
//	int c = strlen(a);
//	if (hs(a, b, c) == 1)
//	{
//		printf("是另外一个字符串旋转之后的字符串");
//	}
//	else 
//	{
//		printf("不是另外一个字符串旋转之后的字符串");
//	}
//	return 0;
//}

//void hs(char* ap, int k,int c)
//{
//	char s[200] = { 0 };
//	strcpy(s, ap);
//	strcat(s, ap);
//	strcat(s, ap);
//	int j = k + c;
//	for (int i = k; i < j ; i++)
//	{
//		printf("%c", s[i]);
//	}
//
//}
//
//int main()
//{
//	char a[20] = { 0 };
//	int k = 0;
//	printf("请输入一个字符窜和左旋的字符数\n");
//	scanf("%s %d", a, &k);
//	int c = strlen(a);
//	hs(a, k,c);
//}
//void dy(int* s,int d)
//{
//	for (int i = 0; i < d; i++)
//	{
//		printf("%d ", *(s + i));
//	}
//}
//
//int sints(const void* s1, const void* s2)
//{
//	return *(int*)s1 - *(int*)s2 ;
//}
//int main()
//{
//	int a[10] = { 23,42,8,2,234,13,19,2,122,3 };
//	int sds = sizeof(a) / sizeof(a[0]);
//	qsort(a, sds, sizeof(a[0]), sints);
//	dy(a,10);
//}
//


//void jiaog(char* a1,char* a2, int dx)
//{
//	for (int i = 0; i < dx;i++)
//	{
//		char zhi = *a1;
//		*a1 = *a2;
//		*a2 = zhi;
//		a1++;
//		a2++;
//	}
//}
//
//void w_qsort(void* ap, int gs, int dx, int (*sfhs)(const void*, const void*))
//{
//	char* app = (char*)ap;
//	for (int i = 0;i < gs - 1;i++)
//	{
//		for (int j = 0;j < gs - 1 - i;j++)
//		{
//			if (sfhs(app + j * dx,app+ (j+1) * dx))
//			{
//				jiaog(app + j * dx, app + (j + 1) * dx,dx);
//			}
//		}
//	}
//}
//int wew(const void* w1, const void* w2)
//{
//	return *(int*)w1 - *(int*)w2;
//}
//void print(int* ap, int sa)
//{
//	for (int i = 0;i < sa;i++)
//	{
//		printf("%d ", *(ap + i));
//	}
//}
//void f_print(float* ap, int sa)
//{
//	for (int i = 0;i < sa;i++)
//	{
//		printf("%f ", *(ap + i));
//	}
//}
//int main()
//{
//	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sa = sizeof(a) / sizeof(a[0]);
//	w_qsort(a, sa, sizeof(a[0]), wew);
//	print(a, sa);
//}

//struct jgt
//{
//	int a;
//	char m[20];
//};
//struct  jjgt
//{
//	int a;
//	char name[20];
//};
//int hs(const void* a1, const void* a2)
//{
//	return *(int*)a1 - *(int*)a2;
//}
//int js(const void* a1, const void* a2)
//{
//	return ((struct jgt*)a1)->a - ((struct jgt*)a2)->a;
//}
//int jss(const void* a1, const void* a2)
//{
//	return strcmp(((struct jgt*)a1)->m, ((struct jgt*)a2)->m);
//}
//int ssf(const void* a1, void* a2)
//{
//	return *(float*)a1 - *(float*)a2;
//}
//int jin(const void* s1, const void* s2)
//{
//	return ( ((struct jjgt*)s1)->a - ((struct jjgt*)s2)->a );
//}
//int jjin(const void* s1, const void* s2)
//{
//	return strcmp(((struct jjgt*)s1)->name, ((struct jjgt*)s2)->name);
//}
//void a()
//{
//	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	struct jgt j[3] = { {42,"bhahaha"},{12,"ahehehe"},{56,"gheiheihei"} };
//	//int sa = sizeof(a) / sizeof(a[0]);
//	int jg = sizeof(j) / sizeof(j[0]);
//	//qsort(a, sa, sizeof(a[0]), hs);
//	qsort(j, jg, sizeof(j[0]), jss);
//	//print(a, sa);
//	for (int i = 0;i < jg; i++)
//	{
//		printf("%s ", j[i].m);
//	}
//}
//void b()
//{
//	float a[5] = { 5.2, 2.3, 7.6, 2.4, 8.8 };
//	int s = sizeof(a) / sizeof(a[0]);
//	qsort(a, s, sizeof(a[0]), ssf);
//	f_print(a, s);
//}
//void c()
//{
//	struct jjgt j[4] = { {20,"cccccc"},{43,"aaaa"},{32,"eeeeee"},{21,"ggggggg"} };
//	int gs = sizeof(j) / sizeof(j[0]);
//	//qsort(j, gs, sizeof(j[0]), jin);
//	qsort(j, gs, sizeof(j[0]), jjin);
//	for (int i = 0;i < gs;i++)
//	{
//		printf("%s ", j[i].name);
//	}
//}
//int main()
//{
//	//a();
//	//b();
//	c();
//}

//int xz(int ap[3][3], int* xp, int* yp, int k)
//{
//	 int x = 0;
//	 int y = *yp - 1;
//	while (x<*xp||y>=0)
//	{
//		
//		if (ap[x][y] < k)
//		{
//			x++;
//		}
//		else if(ap[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			*xp = x;
//			*yp = y;
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int a[3][3] = {1,2,3,4,6,7,8,9,10};
//	int k = 6;
//	int x = 3;
//	int y = 3;
//	int js = xz(a, &x, &y, k);
//	if (js)
//	{
//		printf("找到了\n");
//		printf("下标是 :%d %d", x, y);
//	}
//	else
//	{
//		printf("找不到");
//	}
//}

//int main()
//{
//	char a = "a";
//	char* ap = &a;
//	*ap = 'b';
//	printf("%c", a);
//
//	return 0;
//}

//int main()
//{
//	char* a = "abcdef";
//	printf("%s", a);
//
//	return 0;
//}

//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	const char* str3 = "hello bit.";
//	const char* str4 = "hello bit.";
//
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* ap = &a;
//	int* bp = &b;
//	int* cp = &c;
//	int* s[3] = { &a,&b,&c };
//	int** sp[3] = { &ap,&bp,&cp };
//
//	return 0;
//}

//int main()
//{
//	int* a1[10];
//	int(*a2)[10];
//
//	return 0;
//}

//int main()
//{
//	int a[10];
//	printf("%p\n", a);
//	printf("%p\n", &a);
//
//	return 0;
//}

//int main()
//{
//	int a[10] = {0};
//	printf("%p\n", a);
//	printf("%p\n", &a);
//	printf("%p\n", a + 1);
//	printf("%p\n", &a + 1);
//
//	return 0;
//}

//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int(*ap)[10] = &a;
//
//	return 0;
//}

//void cas(int(*ap)[4], int c, int k)
//{
//	for (int i = 0;i < c;i++)
//	{
//		for (int j = 0;j < k;j++)
//		{
//			printf("%d ", *(*(ap + i) + j));
//			printf("%d ", ap[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int a[3][4] = { 1,2,3,4,1,2,3,4,1,2,3,4 };
//	cas(a, 3, 4);
//}

//void test(int arr[])
//{}
//void test(int arr[10])
//{}
//void test(int* arr)
//{}
//void test2(int* arr[20])
//{}
//void test2(int** arr)
//{}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}


//void test(int arr[3][5])
//{}
//void test(int arr[][5])
//{}
//void test(int(*arr)[5])
//{}
//void test(int** arr)
//{}
//
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//}
//
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//
//	print(p, 10);
//	return 0;
//}
//
//void test(int** ptr)
//{
//	printf("%d", **ptr);
//}
//
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//
//	test(pp);
//	test(&p);
//	return 0;
//}

//void test()
//{
//	printf("hehe\n");
//}
//
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	return 0;
//}

//void test()
//{
//	printf("hehe\n");
//}
//void (*pfun1)();
//void* pfun2();

//int hs(int a, int b)
//{
//	return a;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	hs(a, b);
//	int (*hsp)(int, int) = hs;
//	return 0;
//}

//int add(int a, int b)
//{
//	return a + b;
//}
//int sub(int a, int b)
//{
//	return a - b;
//}
//int mul(int a, int b)
//{
//	return a * b;
//}
//int div(int a, int b)
//{
//	return a / b;
//}
//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 0;
//	do
//	{
//		printf("*************************\n");
//		printf(" 1:add           2:sub \n");
//		printf(" 3:mul           4:div \n");
//		printf("*************************\n");
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 2:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 3:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 4:
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			printf("ret = %d\n", ret);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//int add(int a, int b)
//{
//	return a + b;
//}
//int sub(int a, int b)
//{
//	return a - b;
//}
//int mul(int a, int b)
//{
//	return a * b;
//}
//int div(int a, int b)
//{
//	return a / b;
//}
//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 0;
//	int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //转移表
//	while (input)
//	{
//		printf("*************************\n");
//		printf(" 1:add           2:sub \n");
//		printf(" 3:mul           4:div \n");
//		printf("*************************\n");
//		printf("请选择：");
//		scanf("%d", &input);
//		if ((input <= 4 && input >= 1))
//		{
//			printf("输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = (*p[input])(x, y);
//		}
//		else
//			printf("输入有误\n");
//		printf("ret = %d\n", ret);
//	}
//	return 0;
//}

//void test(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	//函数指针pfun
//	void (*pfun)(const char*) = test;
//	//函数指针的数组pfunArr
//	void (*pfunArr[5])(const char* str);
//	pfunArr[0] = test;
//	//指向函数指针数组pfunArr的指针ppfunArr
//	void (*(*ppfunArr)[5])(const char*) = &pfunArr;
//	return 0;
//}

//int int_cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}
//
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//int int_cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}
//
//void _swap(void* p1, void* p2, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		char tmp = *((char*)p1 + i);
//		*((char*)p1 + i) = *((char*)p2 + i);
//		*((char*)p2 + i) = tmp;
//	}
//}
//void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < count - 1; i++)
//	{
//		for (j = 0; j < count - i - 1; j++)
//		{
//			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
//			{
//				_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	bubble(arr, 10, sizeof(int), int_cmp);
//	return 0;
//}
//



//int main() {
//    int s = 0;
//    int f = 0;
//    int k = 0;
//    int c = 0;
//    int d = 0;
//    scanf("%d:%d %d", &s, &f, &k);
//    if (k > 59)
//    {
//        c = k / 60;
//        d = k % 60;
//    }
//    s += c;
//    f += d;
//    if (s < 9 && f>9)
//        printf("0%d:%d", s, f);
//    else if (s < 9 && f < 9)
//        printf("0%d:0%d", s, f);
//    if (s > 9 && f < 9)
//        printf("%d:%d", s, f);
//    else
//        printf("%d:%d", s, f);
//}

//int main() {
//    int s = 0;
//    int f = 0;
//    int k = 0;
//    int c = 0;
//    int d = 0;
//    scanf("%d:%d %d", &s, &f, &k);
//    if (k > 59)
//    {
//        c = k / 60;
//        d = k % 60;
//    }
//    s += c;
//    f += d;
//    while (s > 23)
//    {
//        s -= 24;
//        if (f > 59)
//        {
//            f -= 60;
//            s++;
//        }
//    }
//    if (s < 9 && f>9)
//        printf("0%d:%d", s, f);
//    else if (s <= 9 && f <= 9)
//        printf("0%d:0%d", s, f);
//    else if (s > 9 && f <= 9)
//        printf("%d:%d", s, f);
//    else
//        printf("%d:%d", s, f);
//}


//int main() {
//    long long n = 0;
//    long long m = 0;
//    long long z = 0;
//    scanf("%lld %lld", &n, &m);
//    long long y = n;
//    long long x = m;
//    while (1) {
//        if (n % y == 0 && m % y == 0) {
//            z = y;
//            break;
//        }
//        y--;
//    }
//    while (1) {
//        if (x % n == 0 && x % m == 0) {
//            x = m;
//            break;
//        }
//        x += m;
//    }
//    printf("%lld", y + x);
//}

//int main() {
//    long long n, m, z;
//    scanf("%lld %lld", &n, &m);
//    long long y = n;
//    long long x = m;
//    while (1) {
//        if (n % y == 0 && m % y == 0)
//            break;
//        y--;
//    }
//    while (m % n) {
//        z = m % n;
//        m = n;
//        n = z;
//    }
//    printf("%lld", y + n);
//}

//int main() {
//    long long n, m, z;
//    scanf("%lld %lld", &n, &m);
//
//     
//    long long y = n;
//    long long x = m;
//    long long s = 0;
//
//
//    while (n%m) {
//        z = n % m;
//        n = m;
//        m = z;
//    }
//
//    s = x * y / m;
//    printf("%lld", s + m);
//
//}


//void hs(int b, long long a)
//{
//    int s = 0;
//    long long w = 0;
//    for (int i = 0;i < b;i++)
//    {
//        if (a < 10)
//        {
//            if (a % 2)
//            {
//                s = 1;
//            }
//            else {
//                s = 0;
//            }
//        }
//        else
//        {
//            s = a % 10;
//            if (s % 2)
//            {
//                s = 0;
//            }
//            else {
//                s = 1;
//            }
//            s = a / 10;
//        }
//        w += s;
//        w *= 10;
//    }
//    printf("%lld", w);
//}
//int main() {
//    long long a = 0;
//    int b = 0;
//    scanf("%lld", &a);
//    long long c = a;
//    while (a)
//    {
//        a = a / 10;
//        b++;
//    }
//    hs(b, a);
//}

//void hs(int b, long long a)
//{
//
//    printf("%d", b);
//}
//int main() {
//    long long a = 0;
//    int b = 0;
//    scanf("%lld", &a);
//    long long c = a;
//    while (a)
//    {
//        a = a / 10;
//        b++;
//    }
//    hs(b, c);
//}

//long long hs(int b, long long a)
//{
//    int c = 0;
//    long long z = 0;
//    if (a > 9)
//    {
//        hs(b--, a / 10);
//    }
//
//    c = a % 10;
//
//    if (c % 2)
//    {
//        z += 1;
//        z *= 10;
//    }
//    else
//    {
//        z *= 10;
//    }
//    return z;
//}
//int main() {
//    long long a = 0;
//    int b = 0;
//    scanf("%lld", &a);
//    long long c = a;
//    while (a)
//    {
//        a = a / 10;
//        b++;
//    }
//    printf("%lld", hs(b, c));
//}

//#include <stdio.h>
//
//int bian(long long n)
//{
//    int b = n % 10;
//    int c = b % 2;
//    n = n / 10;
//    if (n)
//    {
//
//        return 10 * bian(n) + c;
//    }
//
//    return c;
//}
//
//int main()
//{
//    long long n = 0;
//    scanf("%lld", &n);
//    int a = bian(n);
//    printf("%d", a);
//    return 0;
//}
//int main()
//{
//	char a[5] = "qwert";
//
//}

//char* wmd_strcat(char* a, const char* b)
//{
//	char c = a;
//	assert(a&&b);
//	while (*a)
//	{
//		a++;
//	}
//	while (*a++ = *b++)
//	{
//		;
//	}
//	return c;
//}
//
//int main()
//{
//	char a[20] = "hailo wwa\0 ########";
//	char b[] = "nih";
//	printf("%s", wmd_strcat(a, NULL));
//}

//int my_strcmp(const char* a,const char*b)
//{
//	assert(a && b);
//	while (*a==*b&&*a)
//	{
//		a++;
//		b++;
//	}
//	return *a-*b;
//}
//char* my_strncpy( char* aa,const char* bb,int c)
//{
//	assert(aa && bb);
//	char* d = aa;
//	while (c && ( *aa++ = *bb++ ))
//		c--;
//		if (c)
//			while (--c)
//				*aa++ = '\0';
//	return d;
//}

//char* my_strncat(char* aa, char* bb, int c)
//{
//	char* ss = aa;
//	while (*aa++)
//		;
//	aa--;
//	while (c--)
//		if ((* aa++ = *bb++)==0)
//			return ss;
//	*aa = '\0';
//	return ss;
//}

//char* my_strstr(const char* a, const char* b)
//{
//	assert(*a && *b);
//	const char* aa = a;
//	const char* bb = b;
//	const char* cc = a;
//	while (*cc)
//	{
//		aa = cc;
//		bb = b;
//
//		while (*aa && *bb && (*aa == *bb))
//		{
//			aa++;
//			bb++;
//		}
//		if (*bb == '\0')
//			return (char*)cc;
//		cc++;
//	}
//	return NULL;
//}

char* my_strstr(char* a, const char* b)
{
	assert(a && b);
	const char* aa = a;
	const char* bb = b;
	const char* c = a;
	while (*a)
	{
		bb = b;
		aa = c;
		while (*aa && *bb && (*aa == *bb))
		{
			aa++;
			bb++;
		}
		if (*bb == 0)
		{
			return (char*)c;
		}
		c++;
	}
	return NULL;
}

//char* my_strncat(char* a,const char* b, int c)
//{
//	assert(a && b);
//	char* aa = a;
//	while (*a++)
//		;
//	a--;
//	while (c--)
//		if ((*a++ = *b++) == 0)
//			return aa;
//	*a = '\0';
//	return aa;
//}
char* my_strcat(char* a, const char* b)
{
	assert(a && b);
	char* c = a;
	while (*a)
		a++;
	while (*a++ = *b++)
		;
	return c;
}
int my_strcmp(const char* a, const char* b)
{
	assert(a && b);
	while (( * a == *b) && *b)
	{
		a++;
		b++;
	}
	return *a - *b;

}
char* my_strcpy(char* a, const char* b)
{
	assert(a && b);
	char* c = a;
	while (*a++ = *b++)
		;
	return c;
}
//int my_strlen(const char* a)
//{
//	assert(a);
//	int b = 0;
//	while (*a++)
//		b++;
//	return b;
//}
//int my_strlen(const char* a)
//{
//	assert(a);
//	char* b = a;
//	while (*a)
//		a++;
//	return a - b;
//}
int my_strlen(const char* a)
{
	assert(a);
	if (*a == '\0')
		return 0;
	else
		return 1 + my_strlen(a + 1);
}
char* my_strncpy(char* a, const char* b, int c)
{
	assert(a && b);
	char* d = a;
	while (c && (*a++ = *b++))
		c--;
	if (c)
	  while (--c)
			*a++ = '\0';
	return d;
}
int my_strncmp(const char* a, const char* b, size_t c)
{
	assert(a && b);
	while (c && (*a == *b))
	{
		c--;
		a++;
		b++;
	}
	return *a - *b;


}
//int main()
//{
//	char a[20] = "abcdefggfedcba";
//	char b[] = "gfes";
//	printf("%s", my_strstr(a, b));
//	return 0;
//}

//
//int main()
//{
//	char a[10] = "aaaa,bb@cc";
//	char* b;
//
//	b = strtok(a, ",@");
//	while (b != NULL)
//	{
//		b = strtok(NULL, ",@");
//	}
//}

//int main() {
//	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
//	scanf("%d %d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10);
//	int* a[] = { &a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&a10 };
//	int z=0, f=0;
//	for (int i = 0;i < 10;i++)
//	{
//		if (*a[i] >= 0)
//			z++;
//		else
//			f++;
//	}
//	printf("positive:%d\nnegative:%d", z, f);
//
//}

//int main() {
//	float a = 0;
//	char b = 0;
//	scanf("%f %c", &a, &b);
//	char c = (a + 0.4)-1;
//	if (b == 'y')
//		printf("%d", 20 + 5 + c);
//	else
//		printf("%d", 20 + c);
//}
#include <errno.h>
//int main()
//{
//	printf("%s\n", strerror(0));
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//}
//int main()
//{
//	FILE* pfile = fopen("uuuuuu.uuu", "r");
//	if (pfile == NULL)
//	{
//		printf("%s", strerror(errno));
//	}
//}
//#include<math.h>
//int main() {
//	float a, b, c;
//	while (scanf("%f %f %f", &a, &b, &c) != EOF)
//	{
//		float t = b * b - 4 * a * c;
//		if (a)
//			if (t == 0)
//				printf("x1=x2=%.2f\n", -(2 * a / 100 * b));
//			else if (t > 0)
//				printf("x1=%.2f;x2=%.2f\n", 2 * a / (-b + sqrt(b * 2 - 4 * a * c)), (-b - sqrt(b * 2 - 4 * a * c)));
//			else
//				printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi", -b / 2 / a, sqrt(-t) / 2 / a, -b / 2 / a, sqrt(-t) / 2 / a);
//		else
//			printf("Not quadratic equation");
//	}
//
//	return 0;
//}

//int main() {
//	char a[14] = { 0 };
//	int b = 0;
//	int c = 1;
//	int x = 0;
//	scanf("%s", a);
//	for (int i = 0;i < 11;i++)
//	{
//		if (i != 1)
//		{
//			if (i != 5) {
//				b += ((a[i] - 48) * c);
//				c++;
//			}
//		}
//
//	}
//	x = (a[12] - 48);
//	c = b % 11;
//	if (x == 40)
//	{
//		if (c == 10)
//			printf("Right");
//		else
//		{
//			a[12] = 48+c;
//			printf("%s",a);
//		}
//	}
//	else
//	{
//		
//		if (c == x)
//			printf("Right");
//		else if (c == 10)
//		{
//			a[12] = 'X';
//			printf("%s", a);
//		}
//		else
//		{
//			a[12] = 48+c;
//			printf("%s", a);
//		}
//	}
//	return 0;
//}
//#include <errno.h>
//int main()
//{
//	FILE* pfile = fopen("uuuuuu.uuu", "r");
//	if (pfile == NULL)
//	{
//		perror("f");
//	}
//}
//#include <ctype.h>
//int main()
//{
//	printf("%d", islower('a'));
//}
//#include <ctype.h>
//int main()
//{
//	char a[10] = "qWeRrTyUi";
//	printf("%s\n", a);
//	int i = 0;
//	while (a[i])
//	{
//		if (isupper(a[i]))
//		{
//			a[i] = tolower(a[i]);
//		}
//		i++;
//	}
//	printf("%s", a);
//

//void* my_memcpy(void* a1, const void* a2, int c)
//{
//	while (c--)
//	{
//		*(char*)a1 = *(char*)a2;
//		((char*)a1)++;
//		((char*)a2)++;
//	}
//}
//void* my_memmove(void* a1, const void* a2, int c)
//{
//	assert(a1 && a2);
//	if (a1 < a2) 
//	{
//		while (c--)
//		{
//			*(char*)a1 = *(char*)a2;
//			((char*)a1)++;
//			((char*)a2)++;
//		}
//	}
//	else
//	{
//		while (c--)
//		{
//			*((char*)a1 + c) = *((char*)a2 + c);
//		}
//	}
//
//}
//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9 };
//	int b[10] = {0};
//	my_memmove(a+2, a, 20);
//}

//int main()
//{
//	int a[10] = { 0 };
//	memset(a, 1, 20);
//}
//int main()
//{
//	int a[5] = { 1,2,4,4};
//	int b[5] = { 1,3,3,4};
//	printf("%d", memcmp(a, b,8));
//}

//int main() {
//	int b = 1;
//	int c = 0;
//	int d = 0;
//	for (int i = 100;i <= 1000;i++)
//	{
//		d = i;
//		while (d--)
//			if (i % d == 0)
//				break;
//		if (d == 0)
//			c++;
//	}
//	printf("%d", c);
//	return 0;
//}

//int main() {
//	int n, m;
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int aa = 0;
//	while (scanf("%d %d", &n, &m) != EOF) {
//		for (; n <= m; n++) {
//			a = n % 10;
//			aa = a;
//			int bb = a;
//			b = (n / 10) % 10;
//			c = n / 100;
//			while (bb--)
//			{
//				c *= c;
//				b *= b;
//				a *= aa;
//			}
//			if (n == a + b + c) {
//				printf("%d ", n);
//				d++;
//			}
//		}
//		if (d == 0)
//			printf("no\n");
//	}
//
//	return 0;
//}
//#include <math.h>
//int main()
//{
//	int a = 2;
//	int b = 3;
//	int vc = pow(a, b);
//	printf("%d", vc);
//}

//int main() {
//	for (int i = 10000;i < 100000;i++)
//	{
//		if (i == ((i / 10000) * (i % 10000)) + ((i / 1000) * (i % 1000)) + ((i / 100) * (i % 100)) + ((i / 10) * (i % 10)))
//			printf("%d ", i);
//	}
//	return 0;
//}

//int main() {
//	int a, b, c, d, f, g, l;
//	while (scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &f, &g, &l) != EOF)
//	{
//		int s[7] = { a,b,c,d,f,g,l };
//		for (int i = 0;i < 7;i++)
//		{
//			for (int j = 1;j < 7 - i;j++)
//			{
//				int t = 0;
//				if (s[i] > s[j])
//				{
//					t = s[j];
//					s[j] = s[i];
//					s[i] = t;
//
//				}
//			}
//		}
//		float ss = (s[1] + s[2] + s[3] + s[4] + s[5]) / 5.00;
//		printf("%.2f\n", ss);
//
//
//	}
//	return 0;
//}
//int main() {
//	int a = 0, b = 0, c = 100, d = 0, f = 0;
//	while (scanf("%d", &a) != EOF)
//	{
//		if (a > b)
//			b = a;
//		if (a < b)
//			c = a;
//		d += a;
//		f++;
//		if (f == 7)
//		{
//			printf("%.2f\n", (d - b - c) / 5.0);
//			f = 0;
//			b = 0;
//			c = 100;
//			d = 0;
//		}
//
//	}
//	return 0;
//}

//int main() 
//{
//	int n = 0;
//	scanf("%d", &n);
//	while (n)
//	{
//		printf("%d", n % 10);
//		n /= 10;
//	}
//	return 0;
//}
//void hs(int n)
//{
//	int m = n;
//	if (n == 0);
//	else
//	{
//		m = n % 6;
//		hs(n / 6);
//		printf("%d", m);
//	}
//}
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	hs(n);
//	return 0;
//}
//int main()
//{
//	int data = 0;
//	int sum = 1;
//	int data2 = 0;
//	int k = 1;
//	scanf("%d", &data);
//	for (int i = 1;k < data;i++)
//	{
//		for (int j = 0;j < i;j++)
//		{
//			if (k > data)
//				break;
//			sum += i;
//			k++;
//		}
//	}
//
//	return 0;
//}

//int main() {
//	int k = 0;
//	int jb = 1;
//	int tian = 1;
//	scanf("%d", &k);
//	for (int i = 1;tian < k;i++)
//	{
//		for (int j = 0;j < i;j++)
//		{
//			if (tian > k)
//				break;
//			tian++;
//			jb += i;
//		}
//	}
//	printf("%d", jb);
//	return 0;
//}
//int main()
//{
//	int a, b, c;
//	int sum = 0;
//	int d = 0;
//
//	scanf("%d", &a);
//
//	for (b = 1; d < a; b++)
//	{
//		for (c = 0; c < b; c++)
//		{
//			sum += b;
//			d++;
//			if (d == a)
//			{
//				break;
//			}
//		}
//	}
//
//	printf("%d\n", sum);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 1;i <= n;i++)
//	{
//		if (i < 10)
//			printf("%d\n", i);
//		else if (i < 100 && i / 10 == i % 10)
//			printf("%d\n", i);
//		else if (i < 1000 && i >= 100 && i / 100 == i % 10)
//			printf("%d\n", i);
//		else if (i >= 1000 && i < 10000 && i / 1000 == i % 10 && ((i / 100) % 10 == (i % 100) / 10))
//			printf("%d\n", i);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int t = 0, num = i;
//		while (num > 0)
//		{
//			t = t * 10 + num % 10;
//			num = num / 10;
//		}
//		if (t == i)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//struct tag
//{
//	char a;
//	char c;
//	int aa;
//	char aaa;
//}b;
//
//int main()
//{
//	b.a = 'a';
//	printf("%c", b.a);
//
//}
struct Stu
{
	char name[20];//名字
	int age;//年龄
	char sex[5];//性别
	char id[20];//学号
}b1,b2,b3; 

//struct
//{
//	int a;
//}*s;
//
//struct
//{
//	int a;
//	char b;
//	float c;
//}x;
//struct
//{
//	int a;
//	char b;
//	float c;
//}a[20], * p;
//
//int main()
//{
//	p = &x;
//	return 0;
//}

//struct Stu
//{
//	char name[20];//名字
//	int age;//年龄
//	char sex[5];//性别
//	char id[20];//学号
//}b1, b2, b3;
//int main()
//{
//	struct Stu b1;
//	struct Stu b2;
//	struct Stu b3;
//}
//struct
//{
//	int a;
//	char b;
//	float c;
//}x;
//struct
//{
//	int a;
//	char b;
//	float c;
//} * p;
//
//int main()
//{
//	p = &x;
//}

//struct Node
//{
//	int data;
//	struct Node next;
//};

//struct Node
//{
//	int data;
//	struct Node* next;
//};
//typedef struct Node
//{
//	int a;
//	struct Node*pn;
//}Node;
//
//struct Point
//{
//	int x;
//	int y;
//}p1; //声明类型的同时定义变量p1
//struct Point p2; //定义结构体变量p2
//

//初始化：定义变量的同时赋初值。
//struct Point p3 = { x, y };
//struct Stu        //类型声明
//{
//	char name[15];//名字
//	int age;      //年龄
//};
//struct Stu s = { "zhangsan", 20 };//初始化

//struct Node
//{
//	int data;
//	struct Point p;
//	struct Node* next;
//}n1 = { 10, {4,5}, NULL }; //结构体嵌套初始化
//struct Node n2 = { 20, {5, 6}, NULL };//结构体嵌套初始化

//struct s1
//{
//	char a;
//	int b;
//	char c;
//}s;
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//}ss;
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//}ssss;
//int main()
//{
//	printf("%d\n", sizeof(ssss));
//}

//int main()
//{
//	int c = 1;//用于控制最后的尾巴（数柄）；
//	int n = 0;//层数
//	scanf("%d", &n);
//	int d = 3 * n;//a和d用于控制最开始的空白数；
//	for (int i = 1; i <= n; i++)
//	{
//		for (int a = d - 1;a > 0;a--)//
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= i; k++)//k代表一行打印多少个“*     ”
//		{
//			printf("*     ");//把第一层当作“*     ”来打印
//		}
//		printf("\n");
//		for (int a = d - 2; a > 0; a--)//同上
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= i; k++)
//		{
//			printf("* *   ");
//		}
//		printf("\n");
//		for (int a = d - 3; a > 0; a--)//同上
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= i; k++)
//		{
//			printf("* * * ");
//		}
//		printf("\n");
//		d = d - 3;
//	}
//	while (c <= n)
//	{
//		for (int i = 1; i <= (6 * n - 1) / 2; i++)
//		{
//			printf(" ");
//		}
//		printf("*\n");
//		c++;
//	}
//	return 0;
//}

//把圣诞树分两个部分 三角形和枝干  难住我挺久的
//先直接定义第一个小的三角形数组；
//再把第一个复制到下面两个
//再清空第一个三角形；把1-3行的位置中间复制成刚复制下去的其中一个；
//打印枝干；
//行号 3*（2^a-1） ;
//#include<stdio.h>
//#include<math.h>
//int main() {
//	int a;
//	scanf("%d", &a);
//	char ch[400][800] = { "  *  ", " * * ", "* * *" };
//	int i, j, k;
//	int row = 3;
//	int col = 5;
//	for (i = 0; i < a - 1; i++) { //判断需要复制几次三角形
//
//
//		for (j = 0; j < row; j++) { //判断需要复制几行
//
//			for (k = 0; k < col; k++) { //判断每行需要复制几列
//				ch[j + row][k] = ch[j][k]; //第一个三角形第一行全部复制完成
//				ch[j + row][k + 1 + col] = ch[j][k]; //第二个三角形第一行复制完成
//			}
//		}
//
//
//		for (j = 0; j < row; j++) { //三角形原来的位置清空
//			for (k = 0; k < col; k++) {
//				ch[j][k] = ' ';
//			}
//		}
//
//
//		for (j = 0; j < row;
//			j++) { //前面空白中间部分复制一个左下角的三角形上来
//			for (k = 0; k < col; k++) {
//				ch[j][k + row] = ch[j + row][k];
//			}
//		}
//
//
//		row *= 2;
//		col = 2 * col + 1;
//	}
//
//
//	for (i = 0; i < row; i++) { //打印所有三角形
//
//
//		for (j = 0; j < col; j++)
//		{
//
//			if (ch[i][j] == '*')
//			{
//				printf("%c", ch[i][j]);
//			}
//
//
//			else
//			{
//				printf(" ");
//			}
//
//		}
//		printf("\n");
//
//
//	}
//
//	for (i = 0; i < a; i++)
//	{ //打印枝干
//		for (j = 0; j < row - 1; j++)
//		{
//			printf(" ");
//		}
//		printf("*\n");
//	}
//
//	return 0;
//}


//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};

//#pragma pack(8)//设置默认对齐数为8
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//
//
//#pragma pack(1)//设置默认对齐数为1
//struct S2
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//}
//
//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { {1,2,3,4}, 1000 };
////结构体传参
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////结构体地址传参
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s); 
//	print2(&s);
//	return 0;
//}

//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//
//int main()
//{
//	printf("%d", sizeof(struct A));
//}

//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//}
//#define ESOF = 3;
//int main()
//{
//	unsigned char puc[4];
//	struct tagPIM
//	{
//		unsigned char ucPim1;
//		unsigned char ucData0 : 1;
//		unsigned char ucData1 : 2;
//		unsigned char ucData2 : 3;
//	}*pstPimData;
//	pstPimData = (struct tagPIM*)puc;
//	memset(puc, 0, 4);
//	pstPimData->ucPim1 = 2;
//	pstPimData->ucData0 = 3;
//	pstPimData->ucData1 = 4;
//	pstPimData->ucData2 = 5;
//	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//	return 0;
//}