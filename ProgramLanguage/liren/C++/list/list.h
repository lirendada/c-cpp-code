#pragma once
#include<iostream>
#include<cassert>
using namespace std;

namespace liren
{
	// List的节点类
	template <class T>
	struct list_node
	{
		list_node(const T& val = T())
			:_val(val),
			_next(nullptr),
			_prev(nullptr)
		{}

		T _val;
		list_node<T>* _next;
		list_node<T>* _prev;
	};

	/*
	List 的迭代器
	迭代器有两种实现方式，具体应根据容器底层数据结构实现：
	  1. 原生态指针，比如：vector
	  2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
		 1. 指针可以解引用，迭代器的类中必须重载operator*()
		 2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
		 3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
			至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前移动，所以需要重载，如果是forward_list就不需要重载--
		 4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
	*/
	template <class T, class Ref, class Ptr>
	class list_iterator
	{
		typedef list_node<T> Node;  //将节点重命名为Node
		typedef list_iterator<T, Ref, Ptr> Self;  //将迭代器重命名为Self

	public:
		// Ref 和 Ptr 类型需要重定义下，实现反向迭代器时需要用到
		typedef Ref Ref;
		typedef Ptr Ptr;

	public:
		/* 迭代器的构造 */
		list_iterator(Node* node = nullptr)  //设置一个nullptr的缺省值
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_val; //返回结点的数据
		}

		Ptr operator->()
		{
			return &(_node->val);   //返回_node->val的地址
		}

		/* ++it */
		Self& operator++()
		{
			_node = _node->_next;  // 让 _node指向下一个结点
			return *this;   // 返回++后的值
		}
		Self operator++(int)
		{
			Self tmp(*this);  //拷贝构造一个tmp存储原来的值
			_node = _node->_next;
			return tmp;  //返回一个临时对象
		}

