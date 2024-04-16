#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void Func(const string& s)
{
	// �����Ͷ����������ݣ�����д
	string::const_iterator it = s.begin();
	while (it != s.end())
	{
		//*it += 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//string::const_reverse_iterator rit = s.rbegin();
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

//int main()
//{
//	// �����Ͷ�д����������
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		*it += 1;
//
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	
//	string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	Func(s1);
//
//	try
//	{
//		s1[100];
//		//s1.at(100);
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	
//
//	return 0;
//}

int main()
{
	// insert/erase���Ƽ�����ʹ�ã������þ�����
	// ��Ϊ���ǿ��ܶ�����ҪŲ�����ݣ�Ч�ʵ���
	string s1("world");
	s1.insert(0, "hello");
	cout << s1 << endl;

	//s1.insert(5, 1, ' ');
	//s1.insert(5, " ");
	s1.insert(s1.begin()+5, ' ');
	cout << s1 << endl;

	string s2("hello world");
	//s2.erase(5, 1);
	s2.erase(s2.begin() + 5);
	cout << s2 << endl;

	//s2.erase(5, 30);
	s2.erase(5);
	cout << s2 << endl;

	return 0;
}