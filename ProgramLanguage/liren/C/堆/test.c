//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
////以小堆为例的向下调整算法
//void AdjustSmallDown(int* a, int n, int parent)
//{
//	//先默认为左孩子，下面判断若右孩子小则下标加一即可
//	int child = parent * 2 + 1;
//
//	while (child < n)//当child超过n代表已经超出了叶子节点
//	{
//		//先判断右孩子是否比左孩子小,有一个重要的点，就是判断右孩子节点是否存在
//		if ((child + 1 < n) && (a[child + 1] < a[child]))
//		{
//			child += 1;
//		}
//
//		//比较父亲节点和孩子节点
//		if (a[child] < a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;//交换完再将孩子节点作为父亲节点，重复步骤
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
////以大堆为例的向下调整算法
//void AdjustBigDown(int* a, int n, int parent)
//{
//	//先默认为左孩子，下面判断若右孩子小则下标加一即可
//	int child = parent * 2 + 1;
//
//	while (child < n)//当child超过n代表已经超出了叶子节点
//	{
//		//先判断右孩子是否比左孩子大,有一个重要的点，就是判断右孩子节点是否存在
//		if ((child + 1 < n) && (a[child + 1] > a[child]))
//		{
//			child += 1;
//		}
//
//		//比较父亲节点和孩子节点
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;//交换完再将孩子节点作为父亲节点，重复步骤
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
////堆排序
//void HeapSort(int* arr, int n)
//{
//	//建堆，并且是建大堆
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustBigDown(arr, n, i);
//	}
//
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&arr[end], &arr[0]);
//		//将每次的最后一个排除，继续建大堆
//		//选出次大的
//		AdjustBigDown(arr, end, 0);
//		end--;
//	}
//}
//
//int main()
//{
//	/*int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	AdjustDown(arr, n, 0);*/
//
//	int arr[] = { 15,18,28,34,65,19,49,25,37,27 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	////建堆
//	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	//{
//	//	AdjustDown(arr, n, i);
//	//}
//	HeapSort(arr, n);
//
//	for (int i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}