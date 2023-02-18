#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//int main()
//{
//    int n, m;
//    scanf("%d %d", &n, &m);
//    int a[2][3];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            scanf("%d", *a + i + j);
//        }
//    }
//    scanf("%d %d", &n, &m);
//    printf("%d", a[n - 1][m - 1]);
//    return 0;
//}

//int main() {
//    int n, m;
//    scanf("%d %d", &n, &m);
//    int a[2][2];
//    int ss = 0;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            scanf("%d", &a[n][m]);
//            if (ss < a[i][j])
//                ss = a[i][j];
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (ss == a[i][j])
//                printf("%d %d", i, j);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int a[20][20] = { 0 };
//    int ss = 0;
//    int lz=0, ly=n-1;
//    int i = 0;
//    while (ss<n*n)
//    {
//        for (i = lz; i <= ly; i++)
//        {
//            a[lz][i] = ++ss;
//        }
//        for (i = lz+1; i <= ly; i++)
//        {
//            a[i][ly] = ++ss;
//        }
//        for (i = ly-1; i >= lz; i--)
//        {
//            a[ly][i] = ++ss;
//        }
//        for (i = ly - 1; i >= lz+1; i--)
//        {
//            a[i][lz] = ++ss;
//        }
//        lz++;
//        ly--;
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            printf("%d ", a[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int i, j, k, n;
//    int p, q;
//    int a[20][20];
//    int count;
//    scanf("%d", &n);
//    count = 0;
//    p = 0;
//    q = n - 1;
//    while (count < n * n)
//    {
//        for (i = p; i <= q; i++)
//            a[p][i] = ++count;
//        for (i = p + 1; i <= q; i++)
//            a[i][q] = ++count;
//        for (i = q - 1; i >= p; i--)
//            a[q][i] = ++count;
//        for (i = q - 1; i >= p + 1; i--)
//            a[i][p] = ++count;
//        ++p;
//        --q;
//
//    }
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//            printf("%d ", a[i][j]);
//        printf("\n");
//    }
//
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int a[4][4];
//    int s = 0;
//    int z = 0;
//    int f = n * n;
//    int i = 0, j = 0;
//    while (f--)
//    {
//        if (s)
//        {
//            if (j == 0)
//            {
//                a[i][j] = ++z;
//                j++;
//                s = 0;
//            }
//            else
//            {
//                a[i][j] = ++z;
//                i++;
//                j--;
//            }
//        }
//        else
//        {
//            if (i == 0)
//            {
//                a[i][j] = ++z;
//                j++;
//                s = 1;
//            }
//            else
//            {
//                a[i][j] = ++z;
//                j++;
//                z++;
//            }
//        }
//    }
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            printf("%d ", a[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//int* singleNumbers(int* nums, int numsSize, int* returnSize) {
//    int z = 0;
//    int ls = 0;
//    int wz1 = 0;
//    int wz2 = 0;
//    int* ap = malloc(2 * sizeof(int));
//    for (int i = 0; i < numsSize; i++)
//    {
//        z ^= nums[i];
//    }
//
//    for (int i = 0; i < 32; i++)
//    {
//        if ((z >> i) & 1 == 1)
//        {
//            ls = i;
//            break;
//        }
//    }
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        if ((nums[i] >> ls) & 1 == 1)
//        {
//            wz1 ^= nums[i];
//        }
//        else
//        {
//            wz2 ^= nums[i];
//        }
//    }
//    ap[0] = wz1;
//    ap[1] = wz2;
//    return ap;
//}

//void fanz(int* sz, int zd, int zx)
//{
//    int s = 0;
//    while (zx < zd)
//    {
//        s = sz[zx];
//        sz[zx] = sz[zd];
//        sz[zd] = s;
//        zx++;
//        zd--;
//    }
//}
//void rotate(int* nums, int numsSize, int k)
//{
//    k = k % 10;
//    fanz(nums, numsSize - k, numsSize - 1);
//    fanz(nums, 0, numsSize - k - 1);
//    fanz(nums, 0, numsSize - 1);
//}
//
//int main()
//{
//    int a[7] = { 1,2,3,4,5,6,7 };
//
//    rotate(a, 7, 3);
//    return 0;
//}

//void  Reverse(int* a, int left, int right)
//{
//    int tep;
//    while (left < right)
//    {
//        tep = a[left];
//        a[left] = a[right];
//        a[right] = tep;
//        left++;
//        right--;
//    }
//}
//void rotate(int* nums, int numsSize, int k)
//{
//    if (k >= numsSize)
//    {
//        k %= numsSize;
//    }
//    Reverse(nums, numsSize - k, numsSize - 1);
//    Reverse(nums, 0, numsSize - k - 1);
//    Reverse(nums, 0, numsSize - 1);
//}
//void fanz(int* a, int left, int right)
//{
//    int tep;
//        while (left < right)
//        {
//            tep = a[left];
//            a[left] = a[right];
//            a[right] = tep;
//            left++;
//            right--;
//        }
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//    if (k >= numsSize)
//            {
//                k %= numsSize;
//            }
//    fanz(nums, numsSize - k, numsSize - 1);
//    fanz(nums, 0, numsSize - k - 1);
//    fanz(nums, 0, numsSize - 1);
//}
//void fanz(int* sz, int zd, int zx)
//{
//    int s = 0;
//    while (zd < zx)
//    {
//        s = sz[zd];
//        sz[zd] = sz[zx];
//        sz[zx] = s;
//        zd++;
//        zx--;
//    }
//}
//void rotate(int* nums, int numsSize, int k)
//{
//    if (k >= 10)
//    {
//        k %= 10;
//    }
//
//    fanz(nums, numsSize - k, numsSize - 1);
//    fanz(nums, 0, numsSize - k - 1);
//    fanz(nums, 0, numsSize - 1);
//}
//int main()
//{
//    int a[7] = { -1,2,3,4,5,6,7 };
//    rotate(a, 7, 2);
//    for (int i = 0; i < 7; i++)
//        printf("%d ", a[i]);
//    return 0;
//}

int main()
{

}