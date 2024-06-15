#pragma once
namespace bitst
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize((N >> 5) + 1, 0);
		}

		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_bits[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_bits[i] &= ~(1 << j);
		}

		void test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			return _bits[i] & (1 << j);
		}

	private:
		vector<int> _bits;
	};


}

