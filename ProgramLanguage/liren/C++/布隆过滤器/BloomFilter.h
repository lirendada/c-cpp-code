#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using std::cout;
using std::endl;
using std::string;
using std::bitset;

struct BKDRHash
{
	size_t operator()(const string& s)
	{
		// BKDR
		size_t value = 0;
		for (auto ch : s)
		{
			value *= 31;
			value += ch;
		}
		return value;
	}
};

struct APHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& s)
	{
		if (s.size() == 0)   // 这是由本人添加，以保证空字符串返回哈希值0  
			return 0;
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

namespace liren
{
	template <size_t N, 
		size_t Factor = 6,
		class K = string,
		class HashFunc1 = BKDRHash,
		class HashFunc2 = APHash,
		class HashFunc3 = DJBHash>
	class BloomFilter
	{
	public:
		void Set(const K& key)
		{
			size_t len = N * Factor;
			// 由于我们使用三个哈希函数，所以要获取三个下标
			size_t index1 = HashFunc1()(key) % len;
			size_t index2 = HashFunc2()(key) % len;
			size_t index3 = HashFunc3()(key) % len;

			_bs.set(index1);
			_bs.set(index2);
			_bs.set(index3);
		}

		bool Test(const K& key)
		{
			size_t len = N * Factor;

			// 若下面有一个是为0则是不存在的
			size_t index1 = HashFunc1()(key) % len;
			if (_bs.test(index1) == 0)
				return false;

			size_t index2 = HashFunc2()(key) % len;
			if (_bs.test(index2) == 0)
				return false;

			size_t index3 = HashFunc3()(key) % len;
			if (_bs.test(index3) == 0)
				return false;
			
			return true; // 这里只能判断可能存在，不能判断绝对存在
		}
	private:
		bitset<N*Factor> _bs;
	};
}

void TestBloomFilter2()
{
	/*liren::BloomFilter<100> bf;
	bf.Set("张三");
	bf.Set("李四");
	bf.Set("牛魔王");
	bf.Set("红孩儿");
	bf.Set("eat");


	cout << bf.Test("张三") << endl;
	cout << bf.Test("李四") << endl;
	cout << bf.Test("牛魔王") << endl;
	cout << bf.Test("红孩儿") << endl;
	cout << bf.Test("孙悟空") << endl;
	cout << bf.Test("二郎神") << endl;
	cout << bf.Test("猪八戒") << endl;
	cout << bf.Test("ate") << endl;
	cout << bf.Test("eat") << endl;*/

	liren::BloomFilter<100> bf;

	srand(time(nullptr));
	size_t N = 100;
	std::vector<std::string> v1;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
		url += std::to_string(1234 + i);
		v1.push_back(url);
	}

	for (auto& str : v1)
	{
		bf.Set(str);
	}

	for (auto& str : v1)
	{
		cout << bf.Test(str) << endl;
	}
	cout << endl << endl;

	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
		url += std::to_string(6789 + i);
		v2.push_back(url);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.Test(str))
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "zhihu.com";
		//std::string url = "https://www.baidu.com/s?wd=ln2&rsv_spt=1&rsv_iqid=0xc1c7784f000040b1&issp=1&f=8&rsv_bp=1&rsv_idx=2&ie=utf-8&tn=baiduhome_pg&rsv_dl=tb&rsv_enter=1&rsv_sug3=8&rsv_sug1=7&rsv_sug7=100&rsv_sug2=0&rsv_btype=i&prefixsug=ln2&rsp=5&inputT=4576&rsv_sug4=5211";
		//std::string url = "https://zhidao.baidu.com/question/1945717405689377028.html?fr=iks&word=ln2&ie=gbk&dyTabStr=MCw0LDMsMiw2LDEsNSw3LDgsOQ==";
		//std::string url = "https://www.cnblogs.com/-clq/archive/2012/01/31/2333247.html";
		url += std::to_string(rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.Test(str))
		{
			++n3;
		}
	}
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;

}