#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//打印
void SLTPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
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
void SLTPushFront(SLTNode** splist, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);


	newnode->next = *splist;
	*splist = newnode;


}
//尾部插入数据
void SLTPushBack(SLTNode** splist, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);
	if (*splist == NULL)
	{
		*splist = newnode;
	}
	else
	{
		SLTNode* tail = *splist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


//头部删除数据
void SLPopFront(SLTNode** splist)
{
	//没有节点
	assert(*splist);
	//一个节点
	if ((*splist)->next == NULL)
	{
		free(*splist);
		*splist = NULL;
	}
	//多个节点
	else
	{
		SLTNode* del = *splist;
		*splist = del->next;


		free(del);

	}
}
//尾部删除数据
void SLPopBack(SLTNode** splist)
{
	//没有节点
	assert(*splist);
	//一个节点
	if ((*splist)->next == NULL)
	{
		free(*splist);
		*splist = NULL;
	}
	//多个节点
	else
	{
		SLTNode* tail = *splist;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}


}
// 单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
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
void SLTInsert(SLTNode** sphead, SLTNode* pos, SLTDataType x)
{
	assert(sphead);
	assert(pos);
	if (*sphead == pos)
	{
		SLTPushFront(sphead, x);
	}
	else
	{
		SLTNode* ptr = *sphead;
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
void SLTErase(SLTNode** sphead, SLTNode* pos)
{
	assert(sphead);
	assert(pos);
	if (pos == *sphead)
	{
		SLPopFront(sphead);
	}
	else
	{
		SLTNode* ptr = *sphead;
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




