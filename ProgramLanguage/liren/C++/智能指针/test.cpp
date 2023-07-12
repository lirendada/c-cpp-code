#define _CRT_SECURE_NO_WARNINGS
#include "SmartPtr.h"


//int main()
//{
//    liren::unique_ptr<int> uptr1(new int);
//    liren::unique_ptr<int> uptr2(new int);
//
//    *uptr1 = 10;
//    cout << *uptr1 << " or " << uptr1[0] << endl;
//
//    //liren::unique_ptr<int> uptr3(uptr1); // ❌
//    //uptr2 = uptr1; // ❌
//    return 0;
//}

//int main()
//{
//	liren::shared_ptr<int> sp1(new int);
//	liren::shared_ptr<int> sp2(sp1);
//	liren::shared_ptr<int> sp3(sp2);
//
//	*sp1 = 20;
//
//	cout << "*sp1: " << *sp1 << " &sp1: " << sp1.get() << " count: " << sp1.used_count() << endl;
//	cout << "*sp2: " << *sp2 << " &sp2: " << sp2.get() << " count: " << sp2.used_count() << endl;
//	cout << "*sp3: " << *sp3 << " &sp3: " << sp3.get() << " count: " << sp3.used_count() << endl;
//	cout << "------------------------------------------------------------------------------------" << endl;
//
//	liren::shared_ptr<int> sp4(new int);
//	liren::shared_ptr<int> sp5(sp4);
//	cout << "*sp4: " << *sp4 << " &sp4: " << sp4.get() << " count: " << sp4.used_count() << endl;
//	cout << "*sp5: " << *sp5 << " &sp5: " << sp5.get() << " count: " << sp5.used_count() << endl;
//	cout << "------------------------------------------------------------------------------------" << endl;
//
//	sp5 = sp1;
//	cout << "*sp1: " << *sp1 << " &sp1: " << sp1.get() << " count: " << sp1.used_count() << endl;
//	cout << "*sp4: " << *sp4 << " &sp4: " << sp4.get() << " count: " << sp4.used_count() << endl;
//	cout << "*sp5: " << *sp5 << " &sp5: " << sp5.get() << " count: " << sp5.used_count() << endl;
//	cout << "------------------------------------------------------------------------------------" << endl;
//
//	return 0;
//}


//#include <iostream>
//#include <memory>
//int main () 
//{
//	shared_ptr<int> sp (new int);
//
//	weak_ptr<int> wp1;
//	weak_ptr<int> wp2 (wp1);
//	weak_ptr<int> wp3 (sp);
//
//	cout << "use_count:\n";
//	cout << "wp1: " << wp1.use_count() << endl;
//	cout << "wp2: " << wp2.use_count() << endl;
//	cout << "wp3: " << wp3.use_count() << endl;
//
//	cout << endl << "is expired？:" << endl;
//	cout << wp1.expired() << endl;
//	cout << wp1.expired() << endl;
//	cout << wp3.expired() << endl;
//	return 0;
//}

//int main()
//{
//	// liren::test_shared_ptr1();
//	// liren::test_shared_ptr2();
//	// liren::test_circle_ref();
//	liren::test_security();
//	return 0;
//}

template<class T>
struct DeleteArray
{
	void operator()(const T* ptr)
	{
		delete[] ptr;
		cout << "delete[] " << ptr << endl;
	}
};

int main()
{
	liren::shared_ptr<int> sp1(new int[10]); // 使用默认删除器，但不是我们想要的delete[]
	liren::shared_ptr<int, DeleteArray<int>> sp2(new int[10], DeleteArray<int>()); // 使用我们传递的删除器，调用delete[]
	return 0;
}

//int main()
//{
//	//shared_ptr<int> sp1(new int[10]); // 不一定会报错，因为是内置类型
//	//shared_ptr<string> sp2(new string[10]); // 肯定会报错，因为是自定义类型
//
//	// 注意下述传递的第二个参数是函数对象而不是类型，所以需要加()
//	shared_ptr<int> sp1(new int[10], DeleteArray<int>());
//	shared_ptr<string> sp2(new string[10], DeleteArray<string>());
//
//	// 还可用使用lambda表达式
//	shared_ptr<string> sp3(new string[10], [](string* ptr) 
//		{
//			delete[] ptr;
//			cout << "lambda delete[] " << ptr << endl;
//		});
//
//	// 还可以是文件类型
//	shared_ptr<FILE> sp4(fopen("test.cpp", "r"), [](FILE* ptr)
//		{
//			fclose(ptr);
//			cout << "file delete[] " << ptr << endl;
//		}); 
//
//	// 使用库中的默认删除器
//	// shared_ptr<string> sp3(new string[10], default_delete<string>());
//	return 0;
//}

