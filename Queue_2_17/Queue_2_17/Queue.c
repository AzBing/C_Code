#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}
// 队尾入队列 
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
// 队头出队列 
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

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->phead->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->ptail->data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* q)
{
	assert(q);
	
	//return q->phead == NULL && q->ptail == NULL;
	return q->size == 0;
}

// 销毁队列 
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


