#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<vector>
using namespace std;

#include"AVLTree.h"

int main()
{
	const int N = 30000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand());
		//cout << v.back() << endl;
	}

	AVLTree<int, int> t;
	for (auto e : v)
	{

		t.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}

	cout << t.IsBalance() << endl;

	return 0;
}