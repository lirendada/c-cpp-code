#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//二叉树的销毁（使用后序遍历最合适）
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

//二叉树的前序遍历
void BTPrevOrder(BTNode* root)
{
	if (root == NULL)//返回条件
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	BTPrevOrder(root->left);
	BTPrevOrder(root->right);
}

//二叉树的中序遍历
void BTInOrder(BTNode* root)
{
	if (root == NULL)//返回条件
	{
		printf("NULL ");
		return;
	}

	BTPrevOrder(root->left);
	printf("%c ", root->data);
	BTPrevOrder(root->right);
}

//二叉树的后序遍历
void BTPostOrder(BTNode* root)
{
	if (root == NULL)//返回条件
	{
		printf("NULL ");
		return;
	}

	BTPrevOrder(root->left);
	BTPrevOrder(root->right);
	printf("%c ", root->data);
}

//二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) +
		BinaryTreeSize(root->right) +
		1;
}

//二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

//二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	//判断左子树和右子树是否找到x
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
		return left;
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
		return right;

	//若都找不到则返回NULL
	return NULL;
}

//二叉树的层序遍历（广度优先遍历）
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;//先初始化队列，记得最后销毁
	QueueInit(&q);

	if (root == NULL)//判空一下
		return;
	
	QueuePush(&q, root);//先把root放进去

	while (!QueueEmpty(&q))//直到队列为空
	{
		//先记录下队头数据，然后pop，顺便打印
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		printf("%c", tmp->data);

		//将front的下一层带入队列
		//要判断一下左右孩子是否为空
		if (tmp->left != NULL)
			QueuePush(&q, tmp->left);
		if (tmp->right != NULL)
			QueuePush(&q, tmp->right);
	}
	QueueDestroy(&q);
}

//判断二叉树是否为完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;//先创一个队列
	QueueInit(&q);

	if(root != NULL)//若非空，则根节点先入队
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);

		//若为NULL则判断队列中是否都为NULL
		if (tmp == NULL)
		{
			while (!QueueEmpty(&q))
			{
				BTNode* tm = QueueFront(&q);
				QueuePop(&q);

				if (tm != NULL)
					return false;
			}
			break;//记得退出循环
		}

		QueuePush(&q, tmp->left);
		QueuePush(&q, tmp->right);
	}
	QueueDestroy(&q);
	return true;
}

int main()
{
	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D = CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');
	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;

	BTPrevOrder(A);
	printf("\n%d ", BinaryTreeSize(A));
	printf("\n%d ", BinaryTreeLeafSize(A));
	printf("\n%d ", BinaryTreeLevelKSize(A, 3));

	printf("\n%p", BinaryTreeFind(A, 'F'));
	printf("\n%p\n", BinaryTreeFind(A, 'X'));

	BinaryTreeLevelOrder(A);
	printf("\n%d\n", BinaryTreeComplete(A));

	BinaryTreeDestroy(A);
	A = NULL;
	return 0;
}