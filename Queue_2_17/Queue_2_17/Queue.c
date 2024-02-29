#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}
// ��β����� 
void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (q->phead == NULL)
	{
		assert(q->ptail == NULL);
		q->phead = q->ptail = newnode;
	}
	else
	{
		q->ptail->next = newnode;
		q->ptail = newnode;
	}
	q->size++;
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->phead->next == NULL)
	{
		free(q->phead);
		q->phead = q->ptail = NULL;
	}
	else
	{
		QNode* next = q->phead->next;
		free(q->phead);
		q->phead = next;
	}
	q->size--;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->phead->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->ptail->data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q)
{
	assert(q);
	
	//return q->phead == NULL && q->ptail == NULL;
	return q->size == 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->phead = q->ptail = NULL;
	q->size = 0;
}


