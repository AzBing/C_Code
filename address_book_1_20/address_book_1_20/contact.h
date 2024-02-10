#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define MAX 100
#define MAX_NAME 10
enum POTION
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT

};

typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[5];
	char tele[12];
	char addr[20];
}PeoInfo;


//通讯录
//静态版本
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;
//}Contact;

//动态版本
typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;
}Contact;


//初始化通讯录
void InitContact(Contact* pc);

//添加联系人
void AddContact(Contact* pc);

//显示所有联系人信息
void ShowContact(const Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//查找指定联系人
void SearchContact(const Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//排序通讯录
void SortContact(Contact* pc);

//释放空间
void DestroyContact(Contact* pc);

//保存到文件中
void SaveContact(Contact* pc);

