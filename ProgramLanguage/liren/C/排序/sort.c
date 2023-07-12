#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int* a, int* b)
{
    /*int tmp = *a;
    *a = *b;
    *b = tmp;*/

    //使用异或的方法，防止移除以及不用开辟临时变量
    //这个条件要加，因为如果两个数相等，会变成0
    if (*a == *b)
        return;
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
}

// 插入排序
void InsertSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int end = i;
        int tmp = arr[i + 1];
        while (end >= 0)
        {
            if (tmp < arr[end])
            {
                arr[end + 1] = arr[end];
                end--;
            }
            else
                break;
        }
        arr[end + 1] = tmp;
    }
}

// 希尔排序
void ShellSort(int arr[], int n)
{
    int gap = n;
    while (gap > 1)
    {
        gap = (gap / 3) + 1;//加一防止gap最后为0

        for (int i = 0; i < n - gap; i++)//这里n - gap是重点
        {
            int end = i;
            int tmp = arr[end + gap];
            while (end >= 0)
            {
                if (tmp < arr[end])
                {
                    arr[end + gap] = arr[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            arr[end + gap] = tmp;
        }
    }
}

// 选择排序 O(N^2)
void SelectSort(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    //同时找最大和最小，从两边开始互换位置
    while (left <= right)
    {
        int max = left;
        int min = left;
        for (int i = left; i < right + 1; i++)
        {
            if (arr[i] < arr[min])
                min = i;
            if (arr[i] > arr[max])
                max = i;
        }

        Swap(&arr[left], &arr[min]);
        // 如果max和left位置重叠，max被换走了，要修正一下max的位置
        if (left == max)
            max = min;
        Swap(&arr[right], &arr[max]);

        left++;
        right--;
    }
}


// 堆排序
void AdjustDown(int arr[], int n, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && arr[child] < arr[child + 1])
        {
            child += 1;
        }
        if (arr[parent] < arr[child])
        { 
            Swap(&arr[parent], &arr[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
            break;
    }
}
void HeapSort(int arr[], int n)
{
    //建大堆
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)//注意不要写成i++了
    {
        AdjustDown(arr, n, i);
    }

    int end = n - 1;
    while (end > 0)
    {
        Swap(&arr[0], &arr[end]);
        AdjustDown(arr, end, 0);
        end -= 1;
    }

}

// 冒泡排序
void BubbleSort(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
                flag = 0;
            }
        }
        if (flag == 1)
            break;
    }
}

//三数取中函数
int GetMidIndex(int* a, int left, int right)
{
    //用位运算符防止溢出
    int mid = (left + right) >> 1;

    if (a[left] < a[mid])
    {
        if (a[mid] < a[right])
            return mid;
        else if (a[right] < a[left])
            return left;
        else
            return right;
    }
    else  //a[left] >= a[mid]
    {
        if (a[right] < a[mid])
            return mid;
        else if (a[left] < a[right])
            return left;
        else
            return right;
    }
}

// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
    int key = left;
    while (left < right)
    {
        //记得判断left < right，以及要a[right]要>=a[key]，否则死循环
        while (left < right && a[right] >= a[key])
            right--;

        while (left < right && a[left] <= a[key])
            left++;

        Swap(&a[left], &a[right]);
    }
    //因为是右边先动，所以相遇时候left一定小于key的值，所以无需判断
    Swap(&a[key], &a[left]);

    return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
    int hole = a[left];
    while (left < right)
    {
        //找大的
        while (left < right && a[right] >= hole)
            right--;
        //填左边的坑，右边形成了新坑
        a[left] = a[right];

        //找小的
        while (left < right && a[left] <= hole)
            left++;
        //填右边的坑，左边形成了新坑
        a[right] = a[left];
    }
    //最后用key把坑填住
    a[left] = hole;
    return left;
}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
    int prev = left;
    int cur = left + 1;
    int key = left;
    while (cur <= right)
    {
        if (a[cur] < a[key] && prev != cur)
        {
            prev++;
            Swap(&a[prev], &a[cur]);
        }
        cur++;

    }
    Swap(&a[key], &a[prev]);
    return prev;
}

