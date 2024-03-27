#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

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
	node2->right = node7;

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

void DestroyTree(TreeNode* root)
{
	if (root == NULL)
		return;

	DestroyTree(root->left);
	DestroyTree(root->right);
	free(root);
}

void LevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	int levelSize = 1;
	while (!QueueEmpty(&q))
	{
		// 一层一层出
		while (levelSize--)
		{
			TreeNode* front = QueueFront(&q);
			QueuePop(&q);

			printf("%d ", front->data);

			if (front->left)
				QueuePush(&q, front->left);

			if (front->right)
				QueuePush(&q, front->right);
		}
		printf("\n");

		levelSize = QueueSize(&q);
	}
	printf("\n");

	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
bool TreeComplete(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	int levelSize = 1;
	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	// 前面遇到空以后，后面还有非空就不是完全二叉树
	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
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
	//ret->data++;
	printf("TreeComplete:%d\n", TreeComplete(root));

	//PrevOrder(root);
	//printf("\n");

	//LevelOrder(root);

	DestroyTree(root);
	root = NULL;

	return 0;
}