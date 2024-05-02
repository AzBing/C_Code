#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <list>
using namespace std;

//int main()
//{
//	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
//	int n = sizeof(ar) / sizeof(int);
//	vector<int> v(ar, ar + n);
//	vector<int>::iterator it = v.begin();
//
//	while (it != v.end())
//	{
//
//		if (*it != 0)
//		{
//			cout << *it;
//		}
//		else
//		{
//			v.erase(it);
//		}
//		it++;
//	}
//	return 0;
//}
int main()
{
	int array[] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof(array) / sizeof(int);
	list<int> mylist(array, array + n);
	auto it = mylist.begin();

	while (it != mylist.end())
	{
		if (*it != 0)
			cout << *it << " ";
		else
			it = mylist.erase(it);
		++it;

	}
	return 0;
}