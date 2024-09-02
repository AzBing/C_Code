#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<set>
#include<bitset>

using namespace std;
#include "bit_set.h"

int main()
{
	bit::bit_set<100> bs;
	bs.set(40);
	bs.set(39);
	cout << bs.test(39) << endl;
	cout << bs.test(40) << endl;


	return 0;
}
