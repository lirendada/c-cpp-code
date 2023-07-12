#define _CRT_SECURE_NO_WARNINGS
#include "BinarySearchTree.h"

void Test1()
{
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	K::BSTree<int> b;
	for (auto e : a)
	{
		b.InsertR(e);
	}
	b.Inorder();

	for (auto e : a)
	{
		b.EraseR(e);
	}

	b.Erase(7);
	b.Inorder();
}

void Test2()
{
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	K::BSTree<int> b;
	for (auto e : a)
	{
		b.InsertR(e);
	}
	b.Inorder();

	K::BSTree<int> copy = b;
	copy.Inorder();

	K::BSTree<int> opetor;
	opetor = b;
	opetor.Inorder();
}

void Test3()
{
	//输入单词，查找对应的中文翻译
	KV::BSTree<string, string> dict;
	dict.InsertR("string", "字符串");
	dict.InsertR("liren", "利刃");
	dict.InsertR("yt", "杨狗");
	dict.InsertR("apple", "苹果");
	dict.InsertR("const", "常量");
	dict.InsertR("static", "静态");
	//......可以插入词库里面的所有单词

	string str;
	while (cin >> str)
	{
		KV::BSTreeNode<string, string>* tmp = dict.FindR(str);
		if (tmp == nullptr)
			cout << "查无此单词：" << str << endl;
		else
			cout << str << " 中文翻译：" << tmp->_value << endl;
	}
}

void Test4()
{
	//统计字符串出现的次数
	string arr[] = { "利刃","利刃","rk98" ,"杨狗" ,"利刃" ,"杨狗" ,"利刃" ,"利刃" ,"苹果" ,"利刃" };
	KV::BSTree<string, int> countTree;

	//用传引用防止string过多的调用拷贝构造，又为了防止被修改，所以加上const
	for (const auto& e : arr)
	{
		//先查找字符串是否在搜索树中
		//1、不在的话，说明字符串第一次出现，则插入<字符串，1>
		//2、如果存在的话，则直接让对应字符串出现的次数++即可
		KV::BSTreeNode<string, int>* tmp = countTree.Find(e);
		if (tmp == nullptr)
			countTree.Insert(e, 1);
		else
			tmp->_value++;
	}
	countTree.Inorder();
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	return 0;
}