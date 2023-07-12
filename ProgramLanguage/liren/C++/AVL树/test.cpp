#define _CRT_SECURE_NO_WARNINGS
#include "AVLTree.h"

void TestTree1()
{
	AVLTree<int, int> t;
	int arr[] = { 3,10,1,2,9,4,5,6,7 };
	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : arr)
	{
		t.Insert(make_pair(e, 1));
	}
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t[3] *= 102;
	t[1] *= 10;
	t[2] *= 10;
	t.Inorder();

	t.Erase(3);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(1);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(1);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(2);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(4);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(5);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(6);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(7);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(8);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(9);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(10);
	t.Inorder();
	cout << t.IsAVLTree() << endl;

	t.Erase(10);
	t.Inorder();
	cout << t.IsAVLTree() << endl;
}

int main()
{
	TestTree1();
	return 0;
}