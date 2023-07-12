#pragma once
#include<iostream>
#include<deque>
using std::deque;  //同样也要引入std中的deque

namespace liren
{
	template<class T, class Container = deque<int>>
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		T& back()
		{
			return _con.back();
		}
		const T& back() const
		{
			return _con.back();
		}

		T& front()
		{
			return _con.front();
		}
		const T& front() const
		{
			return _con.front();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}