#pragma once
#include<iostream>
#include<cassert>
using namespace std;

namespace liren
{
	template<class T>
	class vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{}

		//（注意，使用reserve的话需要初始化一下变量，因为reserve中需要用到这些变量，若为随机值则乱套了）
		// 但是调试发现，vs2022做了优化，默认替我们初始化为nullptr，但是为了可移植性，强烈建议还是加上初始化列表
		vector(const vector<T>& v) 
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			/*
			//    第一种写法，memcpy有缺陷，会引发深层次的深浅拷贝问题
			_start = new T[v.capacity()];
			memcpy(_start, v.cbegin(), v.size() * sizeof(T));
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
			*/

			//    第二种写法，复用reserve开空间,用循环给空间拷贝
			reserve(v.capacity());
			for (size_t i = 0; i < v.size(); ++i)
				push_back(v._start[i]);
		}

		//第一种写法，自己实现
		/*vector<T>& operator=(const vector<T>& v)
		{
			  reserve(v.capacity());
			  for (size_t i = 0; i < v.size(); ++i)
				  _start[i] = v._start[i];

			  _finish = _start + v.size();

			  return *this;
		}*/
		
		//      第二种写法，复用拷贝构造,且不需要接收引用的参数，只需传值
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		// 类模板的成员函数，还可以再是函数模板
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}

		}

		//对于需要继续构造一个int参数的函数，其实这里改成模板T，让编译器去推类型即可
		vector(size_t n, const T& val = T()) //这里的T()表示构造函数，对于内置类型也会调用其构造函数，若不给值则默认初始化为0
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		/*
		* 理论上将，提供了vector(size_t n, const T& value = T())之后
		* vector(int n, const T& value = T())就不需要提供了，但是对于：
		* vector<int> v(10, 5);
		* 编译器在编译时，认为T已经被实例化为int，而10和5编译器会默认其为int类型
		* 就不会走vector(size_t n, const T& value = T())这个构造方法，
		* 最终选择的是：vector(InputIterator first, InputIterator last)
		* 因为编译器觉得区间构造两个参数类型一致，因此编译器就会将InputIterator实例化为int
		* 但是10和5根本不是一个区间，编译时就报错了
		* 故需要增加该构造方法
		*/
		vector(int n, const T& value = T())
			: _start(new T[n])
			, _finish(_start + n)
			, _end_of_storage(_finish)
		{
			for (int i = 0; i < n; ++i)
			{
				_start[i] = value;
			}
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		iterator begin()
		{
			return _start;
		}
		const_iterator cbegin() const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}
		const_iterator cend() const
		{
			return _finish;
		}

		T& operator[](size_t index)
		{
			assert(index < capacity());

			return _start[index];
		}
		const T& operator[](size_t index) const
		{
			assert(index < capacity());

			return _start[index];
		}

		void resize(size_t n, const T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				for (iterator i = _finish; i < _start + n; ++i)
				{
					*i = val;
				}
				_finish = _start + n;
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//拷贝的第一种写法，但是如果传的是string等自定义类型，就会出现深层次的深浅拷贝问题，不推荐 
					//memcpy(tmp, _start, sz * sizeof(T)); 

					//拷贝的第二种写法，用了赋值运算符，string等底层已经实现了深拷贝，所以不会有问题
					for (size_t i = 0; i < sz; ++i) 
					{
						tmp[i] = _start[i];
					}
					
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}


		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}

		bool empty() const
		{
			return _start == _finish;
		}

		void pop_back()
		{
			assert(!this->empty());//防止_finish相等时候减到_start前面越界

			--_finish;
		}

		void swap(vector<T>& v)
		{
			if (&v == this)
				return;

			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_end_of_storage, v._end_of_storage);
		}

		//STL中的insert不采用在函数中解决失效问题是因为有缺陷
		//但是如果面试官要求解决失效问题，可以把下面的两点要点补上，即可解决
		//所以用insert时候尽量用一次就重新查找pos的位置，避开失效问题
		void insert(iterator pos, const T& x) //解决pos失效的方法一：pos用传引用
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);

				//更新pos，解决扩容后pos变成野指针后失效的问题
				pos = _start + len;
			}

			iterator tmp = _finish - 1; //记得是减1，因为_finish是指向最后一个元素的后面一位
			while (tmp >= pos)
			{
				*(tmp + 1) = *tmp;
				tmp--;
			}
			*pos = x;
			++_finish;

			//解决pos失效的方法二：将每次插入后pos位置向后移动一个位置，保持原来的相对位置不变
			//pos = pos + 1;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			assert(!empty());

			iterator begin = pos;
			while (begin < _finish - 1)
			{
				*begin = *(begin + 1);
				begin++;
			}
			_finish--;

			return pos;
		}

		~vector()
		{
			if(_start)
				delete[] _start;

			_start = _finish = _end_of_storage = nullptr;
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void test1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(3);
		v1.push_back(2);

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		v1.pop_back();
		v1.pop_back();

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		v1.insert(v1.begin(), 100);
		v1.insert(v1.begin(), 200);
		v1.insert(v1.end(), 200);
		v1.insert(v1.end(), 200);
		v1.insert(v1.end(), 200);
		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
	}


	void test2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(3);
		v1.push_back(2);

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		v1.resize(0);

		vector<int>::iterator nit = v1.begin();
		while (nit != v1.end())
		{
			cout << *nit << " ";
			nit++;
		}
		cout << endl;
	}

	void test3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(3);
		v1.push_back(2);

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
			{
				it = v1.erase(it);
			}
			else
			{
				it++;
			}
		}

		vector<int>::iterator nit = v1.begin();
		while (nit != v1.end())
		{
			cout << *nit << " ";
			nit++;
		}
		cout << endl;
	}

	void test4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(3);
		v1.push_back(2);

		vector<int> v2(v1);

		vector<int>::iterator nit = v2.begin();
		while (nit != v2.end())
		{
			cout << *nit << " ";
			nit++;
		}
		cout << endl;

		vector<int> v3;
		v3.push_back(100);
		v3.push_back(100);
		v3.push_back(100);
		nit = v3.begin();
		while (nit != v3.end())
		{
			cout << *nit << " ";
			nit++;
		}
		cout << endl;


		v3 = v1;
		nit = v3.begin();
		while (nit != v3.end())
		{
			cout << *nit << " ";
			nit++;
		}
		cout << endl;

	}

	void test5()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		vector<int> v2(v1);
	}

	void test6()
	{
		vector<double> v(2, 3.1);
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}

	void test7()
	{
		vector<string> v;
		v.push_back("1111111111111111111111111111111111111111111111111"); //插入的字符串长度大于buf的长度
		v.push_back("22222");
		v.push_back("33332");
		v.push_back("44442");
		v.push_back("55552");
		
		for (const auto& s : v)
		{
			cout << s << " ";
		}
		cout << endl;
	}
}