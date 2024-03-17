#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;		// ��ǰ�ṹ������
	struct SListNode* next; // ָ����һ���ṹ���ָ��

}SLTNode;

//��ӡ
void SLTPrint(SLTNode* phead);
//ͷ����������
void SLTPushFront(SLTNode** phead, SLTDataType x);
//β����������
void SLTPushBack(SLTNode** phead, SLTDataType x);

//ͷ��ɾ������
void SLPopFront(SLTNode** phead);
//β��ɾ������
void SLPopBack(SLTNode** phead);

// ���������
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

// ��pos��ǰ�����
void SLTInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);

// ��pos��ǰ�����
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// ɾ��posλ��
void SLTErase(SLTNode** phead, SLTNode* pos);

// ɾ��posλ�ú����ֵ
void SListEraseAfter(SLTNode* pos);

void SLTDestroy(SLTNode** pphead);

