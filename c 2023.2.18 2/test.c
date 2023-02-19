#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//int main()
//{
//
//}

//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}

//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int begin = 0;
//	int end = n - 1;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
//}
//long long Factorial(size_t N)
//{
//	if (0 == N)
//		return 1;
//
//	return Factorial(N - 1) * N;
//}

//long long Fibonacci(size_t N)
//{
//	if (N < 3)
//		return 1;
//
//	return Fibonacci(N - 1) + Fibonacci(N - 2);
//}

//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}
//
//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//		return NULL;
//
//	long long* fibArray =
//		(long long*)malloc((n + 1) * sizeof(long long));
//	fibArray[0] = 0;
//	fibArray[1] = 1; for (int i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}

//
//void hs(int* a, int aa, int* b, int bb)
//{
//    int rst1 = aa - 1, rst2 = bb - 1;
//    int rets = aa+bb-1;
//    while (rst1 >= 0 || rst2 >= 0)
//    {
//        if (a[rst1] > b[rst2])
//        {
//            a[rets--] = a[rst1--];
//        }
//        else
//        {
//            a[rets--] = b[rst2--];
//        }
//    }
//    while (rst2 >= 0)
//    {
//        a[rets--] = b[rst2--];
//    }
//}
//int main()
//{
//    int a[8] = { 2,2,2,3,5 };
//    int b[3] = { 3,3,6 };
//    hs(a,5,b,3);
//    for (int i = 0; i < 8 ; i++)
//    {
//        printf("%d ", a[i]);
//    }
//}
//int removeDuplicates(int* nums, int numsSize) {
//    int i = 1, j = 0;
//    while (i < numsSize)
//    {
//        if (nums[i] != nums[j])
//        {
//            nums[++j] = nums[i];
//        }
//        i++;
//    }
//
//    return j + 1;
//}
//int removeElement(int* nums, int numsSize, int val) {
//
//    if (numsSize == 0)
//        return 0;
//    int i = 0, j = 0;
//    while (i < numsSize)
//    {
//        if (val != nums[i])
//            nums[j++] = nums[i];
//        i++;
//    }
//    return j;
//}
//int main()
//{
//    int a[] = {0,0,1,1,1,2,2,3,3,4  };
//    int i = removeDuplicates(a, 10);
//    int s = 3;
//    while (s--)
//    {
//        printf("%d", a[i]);
//    }
//}