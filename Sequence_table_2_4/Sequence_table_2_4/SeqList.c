#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

void SLInit(SL* p)
{
	p->a = (SLDatetype*)malloc(sizeof(SLDatetype) * 4);
	if (p->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	p->capacity = 4;
	p->size = 0;

}
void SLDestroy(SL* p)
{
	free(p->a);
	p->a = NULL;
	p->capacity = 0;
	p->size = 0;

}

void SLPrint(SL* p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", p->a[i]);
	}
	printf("\n");
}



void ChckSpace(SL* p)
{
	if (p->size == p->capacity)
	{
		SLDatetype* tmp = (SLDatetype*)realloc(p->a, sizeof(SLDatetype) * p->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		p->a = tmp;
		p->capacity *= 2;
	}
}

void SLEndAdd(SL* p, SLDatetype x)
{
	ChckSpace(p);

	p->a[p->size] = x;
	p->size++;
}

void SLHeadAdd(SL* p, SLDatatype x)
{
	ChckSpace(p);
	int end = p->size - 1;
	while (end >= 0)
	{
		p->a[end + 1] = p->a[end];
		end--;
	}
	p->a[0] = x;
	p->size++;

}

void SLPopBack(SL* p)
{
	assert(p->size > 0);
	
	p->size--;

}

void SLPopFront(SL* p)
{
	assert(p->size > 0);

	int left = 1;
	while (left < p->size)
	{
		p->a[left - 1] = p->a[left];
		left++;
	}
	p->size--;
}



