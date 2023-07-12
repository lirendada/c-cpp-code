#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;

//bool fncomp(int left, int right) { return left < right; }
//
//struct classcomp 
//{
//	bool operator() (const int& left, const int& right) const
//	{
//		return left < right;
//	}
//};
//
//int main()
//{
//	set<int> first;                           // 存放int类型的空set
//
//	int myints[] = { 10,20,30,40,50 };
//	set<int> second(myints, myints + 5);        // 迭代器构造区间set
//
//	set<int> third(second);                  // 拷贝构造set
//
//	set<int> fourth(second.begin(), second.end());  // 迭代器构造set.
//
//	set<int, classcomp> fifth;                 // 类作为比较器
//
//	bool(*fn_pt)(int, int) = fncomp;
//	set<int, bool(*)(int, int)> sixth(fn_pt);  // 函数指针作为比较
//
//	return 0;
//}


//int main()
//{
//	// 用数组array中的元素构造set
//	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
//
//	// 1、第一种遍历方法：迭代器
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		//*it = 1; ❌这是不能被修改的，因为set的迭代器底层是用const_iterator
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	// 反向迭代器
//	set<int>::reverse_iterator rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	// 2、第二种遍历方式：范围for
//	for (const auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	map<int, double> m;
//
//	// 调用pair的构造函数，构造一个匿名对象插入
//	m.insert(pair<int, double>(1, 1.1));
//	m.insert(pair<int, double>(5, 5.5));
//	m.insert(pair<int, double>(2, 2.2));
//	for (const auto& e : m)
//	{
//		cout << e.first << "/" << e.second << endl;
//	}
//	cout << endl;
//
//	// 调用函数模板，构造对象
//	m.insert(make_pair(3, 3.3));
//	for (const auto& e : m)
//	{
//		cout << e.first << "/" << e.second << endl;
//	}
//
//	return 0;
//}

template<class T>
void Print(const set<T>& s)
{
	for (const auto& e : s)
		cout << e << " ";
	cout << endl;
}
template<class T>
void Print(const multiset<T>& s)
{
	for (const auto& e : s)
		cout << e << " ";
	cout << endl;
}

//int main()
//{
//	set<int> m;
//
//	m.insert(1);
//	m.insert(3);
//	m.insert(1); //重复的话set是不会插入的
//	m.insert(4);
//	m.insert(5);
//	m.insert(7);
//	m.insert(6);
//	Print(m);
//
//	//通过erase直接删
//	m.erase(1);
//	m.erase(3);
//	Print(m);
//
//	//通过find查找后删掉该迭代器位置的元素
//	set<int>::iterator pos = m.find(5);
//	m.erase(pos);
//	Print(m);
//
//	//删光set中的元素
//	//m.clear();
//	//Print(m);
//
//	auto position = m.find(199);
//	if (position != m.end())
//	{
//		m.erase(position);
//	}
//	Print(m);
//
//	return 0;
//}

//int main()
//{
//	set<int> m;
//
//	m.insert(1);
//	m.insert(3);
//	m.insert(1); //重复的话set是不会插入的
//	m.insert(7);
//	m.insert(6);
//	Print(m);
//
//	//判断一下是否返回的是end()
//	auto position = m.find(199);
//	if (position != m.end())
//	{
//		m.erase(position);
//	}
//	Print(m);
//
//	//不存在的话就不会去删
//	m.erase(200);
//	Print(m);
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,3,1,4,5,1,5,6,8,7 };//含有重复元素
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	//set会去重
//	set<int> s(arr, arr + n);
//	Print(s);
//
//	s.erase(1);
//	Print(s);
//
//	//multiset重复的元素也会算入
//	multiset<int> multis(arr, arr + n);
//	Print(multis);
//
//	multis.erase(1);
//	Print(s);
//
//	return 0;
//}

//bool fncomp(char left, char right) { return left < right; }
//
//struct classcomp 
//{
//	bool operator() (const char& left, const char& right) const
//	{
//		return left < right;
//	}
//};
//
//int main()
//{
//	map<char, int> first;  //构造空的map
//
//	first['a'] = 10;
//	first['b'] = 30;
//	first['c'] = 50;
//	first['d'] = 70;
//
//	map<char, int> second(first.begin(), first.end());  //迭代器构造map
//
//	map<char, int> third(second);  //拷贝构造map
//
//	map<char, int, classcomp> fourth;                 // 用类方法做比较
//
//	bool(*fn_pt)(char, char) = fncomp;
//	map<char, int, bool(*)(char, char)> fifth(fn_pt); // 用函数指针做比较
//
//	return 0;
//}

