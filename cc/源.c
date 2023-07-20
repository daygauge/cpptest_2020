#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//#include <iostream>
//using namespace std;
//#include <string>
//
//void printls()
//{
//    string a = "aaaaa";
//
//    cout <<sizeof(a)<< endl;
//}

#include <malloc.h>


int main( void )
{

    int* a = malloc(4);
    a = 10;

    free(a);
    a = NULL;
    printf("%d", a);

    //printls();
    return 0;
}