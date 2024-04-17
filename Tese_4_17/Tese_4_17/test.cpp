#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include<string>

//int main()
//{
//	string file("string.cpp.tar.zip");
//	size_t pos = file.rfind('.');
//	if (pos != string::npos)
//	{
//		//string suffix = file.substr(pos, file.size() - pos);
//		string suffix = file.substr(pos);
//		cout << suffix << endl;
//	}
//
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//	}
//
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;
//
//
//	return 0;
//}

//int main()
//{
//	std::string str("Please, replace the vowels in this sentence by asterisks.");
//	std::size_t found = str.find_first_of("abcdv");
//	while (found != std::string::npos)
//	{
//		str[found] = '*';
//		found = str.find_first_of("abcdv", found + 1);
//	}
//
//	std::cout << str << '\n';
//
//	string s1("hello world");
//	string s2("hello world");
//	s1 == s2;
//	s1 == "hello world";
//	"hello world" == s1;
//
//	return 0;
//}



int main() {
	//cin >> i >> j;
	string str;
	//cin >> str;
	getline(cin, str);
	size_t pos = str.rfind(' ');
	if (pos != string::npos)
	{
		cout << str.size() - pos - 1 << endl;
	}
	else
	{
		cout << str.size() << endl;
	}

	return 0;
}

