#pragma once
#include<iostream>
#include<deque>
using std::deque; //记得要引入std中的deque

namespace liren
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& val) // 对于栈而言，入栈就是尾插
		{
			_con.push_back(val);
		}

		void pop() // 对于栈而言，出栈就是尾删
		{
			_con.pop_back();
		}

		T& top() // 返回尾上数据
		{
			return _con.back();
		}
		const T& top() const //const版本
		{
			return _con.back();
		}

		size_t size() const // 返回栈大小
		{
			return _con.size();
		}

		bool empty() const // 返回栈是否为空
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}