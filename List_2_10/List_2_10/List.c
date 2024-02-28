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

//初始化双链表(哨兵位)
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

// 双向链表打印
void ListPrint(ListNode* phead)
{
	assert(phead);
	printf("哨兵位->");
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");

}

// 双向链表尾插
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

// 双向链表头插
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


// 双向链表尾删
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

// 双向链表头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;

	free(first);

	phead->next = second;
	second->prev = phead;

}

// 双向链表查找
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


// 双向链表在pos的前面进行插入
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

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);

}

// 双向链表销毁
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







