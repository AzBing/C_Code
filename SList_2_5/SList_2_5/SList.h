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

//��ӡ
void SLTPrint(SLTNode* plist);
//ͷ����������
void SLTPushFront(SLTNode** splist, SLTDataType x);
//β����������
void SLTPushBack(SLTNode** splist, SLTDataType x);

//ͷ��ɾ������
void SLPopFront(SLTNode** splist);
//β��ɾ������
void SLPopBack(SLTNode** splist);

// ���������
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

// ��pos��ǰ�����
void SLTInsert(SLTNode** sphead, SLTNode* pos, SLTDataType x);

// ��pos��ǰ�����
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// ɾ��posλ��
void SLTErase(SLTNode** sphead, SLTNode* pos);

// ɾ��posλ�ú����ֵ
void SListEraseAfter(SLTNode* pos);


