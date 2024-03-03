#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;


void AdjustUp(HPDataType* a, int child);
void AdjustDown(int* a, int n, int prent);
void Swap(HPDataType* p1, HPDataType* p2);


void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
// 堆的数据个数
int HeapSize(HP* php);





