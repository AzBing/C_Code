#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include"RBTree.h"
#include"MyMap.h"
#include"MySet.h"

void test_set()
{
	bit::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(2);
	s.insert(0);
	s.insert(10);
	s.insert(5);
}

void test_map()
{
	bit::map<string, string> dict;
	dict.insert(make_pair("sort", "ÅÅĞò"));
	dict.insert(make_pair("sort", "ÕûÀí"));
	dict.insert(make_pair("left", "×ó±ß"));
	dict.insert(make_pair("right", "ÓÒ±ß"));

}

int main()
{
	test_map();
	test_set();

	return 0;
}


