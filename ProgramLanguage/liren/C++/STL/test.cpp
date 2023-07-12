#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//template <class T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//
//	double c = 3, d = 5;
//	Swap(c, d);
//	return 0;
//}



//template <class T>
//T Add(const T& a,const T& b)
//{
//	return a + b;
//}
//template <class T1,class T2>
//T1 Add(const T1& a, const T2& b)
//{
//	return a + b;
//}
//int main()
//{
//	int a = 10;
//	double d = 20.0;
//
//	/*cout << typeid(Add<double>(a, d)).name() << endl;*/
//
//	Add(a, d);
//
//	return 0;
//}


#include<assert.h>
namespace liren
{
	template<class T>
	class vector
	{
	public:
		vector()
			:_a(nullptr)
			, _size(0)
			, _capacity(0)
		{}
		~vector()
		{
			delete[] _a;
			_a = nullptr;
			_size = _capacity = 0;
		}
		void push_back(const T& x)
		{
			if (_size == _capacity)
			{
				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				T* tmp = new T[newcapacity];
				if (_a)
				{
					memcpy(tmp, _a, sizeof(T) * _size);
					delete[] _a;
				}
				_a = tmp;
				_capacity = newcapacity;
			}
			_a[_size] = x;
			++_size;
		}

		// 读+写
		T& operator[](size_t pos);
		size_t size();
	private:
		T* _a;
		size_t _size;
		size_t _capacity;
	};
	// 模板不支持分离编译，也就是声明在.h ,定义在.cpp，原因后面再讲
	// 建议就是定义在一个文件 xxx.h  xxx.hpp
	// 在类外面定义
	template<class T>
	T& vector<T>::operator[](size_t pos)
	{
		assert(pos < _size);

		return _a[pos];
	}

	template<class T>
	size_t vector<T>::size()
	{
		return _size;
	}
}

int main()
{
	liren::vector<int> v1;		// int
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	// v1.operator[](3);
	//cout << v1[3] << endl;
	//cout << v1[5] << endl;
	for (size_t i = 0; i < v1.size(); ++i)
	{
		v1[i] *= 2;
	}
	cout << endl;

	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;


	liren::vector<double> v2;   // double
	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(3.3);
	v2.push_back(4.4);

	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	return 0;
}