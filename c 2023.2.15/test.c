#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main() {
//    int n, a;
//    int c = 1;
//    int b[50] = { 0 };
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//        scanf("%d", &b[i]);
//    scanf("%d", &a);
//    for (int i = 0; i < n; i++)
//    {
//        if (b[i] == a && c)
//        {
//            b[i] = b[i + 1];
//            c = 0;
//        }
//    }
//    if (c == 0)
//        n--;
//    for (int i = 0; i < n; i++)
//    {
//        printf("%d ", b[i]);
//    }
//    return 0;
//}

//int main() {
//    int n, a;
//    int c = 0;
//    int b[50] = { 0 };
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//        scanf("%d", &b[i]);
//    scanf("%d", &a);
//    for (int i = 0; i < n; i++)
//    {
//        if (n != b[i])
//        {
//            printf("%d ", b[i]);
//        }
//    }
//    return 0;
//}

//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int a[100] = { 0 };
//    int s = 0;
//    for (int i = 1; i <= n; i++)
//        a[i] = i;
//    for (int i = 1; i < n; i++)
//        if (a[i])
//            for (int j = i; j < n; j++)
//                if (a[j] && a[j] % a[i] == 0)
//                    a[j] = 0;
//    for (int i = 0; i < n; i++)
//        if (a[i])
//            printf("%d", a[i]);
//        else
//            s++;
//    printf("\n%d", s);
//    return 0;
//}

int main() {
    int n = 0;
    int a[100] = { 0 };
    int s = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = i;
        }
        for (int i = 2; i <= n; i++)
        {
            if (i)
                for (int j = 2; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        a[i] = 0;
                    }
                }
        }
        for (int i = 2; i <= n; i++)
        {
            if (a[i] != 0)
                printf("%d ", a[i]);
            else
                s++;
        }
        printf("\n%d\n", s);
    }
    return 0;
}