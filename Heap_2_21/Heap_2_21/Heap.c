#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

// 小堆
void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//20:19jixu 
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	//while (parent >= 0)
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
			//child = (child - 1) / 2;
			//parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// O(logN)
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}

		php->a = tmp;
		php->capacity = newCapacity;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

// 21:15继续

void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		// 假设左孩子小，如果解设错了，更新一下

		if (child + 1 < size && a[child + 1] < a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

size_t HeapSize(HP* php)
{
	assert(php);

	return php->size;
}

bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}