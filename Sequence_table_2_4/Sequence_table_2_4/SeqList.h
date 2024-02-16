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

//尾部插入数据
void SLEndAdd(SL* p, SLDatetype x);
//头部插入数据
void SLHeadAdd(SL* p, SLDatetype x);

//尾部删除数据
void SLPopBack(SL* p);

//头部删除数据
void SLPopFront(SL* p);


