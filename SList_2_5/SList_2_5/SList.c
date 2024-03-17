#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//��ӡ
void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
SLTNode* BuyLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("newnode fail");
		return 0;
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}
//ͷ����������
void SLTPushFront(SLTNode** phead, SLTDataType x)
{
	assert(phead);
	SLTNode* newnode = BuyLTNode(x);
	newnode->next = *phead;
	*phead = newnode;
}
//β����������
void SLTPushBack(SLTNode** phead, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		SLTNode* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


//ͷ��ɾ������
void SLPopFront(SLTNode** phead)
{
	//û�нڵ�
	assert(*phead);
	//һ���ڵ�
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	//����ڵ�
	else
	{
		SLTNode* del = *phead;
		*phead = del->next;

		free(del);
	}
}
//β��ɾ������
void SLPopBack(SLTNode** phead)
{
	//û�нڵ�
	assert(*phead);
	//һ���ڵ�
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	//����ڵ�
	else
	{
		SLTNode* tail = *phead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
// ���������
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ��pos��ǰ�����
void SLTInsert(SLTNode** phead, SLTNode* pos, SLTDataType x)
{
	assert(phead);
	assert(pos);
	if (*phead == pos)
	{
		SLTPushFront(phead, x);
	}
	else
	{
		SLTNode* ptr = *phead;
		while (ptr->next != pos)
		{
			ptr = ptr->next;
		}
		SLTNode* newnode = BuyLTNode(x);
		ptr->next = newnode;
		newnode->next = pos;
	}
}

// ��pos��ǰ�����
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuyLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ɾ��posλ��
void SLTErase(SLTNode** phead, SLTNode* pos)
{
	assert(phead);
	assert(pos);
	if (pos == *phead)
	{
		SLPopFront(phead);
	}
	else
	{
		SLTNode* ptr = *phead;
		while (ptr->next != pos)
		{
			ptr = ptr->next;
		}
		ptr->next = pos->next;
		free(pos);
	}
}
// ɾ��posλ�ú����ֵ
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}
//���ٵ�����
void SLTDestroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;

	while (cur)
	{
		SLTNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*pphead = NULL;
}