		/* --it */
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& s) const //使用传引用提高效率
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

		Node* _node;
	};

	//反向迭代器的自主实现版本
	//template <class iterator, class Ref, class Ptr>
	//struct reverse_iterator
	//{
	//	// Iterator是哪个容器的迭代器，reverse_iterator<Iterator>就可以适配出哪个容器的反向迭代器。复用的体现

	//	typedef reverse_iterator<iterator, Ref, Ptr> Self; //将反向迭代器重命名为Self

	//	reverse_iterator(iterator it)
	//		:_it(it)
	//	{}

	//	Ref operator*()
	//	{
	//		iterator prev(_it);
	//		return *(--prev);  // 注意结构上的错位
	//	}

	//	Ptr operator->()
	//	{
	//		iterator prev = _it;
	//		return &(operator*());  //复用上面的operator*()
	//	}

	//	Self& operator++()  //与正向迭代器相反，反向迭代器的++其实是正向迭代器的--，反之也成立
	//	{
	//		--_it;
	//		return *this;
	//	}
	//	Self operator++(int)
	//	{
	//		Self tmp = _it;
	//		--_it;
	//		return tmp;
	//	}

	//	Self& operator--()
	//	{
	//		++_it;
	//		return *this;
	//	}
	//	Self operator--(int)
	//	{
	//		Self tmp = _it;
	//		++_it;
	//		return tmp;
	//	}

	//	bool operator!=(const Self& s) const
	//	{
	//		return _it != s._it;
	//	}

	//	iterator _it;
	//};

	//反向迭代器的适配版本
	template<class Iterator>
	class Reverse_iterator
	{
	public:
		// 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的一个类型，而不是静态成员变量
		// 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
		// 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
		typedef typename Iterator::Ref Ref;
		typedef typename Iterator::Ptr Ptr;

		typedef Reverse_iterator<Iterator> Self;

	public:
		Reverse_iterator(Iterator it)
			:_it(it)
		{}

		Ref operator*()
		{
			Iterator prev(_it);
			return *(--prev);  // 注意结构上的错位
		}

		Ptr operator->()
		{	
			return &(operator*());  //复用上面的operator*()
		}

		Self& operator++()  //与正向迭代器相反，反向迭代器的++其实是正向迭代器的--，反之也成立
		{
			--_it;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp = _it;
			--_it;
			return tmp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp = _it;
			++_it;
			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _it != s._it;
		}

		bool operator==(const Self& s) const
		{
			return _it == s._it;
		}
		
		Iterator _it;
	};

	template <class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;

		//记得这里第一个参数是要传iterator，而不是T，因为我们是通过iterator来包装反向迭代器的
		/*typedef reverse_iterator<iterator, T&, T*> re_iterator; 
		typedef reverse_iterator<iterator, const T&, const T*> const_re_iterator;*/

		typedef Reverse_iterator<iterator> reverse_iterator;
		typedef Reverse_iterator<const_iterator> const_reverse_iterator;

	public:
		list()
		{
			CreateHead();
		}

		//传统写法的拷贝构造
		//list(const list<T>& l)
		//{
		//	//创建新的头节点
		//	CreateHead();

		//	for (auto e : l)
		//	{
		//		push_back(e);
		//	}
		//}

		//拷贝构造的现代写法
		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l)
		{
			CreateHead();

			// 用l中的元素构造临时的temp,然后与当前对象交换
			list<T> temp(l.begin(), l.end());
			this->swap(temp);
		}

		//传统写法的赋值重载
		//list<T>& operator=(list<T> L)
		//{
		//	if (this != &L) //判断一下是否为自己给自己赋值，若是的话则没必要赋值
		//	{
		//		clear();
		//		for (auto e : L)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}

		//现代写法的赋值重载
		list<T>& operator=(list<T> l) //接收的不是引用，而只是一个值
		{
			this->swap(l);
			return *this;
		}

		~list()
		{
			clear(); //先将有效元素释放掉

			//然后将头节点也释放掉，并置空
			delete _head;
			_head = nullptr;
		}

		///////////////////////////////////////////////////////////
		// 正向迭代器和反向迭代器

		iterator begin()
		{
			return iterator(_head->_next);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		////////////////////////////////////////////////////////////
		// List的插入和删除
		
		// 在pos位置前插入值为val的节点
		void insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x); //开辟新节点
			Node* prev = pos._node;

			newnode->_prev = prev->_prev;
			newnode->_next = prev;
			newnode->_prev->_next = newnode;
			prev->_prev = newnode;
		}

		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			assert(pos != end());   // 防止头结点被删除

			Node* cur = pos._node;   // 找到pos位置的结点
			Node* cur_prev = cur->_prev;   // 找到pos的前驱
			Node* cur_next = cur->_next;   // 找到pos的后继

			// 删除cur
			delete cur;

			// 缝合：  cur_prev <-> cur(删) <-> cur_next
			cur_prev->_next = cur_next;
			cur_next->_prev = cur_prev;

			return iterator(cur_next);
		}
		
		void push_back(const T& x)
		{
			//第一种自己实现
			/*Node* newnode = new Node(x);

			_head->_prev->_next = newnode;
			newnode->_prev = _head->_prev;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			//第二种复用insert
			insert(end(), x); //在end（pHead）前插入，即尾插
		}

		void push_front(const T& x)
		{
			insert(begin(), x);  // 在begin（头结点的下一个结点）前插入，即头插
		}

		void pop_back()
		{
			erase(--end());  // 删除最后一个元素，即尾结点
		}

		void pop_front()
		{
			erase(begin());  // 删除头结点的下一个结点（即begin位置的结点）
		}

		void clear()
		{
			iterator cur = begin(); //注意要传迭代器，因为等会erase只接收迭代器
			while (cur != end())
			{
				erase(cur++); //因为erase完迭代器会失效，所以要重新赋值
			}
		}

		void swap(liren::list<T>& l)
		{
			::swap(_head, l._head);  //直接交换两处的指针即可
		}

		//////////////////////////////////////////////////////////////
		// List的元素访问操作
		
		// 注意：List不支持operator[]
		T& front()
		{
			return _head->_next->_val;
		}
		const T& front()const
		{
			return _head->_next->_val;
		}

		T& back()
		{
			return _head->_prev->_val;
		}
		const T& back()const
		{
			return _head->_prev->_val;
		}

		///////////////////////////////////////////////////////////////
		// List的容量相关

		size_t size() const
		{
			Node* cur = _head->_next;
			size_t count = 0;
			while (cur != _head)
			{
				count++;
				cur = cur->_next;
			}
			return count;
		}

		bool empty() const
		{
			return _head == _head->_next;
		}

		void resize(size_t n, const T& val = T())
		{
			size_t sz = size();
			if (n <= sz)
			{
				while (n <= sz)
				{
					pop_back();
					sz--;
				}
			}
			else
			{
				while (sz < n)
				{
					push_back(val);
					sz++;
				}
			}
		}

		
	private:
		void CreateHead()
		{
			_head = new Node; //不传参，这样子node就会调用缺省值进行初始化，比较方便，但前提是要在list_node的构造函数中设置缺省值
			_head->_next = _head;
			_head->_prev = _head;
		}

		Node* _head;
	};

	template<class T>
	void PrintList(const liren::list<T>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			//*it = 10;
			cout << *it << " ";
			++it;
		}

		cout << endl;
	}

	void test1()
	{
		list<int> ls;
		ls.push_back(1);
		ls.push_back(2);
		ls.push_back(3);
		ls.push_back(4);

		/*list<int>::const_iterator it = ls.begin();
		while (it != ls.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;*/

		PrintList(ls);
	}

	void test2()
	{
		list<int> ls;
		ls.push_back(1);
		ls.push_back(2);
		ls.push_back(3);
		ls.push_back(4);

		list<int>::reverse_iterator rit = ls.rbegin();
		while (rit != ls.rend())
		{
			cout << *rit << " ";
			rit++;
		}
		cout << endl;

		ls.clear();
		for (auto e : ls)
		{
			cout << e << " ";
		}
	}
}



