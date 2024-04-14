#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//class string
//{
//private:
//	char* _ptr;
//	char _buf[16];
//	size_t _size;
//	size_t _capacity;
//};

//int main()
//{
//  1.5倍扩容
//	string s;
//
//	//cout << sizeof(s) << endl;
//	s.reserve(100);
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	cout << "capacity changed: " << sz << '\n';
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}


//int main()
//{
//	// 扩容
//	string s1("hello world");
//	s1.reserve(100);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	// 扩容+初始化
//	string s2("hello world");
//	s2.resize(100, 'x');
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//	// 比size小，删除数据，保留前5个
//	s2.resize(5);
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto ch : s1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

class A
{
public:
    A(int a)
        :_a1(a)
        , _a2(_a1)
    {}

    void Print()
    {
        cout << _a1 << " " << _a2 << endl;
    }
private:
    int _a2;
    int _a1;
};
int main() {
    A aa(1);
    aa.Print();
}