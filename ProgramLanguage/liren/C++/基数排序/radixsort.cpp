#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_COUNT = 3; // 最大的位数
const int MAX_RADIX = 10; // 最大的基数桶数
queue<int> q[MAX_RADIX];

int GetKey(int n, int k)
{
	int key = 0;
	while (k--)
	{
		key = n % 10;
		n /= 10;
	}
	return key;
}

void Distribute(vector<int>& v, int left, int right, int k)
{
	for (int i = left; i < right; ++i)
	{
		int key = GetKey(v[i], k);
		q[key].push(v[i]);
	}
}

void Collect(vector<int>& v)
{
	int i = 0;
	for (int k = 0; k < MAX_RADIX; ++k)
	{
		while (!q[k].empty())
		{
			v[i++] = q[k].front();
			q[k].pop();
		}
	}
}

void radixsort(vector<int>& v, int left, int right)
{
	if (v.size() == 0)
		return;

	for (int k = 1; k <= MAX_COUNT; ++k)
	{
		// 分发数据
		Distribute(v, left, right, k);

		// 回收数据
		Collect(v);
	}
}

int main()
{
	int arr[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	radixsort(v, 0, v.size());

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}