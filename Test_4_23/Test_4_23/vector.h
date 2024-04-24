#pragma once
#include <assert.h>
namespace vt
{
	template<class T>
	class vector
	{
	public:

		typedef T* iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		void puch_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t sz = size();
				size_t cap = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[cap];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[]_start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + cap;
			}
			*_finish = x;
			++_finish;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		size_t capacity()
		{
			return _endofstorage - _start;
		}

		size_t size()
		{
			return _finish - _start;
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test_vector1()
	{
		vector<int> v1;
		v1.puch_back(1);
		v1.puch_back(2);
		v1.puch_back(3);
		v1.puch_back(4);
		v1.puch_back(5);

		for (size_t i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto ch : v1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
}