void QuickSort(int* a, int left, int right)
{
    //记得递归返回条件
    if (left >= right)
        return;

    //分小区间，数据多的继续递归，少的就直接插入排序
    //这里的小区间取不同的大小，效果不一样，得看要排的数据多大
    if (right - left > 500)
    {
        //三数取中
        int mid = GetMidIndex(a, left, right);
        Swap(&a[mid], &a[left]);

        int key = PartSort1(a, left, right);
        QuickSort(a, left, key - 1);
        QuickSort(a, key + 1, right);
    }
    else
    {
        InsertSort(a + left, right - left + 1);
    }
}

// 非递归
// 递归 现代编译器优化很好，性能已经不是大问题
// 最大的问题->递归深度太深，程序本身没问题，但是栈空间不够，导致栈溢出
// 只能改成非递归，改成非递归有两种方式：
// 1、直接改循环-》斐波那契数列求解
// 2、树遍历非递归和快排非递归等等，只能用Stack存储数据模拟递归过程
// [begin, end]
#include "stack.h"
// 快速排序 非递归实现(用栈)
void QuickSortNonR(int* a, int left, int right)
{
    //三数取中
    int mid = GetMidIndex(a, left, right);
    Swap(&a[mid], &a[left]);

    Stack st;//初始化队列，顺便将left和right放进去
    StackInit(&st);
    StackPush(&st, left);
    StackPush(&st, right);

    while (!StackEmpty(&st))
    {
        int end = StackTop(&st);
        StackPop(&st);

        int begin = StackTop(&st);
        StackPop(&st);

        int key = PartSort1(a, begin, end);
                
        if (begin < key - 1)
        {
            StackPush(&st, begin);
            StackPush(&st, key - 1);
        }

        if (key + 1 < end)
        {
            StackPush(&st, key + 1);
            StackPush(&st, end);
        }
    }

    StackDestroy(&st);
}


// 归并排序递归实现(要开辟临时数组，所以需要个子函数）
// 时间复杂度：O(N*logN)
// 空间复杂度：O(N)
void Merge(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
    //两端有序子区间归并tmp，并拷贝回去
    int j = begin1;
    int i = begin1;
    while ((begin1 <= end1) && (begin2 <= end2))
    {
        if (a[begin1] <= a[begin2])
            tmp[i++] = a[begin1++];

        else
            tmp[i++] = a[begin2++];
    }
    //将有可能还没结束的数据放到tmp中去
    while (begin1 <= end1)
        tmp[i++] = a[begin1++];

    while (begin2 <= end2)
        tmp[i++] = a[begin2++];

    //拷贝回去
    for (j; j <= end2; j++)
        a[j] = tmp[j];
}
void _MergeSort(int a[], int left, int right, int* tmp)
{
    //递归结束条件
    if (left >= right)
        return;

    //分治步骤:分为[left, mid]和[mid + 1, right] 
    int mid = (left + right) >> 1;
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    //由于下面迭代版本也要用到这部分，所以整合出来当作子函数
    Merge(a, left, mid, mid + 1, right, tmp);
}

void MergeSort(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }

    _MergeSort(a, 0, n - 1, tmp);

    free(tmp);
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }

    int gap = 1;
    while (gap < n)
    {
        for (int i = 0; i < n; i += gap * 2)
        {
            //对区间[i, i+gap-1] [i+gap, i+2*gap-1]归并
            int begin1 = i, end1 = i + gap - 1;
            int begin2 = i + gap, end2 = i + 2 * gap - 1;

            //归并最后一小组时，如果不存在第二个小区间，则无需归并
            if (begin2 >= n)
                break;

            //归并最后一小组时，如果第二个小区间不够gap个，则要调整一下end2
            if (end2 >= n)
                end2 = n - 1;

            Merge(a, begin1, end1, begin2, end2, tmp);
        }
        gap *= 2;
    }

    free(tmp);
}


// 计数排序
// 时间复杂度：O(N+range)
// 只适合一组数据，数据的范围比较集中. 如果范围集中，效率是很高的，但是局限性也在这里
// 并且只适合整数，如果是浮点数、字符串等等就不行了
// 空间辅助度：O(range)
void CountSort(int* a, int n)
{
    int max = a[0];
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    int range = max - min + 1;
    int* count = (int*)malloc(sizeof(int) * range);
    if (count == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    memset(count, 0, sizeof(int) * range);//记得初始化为0

    for (int i = 0; i < n; i++)
    {
        count[a[i] - min] += 1;
    }

    int j = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i]--)
        {
            a[j++] = i + min;
        }
    }

    free(count);
}

