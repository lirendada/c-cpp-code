#pragma once
#include<iostream>
#include<vector>
using std::vector;

namespace liren
{
	//less是用来比较谁小的
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right) const
		{
			return left < right;
		}
	};

	//greater是用来比较谁大的
	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right) const
		{
			return left > right;
		}
	};

	//这里的Compare就是我们的仿函数！
	template<class T, class Container = std::vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		// 创造空的优先级队列
		priority_queue() : _con() 
		{}

		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
			: _con(first, last)  //这里其实就调用了vector的构造函数完成了构造
		{
			// 将_con中的元素调整成堆的结构
			for (int parent = (_con.size() - 1 - 1) >> 1; parent >= 0; parent--)
			{
				AdjustDown(parent);
			}
		}

		void push(const T& val)
		{
			_con.push_back(val);
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			if (empty())
				return;

			::swap(_con.front(), _con.back()); //多调用容器的接口复用
			_con.pop_back();
			AdjustDown(0);
		}

		size_t size() const
		{
			return _con.size();
		}

		// 堆顶元素不允许修改，因为：堆顶元素修改可以会破坏堆的特性
		const T& top() const
		{
			return _con.front();
		}

		bool empty() const
		{
			return _con.empty();
		}

	private:

		//向下调整算法
		void AdjustDown(int parent)
		{
			Compare Com;

			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && Com(_con[child], _con[child + 1]))
				{
					child += 1;
				}

				if (Com(_con[parent], _con[child]))
				{
					::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}

		//向下调整算法
		void AdjustUp(int child)
		{
			Compare Com;

			int parent = (child - 1) >> 1;
			while (child > 0)
			{
				if (Com(_con[parent], _con[child]))
				{
					::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) >> 1;
				}
				else
					break;
			}
		}

	private:
		Container _con;
	};
}