#pragma once
#include <string>
#include <iostream>
using namespace std;
#include <ctime>
#define ZDX 1000
typedef struct mailList
{
	string mane;
	string surname;
	int age;
	string telephone;
	string HomeAddress;
}mail;
typedef struct NumberofAddressBooks
{
	mail txr[ZDX];
	int dqgs;
}Books;

void AddContacts(Books* lx);//添加联系人

void ShowContacts(Books* lx);//显示联系人

void DeleteContacts(Books* lx);//删除联系人

void SeekContacts(Books* lx);//查找联系人

void ReviseContacts(Books* lx);//修改找联系人

void EmptyContacts(Books* lx);//销毁联系人列表