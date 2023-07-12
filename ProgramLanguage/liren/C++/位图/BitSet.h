#pragma once
// BitSet.h
#include <iostream>
#include <vector>

namespace liren
{
	// N代表要存放的比特位数量
	template <size_t N>
	class BitSet
	{
	public:
		// 构造函数
		BitSet()
		{
			// 每次多开一个字节，并初始化为0
			_bits.resize(N / 8 + 1, 0);
		}

		// 将x位置处的比特位设为1
		void set(size_t x)
		{
			// 先获取x的位置
			size_t i = x / 8;
			size_t j = x % 8;

			// 接着让x处的比特位（按位或）上（只有x处为1的数）
			// 注意这里vs是小端存储，注意方向
			_bits[i] |= (1 << j);
		}

		// 将x位置处的比特位设为0
		void reset(size_t x)
		{
			// 先获取x的位置
			size_t i = x / 8;
			size_t j = x % 8;

			// 接着让x处的比特位（按位与）上（只有x处为0的数）
			// 注意这里vs是小端存储，注意方向
			_bits[i] &= (~(1 << j));
		}

		// 检查x位置处的比特位是否为1
		bool test(size_t x)
		{
			// 先获取x的位置
			size_t i = x / 8;
			size_t j = x % 8;

			// 接着让x处的比特位（按位与）上（只有x处为1的数）
			return _bits[i] & (1 << j);
		}

	private:
		std::vector<char> _bits; 
	};

	template <size_t N>
	class TwoBitSet
	{
	public:
		void set(size_t x)
		{
			// 如果两个比特位都是0，则出现0次
			if (!_bs1.test(x) && !_bs2.test(x))
			{
				// 将其变成出现1次
				_bs2.set(x);
			}
			// 如果出现一次，则_bs1为0，_bs2为1
			else if (!_bs1.test(x) && _bs2.test(x))
			{
				// 将其变成出现2次
				_bs1.set(x);
				_bs2.reset(x);
			}
		}

		void PrintOnceNum()
		{
			for (size_t i = 0; i < N; ++i)
			{
				if (!_bs1.test(i) && _bs2.test(i))
				{
					std::cout << i << " ";
				}
			}
			std::cout << std::endl;
		}
	private:
		BitSet<N> _bs1;
		BitSet<N> _bs2;
	};
}