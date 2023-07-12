////#include <iostream>
////#include <string>
////#include <stack>
////using namespace std;
////
////inline bool isNum(char c)
////{
////	if (c >= '0' && c <= '9')
////		return true;
////	return false;
////}
////
////// 比较优先级
////bool Prior(char c1, char c2)
////{
////	string s = "+-%*/";
////	int i = 0;
////	while (s[i] && s[i] != c1)
////		++i;
////
////	if (i == 1 || i == 4)
////		--i;
////
////	int j = 0;
////	while (s[j] && s[j] != c2)
////		j++;
////	if (j == 1 || j == 4)
////		--j;
////
////	if (i >= j)
////		return true;
////	return false;
////}
////
////void DealOperator(stack<char>& st, char c, string& tmp)
////{
////	if (st.empty())
////		st.push(c);
////	else
////	{
////		if (Prior(c, st.top()))
////		{
////			st.push(c);
////		}
////		else
////		{
////			while (!st.empty() && Prior(st.top(), c))
////			{
////				tmp += st.top();
////				st.pop();
////			}
////			st.push(c);
////		}
////	}
////}
////
////void Op(stack<int>& st, int& left, int& right)
////{
////	right = st.top();
////	st.pop();
////	left = st.top();
////	st.pop();
////}
////
////int main()
////{
////	string tmp;
////	getline(cin, tmp);
////	stack<char> st;
////	stack<char> st2; // 用来处理括号
////	bool flag = false;
////
////	string res;
////	for (size_t i = 0; i < tmp.size(); ++i)
////	{
////		if (isNum(tmp[i]) && flag == false)
////		{
////			res += tmp[i];
////		}
////		else
////		{
////			if (tmp[i] == '(')
////			{
////				flag = true;
////				continue;
////			}
////
////			if (flag)
////			{
////				// 单独放到st2中处理
////				if (tmp[i] == ')')
////				{
////					flag = false;
////					while (!st2.empty())
////					{
////						res += st2.top();
////						st2.pop();
////					}
////					continue;
////				}
////
////				if (isNum(tmp[i]))
////					res += tmp[i];
////				else
////					DealOperator(st2, tmp[i], res);
////			}
////			else
////			{
////				DealOperator(st, tmp[i], res);
////			}
////		}
////	}
////	while (!st.empty())
////	{
////		res += st.top();
////		st.pop();
////	}
////	cout << res << endl;
////
////	stack<int> s;
////	// res就是我们要的逆波兰表达式
////	for (char c : res)
////	{
////		// 分别存储左右操作数
////		int left, right;
////
////		if (c == '+')
////		{
////			Op(s, left, right);
////			s.push(left + right);
////		}
////		else if (c == '-')
////		{
////			Op(s, left, right);
////			s.push(left - right);
////		}
////		else if (c == '*')
////		{
////			Op(s, left, right);
////			s.push(left * right);
////		}
////		else if (c == '/')
////		{
////			Op(s, left, right);
////			s.push(left / right);
////		}
////		else
////		{
////			s.push(c - '0');
////		}
////	}
////	cout << s.top();
////	return 0;
////}
//
////#include <iostream>
////using namespace std;
////
////template <class T>
////struct ListNode
////{
////	T _data;
////	ListNode<T>* _next;
////
////	ListNode(T data = 0, ListNode<T>* next = nullptr)
////		:_data(data)
////		,_next(next)
////	{}
////};
////
////template <class T>
////class ListQueue
////{
////public:
////	ListQueue()
////	{
////		// 初始化的头节点默认指向自己
////		_tail = new ListNode<T>(0);
////		_tail->_next = _tail;
////	}
////
////	void Push(T data)
////	{
////		// 插入元素，在tail也就是队尾插入比较方便
////		ListNode<T>* newnode = new ListNode<T>(data);
////		newnode->_next = _tail->_next;
////		_tail->_next = newnode;
////		_tail = newnode;
////	}
////
////	void Pop()
////	{
////		// 无元素则直接return
////		if (empty())
////			return;
////
////		// 删除元素其实就是队头的元素其实就是头节点后面那个元素
////		ListNode<T>* head = _tail->_next;
////		ListNode<T>* next = head->_next;
////		head->_next = next->_next;
////
////		if(next == _tail)
////			_tail = head;
////		delete next;
////	}
////
////	bool front()
////	{
////		if (empty())
////			return false;
////
////		cout << _tail->_next->_next->_data << endl;
////		return true;
////	}
////
////	bool back()
////	{
////		if (_tail == _tail->_next)
////			return false;
////		cout << _tail->_data << endl;
////		return true;
////	}
////
////	bool empty()
////	{
////		return _tail == _tail->_next;
////	}
////private:
////	ListNode<T>* _tail;
////};
////
////int main()
////{
////	ListQueue<int> lq;
////	lq.Push(1);
////	lq.Push(2);
////	lq.Push(3);
////	lq.Push(4);
////	while (!lq.empty())
////	{
////		lq.front();
////		lq.Pop();
////	}
////}
//
////#include <iostream>
////using namespace std;
////
////template <class T>
////class Queue
////{
////public:
////	Queue(size_t sz = 4)
////		:_sz(sz)
////	{
////		_base = new T[_sz];
////	}
////
////	bool Push(T data)
////	{
////		// 队列满则false
////		if (_front == _tail && tag == 1)
////			return false;
////
////		_base[_tail] = data;
////		_tail = (_tail + 1) % _sz;
////		
////		// 判断是否满
////		if (_front == _tail)
////			tag = 1;
////
////		return true;
////	}
////
////	bool Pop()
////	{
////		// 队列空则false
////		if (_front == _tail && tag == 0)
////			return false;
////
////		_front = (_front + 1) % _sz;
////		tag = 0;
////
////		return true;
////	}
////
////	void Print()
////	{
////		T* it = _base;
////		for (size_t i = 0; i < _sz; ++i)
////		{
////			cout << it[i] << " ";
////		}
////		cout << endl;
////	}
////private:
////	T* _base;
////	size_t _front = 0;
////	size_t _tail = 0;
////	int tag = 0;
////	size_t _sz;
////};
////int main()
////{
////	Queue<int> q(5);
////	q.Push(1);
////	q.Push(1);
////	q.Push(1);
////	q.Push(1);
////	q.Push(1);
////	q.Push(1);
////	q.Print();
////	return 0;
////}
//
////#include <iostream>
////#include <string>
////using namespace std;
////bool isPalindrome(string& s)
////{
////	int head = 0;
////	int tail = s.size() - 1;
////	while (head < tail)
////	{
////		if (s[head] != s[tail])
////			return false;
////
////		head++;
////		tail--;
////	}
////	return true;
////}
////int main()
////{
////	string s;
////	getline(cin, s);
////	cout << isPalindrome(s) << endl;
////	return 0;
////}
//
//
////#include <iostream>
////#include <string>
////using namespace std;
////template <class T>
////class Queue
////{
////public:
////	Queue(size_t sz = 5)
////		:_sz(sz)
////	{
////		_base = new T[_sz];
////	}
////
////	bool push(T data)
////	{
////		 队列满
////		if (_front == _tail && tag == 1)
////			return false;
////
////		 队列空
////		if (_front == _tail && tag == 0)
////		{
////			_base[_tail] = data;
////			_tail = (_tail + 1) % _sz;
////		}
////		else // 队列非空非满
////		{
////			int t = _base[_front] + _base[_tail - 1 + _sz]%_sz;
////			if (t / 2 > data)
////			{
////				 插入队头
////				_front = (_front - 1 + _sz) % _sz;
////				_base[_front] = data;
////			}
////			else
////			{
////				_base[_tail] = data;
////				_tail = (_tail + 1) % _sz;
////			}
////		}
////		
////		if (_front == _tail)
////				tag = 1;
////		return true;
////	}
////
////	bool pop()
////	{
////		if (_front == _tail && tag == 0)
////		{
////			return false;
////		}
////
////		_front = (_front + 1) % _sz;
////		tag = 0;
////		return true;
////	}
////
////	void Print()
////	{
////		if (_front == _tail && tag == 0)
////			return;
////
////		int front = _front;
////		if (_front == _tail && tag == 1)
////		{
////			int tail = (_tail - 1 + _sz) % _sz;
////			
////			while (front != tail)
////			{
////				cout << _base[front] << " ";
////				front = (front + 1) % _sz;
////			}
////			cout << _base[front] << endl;
////			return;
////		}
////
////		while (front != _tail)
////		{
////			cout << _base[front] << " ";
////			front = (front + 1) % _sz;
////		}
////	}
////private:
////	T* _base;
////	int _front = 0;
////	int _tail = 0;
////	int tag = 0;
////	size_t _sz;
////};
////int main()
////{
////	Queue<int> q(5);
////	q.push(1);
////	q.push(2);
////	q.push(3);
////	q.push(4);
////	q.push(4);
////	q.push(4);
////	q.push(4);
////	q.push(1);
////	q.Print();
////	return 0;
////}
//
////#include <iostream>
////#include <string>
////using namespace std;
////void Reverse(string& t)
////{
////	int left = 0;
////	int right = t.size() - 1;
////	while (left < right)
////	{
////		char c = t[left];
////		t[left] = t[right];
////		t[right] = c;
////
////		left++;
////		right--;
////	}
////}
////int main()
////{
////	string t;
////	getline(cin, t);
////	Reverse(t);
////	cout << t << endl;
////	return 0;
////}
//
////#include <iostream>
////#include <string>
////using namespace std;
////string Replace(string& s, string& t, string& v)
////{
////	if (s.size() == 0 || s.size() < t.size())
////	{
////		return {};
////	}
////
////	string res;
////	for (size_t i = 0; i < s.size() && i + t.size() <= s.size();)
////	{
////		if (s[i] != t[i % t.size()])
////			res += s[i++];
////		else
////		{
////			int flag = 1;
////			size_t j = i;
////			for (j = i; j < i + t.size(); ++j)
////			{
////				if (s[j] != t[j % t.size()])
////				{
////					flag = 0;
////					break;
////				}
////			}
////			if (flag == 1)
////			{
////				res += v;
////				i = j;
////			}
////		}
////	}
////	return res;
////}
////int main()
////{
////	string s, t, v;
////	getline(cin, s);
////	getline(cin, t);
////	getline(cin, v);
////	s = Replace(s, t, v);
////	cout << s;
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//using namespace std;
////bool StrAssign(string& t, char* chars)
////{
////	if (strlen(chars) > 255)
////		return false;
////
////	t.resize(strlen(chars));
////	for (int i = 1; i <= t.size(); ++i)
////	{
////		t[i - 1] = chars[i - 1];
////	}
////	return true;
////}
//
////int StrCompare(string& s1, string& s2)
////{
////	int i = 0;
////	while (i < s1.size() && i < s2.size())
////	{
////		if (s1[i] > s2[i])
////			return 1;
////		else if (s1[i] < s2[i])
////			return -1;
////		i++;
////	}
////	if (s1.size() > s2.size())
////		return 1;
////	else if (s1.size() == s2.size())
////		return 0;
////	else
////		return -1;
////}
//
////void CountNum(string& s)
////{
////	if (s.size() == 0)
////		return;
////
////	int num = 0;
////	int alpht = 0;
////	int other = 0;
////	for (size_t i = 0; i < s.size(); ++i)
////	{
////		if (s[i] >= '0' && s[i] <= '9')
////			num++;
////		else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
////			alpht++;
////		else
////			other++;
////	}
////	cout << "num:" << num << endl;
////	cout << "alpht:" << alpht << endl;
////	cout << "other:" << other << endl;
////}
//
//
//bool Concat(string& t, string& s1, string& s2)
//{
//	if (s1.size() == 0 || s2.size() == 0)
//		return false;
//
//	t = s1 + s2;
//	return true;
//}
//
//
//
//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	string s;
//	cout << Concat(s, s1, s2) << endl;
//	cout << s;
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//void FindMax(string& s)
//{
//	if (s.size() == 0)
//		return;
//
//	int Max = 1;
//	int Maxindex = 0;
//	int j = 0;
//	for (size_t i = 1; i < s.size(); ++i)
//	{
//		if (s[i] != s[i - 1])
//		{
//			j = i;
//		}
//		
//		if (Max < i - j + 1)
//		{
//			Max = i - j + 1;
//			Maxindex = j;
//		}
//	}
//	cout << s.substr(Maxindex, Max) << endl;
//	cout << Maxindex << endl;
//}
//int main()
//{
//	string s;
//	getline(cin, s);
//	FindMax(s);
//	return 0;
//}

#include<stdio.h>
#include<string.h>
//定义顺序表 
struct SeqString 
{
	char ch[100];//定义数组最大长度 
	int top = 0;
	int length;
};
int main() 
{
	char s1[100], s2[100];
	printf("请输入字符串1:");
	fgets(s1, 1000, stdin);
	getchar;
	printf("请输入字符串2:");
	fgets(s2, 1000, stdin);
	int max = 0;
	int i, j;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	SeqString str[100];
	int n = 0;
	int MAX = 0;
	for (i = 0; i < len1; i++) 
	{
		for (j = 0; j < len2; j++) 
		{
			if (s1[i + j] == s2[j]) 
			{
				max++;
				str[n].ch[str[n].top] = s2[j];
				str[n].top++;
			}
			else 
			{
				str[n].ch[str[n].top] = '\0';
				str[n].length = max;
				if (max > MAX)
					MAX = max;
				max = 0;
				n++;
			}
		}
	}

	printf("最长为%d\n最长公共子串为：", MAX);

	for (int k = 0; k < n; k++) 
	{
		if (str[k].length == MAX)
			puts(str[k].ch);
	}

	return 0;
}