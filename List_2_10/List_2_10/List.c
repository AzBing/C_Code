#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

ListNode* BuyLTNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

//��ʼ��˫����(�ڱ�λ)
ListNode* LTInit()
{
	ListNode* phead = BuyLTNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
bool LTEmpty(ListNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

// ˫�������ӡ
void ListPrint(ListNode* phead)
{
	assert(phead);
	printf("�ڱ�λ->");
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");

}

// ˫������β��
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* tail = phead->prev;
	ListNode* newnode = BuyLTNode(x);

	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = phead;
	phead->prev = newnode;

}

// ˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* newnode = BuyLTNode(x);
	ListNode* first = phead->next;


	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;
}


// ˫������βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));

	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;

	free(tail);
	tailPrev->next = phead;
	phead->prev = tailPrev;
}

// ˫������ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;

	free(first);

	phead->next = second;
	second->prev = phead;

}

// ˫���������
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyLTNode(x);
	ListNode* prev = pos->prev;

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;

}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);

}

// ˫����������
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;

	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
}







