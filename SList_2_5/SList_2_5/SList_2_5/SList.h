#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;

}SLTNode;

//打印
void SLTPrint(SLTNode* plist);
//头部插入数据
void SLTPushFront(SLTNode** splist, SLTDataType x);
//尾部插入数据
void SLTPushBack(SLTNode** splist, SLTDataType x);

//头部删除数据
void SLPopFront(SLTNode** splist);
//尾部删除数据
void SLPopBack(SLTNode** splist);

// 单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

// 在pos的前面插入
void SLTInsert(SLTNode** sphead, SLTNode* pos, SLTDataType x);

// 在pos的前面插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// 删除pos位置
void SLTErase(SLTNode** sphead, SLTNode* pos);

// 删除pos位置后面的值
void SListEraseAfter(SLTNode* pos);


