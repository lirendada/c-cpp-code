#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


////简易桶排序
//using namespace std;
//int main()
//{
//	int arr[11] = { 0 };
//	int n = 0,t=0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> t;
//		arr[t]++;
//	}
//	for (int i = 0; i < 11; i++)
//	{
//		for (int j = 1; j <= arr[i]; j++)
//			cout << i << " ";
//	}
//	return 0;
//}


//冒泡排序
//struct student
//{
//	char name[21];
//	int score;
//};
//int main()
//{
//	using namespace std;
//	student a[100], t;
//	int n = 0,flag=1;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i].name >> a[i].score;
//	}
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (a[j].score > a[j + 1].score)
//			{
//				t = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = t;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i].name << "  " ;
//	}
//	return 0;
//}


//快速排序
//#include<cstdlib>
//#include<ctime>
//#define NUM 100000
//using namespace std;
//void quicksort(int a[],int left, int right)
//{
//	if (left > right)
//		return;
//	int i = left, j = right, base = a[left];
//	while (i!=j)
//	{
//		while (a[j] >= base && i < j)
//			j--;
//		while (a[i] <= base && i < j)
//			i++;
//		if (i < j)
//		{
//			int t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//		}
//	}
//	a[left] = a[i];
//	a[i] = base;
//
//	quicksort(a,left, i - 1);
//	quicksort(a,i + 1, right);
//}
////int main()
////{
////	using namespace std;
////	cin >> n;
////	for (int i = 1; i <= n; i++)
////		cin >> a[i];
////
////	quicksort(1, n);
////
////	for (int i = 1; i <= n; i++)
////		cout << a[i] << " ";
////	return 0;
////}
//int main()
//{
//	srand((unsigned int)(0));
//	int a[NUM] = { 0 };
//	for (int i = 0; i < NUM; i++)
//		a[i] = rand() % 10000 + 1;//随机数组
//		/*arr[i] = i + 1;*///升序数组
//		/*arr[i] = 23;*///重复数组
//	/*for (int i = 0; i < NUM; i++)
//		cout << arr[i] << " ";*/
//	cout << endl;
//	clock_t start_time = clock();
//	quicksort(a, 0, NUM - 1);
//	clock_t end_time = clock();
//	/*for (int i = 0; i < NUM; i++)
//		cout << arr[i] << " ";
//	cout << endl;*/
//	cout << "Runing time is:" << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
//	return 0;
//}


//using namespace std;
//int arr[1001],n;
//int main()
//{
//	int t=0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> t;
//		arr[t]+=1;
//	}
//	for (int i = 1; i <= 1001; i++)
//	{
//		if (arr[i] == 1)
//			cout << i << " ";
//	}
//	return 0;
//}


//using namespace std;
//#define MAX 1001
//void quicksort(int a[], int left, int right)
//{
//	if (left > right)
//		return;
//	int base = a[left],i=left,j=right;
//	while (i != j)
//	{
//		while (a[j] >= base && i < j)
//			j--;
//		while (a[i] <= base && i < j)
//			i++;
//		if (i < j)
//		{
//			int tmp = a[j];
//			a[j] = a[i];
//			a[i] = tmp;
//		}
//	}
//	a[left] = a[i];
//	a[i] = base;
//	quicksort(a, left, i - 1);
//	quicksort(a, i+1, right);
//}
//int main()
//{
//	int arr[MAX]={0},n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> arr[i];
//	quicksort(arr, 1, n);
//	for (int i = 1; i <= n; i++)
//		cout << arr[i] << " ";
//	return 0;
//}


////队列(删除第一个，第二个放队尾，最后打印出删除的元素的顺序)
//using namespace std;
//int arr[101];
//int main()
//{
//	int n = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> arr[i];
//	int head = 1, tail = n + 1;
//
//	while (head<tail)//当列表不为空的时候执行循环
//	{
//		cout << arr[head] << " ";//打印队首并将head指向下个数
//		head++;
//
//		arr[tail] = arr[head];//将第二个元素放队尾后，将head指向新对首
//		head++,tail++;
//	}
//
//	return 0;
//}


//using namespace std;
//struct queue
//{
//	int data[100];
//	int head;
//	int tail;
//};
//int main()
//{
//	queue a;
//	int n = 0;
//	cin >> n;
//	//初始化队列
//	a.head = 1,a.tail=n+1;
//	for (int i = 1; i <= n; i++)
//	{
//		//依次向队列插入n个数
//		cin >> a.data[i];
//	}
//	while (a.head < a.tail)//当队列不为空时候执行循环
//	{
//		cout << a.data[a.head] << " ";
//		a.head++;
//		a.data[a.tail] = a.data[a.head];
//		a.tail++, a.head++;
//	}
//	return 0;
//}


//直接插入排序
//using namespace std;
//void print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//}
//void insertsort(int arr[], int sz)
//{
//	if (sz == 0)
//		return;
//	for(int i = 1; i < sz; i++)
//	{
//		int tmp = arr[i];
//		int s = i;
//		while (arr[s] < arr[s - 1]&&s>0)
//		{
//			int t = arr[s];
//			arr[s] = arr[s - 1];
//			arr[s - 1] = t;
//			s--;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 86,45,31,48,37,56,97,25,10,67 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	insertsort(arr, sz);
//	print(arr, sz);
//	return 0;
//}


//选择排序
//using namespace std;
//void print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//}
//void selectsort(int arr[], int sz)
//{
//	int min=0;
//	for (int i = 0; i < sz - 1; i++)
//	{
//		min = i;
//		for (int j = 1+i; j < sz ; j++)
//		{
//			if (arr[j] < arr[min])
//				min = j;
//		}
//		int tmp = arr[i];
//		arr[i] = arr[min];
//		arr[min]=tmp;
//	}
//	print(arr, sz);
//}
//int main()
//{
//	int arr[10] = { 6,1,7,8,9,3,5,4,10,2};
//	int sz = 10;
//	print(arr, sz);
//	selectsort(arr, sz);
//	return 0;
//}


