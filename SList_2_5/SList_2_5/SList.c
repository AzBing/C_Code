#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//��ӡ
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
//ͷ����������
void SLTPushFront(SLTNode** splist, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);


	newnode->next = *splist;
	*splist = newnode;


}
//β����������
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


//ͷ��ɾ������
void SLPopFront(SLTNode** splist)
{
	//û�нڵ�
	assert(*splist);
	//һ���ڵ�
	if ((*splist)->next == NULL)
	{
		free(*splist);
		*splist = NULL;
	}
	//����ڵ�
	else
	{
		SLTNode* del = *splist;
		*splist = del->next;


		free(del);

	}
}
//β��ɾ������
void SLPopBack(SLTNode** splist)
{
	//û�нڵ�
	assert(*splist);
	//һ���ڵ�
	if ((*splist)->next == NULL)
	{
		free(*splist);
		*splist = NULL;
	}
	//����ڵ�
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
// ���������
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




// ��pos��ǰ�����
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


// ��pos��ǰ�����
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuyLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;


}




// ɾ��posλ��
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
// ɾ��posλ�ú����ֵ
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);


	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}




