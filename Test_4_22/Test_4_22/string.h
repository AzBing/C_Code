#pragma once
#include <assert.h>
namespace bit
{
	class string
	{
	public:
		/*string()
			:_str(new char[1] {'\0'})
			, _size(0)
			, _capacity(0)
		{}*/

		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size + 1)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		/*string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}*/

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}*/

		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				swap(tmp);
			}
			return *this;
		}*/

		string& operator=(string tmp)
		{
			swap(tmp);
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		size_t capacity()const
		{
			return _capacity;
		}

		size_t size()const
		{
			return _size;
		}

		const char* c_str()
		{
			return _str;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				while (_size < n)
				{
					_str[_size] = ch;
					++_size;
				}
				_str[_size] = '\0';
			}
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			const char* tmp = strstr(_str + pos, str);
			if (tmp)
			{
				return tmp - _str;
			}
			else
			{
				return npos;
			}
		}

		string substr(size_t pos, size_t len = npos)
		{
			string s;
			size_t end = pos + len;
			if (len == npos || pos + len >= _size)
			{
				len = _size - pos;
				end = _size;
			}
			s.reserve(len);
			for (size_t i = pos; i < end; i++)
			{
				s += _str[i];
			}
			return s;
		}

		void puch_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			puch_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
			/*size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			_size++;*/
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			int len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			//挪动数据
			int end = _size;
			//根据追加字符串的长度来计算挪动几次
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || len + pos >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + len + pos);
				_size -= len;
			}
		}

		bool operator<(const string& s) const
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator<=(const string& s) const
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s) const
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s) const
		{
			return !(*this < s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos;
	};
	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, string& s)
	{
		/*for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}*/
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}

	/*istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}*/

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char buff[129];
		size_t i = 0;

		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 128)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}

			ch = in.get();
		}

		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}

	void test_string1()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		string s2;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;
		s1.puch_back(' ');
		s1.append("hello tengxun");
		cout << s1.c_str() << endl;

		s1 += '*';
		s1 += "########";
		cout << s1.c_str() << endl;
	}
	void test_string3()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;
		/*s1.insert(0, 'x');
		cout << s1.c_str() << endl;
		s1.insert(6, '#');
		cout << s1.c_str() << endl;*/
		/*s1.insert(0, "bit ");
		cout << s1.c_str() << endl;*/
		s1.erase(0, 6);
		cout << s1.c_str() << endl;
	}
	void test_string4()
	{
		string s1("hello world");
		string s2("hella");
		cout << (s1 > s2) << endl;
		cout << (s1 != s2) << endl;

		cout << s2 << endl;
		cin >> s2;
		cout << s2 << endl;

	}
	void test_string5()
	{
		string s1("hello world");
		s1.resize(12, 'x');
		cout << s1 << endl;
		string s2 = s1;
		cout << s2 << endl;

	}

	void test_string6()
	{
		string s1("aaaaaaaa");
		cin >> s1;
		cout << s1 << endl;

		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

	}
}




