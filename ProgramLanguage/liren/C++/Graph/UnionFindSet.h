#pragma once
#include <vector>
#include <iostream>
using namespace std;

class UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:_ufs(n, -1)
	{}

	// 将两个集合并起来
	void Union(int x1, int x2)
	{
		// 先找到两个集合的根
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		// 如果本身就是一个集合，那就不用合并
		if (root1 == root2)
			return;

		// 做一下优化，让小的往大的集合合并
		if (abs(_ufs[root1]) < abs(_ufs[root2]))
			swap(root1, root2);
		
		// 将新的根的值也就是这个集合总个数更新
		_ufs[root1] += _ufs[root2];

		// 将他们链接起来，这里统一把第二个合并到第一个
		_ufs[root2] = root1;
	}

	// 找一个节点的根的值
	int FindRoot(int x)
	{
		int root = x;
		while (_ufs[root] >= 0)
		{
			root = _ufs[root];
		}

		// 进行路径压缩优化
		while (_ufs[x] >= 0)
		{
			// 注意要先用tmp将x的双亲保存下来，再让x的双亲变成根节点
			int tmp = _ufs[x];
			_ufs[x] = root;

			// x不断更新为路径上的双亲，直到遇到根节点
			x = tmp;
		}

		return root;
	}

	// 检测是否在同一个集合
	bool IsInSameSet(int x1, int x2)
	{
		return FindRoot(x1) == FindRoot(x2);
	}

	// 求一共有几个集合
	size_t SetSize(int x)
	{
		size_t n = 0;
		for (size_t i = 0; i < _ufs.size(); ++i)
		{
			if (_ufs[i] < 0)
				n++;
		}
		return n;
	}
private:
	vector<int> _ufs; // 存放节点双亲下标（负数代表根节点）
};