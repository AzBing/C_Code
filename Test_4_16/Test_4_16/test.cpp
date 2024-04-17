#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int main()
//{
//	//string s1("hello world");
//	//s1.replace(5, 1, "%%d");
//	//cout << s1 << endl;
//
//	//string s1("hello world i love you");
//	//size_t num = 0;
//	//for (auto ch : s1)
//	//{
//	//	if (ch == ' ')
//	//		++num;
//	//}
//	//// 提前开空间，避免repalce时扩容
//	//s1.reserve(s1.size() + 2 * num);
//
//	//size_t pos = s1.find(' ');
//	//while (pos != string::npos)
//	//{
//	//	s1.replace(pos, 1, "%20");
//	//	pos = s1.find(' ', pos + 3);
//	//}
//	//cout << s1 << endl;
//

//	string s1("hello world i love you");
//	string newStr;
//	size_t num = 0;
//	for (auto ch : s1)
//	{
//		if (ch == ' ')
//			++num;
//	}
//	// 提前开空间，避免repalce时扩容
//	newStr.reserve(s1.size() + 2 * num);
//
//	for (auto ch : s1)
//	{
//		if (ch != ' ')
//			newStr += ch;
//		else
//			newStr += "%20";
//	}
//
//	s1 = newStr;
//	cout << newStr << endl;
//
//	string s2("xxxxx");
//	s1.swap(s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//
//	swap(s1, s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//}

//int main()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;
//	cout << (void*)s1.c_str() << endl;
//
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;
//	s1 += '\0';
//	s1 += '\0';
//	s1 += "xxxxx";
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;
//
//	string filename("test.cpp");
//	FILE* fout = fopen(filename.c_str(), "r");
//	if (fout == nullptr)
//		perror("fopen fail");
//
//	char ch = fgetc(fout);
//	while (ch != EOF)
//	{
//		cout << ch;
//		ch = fgetc(fout);
//	}
//
//	fclose(fout);
//
//	return 0;
//}


