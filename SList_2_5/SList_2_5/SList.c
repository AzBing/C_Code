#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//打印
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
//头部插入数据
void SLTPushFront(SLTNode** phead, SLTDataType x)
{
	assert(phead);
	SLTNode* newnode = BuyLTNode(x);
	newnode->next = *phead;
	*phead = newnode;
}
//尾部插入数据
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


//头部删除数据
void SLPopFront(SLTNode** phead)
{
	//没有节点
	assert(*phead);
	//一个节点
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	//多个节点
	else
	{
		SLTNode* del = *phead;
		*phead = del->next;

		free(del);
	}
}
//尾部删除数据
void SLPopBack(SLTNode** phead)
{
	//没有节点
	assert(*phead);
	//一个节点
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	//多个节点
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
// 单链表查找
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

// 在pos的前面插入
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

// 在pos的前面插入
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuyLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 删除pos位置
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
// 删除pos位置后面的值
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}
//销毁单链表
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

