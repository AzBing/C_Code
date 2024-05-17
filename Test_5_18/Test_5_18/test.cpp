#define _CRT_SECURE_NO_WARNINGS 1
#include "BinarySearchTree.h"

int main()
{

	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> bt;
	for (auto e : a)
	{
		bt.Insert(e);
	}
	bt.InOrder();

	return 0;
}