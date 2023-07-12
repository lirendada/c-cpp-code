//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//using namespace std;
//
//string GetDomain(const string& s)
//{
//	size_t begin = s.find("://");
//	if (begin == string::npos)
//	{
//		return string();
//	}
//
//	begin += 3;
//	size_t end = s.find('/', begin);
//	if (end != string::npos)
//	{
//		return s.substr(begin, end - begin);
//	}
//	return string();
//}
//
//string GetProtocol(const string& s)
//{
//	size_t pos = s.find("://");
//	if (pos != string::npos)
//	{
//		return s.substr(0, pos);
//	}
//	else
//	{
//		return string();//返回空string
//	}
//}
//
//int main()
//{
//	//string s1;
//	//string s2("lirendada love yt");
//	//string s3(10, 't');
//	//string s4(s2);
//	//string s5(s3, 5, 2);
//	//cout << s5 << endl;
//
//	//cout << s2.size() << endl;
//	//cout << s2.length() << endl;
//	//cout << s2.capacity() << endl;
//	//cout << s2 << endl;
//
//	/*s2.clear();
//	//cout << s2.size() << endl;
//	//cout << s2.capacity() << endl;
//	//cout << s2 << endl;*/
//
//	//s2.resize(10, 'v');
//	//cout << s2.size() << endl;
//	//cout << s2.capacity() << endl;
//	//cout << s2 << endl;
//
//	//s2.resize(15);//默认用‘\0’填充
//	//cout << s2.size() << endl;
//	//cout << s2.capacity() << endl;
//	//cout << s2 << endl;
//
//	//s2.resize(5);
//	//cout << s2.size() << endl;
//	//cout << s2.capacity() << endl;
//	//cout << s2 << endl;
//
//	//s2.reserve(100);
//	//cout << s2.size() << endl;
//	//cout << s2.capacity() << endl;
//	//cout << s2 << endl;
//
//	//s2.reserve(50);
//	//cout << s2.size() << endl;
//	//cout << s2.capacity() << endl;
//	//cout << s2 << endl;
//
//	//size_t sz1 = s1.capacity();
//	//cout << "make a grow:\n";
//	//for (int i = 0; i < 100; i++)
//	//{
//	//	s1.push_back('c');
//	//	if (sz1 != s1.capacity())
//	//	{
//	//		sz1 = s1.capacity();
//	//		cout << "capacity changed: " << sz1 << "\n";
//	//	}
//	//}
//	//cout << s1.size() << endl;
//	//cout << s1.capacity() << endl;
//	//cout << s1 << endl;
//
//	//string s;
//	//s.reserve(100);
//	//size_t sz = s.capacity();
//	//cout << "make a grow:\n";
//	//for (int i = 0; i < 100; i++)
//	//{
//	//	s.push_back('c');
//	//	if (sz != s.capacity())
//	//	{
//	//		sz = s.capacity();
//	//		cout << "capacity changed: " << sz << "\n";
//	//	}
//	//}
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//	//cout << s << endl;
//
//	//string s1("liren nb!");
//
//	////第一种遍历:[]
//	//s1[3] = 'a';
//	//for (size_t i = 0; i < s1.size(); i++)
//	//{
//	//	cout << s1[i];
//	//}
//	//cout << "\n";
//
//	////第二种：迭代器
//	//// [begin(), end() ) end()返回的不是最后一个数据位置的迭代器，返回是最后一个位置下一个位置
//	//// 也要注意的是，C++中凡是给迭代器一般都是给的[)左闭右开的区间
//	//// 迭代器是类似指针一样东西，具体是什么我们讲了底层实现才能知道
//	//string::iterator sit = s1.begin();
//	//while (sit != s1.end())
//	//{
//	//	//*sit = 'a';
//	//	cout << *sit++;
//	//}
//	//cout << endl;
//
//	//string::reverse_iterator resit = s1.rbegin();
//	//while (resit != s1.rend())
//	//{
//	//	cout << *resit++;
//	//}
//	//cout << endl;
//
//	//// 迭代器意义：像string、vector支持[]遍历，但是list、map等等容器不支持[]
//	//// 我们就要用迭代器遍历，所以迭代器是一种统一使用的方式
//	//vector<int> v = { 1, 2, 3, 4 };
//	//vector<int>::iterator vit = v.begin();
//	//while (vit != v.end())
//	//{
//	//	cout << *vit << " ";
//	//	++vit;
//	//}
//	//cout << endl;
//
//	//list<int> lt = { 1, 2, 3, 4 };
//	//list<int>::iterator ltit = lt.begin();
//	//while (ltit != lt.end())
//	//{
//	//	cout << *ltit << " ";
//	//	++ltit;
//	//}
//	//cout << endl;
//
//	////第三种：范围for
//	//for (auto& e : s1)//用引用后可以修改值
//	//{
//	//	//e += 1;
//	//	cout << e;
//	//}
//	//cout << endl;
//
//	//cout << s1.c_str() << endl;//以c语言的方式打印字符串
//
//	////cout << s1.data();
//
//
//	/*string s1("hello liren");
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;
//
//	s1.resize(20);
//	s1 += "!!!";
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//
//	cout << s1.c_str() << endl;
//	cout << strlen(s1.c_str()) << endl;*/
//
//
//	// 假设要求取出文件名的后缀
//	/*string filename = "test.txt.zip";
//	size_t pos = filename.rfind('.');
//	if (pos != string::npos)
//	{
//		cout << filename.substr(pos, string::npos);
//	}*/
//	
//	// 要求写一个程序分别取出域名和协议名
//	string url1 = "http://www.cplusplus.com/reference/string/string/rfind/";
//	string url2 = "https://tower.im/users/sign_in";
//	string url3 = "tower.im/users/sign_in";
//
//	cout << GetDomain(url1) << endl;
//	cout << GetDomain(url2) << endl;
//	cout << GetDomain(url3) << endl;
//
//	cout << GetProtocol(url1) << endl;
//	cout << GetProtocol(url2) << endl;
//	cout << GetProtocol(url3) << endl;
//	
//	return 0;
//}