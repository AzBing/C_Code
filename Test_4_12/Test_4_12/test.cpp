#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3 = "hello world";
//	string s4(s3, 6, 3);
//	cout << s4 << endl;
//	string s5(s3, 6, 13);
//	cout << s5 << endl;
//	string s6(s3, 6);
//	cout << s6 << endl;
//	string s7("hello world", 5);
//	cout << s7 << endl;
//	string s8(10, '*');
//	cout << s8 << endl;
//
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		s2[i]++;
//	}
//
//	cout << s2 << endl;
//
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		cout << s2[i] << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.max_size() << endl;
//	cout << s1.capacity() << endl;
//
//	return 0;
//}
//
int main()
{
	string s1("hello");
	s1.push_back(' ');
	s1.push_back('!');
	cout << s1 << endl;

	s1.append("world");
	cout << s1 << endl;

	s1 += ' ';
	s1 += '!';
	s1 += "world";
	cout << s1 << endl;
}

