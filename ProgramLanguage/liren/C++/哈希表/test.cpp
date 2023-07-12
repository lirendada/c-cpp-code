#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
//#include <unordered_set>
//#include <set>
#include "hashtable.h"

//void test1()
//{
//	unordered_set<int> us;
//	us.insert(5);
//	us.insert(1);
//	us.insert(5);
//	us.insert(3);
//	us.insert(7);
//	us.insert(2);
//
//	auto it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	unordered_multiset<int> mus;
//	mus.insert(5);
//	mus.insert(1);
//	mus.insert(5);
//	mus.insert(3);
//	mus.insert(7);
//	mus.insert(2);
//
//	auto mit = mus.begin();
//	while (mit != mus.end())
//	{
//		cout << *mit << " ";
//		mit++;
//	}
//	cout << endl;
//}
//
//void test_op()
//{
//	int n = 1000000;
//	vector<int> v;
//	v.reserve(n);
//	srand(time(0));
//	for (int i = 0; i < n; ++i)
//	{
//		//v.push_back(i);
//		v.push_back(rand());
//	}
//
//	size_t begin1 = clock();
//	set<int> s;
//	for (auto e : v)
//	{
//		s.insert(e);
//	}
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	unordered_set<int> us;
//	for (auto e : v)
//	{
//		us.insert(e);
//	}
//	size_t end2 = clock();
//
//	cout << s.size() << endl;
//
//	cout << "set insert:" << end1 - begin1 << endl;
//	cout << "unordered_set insert:" << end2 - begin2 << endl;
//
//
//	size_t begin3 = clock();
//	for (auto e : v)
//	{
//		s.find(e);
//	}
//	size_t end3 = clock();
//
//	size_t begin4 = clock();
//	for (auto e : v)
//	{
//		us.find(e);
//	}
//	size_t end4 = clock();
//	cout << "set find:" << end3 - begin3 << endl;
//	cout << "unordered_set find:" << end4 - begin4 << endl;
//
//	size_t begin5 = clock();
//	for (auto e : v)
//	{
//		s.erase(e);
//	}
//	size_t end5 = clock();
//
//	size_t begin6 = clock();
//	for (auto e : v)
//	{
//		us.erase(e);
//	}
//	size_t end6 = clock();
//	cout << "set erase:" << end5 - begin5 << endl;
//	cout << "unordered_set erase:" << end6 - begin6 << endl;
//}

void Myhash1()
{
	/*CloseHash::hashtable<string, string> hs;
	hs.insert(make_pair("liren", "ÀûÈĞ"));
	hs.insert(make_pair("sort", "ÅÅĞò"));
	hs.insert(make_pair("eat", "³Ô"));
	hs.insert(make_pair("isnert", "²åÈë"));
	hs.insert(make_pair("ate", "³Ô"));*/

	CloseHash::hashtable<int, int> ht;

	int a[] = { 2, 12, 22, 32, 42, 52, 62 };
	for (auto e : a)
	{
		ht.insert(make_pair(e, e));
	}

	ht.insert(make_pair(72, 72));
	ht.insert(make_pair(32, 32));
	ht.insert(make_pair(-1, -1));
	ht.insert(make_pair(-999, -999));


	cout << ht.find(12) << endl;
	ht.erase(12);
	cout << ht.find(12) << endl;
}

void Test()
{
	hash<string> h;
	cout << h("liren") << endl;
	cout << h("sort") << endl;
	cout << h("isnert") << endl;
	cout << h("eat") << endl;
	cout << h("ate") << endl;
}

void Mylink()
{
	LinkHash::hashtable<int, int> ht;
	int a[] = { 2, 12, 22, 32, 42, 52, 62 ,72, 82, 102};
	for (auto e : a)
	{
		ht.insert(make_pair(e, e));
	}
	ht.insert(make_pair(132,132));
	for (auto e : a)
	{
		ht.erase(e);
	}
	ht.erase(132);
}

int main()
{
	//test1();
	//test_op();

	//Myhash1();
	//Test();
	Mylink(); 
	return 0;
}