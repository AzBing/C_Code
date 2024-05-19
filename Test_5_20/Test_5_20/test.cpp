#define _CRT_SECURE_NO_WARNINGS 1
#include "BinarySearchTree.h"

int main()
{

	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> bs;
	for (auto e : a)
	{
		bs.Insert(e);
	}
	bs.InOrder();

	//bs.Eraer(14);
	//bs.InOrder();

	//bs.Eraer(7);
	//bs.InOrder();

	//bs.Eraer(8);
	//bs.InOrder();

	//for (auto e : a)
	//{
	//	bs.Eraer(e);
	//	bs.InOrder();
	//}

	return 0;
}
