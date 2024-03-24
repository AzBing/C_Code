#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

//int main()
//{
//	int a[] = { 4,6,2,1,5,8,2,9};
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	/*int k = 3;
//	while (k--)
//	{
//		printf("%d\n", HeapTop(&hp));
//		HeapPop(&hp);
//	}*/
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	printf("\n");
//
//	return 0;
//}

// 升序
void HeapSort(int* a, int n)
{
	// 建大堆
	// O(N*logN)
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	// O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//int main()
//{
//	int a[] = { 4, 6, 2, 1, 5, 8, 2, 9 };
//
//	HeapSort(a, sizeof(a)/sizeof(int));
//
//	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

void CreateNDate()
{
	// 造数据
	int n = 10000000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 10000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(const char* file, int k)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	// 建一个k个数小堆
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc error");
		return;
	}

	// 读取前k个，建小堆
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
		AdjustUp(minheap, i);
	}

	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minheap[0])
		{
			minheap[0] = x;
			AdjustDown(minheap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}
	printf("\n");

	free(minheap);
	fclose(fout);
}

int main()
{
	// CreateNDate();
	//PrintTopK("Data.txt", 5);

	return 0;
}