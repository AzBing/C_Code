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


//ͨѶ¼
//��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;
//}Contact;

//��̬�汾
typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;
}Contact;


//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//�����ϵ��
void AddContact(Contact* pc);

//��ʾ������ϵ����Ϣ
void ShowContact(const Contact* pc);

//ɾ��ָ����ϵ��
void DelContact(Contact* pc);

//����ָ����ϵ��
void SearchContact(const Contact* pc);

//�޸�ָ����ϵ��
void ModifyContact(Contact* pc);

//����ͨѶ¼
void SortContact(Contact* pc);

//�ͷſռ�
void DestroyContact(Contact* pc);

//���浽�ļ���
void SaveContact(Contact* pc);

