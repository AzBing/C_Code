#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;		// 当前结构体数据
	struct SListNode* next; // 指向下一个结构体的指针

}SLTNode;

//打印
void SLTPrint(SLTNode* phead);
//头部插入数据
void SLTPushFront(SLTNode** phead, SLTDataType x);
//尾部插入数据
void SLTPushBack(SLTNode** phead, SLTDataType x);

//头部删除数据
void SLPopFront(SLTNode** phead);
//尾部删除数据
void SLPopBack(SLTNode** phead);

// 单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

// 在pos的前面插入
void SLTInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);

// 在pos的前面插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// 删除pos位置
void SLTErase(SLTNode** phead, SLTNode* pos);

// 删除pos位置后面的值
void SListEraseAfter(SLTNode* pos);

void SLTDestroy(SLTNode** pphead);

