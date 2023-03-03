#define _CRT_SECURE_NO_WARNINGS 1
#include "tests.h"

void AddContacts(Books* lx)
{
	if (lx->dqgs == ZDX)
	{
		cout << "通讯录已满\n";
		return;
	}
	cout << "请输入名称: ";
	cin >> lx->txr[lx->dqgs].mane;
	cout << "\n";

	cout << "请输入性别: ";
	cin >> lx->txr[lx->dqgs].surname;
	cout << "\n";

	cout << "请输入年龄: ";
	cin >> lx->txr[lx->dqgs].age;
	cout << "\n";

	cout << "请输入电话: ";
	cin >> lx->txr[lx->dqgs].telephone;
	cout << "\n";

	cout << "请输入住址: ";
	cin >> lx->txr[lx->dqgs].HomeAddress;
	system("cls");
	cout << "添加成功\n";
	lx->dqgs++;

}

void ShowContacts(Books* lx)
{
	if (lx->dqgs == 0)
	{
		cout << "当前通讯录为空\n";
		return;
	}
	cout << "名称\t\t性别\t\t年龄\t\t电话\t\t住址\t\n";
	for (int i = 0; i < lx->dqgs; i++)
	{
		cout << lx->txr[i].mane << "\t\t"
			<< lx->txr[i].surname << "\t\t"
			<< lx->txr[i].age << "\t\t"
			<< lx->txr[i].telephone << "\t\t"
			<< lx->txr[i].HomeAddress << "\n";
	}
	system("pause");
	system("cls");
}
void DeleteContacts(Books* lx)
{
	if (lx->dqgs == 0)
	{
		cout << "当前通讯录为空\n";
		return;
	}
	string xm;
	cout << "请输入需要删除的联系人姓名:";
	cin >> xm ;
	for (int i = 0; i < lx->dqgs; i++)
	{
		if (lx->txr[i].mane == xm)
		{
			lx->dqgs--;
			for (int j = i; j < lx->dqgs; j++)
				lx->txr[j].mane = lx->txr[j + 1].mane;
			return;
		}
	}
	system("cls");
	cout << "删除成功\n";
}
void SeekContacts(Books* lx)
{
	if (lx->dqgs == 0)
	{
		cout << "当前通讯录为空\n";
		return;
	}
	string xm;
	cout << "请输入需要查找的联系人姓名:";
	cin >> xm;
	for (int i = 0; i < lx->dqgs; i++)
	{
		if (lx->txr[i].mane == xm)
		{
			cout << "名称\t\t性别\t\t年龄\t\t电话\t\t住址\t\n";
			cout << lx->txr[i].mane << "\t\t"
				<< lx->txr[i].surname << "\t\t"
				<< lx->txr[i].age << "\t\t"
				<< lx->txr[i].telephone << "\t\t"
				<< lx->txr[i].HomeAddress << "\n";
			return;
		}
	}
}
void ReviseContacts(Books* lx)
{
	if (lx->dqgs == 0)
	{
		cout << "当前通讯录为空\n";
		return;
	}
	string xm;
	cout << "请输入需要修改的联系人姓名:";
	cin >> xm;
	for (int i = 0; i < lx->dqgs; i++)
	{
		if (lx->txr[i].mane == xm)
		{
			cout << "请输入修改后的名称: ";
			cin >> lx->txr[i].mane;
			cout << "\n";
			cout << "请输入修改后的性别: ";
			cin >> lx->txr[i].surname;
			cout << "\n";
			cout << "请输入修改后的年龄: ";
			cin >> lx->txr[i].age;
			cout << "\n";
			cout << "请输入修改后的电话: ";
			cin >> lx->txr[i].telephone;
			cout << "\n";
			cout << "请输入修改后的住址: ";
			cin >> lx->txr[i].HomeAddress;
			system("cls");
			cout << "修改成功\n";
			return;
		}
	}
}
void EmptyContacts(Books* lx)
{
	lx->dqgs = 0;
	cout << "销毁成功\n";
}