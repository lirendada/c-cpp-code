#define _CRT_SECURE_NO_WARNINGS
#include "myMap.h"
#include "mySet.h"
#include "Iterator.h"

void Test1()
{
	//int arr[] = { 4,2,1,3,5,15,7,16,14 };
	int arr[] = { 12,1,9,2,0,11,7,19,4,15,18,5,14,13,10,16,6,3,8,17 };

	liren::set<int> s;
	for (auto e : arr)
		s.insert(e);

	liren::set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		sit++;
	}
	cout << endl;
	for (auto e : s)
		cout << e << " ";
	cout << endl;
	
	liren::set<int>::reverse_iterator rsit = s.rbegin();
	while (rsit != s.rend())
	{
		cout << *rsit << " ";
		rsit++;
	}
	cout << endl;

	liren::map<int, int> m;
	for (auto e : arr)
		m.insert(make_pair(e, e));

	liren::map<int, int>::iterator mit = m.begin();
	while (mit != m.end())
	{
		cout << mit->first << ":" << mit->second << " ";
		++mit;
	}
	cout << endl;
	for (auto e : m)
		cout << e.first << ":" << e.second << " ";
	cout << endl;

	liren::map<int, int>::reverse_iterator rmit = m.rbegin();
	while (rmit != m.rend())
	{
		cout << rmit->first << ":" << rmit->second << " ";
		++rmit;
	}
	cout << endl;
}

void Test2()
{
	int arr[] = { 12,1,9,2,0,11,7,19,4,15,18,5,14,13,10,16,6,3,8,17 };
	liren::map<int, int> m;
	for (auto e : arr)
		m.insert(make_pair(e, e));
	for (auto e : m)
		cout << e.first << ":" << e.second << " ";
	cout << endl;

	liren::map<int, int> copymap(m);
	for (auto e : m)
		cout << e.first << ":" << e.second << " ";
	cout << endl;

	liren::map<int, int> opecopymap;
	opecopymap = m;
	for (auto e : m)
		cout << e.first << ":" << e.second << " ";
	cout << endl;
}

int main()
{
	//Test1();
	Test2();
	return 0;
}