#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;

#include"list.h"
#include"vector.h"


//void func(const lis::list<int>& lt)
//{
//	lis::list<int>::const_reverse_iterator rit = lt.rbegin();
//	while (rit != lt.rend())
//	{
//		//*rit += 1;
//
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}

//int main()
//{
//	lis::list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(5);
//
//	lis::list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	lis::list<int>::reverse_iterator rit = lt.rbegin();
//	while (rit != lt.rend())
//	{
//		*rit += 1;
//
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	func(lt);
//
//	return 0;
//}
 
void func(const vet::vector<int>& lt)
{
	vet::vector<int>::const_reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		//*rit += 1;

		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}


int main()
{
	vet::vector<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	vet::vector<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vet::vector<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		//*rit += 1;

		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	func(lt);


	return 0;
}
