#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>


//void TestHeap1()
//{
//	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//	{
//		HeapPush(&hp, array[i]);
//	}
//	HeapPrint(&hp);
//
//	// topK 快
//	int k = 5;
//	while (k--)
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//
//	HeapDestroy(&hp);
//}

//void TestHeap2()
//{
//	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//	{
//		HeapPush(&hp, array[i]);
//	}
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//
//	HeapDestroy(&hp);
//}

//void TestHeap3()
//{
//	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
//	HP hp;
//	HeapCreate(&hp, array, sizeof(array) / sizeof(int));
//	HeapPrint(&hp);
//
//	HeapDestroy(&hp);
//}

// O(N*logN)
//void HeapSort(int* a, int n)
//{
	// 向上调整建堆 -- N*logN
	/*for (int i = 1; i < n; ++i)
	{
	AdjustUp(a, i);
	}*/

	// 向下调整建堆 -- O(N)
	// 升序：建大堆
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	// O（N*logN）
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}

//void TestHeap4()
//{
//	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
//	HeapSort(array, sizeof(array) / sizeof(int));
//
//	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//}

//void TestHeap5()
//{
//	int minHeap[5];
//	FILE* fout = fopen("data.txt", "r");
//	if (fout == NULL)
//	{
//		perror("fopen fail");
//		return;
//	}
//
//	for (int i = 0; i < k; ++i)
//	{
//		fscanf(fout, "%d", &minHeap[i]);
//	}
//
//	// 建小堆
//	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(minHeap, k, i);
//	}
//
//	int val = 0;
//	while (fscanf(fout, "%d", &val) != EOF)
//	{
//		if (val > minHeap[0])
//		{
//			minHeap[0] = val;
//			AdjustDown(minHeap, k, 0);
//		}
//	}
//
//	for (int i = 0; i < k; ++i)
//	{
//		printf("%d ", minHeap[i]);
//	}
//	printf("\n");
//
//	fclose(fout);
//}

//void TestHeap5()
//{
//	// 造数据
//	int n, k;
//	printf("请输入n和k:>");
//	scanf("%d%d", &n, &k);
//	srand(time(0));
//	FILE* fin = fopen("data.txt", "w");
//	if (fin == NULL)
//	{
//		perror("fopen fail");
//		return;
//	}
//
//	int randK = k;
//	for (size_t i = 0; i < n; ++i)
//	{
//		int val = rand() % 100000;
//		fprintf(fin, "%d\n", val);
//	}
//
//	fclose(fin);

	/////////////////////////////////////////////////////////////////////////////////////////
	// 找topk
//	FILE* fout = fopen("data.txt", "r");
//	if (fout == NULL)
//	{
//		perror("fopen fail");
//		return;
//	}
//
//	//int minHeap[5];
//	int* minHeap = malloc(sizeof(int) * k);
//	if (minHeap == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//
//	for (int i = 0; i < k; ++i)
//	{
//		fscanf(fout, "%d", &minHeap[i]);
//	}
//
//	// 建小堆
//	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(minHeap, k, i);
//	}
//
//	int val = 0;
//	while (fscanf(fout, "%d", &val) != EOF)
//	{
//		if (val > minHeap[0])
//		{
//			minHeap[0] = val;
//			AdjustDown(minHeap, k, 0);
//		}
//	}
//
//	for (int i = 0; i < k; ++i)
//	{
//		printf("%d ", minHeap[i]);
//	}
//	printf("\n");
//
//	fclose(fout);
//}

//int main()
//{
//	//TestHeap5();
//
//	return 0;
//}


//typedef int BTDataType;
//typedef struct BinaryTreeNode
//{
//	BTDataType data;
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//}BTNode;

//void PrevOrder(BTNode* root) {
//	if (root == NULL) {
//		printf("NULL ");
//		return;
//	}
//
//	printf("%d ", root->data);
//	PrevOrder(root->left);
//	PrevOrder(root->right);
//}

//void InOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//
//	InOrder(root->left);
//	printf("%d ", root->data);
//	InOrder(root->right);
//}

//void PostOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//
//	PostOrder(root->left);
//	PostOrder(root->right);
//	printf("%d ", root->data);
//}

//BTNode* BuyBTNode(BTDataType x)
//{
//	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//	if (node == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//
//	node->data = x;
//	node->left = node->right = NULL;
//	return node;
//}

// 求二叉树节点个数
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	static int size = 0;
//	size++;
//	TreeSize(root->left);
//	TreeSize(root->right);
//	return size;
//}

//int size = 0;
//void TreeSize1(BTNode* root)
//{
//	if (root == NULL)
//		return;
//
//	size++;
//	TreeSize1(root->left);
//	TreeSize1(root->right);
//}
//
//int TreeSize2(BTNode* root)
//{
//	return root == NULL ? 0 :
//		TreeSize2(root->left) + TreeSize2(root->right) + 1;
//}

// 叶子节点
//int TreeLeafSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	if (root->left == NULL
//		&& root->right == NULL)
//	{
//		return 1;
//	}
//
//	return TreeLeafSize(root->left)
//		+ TreeLeafSize(root->right);
//}

// 求树的高度/深度呢？
//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	return TreeHeight(root->left) > TreeHeight(root->right)
//		? TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
//}

//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	int leftHeight = TreeHeight(root->left);
//	int rightHeight = TreeHeight(root->right);
//
//	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//}

// 求第k层的节点个数 k >= 1
//int TreeKLevelSize(BTNode* root, int k)
//{
//	if (root == NULL)
//		return 0;
//
//	if (k == 1)
//		return 1;
//
//	// k > 1 子树的k-1
//	return TreeKLevelSize(root->left, k - 1)
//		+ TreeKLevelSize(root->right, k - 1);
//}

//int main()
//{
//	BTNode* n1 = BuyBTNode(1);
//	BTNode* n2 = BuyBTNode(2);
//	BTNode* n3 = BuyBTNode(3);
//	BTNode* n4 = BuyBTNode(4);
//	BTNode* n5 = BuyBTNode(5);
//	BTNode* n6 = BuyBTNode(6);
//
//	BTNode* n7 = BuyBTNode(7);
//	n3->right = n7;
//
//	n1->left = n2;
//	n1->right = n4;
//	n2->left = n3;
//	n4->left = n5;
//	n4->right = n6;
//
//	PrevOrder(n1);
//	printf("\n");
//
//	InOrder(n1);
//	printf("\n");
//
//	PostOrder(n1);
//	printf("\n");
//
//	size = 0;
//	TreeSize1(n1);
//	printf("TreeSize:%d\n", size);
//
//	size = 0;
//	TreeSize1(n1);
//	printf("TreeSize:%d\n", size);
//
//	size = 0;
//	TreeSize1(n1);
//	printf("TreeSize:%d\n", size);
//
//	printf("TreeSize:%d\n", TreeSize2(n1));
//	printf("TreeSize:%d\n", TreeSize2(n1));
//	printf("TreeSize:%d\n", TreeSize2(n1));
//
//	printf("TreeLeafSize:%d\n", TreeLeafSize(n1));
//	printf("TreeHeight:%d\n", TreeHeight(n1));
//	printf("TreeKLevelSize:%d\n", TreeKLevelSize(n1, 3));
//	printf("TreeKLevelSize:%d\n", TreeKLevelSize(n1, 4));
//
//	return 0;
//}