#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"


void TestInsertSort()
{
	int a[] = { 5,3,1,2,4,9,7,0,6,8 };
	//InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

}
void TestPartSort()
{
	int a[] = { 6,1,2,5,4,9,8,3,7,10 };
	PrintArray(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));

}
int main()
{
	//TestInsertSort();
	TestPartSort();


	return 0;
}



