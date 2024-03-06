#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include "Stack.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

//选择排序
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	int maxi = begin, mini = begin;
	while (begin < end)
	{
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}
void AdjustDwon(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while(child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
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
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

//交换排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool exchange = false;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;

				exchange = true;
			}
		}
		if (exchange == false)
		{
			break;
		}
	}
}
int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);

	return left;
}
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		if (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		if (left < right && a[right] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;

	return hole;
}
int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && prev != cur)
		{
			prev++;
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int keyi = PartSort3(a, begin, end);

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, end);
	StackPush(&st, begin);
	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort1(a, left, right);

		if (keyi + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyi + 1);
		}
		if (left < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}
	}
	StackDestroy(&st);
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin == end)
		return;

	int mid = (begin + end) / 2;
	// [begin][mid] [mid+1][end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid+1, end2 = end;

	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin) + 1);
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}


void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1;
	while (gap < n)
	{
		int j = 0;
		for (int i = 0; i < n; i += 2*gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// 存在越界风险
			// end1,begin2,end2
			// begin2,end2
			// end2
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			//归并一组后直接进行拷贝
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		//memcpy(a, tmp, sizeof(int) * n);
		gap *= 2;
	}
	free(tmp);
}






