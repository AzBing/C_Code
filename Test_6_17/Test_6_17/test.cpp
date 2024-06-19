#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<array>
using namespace std;

#include<assert.h>

struct Point
{
	int _x;
	int _y;
};

// �б��ʼ��
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//
//	return 0;
//}

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

// һ�ж��������б��ʼ��
// ���ҿ���ʡ�Ե�=
//int main()
//{
//	int i = 0;
//	int j = { 0 };
//	int k{ 0 };
//
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	Point p{ 1, 2 };
//
//	Date d1(2023, 11, 25);
//
//	// ����ת��  ����+��������-���Ż�ֱ�ӹ���
//	Date d2 = { 2023, 11, 25 };
//	Date d3{ 2023, 11, 25 };
//
//	string s1 = "xxxx";
//
//	const Date& d4 = { 2023, 11, 25 };
//
//	Date* p1 = new Date[3]{ d1, d2, d3 };
//	Date* p2 = new Date[3]{ {2022, 11, 25}, {2022, 11, 26}, {2022, 11, 27} };
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1 = { 1,2,3,4 };
//	vector<int> v2 = { 1,2,3,4,5,6};
//
//	v1 = { 10,20,30 };
//
//	list<int> lt = { 10,20,30 };
//
//	// �������������ת��  ����+��������-���Ż�ֱ�ӹ���
//	// ����Ӧ���캯����������ƥ��
//	Date d2 = { 2023, 11, 25 };
//
//	// the type of il is an initializer_list 
//	auto il1 = { 10, 20, 30, 40, 50 };
//	cout << typeid(il1).name() << endl;
//
//	initializer_list<int> il2 = { 10, 20, 30};
//
//	initializer_list<int>::iterator it2 = il2.begin();
//	while (it2 != il2.end())
//	{
//		cout << *it2 << " ";
//		++it2;
//	}
//	cout << endl;
//	
//	//for (int e : il2)
//	for (auto e : il2)
//	{
//		cout << e << " ";
//	}
//	cout<< endl;
//
//	pair<string, string> kv1("sort", "����");
//	map<string, string> dict = {{"insert", "����"}, {"get","��ȡ"} };
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//
//	Date dd2 = { 2023, 11, 25 };
//	//Date dd3 = { 2023, 11, 25, 20};
//
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	double d = 2.2;
//
//	// �������ַ�����ʽ��ȡ��
//	cout << typeid(i).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	// typeid(i).name() j;
//	auto j = i;
//
//	auto ret = i * d;
//	decltype(ret) x;
//
//	// ��ret������ȥʵ����vector
//	// decltype�����Ƶ���������͡���������ǿ�����
//	// ����ģ��ʵ�Σ������ٶ������
//	vector<decltype(ret)> v;
//	v.push_back(1);
//	v.push_back(1.1);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}

//int main()
//{
//	array<int, 10> a1;
//	cout << sizeof(a1) << endl;
//	//a1[10];
//
//	vector<int> v(10, 0);
//	cout << sizeof(v) << endl;
//
//	int i = 0;
//	int j = i;
//
//	// ���¼������ǳ�������ֵ
//	10;
//	i + j;
//	fmin(i, j);
//}

//int main()
//{
//	int i = 0;
//	int j = i;
//	
//	// ��ֵ�����ܷ����ֵȡ���������ܣ�����const��ֵ���ÿ���
//	const int& r1 = 10;
//	const int& r2 = i + j;
//
//	int&& rr1 = 10;
//	int&& rr2 = i+j;
//
//	// ��ֵ�����ܷ����ֵȡ���������ܣ�������ֵ���ÿ��Ը�move(��ֵ)ȡ����
//	int&& rr3 = move(i);
//
//	return 0;
//}

namespace bit
{
	class string
	{
	public:
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
			, _capacity(_size)
		{
			//cout << "string(char* str) -- ����" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
		{
			cout << "string(const string& s) -- ���" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// �ƶ�����
		string(string&& s)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;

			swap(s);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- ���" << endl;
			/*string tmp(s);
			swap(tmp);*/
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
		}

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s)-- �ƶ���ֵ" << endl;

			swap(s);
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
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

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0; // �������������ʶ��\0
	};

	bit::string to_string(int x)
	{
		bit::string ret;
		while (x)
		{
			int val = x % 10;
			x /= 10;
			ret += ('0' + val);
		}

		reverse(ret.begin(), ret.end());

		return ret;
	}
}

int main()
{
	//bit::string s = bit::to_string(1234);

	bit::string s1("hello world");
	bit::string s2 = s1;
	bit::string s3 = move(s1);

	return 0;
}