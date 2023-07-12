#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>
using namespace std;

//int main()
//{
//	int n;
//	cin >> n;
//	vector<thread> v(n);
//	for (auto& t : v)
//	{
//		t = thread([]()
//			{
//				for (int i = 0; i < 10; ++i)
//				{
//					cout << this_thread::get_id() << " : " << i << endl;
//				}
//			});
//	}
//
//	Sleep(5000);
//	return 0;
//}

int main()
{
	cout << "this_thread::get_id() is : " << this_thread::get_id() << endl;
	thread t1([]()
		{
				cout << "this_thread::get_id() is : " << this_thread::get_id() << endl;
		});
	Sleep(1999);
	cout << "thread::get_id() is : " << t1.get_id() << endl;
	
	t1.join();
	return 0;
}