#pragma once
#include<iostream>
#include<cassert>
#include<cstring>
using namespace std;

namespace liren
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

	public:
		string(const char* str = "")
		{
			if (str == nullptr)
			{
				assert(false);
				return;
			}

			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//每次开辟时候多出一个位置给'\0'
			strcpy(_str, str);
		}

		//传统的拷贝与赋值写法
		//string(const string& s)
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}
		
		//string& operator=(const string& s)
		//{
		//	if (this != &s)//防止自己给自己赋值
		//	{
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//	}

		//	return *this;
		//}

		//现代的拷贝与赋值写法
		//因为拷贝构造是在对象定义构造的，所以此时的_str是随机值，所以要设为nullptr
		string(const string& s)
			:_str(nullptr)   //将_str设为nullptr是为了防止swap时候tmp调用析构时候将随机值处的内存数据删掉
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);//利用构造函数开辟一个tmp
			this->swap(tmp);
		}

		//因为赋值是在对象已经存在后再赋值的，所以无需将_str设为nullptr
		string& operator=(string s)
		{
			this->swap(s);
			return *this;
		}
		/*若想避免自己给自己赋值，可用下面这个版本，但是没必要，因为基本没有自己给自己赋值的情况
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				this->swap(tmp);
				return *this;
			}
		}*/


		//自己写的swap去调用全局swap完成类成员的交换
		void swap(string& s)       //注意不能用const，因为要交换
		{
			//使用::来识别全局的swap函数
			::swap(_str, s._str);
			::swap(_capacity, s._capacity);
			::swap(_size, s._size);
		}

		//////////////////////////////////////////////////////////////
		// iterator 与 const_iterator 迭代器  

		iterator begin()
		{
			return _str;
		}

		const_iterator begin() const
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		/////////////////////////////////////////////////////////////
		// modify

		void push_back(char c)
		{
			//第一种方法，自己写
			/*if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = c;
			_size++;
			_str[_size] = '\0';*/

			//第二种方法，复用insert
			this->insert(_size, c);
		}

		//append不能直接增容倍数，因为有可能str长度大于这个设的倍数
		void append(const char* str)
		{
			//第一种方法，自己写
			//size_t len = _size + strlen(str);

			////若加完str后的大于_capacity，则扩容
			//if (len > _capacity) 
			//{
			//	reserve(len);
			//}

			//strcpy(_str + _size, str);//不推荐用strcat，因为得先找尾，效率低
			//_size = len;


			//第二种方法，复用insert
			this->insert(_size, str);
		}

		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		const char* c_str() const
		{
			return _str;
		}

		/////////////////////////////////////////////////////////////
		// capacity

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const
		{
			return _size == 0;
		}

		void resize(size_t n, char c = '\0')
		{
			if (n > _size)  //可能需要扩容
			{
				//其实可以直接调用reverse函数，因为这个函数里面已经有一次判断了
				//但是为了可读性与减少函数之间的耦合性，要增加这一层判断
				if (n > _capacity)	
				{
					reserve(n);
				}

				memset(_str + _size, c, n - _size);
				_str[n] = '\0';
				_size = n; 
			}
			else  //若小于_size的话直接无需把后面的数据修改，直接改变_size即可，并将_size处置为'\0'
			{
				_size = n;
				_str[n] = '\0';
			}
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//留一个位给'\0'

				//strcpy(tmp, _str);不能strcpy

				strncpy(tmp, _str, _size + 1); //要把末尾的'\0'也拷过去，所以说_size + 1

				delete[] _str;

				_str = tmp;
				_capacity = n;
			}
		}

		/////////////////////////////////////////////////////////////
		// access

		//at左右与[]类似，但是at越界是抛异常
		char& operator[](size_t index)
		{
			//其实可以不用判断index >= 0，因为pos传过来是个size_t类型
			assert(index >= 0 && index < _size);

			return _str[index];
		}
		//要写两个版本，因为如果是const对象调用[]的话，若没有两个版本则只能读不能写
		const char& operator[](size_t index)const
		{
			//其实可以不用判断index >= 0，因为pos传过来是个size_t类型
			assert(index >= 0 && index < _size);

			return _str[index];
		}

		/////////////////////////////////////////////////////////////

		// 返回字符c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == c)
					return i;
			}
			return npos;
		}

		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const
		{
			//运用c的库函数strstr
			const char* tmp = strstr(_str + pos, s);
			if (tmp == nullptr)
				return npos;

			//两个指针相减求出该处的下标
			return tmp - _str;
		}

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			//其实可以不用判断pos >= 0，因为pos传过来是个size_t类型
			assert(pos >= 0 && pos <= _size);

			if (_size == _capacity)
				reserve(_capacity == 0 ? 4 : _capacity * 2);//防止_capacity为0的情况

			size_t end = _size; 
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = c;
			_size++;
			_str[_size] = '\0';//记得_size处置为'\0'

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			//其实可以不用判断pos >= 0，因为pos传过来是个size_t类型
			assert(pos >= 0 && pos <= _size);

			size_t sl = strlen(str);
			size_t len = _size + sl;
			if (len > _capacity)
				reserve(len);

			//用指针挪动不容易出问题
			char* end = _str + _size;
			while (end >= _str + pos)
			{
				*(end + sl) = *end;
				end--;
			}

			strncpy(_str + pos, str, sl);//不能用strcpy，因为会把pos+ls处置为'\0'

			_size = len;

			return *this;
		}

		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			size_t leftLen = _size - pos;
			if (leftLen <= len) //剩余的字符小于要删的长度
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;//类外定义
	};

	const size_t string::npos = -1;

	/////////////////////////////////////////////////////////////
		//relational operators
		//作为非成员函数

	bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	bool operator<=(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) <= 0;
	}

	bool operator>(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) > 0;
	}

	bool operator>=(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) >= 0;
	}

	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	bool operator!=(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) != 0;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		//out << s._str << endl;  不能直接这样子，因为out遇到空格也会中断

		for (auto i : s)
			out << i;

		return out;
	}

	istream& operator>>(istream& in, string& s)//注意s不能用const修饰
	{
		//in >> s._str;  不能这样子写，因为遇到空格就中断了输入

		//char ch;
		//in >> ch;  //因为in是istream的对象，所以它遇见空格和换行也会中断

		s.clear();//记得先清理一下

		char ch = in.get();//get是istream库里的函数，接收的字符串不会因为空格而中断
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}

	istream& getline(istream& in, string& s)
	{
		//与 >> 的重载差不多，只不过遇到' ' 也就是空格也要接收
		s.clear();

		char ch = in.get();
		while (ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
	 
	void func(const string& s)//因为s是const修饰的，所以迭代器得用const_iterator
	{
		string::const_iterator it = s.begin();
		while (it != s.end())
		{
			//*it = 'x';        //注意s是const，只能读不能写
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void test_string1()
	{
		string s1("hello liren");
		string s2(s1);

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		liren::string s3("liren nb");
		s2 = s3;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;

		for (size_t i = 0; i < s1.size(); ++i)
			cout << s1[i] << " ";
		cout << endl;

		string::iterator sit = s3.begin();
		while (sit != s3.end())
		{
			cout << *sit << " ";
			sit++;
		}
		cout << endl;

		cout << (s1 == s3) << endl;
	}

	void test_string2() 
	{
		string s1("hello liren");
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		/*s1 += 'a';
		cout << s1.c_str() << endl;
		
		s1 += "alsncioawbndf  lanwflanwlfnalwfnalwf";
		cout << s1.c_str() << endl;*/

		s1.resize(50,'c');
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.resize(60,'c');
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.reserve(100);
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.resize(70, 'b');
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.resize(10);
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.resize(100, 'k');
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;
		
	}

	void test_string3()
	{
		string s1("lirendada love yangtong");
		func(s1);
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.insert(3, 'v');
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.insert(0, 'v');
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.insert(s1.size(), 'v');
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.insert(s1.size(), " yes or no!");
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.insert(0, " yes or no!");
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.insert(3, " yes or no!");
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.clear();
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;
	}

	void test_string4()
	{
		string s1("lirendada love yangtong");
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.erase(0, 0);
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		string s2("liren ok or no!");
		string s3;
		cout << s2 << endl;
		cin >> s2 >> s3;
		cout << s2 << endl;
		cout << s3 << endl;

		getline(cin, s2);
		cout << s2;
	}

	void test_string5()
	{
		string s1("lirendada love yt");
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;

		s1.resize(20, 'c');
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;
	}
}
