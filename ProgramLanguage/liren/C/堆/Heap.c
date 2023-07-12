#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

//堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (hp->a == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	else
	{
		hp->capacity = n;
		hp->size = n;
		//将a数组中的数据拷到hp->a中
		memcpy(hp->a, a, sizeof(HPDataType) * n);

		//建成大堆
		for (int i = (hp->size - 1 - 1) / 2; i >= 0; i--)
		{
			AdjustBigDown(hp->a, hp->size, i);
		}
	}
}

//堆的销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}

//打印堆
void HeapPrint(Heap* hp)
{
	assert(hp);
	printf("物理结构为：\n");
	for (int i = 0; i < hp->size; i++)
		printf("%d ", hp->a[i]);

	printf("\n简易的逻辑结构为：\n");
	int num = 0;
	int level = 1;
	for (int i = 0; i < hp->size; i++)
	{
		printf("%-3d ", hp->a[i]);
		++num;
		if (num == level)
		{
			printf("\n");
			level *= 2;
			num = 0;
		}
	}
	printf("\n");
	printf("\n");
}

//堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	//判断是否需要扩容
	if (hp->size == hp->capacity)
	{
		HPDataType* newarr = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * 2 * hp->capacity);
		if (newarr == NULL)
		{
			printf("realloc fail!\n");
			exit(-1);
		}
		hp->a = newarr;
		hp->capacity *= 2;
	}

	hp->a[hp->size] = x;
	hp->size++;
	//向上调整
	AdjustBigUp(hp->a, hp->size - 1);
}

//堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	//先将尾和头交换
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	//然后去掉尾
	hp->size--;
	//最后向下调整
	AdjustBigDown(hp->a, hp->size, 0);
}

//取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	return hp->a[0];
}

//堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

//堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}

//对数组进行堆排序
void HeapSort(HPDataType* a, int n)
{
	int end = n - 1;
	while (end > 0)
	{
		//先交换每次的a[end]和a[0]
		Swap(&a[end], &a[0]);
		//将每次的最后一个排除，继续建大堆，选出次大的
		AdjustBigDown(a, end, 0);
		end--;
	}
}

//交换函数
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//以大堆为例的向上调整算法
void AdjustBigUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;

	//while(parent >= 0) 这样子是错的，因为parent永不为0
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//以大堆为例的向下调整算法
void AdjustBigDown(HPDataType* a, int n, int parent)
{
	//先默认为左孩子，下面判断若右孩子小则下标加一即可
	int child = parent * 2 + 1;

	while (child < n)//当child超过n代表已经超出了叶子节点
	{
		//先判断右孩子是否比左孩子大,有一个重要的点，就是判断右孩子节点是否存在
		if ((child + 1 < n) && (a[child + 1] > a[child]))
		{
			child += 1;
		}

		//比较父亲节点和孩子节点
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;//交换完再将孩子节点作为父亲节点，重复步骤
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//TopK问题： 找出N个数里面最大/最小的前K个问题。
//这里实现两个版本：
//1. 找最大的K个元素
//假设堆为小堆
void PrintSTopK(int* a, int n, int k)
{
	Heap hp;
	//建立含有K个元素的堆
	HeapCreate(&hp, a, k);

	for (size_t i = k; i < n; ++i)  // N
	{
		//每次和堆顶元素比较，大于堆顶元素，则删除堆顶元素，插入新的元素
		if (a[i] > HeapTop(&hp)) // LogK
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	for (int i = 0; i < k; ++i) {
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}

//2. 找最小的K个元素
//假设堆为大堆
void PrintBTopK(int* a, int n, int k)
{
	Heap hp;
	//建立含有K个元素的堆
	HeapCreate(&hp, a, k);

	for (size_t i = k; i < n; ++i)  // N
	{
		//每次和堆顶元素比较，小于堆顶元素，则删除堆顶元素，插入新的元素
		if (a[i] < HeapTop(&hp)) // LogK
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	for (int i = 0; i < k; ++i) {
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	//随机生成10000个数存入数组，保证元素都小于1000000
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	//确定10个最大的数
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;

	PrintBTopK(a, n, 10);
}