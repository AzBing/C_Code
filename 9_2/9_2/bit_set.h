#pragma once

namespace bit
{
	template<size_t N>
	class bit_set
	{
	public:
		bit_set()
		{
			_bits.resize((N >> 5) + 1, 0);
		}
		// 对应的比特位，置1
		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_bits[i] |= (1 << j);
		}
		// 标志位显示删除
		void reset(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_bits[i] &= ~(1 << j);
		}
		// 判断值在不在
		bool test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			return _bits[i] & (1 << j);
		}

	private:
		vector<int> _bits;

	};
}
