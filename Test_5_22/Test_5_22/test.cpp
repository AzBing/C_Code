#define _CRT_SECURE_NO_WARNINGS 1

#include "BinarySearchTree.h"

//int main()
//{
//
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	BSTree<int> bs;
//	for (auto e : a)
//	{
//		bs.InsertR(e);
//	}
//	bs.InOrder();
//
//	//bs.Erase(14);
//	//bs.InOrder();
//
//	//bs.Erase(7);
//	//bs.InOrder();
//
//	//bs.Erase(8);
//	//bs.InOrder();
//
//	//for (auto e : a)
//	//{
//	//	bs.Erase(e);
//	//	bs.InOrder();
//	//}
//
//	bs.EraseR(14);
//	bs.InOrder();
//
//	return 0;
//}


int main()
{
	
	string arr[] = { "西瓜", "苹果","西瓜", "苹果", "苹果", "香蕉", "西瓜", "香蕉", "苹果", "西瓜", "苹果", "苹果", "苹果" };
	kv::BSTree<string, int> countTree;
	for (auto& e : arr)
	{
		kv::BSTreeNode<string, int>* ret = countTree.Find(e);
		if (ret == nullptr)
		{
			countTree.Insert(e, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	countTree.InOrder();

	return 0;
}
