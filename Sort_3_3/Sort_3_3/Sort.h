#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void PrintArray(int* a, int n);
//��������
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
//ѡ������
void SelectSort(int* a, int n);
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
//��������
void BubbleSort(int* a, int n);
int PartSort1(int* a, int left, int right);
int PartSort2(int* a, int left, int right);
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);
