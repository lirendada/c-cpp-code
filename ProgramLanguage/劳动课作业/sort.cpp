#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define NUM 10000
#define MAX 10000
enum option
{
	EXIT,BUBBLESORT,QUICKSORT,INSERTSORT,BUCKETSORT,SELECTSORT
};

void print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void menu()
{
	cout << "***********************************\n";
	cout << "***********************************\n";
	cout << "****  1.冒泡排序   2.快速排序  ****\n";
	cout << "****  3.插入排序   4.简易桶排序****\n";
	cout << "****  5.选择排序   0.退出程序  ****\n";
	cout << "***********************************\n";
	cout << "***********************************\n";
}

void bucketsort(int arr[], int sz)
{
	clock_t start_time = clock();
	int sumbucketsort = 0;
	int tmp[MAX + 1] = { 0 };
	for (int i = 0; i < NUM; i++)
	{
		tmp[arr[i]]++;
	}
	for (int i = 1; i < MAX + 1; i++)
	{
		for (int j = 1; j <= tmp[i]; j++)
		{
			cout << i << " ";
			sumbucketsort++;
		}
	}
	cout << endl << "总共循环" << sumbucketsort << "次" << endl;
	clock_t end_time = clock();
	cout << "Runing time is:" << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	cout << endl;
}

void selectsort(int arr[], int sz)
{
	clock_t start_time = clock();
	int min = 0,sumselect=0;
	for (int i = 0; i < sz-1; i++)
	{
		min = i;
		for (int j = 1+i; j < sz; j++)
		{
			if (arr[j] < arr[min])
				min = j;
			sumselect++;
		}
		int tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
	print(arr, sz);
	cout << "总共循环" << sumselect << "次" << endl << endl;
	clock_t end_time = clock();
	cout << "Runing time is:" << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}

void bubblesort(int arr[], int sz)
{
	clock_t start_time = clock();
	int flag = 1;
	int sumbubble = 0;
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
			sumbubble++;
		}
		if (flag == 1)
			break;
	}
	print(arr, sz);
	cout << "总共循环" << sumbubble << "次" << endl << endl;
	clock_t end_time = clock();
	cout << "Runing time is:" << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}

static int sumquick = 0;
static int f = 1;
void quicksort(int left, int right, int arr[])
{
	if (f == 1)
		sumquick = 0;
	int i = left, j = right, tmp = arr[left];
	if (i > j)
		return;
	while (i != j)
	{
		while (arr[j] >= tmp && i < j)
			j--;
		while (arr[i] <= tmp && i < j)
			i++;
		if (i < j)
		{
			int t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
		}
		sumquick++;
	}
	f = 0;
	arr[left] = arr[i];
	arr[i] = tmp;
	quicksort(left, i - 1, arr);
	quicksort(i + 1, right, arr);
}

void insertsort(int arr[], int sz)
{
	clock_t start_time = clock();
	int suminsert = 0;
	int i, j, tmp;
	for (i = 1; i <= sz; i++)
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
		{
			arr[j + 1] = arr[j];
			suminsert++;
		}
		arr[j + 1] = tmp;
	}
	print(arr, sz);
	cout << "总共循环" << suminsert << "次" << endl << endl;
	clock_t end_time = clock();
	cout << "Runing time is:" << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}

int main()
{
	srand((unsigned int)NULL);
	int arr[NUM] = { 0 };
	int n = 0;
	do
	{
		cout << "自动生成的数组为：" << endl;
		for (int i = 0; i < NUM; i++)
			arr[i] = rand() % MAX + 1;/*
		print(arr, NUM);*/
		menu();
		cout << "请选择你想使用的排序方法：";
		cin >> n;
		switch (n)
		{
		case BUBBLESORT:
			bubblesort(arr, NUM);
			break;
		case QUICKSORT:
			quicksort(0, NUM - 1, arr);
			print(arr, NUM);
			cout << "总共循环" << sumquick << "次" << endl << endl;
			sumquick = 0;
			break;
		case INSERTSORT:
			insertsort(arr, NUM);
			break;
		case BUCKETSORT:
			bucketsort(arr, NUM);
			break;
		case SELECTSORT:
			selectsort(arr, NUM);
			break;
		case EXIT:
			cout << "退出成功！" << endl;
			break;
		default:
			cout << "输入错误！" << endl;
		}
	} while (n != 0);
	return 0;
}