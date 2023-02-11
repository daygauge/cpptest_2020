#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>\

//
//int main()
//{
//	int a = 10000;
//	FILE* ss = foren("wenjian.ess","w");
//	fwrite(&a, 4, 1, ss);
//	fclose(ss);
//	ss = NULL;
//}

//int main()
//{
//	FILE* fopen(const char* filename, const char* mode);
//	int fclose(FILE * stream);
//}
//int main()
//{
//	FILE* a = fopen("sss.txt", "w");
//	if (a != NULL)
//	{
//		fputs("dakai daikai", a);
//		fclose(a);
//		a == NULL;
//	}
//}
 
//int main()
//{
//	FILE* a = fopen("ststsss.txt", "w");
//	if (a != NULL)
//	{
//		//fputc('a', a);
//		//fputc('b', a);
//		//fputc('c', a);
//		fclose(a);
//		a == NULL;
//	}
//}

//int main()
//{
//	fputc('a', stdout);
//}\

//int main()
//{
//	int c = 0;
//	FILE* a = fopen("ststsss.txt", "r");
//	if (a != NULL)
//	{
//		 c = fgetc(a);
//		printf("%c\n", c);
//		 c = fgetc(a);
//		printf("%c\n", c);
//		 c = fgetc(a);
//		printf("%c\n", c);
//		fclose(a);
//		a = NULL;
//	}
//}

//int main()
//{
//	int c = 0;
//	FILE* a = fopen("ststsss.txt", "r");
//	if (a != NULL)
//	{
//		c = fgetc(stdin);
//		printf("%c\n", c);
//		c = fgetc(stdin);
//		printf("%c\n", c);
//		c = fgetc(stdin);
//		printf("%c\n", c);
//		fclose(a);
//		a = NULL;
//	}
//}

//int main()
//{
//	char s[10] ={ 0 };
//	FILE* a = fopen("ststsss.txt", "r");
//	if (a != NULL)
//	{
//		fgets(s, 4, a);
//		printf("%s\n", s);
//
//		fgets(s, 4, a);
//		printf("%s\n", s);
//
//		fclose(a);
//		a = NULL;
//	}
//}

//struct MyStruct
//{
//	int s;
//	char as;
//};
//
//int main()
//{
//	struct MyStruct s = { 1,'a' };
//
//	FILE* a = fopen("ststsss.txt", "w");
//	if (a != NULL)
//	{
//		fprintf(a, "%d %c", s.s, s.as);
//
//		fclose(a);
//		a = NULL;
//	}
//	
//}

//
//struct MyStruct
//{
//	int s;
//	char as;
//};
//
//int main()
//{
//	struct MyStruct s = { 1,'a' };
//
//	FILE* a = fopen("ststsss.txt", "r");
//	if (a != NULL)
//	{
//		fscanf(a, "%d %c", &(s.s), &(s.as));
//		printf("%d %c", s.s, s.as);
//
//		fclose(a);
//		a = NULL;
//	}
//	
//}

//int main()
//{
//	int as = 10000;
//	FILE* a = fopen("ststsss.txt", "w");
//	if (a != NULL)
//	{
//		fwrite(&as, 4, 1, a);
//
//		fclose(a);
//		a = NULL;
//	}
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
