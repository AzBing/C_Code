#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HeapDestroy(HP* php)
{
	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int prent)
{
	int child = prent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[prent])
		{
			Swap(&a[prent], &a[child]);
			prent = child;
			child = prent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void AdjustUp(HPDataType* a, int child)
{
	int prent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[prent])
		{
			Swap(&a[child], &a[prent]);

			child = prent;
			prent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);

}

void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	return php->a[0];
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}
