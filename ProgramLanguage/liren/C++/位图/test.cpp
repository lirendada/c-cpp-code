#include "BitSet.h"

void FindIntersection()
{
	int a1[] = { 5, 30, 1, 99, 10 };
	const size_t n1 = sizeof(a1) / sizeof(a1[0]);
	int a2[] = { 8, 10, 11, 9, 30, 10, 30, 10, 30 };
	const size_t n2 = sizeof(a2) / sizeof(a2[0]);

	liren::BitSet<0xffffffff> bs1;
	liren::BitSet<0xffffffff> bs2;

	// 先将a1和a2放到两个位图中
	for (size_t i = 0; i < n1; ++i)
		bs1.set(a1[i]);
	for (size_t i = 0; i < n2; ++i)
		bs2.set(a2[i]);

	// 遍历bs2，看看是否在bs1中，在就是交集
	for (size_t i = 0; i <= 0xffffffff; ++i)
	{
		if (bs2.test(i))
		{
			if (bs1.test(i))
				std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

int main()
{
	/*liren::BitSet<20> t;

	t.set(10);
	std::cout << t.test(10) << std::endl;

	t.reset(10);
	std::cout << t.test(10);*/

	// 40亿个整数，我们只需要开500MB的比特位即可
	// 但是为了保证int的范围都被包括，我们要开42亿整数空间的大小
	// 也就是unsigned的最大值
	// 但其实这里我们直接利用十六进制表示即可开unsigned的最大值
	//liren::BitSet<-1> b; 这种写法会报错

	/*liren::BitSet<0xffffffff> b;
	
	b.set(1314);
	std::cout << b.test(1314) << std::endl;

	b.reset(1314);
	std::cout << b.test(1314);*/

	int a[] = { 99, 0, 4, 50, 33, 44, 2, 5, 99, 0, 50, 99, 50, 2 };
	liren::TwoBitSet<100> tbs;
	for (auto e : a)
	{
		tbs.set(e);
	}
	tbs.PrintOnceNum();

	FindIntersection();

	return 0;
}