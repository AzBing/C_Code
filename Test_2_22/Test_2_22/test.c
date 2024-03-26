#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

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

//int main()
//{
//	// CreateNDate();
//	//PrintTopK("Data.txt", 5);
//
//	return 0;
//}

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}TreeNode;

TreeNode* BuyTreeNode(int x)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

TreeNode* CreateTree()
{
	TreeNode* node1 = BuyTreeNode(1);
	TreeNode* node2 = BuyTreeNode(2);
	TreeNode* node3 = BuyTreeNode(3);
	TreeNode* node4 = BuyTreeNode(4);
	TreeNode* node5 = BuyTreeNode(5);
	TreeNode* node6 = BuyTreeNode(6);
	TreeNode* node7 = BuyTreeNode(7);


	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}

void PrevOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//int TreeSize(TreeNode* root)
//{
//	static int size = 0;
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

//int size = 0;
//void TreeSize(TreeNode* root)
//{
//	if (root == NULL)
//		return;
//
//	++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//}

int TreeSize(TreeNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) +
		TreeSize(root->right) + 1;
}

// 叶子节点的个数
int TreeLeafSize(TreeNode* root)
{
	// 空 返回0
	if (root == NULL)
		return 0;
	// 不是空，是叶子 返回1
	if (root->left == NULL
		&& root->right == NULL)
		return 1;

	// 不是空 也不是叶子  分治=左右子树叶子之和
	return TreeLeafSize(root->left) +
		TreeLeafSize(root->right);
}

//int TreeHeight(TreeNode* root)
//{
//	if (root == NULL)
//		return 0;
//	int leftHeight = TreeHeight(root->left);
//	int rightHeight = TreeHeight(root->right);
//
//	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//}

int TreeHeight(TreeNode* root)
{
	if (root == NULL)
		return 0;

	return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}

int TreeLevelK(TreeNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return TreeLevelK(root->left, k - 1)
		+ TreeLevelK(root->right, k - 1);
}

// 二叉树查找值为x的结点
TreeNode* TreeFind(TreeNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	TreeNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;

	TreeNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

//TreeNode* TreeFind(TreeNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return NULL;
//
//	if (root->data == x)
//		return root;
//
//	TreeNode* ret1 = TreeFind(root->left, x);
//	if (ret1)
//		return ret1;
//
//	return TreeFind(root->right, x);
//}

//bool TreeFind(TreeNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return NULL;
//
//	if (root->data == x)
//		return root;
//
//	return TreeFind(root->left, x) || TreeFind(root->right, x);
//}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
TreeNode* TreeCreate(char* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	if (root == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	root->data = a[(*pi)++];

	root->left = TreeCreate(a, pi);
	root->right = TreeCreate(a, pi);
	return root;
}

void LevelOrder(TreeNode* root)
{

}

int main()
{
	TreeNode* root = CreateTree();
	PrevOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	/*size = 0;
	TreeSize(root);
	printf("TreeSize:%d\n", size);

	size = 0;
	TreeSize(root);
	printf("TreeSize:%d\n", size);

	size = 0;
	TreeSize(root);
	printf("TreeSize:%d\n", size);*/


	printf("TreeSize:%d\n", TreeSize(root));
	printf("TreeSize:%d\n", TreeSize(root));
	printf("TreeSize:%d\n", TreeSize(root));

	printf("TreeLeafSize:%d\n", TreeLeafSize(root));
	printf("TreeHeight:%d\n", TreeHeight(root));
	printf("TreeLevelK:%d\n", TreeLevelK(root, 4));

	TreeNode* ret = TreeFind(root, 5);
	printf("TreeFind:%p\n", ret);
	ret->data++;

	PrevOrder(root);
	printf("\n");

	return 0;
}