//快排的优化(失败)
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//#define NUM 100000
//void insertsort(int arr[], int left,int right)
//{
//	int i, tmp;
//	for (i = left+1; i <= right; i++)
//	{
//		tmp = i;
//		while (arr[tmp] <= arr[tmp - 1] && tmp > 0)
//		{
//			int s = arr[tmp];
//			arr[tmp] = arr[tmp - 1];
//			arr[tmp - 1] = s;
//			tmp--;
//		}
//	}
//}
//void swap(int* i, int* j)
//{
//	int tmp = *i;
//	*i = *j;
//	*j = tmp;
//}
//int med3(int arr[], int left,int right)
//{
//	int mid = left + ((right - left) >> 1);//防止数值过大溢出
//	if (arr[left] > arr[mid])
//		swap(&arr[left], &arr[mid]);
//	if (arr[left] > arr[right])
//		swap(&arr[left], &arr[right]);
//	if (arr[mid]>arr[right])
//		swap(&arr[mid], &arr[right]);
//	swap(&arr[mid], &arr[right-1]);
//	return arr[right-1];
//}
//	template <class T>
//int crack(T arr[], int left, int right)
//{
//	T base = med3(arr, left, right);
//	int i = left, j = right - 1;
//	while (1)
//	{
//		while (arr[++i] < base);
//		while (arr[--j] > base);
//		if (i >= j)
//			break;
//		swap(&arr[i], &arr[j]);
//	}
//	swap(&arr[i], & arr[right - 1]);
//	return i;
//}
//	template <class T>
//void quicksort(T arr[], int left,int right)
//{
//	if (left > right)
//		return;
//	int base;
//	if(right - left >= 10)
//	{
//		insertsort(arr, left, right);
//		return;
//	}if (left<right)
//	{
//		base = crack(arr, left, right);
//		quicksort(arr, left, base - 1);
//		quicksort(arr, base + 1, right);
//	}
//}
//int main()
//{
//	srand((unsigned int)(0));
//	int arr[NUM] = { 0 };
//	for (int i = 0; i < NUM; i++)
//		arr[i] = rand() % 10000 + 1;//随机数组
//		//arr[i] = i + 1;//升序数组
//		//arr[i] = 23;//重复数组
//	/*for (int i = 0; i < NUM; i++)
//		cout << arr[i] << " ";
//	cout << endl;*/
//	clock_t start_time = clock();
//	quicksort(arr,0,NUM-1);
//	clock_t end_time = clock();
//	/*for (int i = 0; i < NUM; i++)
//		cout << arr[i] << " ";
//	cout << endl;*/
//	cout << "Runing time is:" << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
//	return 0;
//}



/*
   次快排代码采用了  三数取中&插入排序
 */
#include <time.h>
#include <stdlib.h>
using namespace std;
#define M 1000000
template <class T>
void Print(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << a[i] << "]";
	}
	cout << endl;
}
template <class T>
void Swap(T& a, T& b)
{
	T asd;
	asd = a;
	a = b;
	b = asd;
}
int NumberOfThree(int arr[], int low, int high)
{
	int mid = low + ((high - low) >> 1);

	if (arr[mid] > arr[high])
	{
		Swap(arr[mid], arr[high]);
	}
	if (arr[low] > arr[high])
	{
		Swap(arr[low], arr[high]);
	}
	if (arr[mid] > arr[low])
	{
		Swap(arr[mid], arr[low]);
	}
	//此时，arr[mid] <= arr[low] <= arr[high]
	return arr[low];
}
template <class T>
int Partition(T a[], int p, int r)
{
	int i = p, j = r;
	T x = NumberOfThree(a, p, r);
	while (true)
	{
		while (a[++i] < x && i <= r);
		while (a[--j] > x);
		if (i >= j)break;
		Swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}
void InsertSort(int arr[], int m, int n)
{
	int i, j;
	int temp; // 用来存放临时的变量
	for (i = m + 1; i <= n; i++)
	{
		temp = arr[i];
		for (j = i - 1; (j >= m) && (arr[j] > temp); j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
void insertSort(int arr[], int left,int right)//较前一种插入慢
{
	int i, tmp;
	for (i = left+1; i <= right; i++)
	{
		tmp = i;
		while (arr[tmp] <= arr[tmp - 1] && tmp > 0)
		{
			int s = arr[tmp];
			arr[tmp] = arr[tmp - 1];
			arr[tmp - 1] = s;
			tmp--;
		}
	}
}
template <class T>
void QSort(T arr[], int low, int high)
{
	int pivotPos;
	if (high - low <= 10)
	{
		InsertSort(arr, low, high);
		/*insertSort(arr, low, high);*/
		return;
	}
	if (low < high)
	{
		pivotPos = Partition(arr, low, high);
		QSort(arr, low, pivotPos - 1);
		QSort(arr, pivotPos + 1, high);
	}
}
int a[M] = { 0 };
int main()
{
	srand(unsigned int(0));
	for (int i = 0; i < M; i++)
		/*a[i] = i+1;  */            //设置升序数组
		a[i] = rand() % (M);         //设置随机数组
		//if(i < M/2-1)            //设置重复数组
		//	a[i] = 1;
		//else
			/*a[i] = 10;*//*
	Print(a, M);*/
	clock_t start_time = clock();
	QSort(a, 0, M - 1);
	clock_t end_time = clock();
	cout << "Runing time is:" << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	/*Print(a, M);*/
	return 0;
}