#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

#include "bitset.h"

int main()
{

	std:bitset<100> bs;
	bs.set(40);
	bs.set(39);

	cout << bs.test(38) << endl;
	cout << bs.test(39) << endl;
	cout << bs.test(40) << endl;
	cout << bs.test(41) << endl;
	cout << bs.test(42) << endl << endl;

	bs.reset(40);

	cout << bs.test(38) << endl;
	cout << bs.test(39) << endl;
	cout << bs.test(40) << endl;
	cout << bs.test(41) << endl;
	cout << bs.test(42) << endl << endl;

	return 0;
}