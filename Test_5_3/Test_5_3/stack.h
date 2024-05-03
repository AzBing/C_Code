#pragma once
#include<vector>
#include<list>
#include<deque>

namespace sta
{
	//template<class T>
	//class stack
	//{
	//private:
	//	T* _a;
	//	size_t _size;
	//	size_t _capacity;
	//};

	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}

	private:
		Container _con;
	};
}