//int main()
//{
//	map<string, string> m;
//	m.insert(make_pair("liren", "利刃"));
//	m.insert(make_pair("apple", "苹果"));
//	m.insert(make_pair("banana", "香蕉"));
//	m.insert(make_pair("milk", "牛奶"));
//
//	// 遍历方式1：迭代器
//	map<string, string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << " -> " << it->second << endl;
//		it++;
//	}
//	cout << endl;
//
//	// 反向迭代器
//	map<string, string>::reverse_iterator rit = m.rbegin();
//	while (rit != m.rend())
//	{
//		cout << rit->first << " -> " << rit->second << endl;
//		rit++;
//	}
//	cout << endl;
//
//	// 遍历方式2：范围for
//	// 注意这里的s其实就是pair的对象，所以我们得用s.first来访问而不是s->first
//	for (const auto& s : m)
//	{
//		cout << s.first << " -> " << s.second << endl;
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	map<string, string> m;
//
//	// 向map中插入元素的方式：
//	// 将键值对<"peach","桃子">插入map中，用pair直接来构造键值对
//	m.insert(pair<string, string>("peach", "桃子"));
//
//	// 将键值对<"peach","桃子">插入map中，用make_pair函数来构造键值对
//	m.insert(make_pair("banan", "香蕉"));
//
//	// 借用operator[]向map中插入元素
//	/*
//	operator[]的原理是：
//	用<key, T()>构造一个键值对，然后调用insert()函数将该键值对插入到map中
//	如果key已经存在，插入失败，insert函数返回该key所在位置的迭代器以及false
//	如果key不存在，插入成功，insert函数返回新插入元素所在位置的迭代器以及true
//	operator[]函数最后将insert返回值键值对中的value返回
//	*/
//
//	// 将<"apple", "">插入map中，插入成功，返回value的引用，将“苹果”赋值给该引用结果，
//	m["apple"] = "苹果";		//插入+修改
//	m["water"];				//插入
//	m["water"] = "水";		//修改
//	m["liren"] = "利刃";		//插入+修改
//
//	// key不存在时抛异常
//	//m.at("waterme") = "水蜜桃";
//	cout << m.size() << endl;
//	cout << m.count("peach") << endl;
//
//	// 用迭代器去遍历map中的元素，可以得到一个按照key排序的序列
//	for (auto& e : m)
//		cout << e.first << "--->" << e.second << endl;
//	cout << endl;
//
//	// map中的键值对key一定是唯一的，如果key存在将插入失败
//	// insert返回的是pair，所以这里auto的类型是 pair<map<string, string>::iterator, bool>
//	auto ret = m.insert(make_pair("peach", "桃色"));
//	if (ret.second)
//		cout << "<peach, 桃色>不在map中, 已经插入" << endl;
//	else
//		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" << ret.first->second << " 插入失败" << endl;
//
//	// 删除key为"apple"的元素
//	m.erase("apple");
//
//	if (1 == m.count("apple"))
//		cout << "apple还在" << endl;
//	else
//		cout << "apple被吃了" << endl;
//
//	return 0;
//}

void Test1()
{
	// 统计次数方式1：使用find+insert的方法

	string arr[] = { "香蕉", "苹果", "山竹", "山竹", "葡萄", "葡萄", "山竹", "榴莲", "山竹", "葡萄", "香蕉" };
	map<string, int> countMap;

	// 因为string是自定义类型，若传值给e的话会多次调用拷贝构造，所以这里用传引用
	for (const auto& e : arr)
	{
		map<string, int>::iterator it = countMap.find(e);

		// 不为end()说明存在该节点，则让次数++
		// 为end()说明不存在节点，则插入
		if (it != countMap.end())
		{
			it->second++;
		}
		else
		{
			countMap.insert(make_pair(e, 1));
		}
	}

	// 打印
	for (const auto& e : countMap)
		cout << e.first << ":" << e.second << endl;
}

void Test2()
{
	//统计次数方式2：直接用insert

	string arr[] = { "香蕉", "苹果", "山竹", "山竹", "葡萄", "葡萄", "山竹", "榴莲", "山竹", "葡萄", "香蕉" };
	map<string, int> countMap;

	for (const auto& e : arr)
	{
		// 因为insert返回的是pair，所以得用pair的对象接收
		pair<map<string, int>::iterator, bool> res = countMap.insert(make_pair(e, 1));

		// 通过返回的pair对象的second的bool值来判断是否插入成功
		// 若成功则说明原来不存在该节点，则不需要做任何事
		// 若失败则说明之前已经存在该节点了，则需要让次数++
		if (res.second == false)
		{
			res.first->second++;
		}
	}

	// 打印
	for (const auto& e : countMap)
		cout << e.first << ":" << e.second << endl;
}

