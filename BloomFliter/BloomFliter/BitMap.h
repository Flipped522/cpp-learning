#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include <vector>

namespace cgc
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bs.resize(N / 32 + 1, 0);
		}

		void set(size_t x)
		{
			int i = x / 32;
			int j = x % 32;

			_bs[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			int i = x / 32;
			int j = x % 32;

			_bs[i] &= (~(1 << j));
		}

		bool test(size_t x)
		{
			int i = x / 32;
			int j = x % 32;

			return _bs[i] & (1 << j);
		}

	private:
		std::vector<int> _bs;
	};

	template<size_t N>
	class twobit
	{
	public:
		void set(size_t x)
		{
			bool bit1 = _bs1.test(x);
			bool bit2 = _bs2.test(x);

			if (!bit1 && !bit2) // 00 -> 01
			{
				_bs1.reset(x);
				_bs2.set(x);
			}
			else if (!bit1 && bit2)  // 01->10
			{
				_bs1.set(x);
				_bs2.reset(x);
			}
			else if (bit1 && !bit2) //  10->11
			{
				_bs1.set(x);
				_bs2.set(x);
			}
		}

		int get_count(size_t x)
		{
			int bit1 = _bs1.test(x);
			int bit2 = _bs2.test(x);

			if (!bit1 && !bit2)
			{
				return 0;
			}
			else if (!bit1 && bit2)
			{
				return 1;
			}
			else if (bit1 && !bit2)
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}
	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};
}