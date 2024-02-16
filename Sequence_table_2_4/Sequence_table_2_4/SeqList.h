#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDatetype;
typedef struct SeqList
{
	SLDatetype* a;
	int size;
	int capacity;
}SL;

void SLInit(SL* p);

void SLDestroy(SL* p);

void SLPrint(SL* p);

//β����������
void SLEndAdd(SL* p, SLDatetype x);
//ͷ����������
void SLHeadAdd(SL* p, SLDatetype x);

//β��ɾ������
void SLPopBack(SL* p);

//ͷ��ɾ������
void SLPopFront(SL* p);