void Test3()
{
	// 统计次数方式3：直接用operator[]

	string arr[] = { "香蕉", "苹果", "山竹", "山竹", "葡萄", "葡萄", "山竹", "榴莲", "山竹", "葡萄", "香蕉" };
	map<string, int> countMap;

	for (const auto& e : arr)
	{
		// 如果e不在countMap中，则先插入，再返回节点中value对象的引用
		// 如果e在countMap中，则直接返回key所在节点中对应value对象的引用
		countMap[e]++;
	}

	// 打印
	for (const auto& e : countMap)
		cout << e.first << ":" << e.second << endl;
}

struct CountItCompare
{
	bool operator()(map<string, int>::iterator x, map<string, int>::iterator y) const
	{
		return x->second > y->second;
	}
};

void Sort1()
{
	// 统计次数方式3：直接用operator[]
	string arr[] = { "香蕉", "苹果", "山竹", "山竹", "葡萄", "葡萄", "山竹", "榴莲", "山竹", "葡萄", "香蕉" };
	map<string, int> countMap;
	for (const auto& e : arr)
		countMap[e]++;

	// 对所有物品次数排序的思路一: 对countMap的迭代器进行排序（需要自己写比较函数）

	vector<map<string, int>::iterator> v;

	// 先将迭代器插入到vector中（注意这里不能用vector的区间初始化，因为如果是区间初始化，那么放进去的是pair而不是迭代器）
	map<string, int>::iterator Mapit = countMap.begin();
	while (Mapit != countMap.end())
	{
		v.push_back(Mapit);
		Mapit++;
	}

	//接着对vector中的迭代器进行排序
	sort(v.begin(), v.end(), CountItCompare());

	// 打印前三名最多次数的
	for (int i = 0; i < 3; ++i)
		cout << "第" << i+1 << "名：" << v[i]->first << endl;
}

void Sort2()
{
	// 统计次数方式3：直接用operator[]
	string arr[] = { "香蕉", "葡萄", "山竹", "山竹", "葡萄", "葡萄", "山竹", "榴莲", "山竹", "葡萄", "香蕉" };
	map<string, int> countMap;
	for (const auto& e : arr)
		countMap[e]++;

	// 对所有物品次数排序的思路二: 利用map排序，用map<int, string>类型来反向存储，这样子就可以比较key值也就是次数
	map<int, string, greater<int>> sortMap;
	for (const auto& e : countMap)
	{
		sortMap.insert(make_pair(e.second, e.first));
	}

	// 打印前三名最多次数的
	int i = 1;
	for (const auto& e : sortMap)
	{
		if (i > 3)
			break;
		cout << "第" << i++ << "名：" << e.second << endl;
	}
}

void Sort3()
{
	// 统计次数方式3：直接用operator[]
	string arr[] = { "香蕉", "苹果", "山竹", "山竹", "葡萄", "葡萄", "山竹", "榴莲", "山竹", "葡萄", "香蕉" };
	map<string, int> countMap;
	for (const auto& e : arr)
		countMap[e]++;

	// 对所有物品次数排序的思路三: 利用set存储map的迭代器排序，类似第一种方式，这样子也能避免拷贝pair
	set<map<string, int>::iterator, CountItCompare> sortSet;

	map<string, int>::iterator countMapIt = countMap.begin();
	while (countMapIt != countMap.end())
	{
		sortSet.insert(countMapIt);
		countMapIt++;
	}

	// 打印前三名最多次数的
	int i = 1;
	for (const auto& e : sortSet)
	{
		if (i > 3)
			break;
		cout << "第" << i++ << "名：" << e->first << endl;
	}
}

struct CountItCompareLess
{
	bool operator()(map<string, int>::iterator x, map<string, int>::iterator y) const
	{
		return x->second < y->second;
	}
};

void Sort4()
{
	// 统计次数方式3：直接用operator[]
	string arr[] = { "香蕉", "苹果", "山竹", "山竹", "葡萄", "葡萄", "山竹", "榴莲", "山竹", "葡萄", "香蕉" };
	map<string, int> countMap;
	for (const auto& e : arr)
		countMap[e]++;

	// 对所有物品次数排序的思路四：利用优先级队列存放迭代器进行排序，注意用的是小堆根
	
	// 注意如果要传比较器的话，那么也得将vector也传过去，由于太长，所以我们用typedef简化
	typedef map<string, int>::iterator M_IT;
	priority_queue<M_IT, vector<M_IT>, CountItCompareLess> pq; //求最大的几个数所以要弄小堆

	map<string, int>::iterator countMapIt = countMap.begin();
	while (countMapIt != countMap.end())
	{
		pq.push(countMapIt);
		countMapIt++;
	}

	// 打印前三名最多次数的
	for (int i = 1; i <= 3; ++i)
	{
		cout << "第" << i << "名：" << pq.top()->first << endl;
		pq.pop();
	}
	cout << endl;
}

int main()
{
	Sort4();
	return 0;
}