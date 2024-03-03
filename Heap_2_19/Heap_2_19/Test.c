#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"
#include <time.h>
void Heapsort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}



void CreateNode()
{
	int n = 1000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return NULL;
	}
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void PreintTopk(int k)
{
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return NULL;
	}
	int* kminheap = (int*)malloc(sizeof(int) * k);
	if (kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kminheap[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kminheap, k, 0);
	}
	int val = 0;
	while (!feof(fout))
	{
		fscanf(fout, "%d", &val);
		if (val > kminheap[0])
		{
			kminheap[0] = val;
			AdjustDown(kminheap, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kminheap[i]);
	}
	printf("\n");

}

int main()
{
	//HP hp;
	//HeapInit(&hp);
	//int a[] = { 65,100,70,32,50,60 };
	//for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	//{
	//	HeapPush(&hp,a[i]);
	//}
	//while (!HeapEmpty(&hp))
	//{
	//	int top = HeapTop(&hp);
	//	printf("%d\n", top);
	//	HeapPop(&hp);
	//}
	/*int a[] = { 7,6,5,8,9,4,2,1,3 };
	int top = sizeof(a) / sizeof(int);
	Heapsort(a, top);*/

	CreateNode();
	PreintTopk(5);



	return 0;
}




