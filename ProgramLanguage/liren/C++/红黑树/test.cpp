#define _CRT_SECURE_NO_WARNINGS
#include "RBTree.h"

void Test1()
{
	//int arr[] = { 4,2,1,3,5,15,7,16,14 };
	int arr[] = { 12,1,9,2,0,11,7,19,4,15,18,5,14,13,10,16,6,3,8,17 };
	RBTree<int, int> t;
	for (auto e : arr)
		t.Insert(make_pair(e, e));
	cout << t.CheckBlance() << endl;
	t.InOrder();

	/*t.Erase(1);
	t.Erase(2);
	t.Erase(3);
	t.Erase(4);
	t.Erase(5);
	t.Erase(7);
	t.Erase(14);
	t.Erase(15);
	t.Erase(16);*/
	for (auto e : arr)
	{
		t.Erase(e);
		cout << t.CheckBlance() << endl;
		t.InOrder();
	}
}

void Test2()
{
	srand(time(0));
	RBTree<int, int> t;
	int n = 200;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		v.push_back(rand()%100);
		t.Insert(make_pair(v.back(), v.back()));
	}
	cout << t.CheckBlance() << endl << endl;

	for (auto e : v)
	{
		t.Erase(e);
		cout << t.CheckBlance() << endl;
		//t.InOrder();
	}
}

int main()
{
	//Test1();
	Test2();
	return 0;
}