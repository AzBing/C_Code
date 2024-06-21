#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<array>
#include<algorithm>
#include<functional>
using namespace std;

#include<assert.h>


struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价
	//...

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};


struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//	//sort(v.begin(), v.end(), ComparePriceLess());
//	//sort(v.begin(), v.end(), ComparePriceGreater());
//
//	//sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->bool {return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._evaluate < g2._evaluate; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._evaluate > g2._evaluate; });
//
//	return 0;
//}

int main()
{
	// 匿名函数对象
	// class <lambda_ba37a3eb9b8e2495e3aae6ef76d9eed2>
	// <lambda_uuid>
	auto f1 = [](int x)->int {cout << x << endl; return 0; };
	f1(1);
	cout << typeid(f1).name() << endl;

	//class <lambda_8c5f46db939004e569f343c4f7d08c27>
	auto f2 = [](int x)
	{
		cout << x << endl;
		return 0;
	};
	f2(2);

	//f1 = f2;

	cout << typeid(f2).name() << endl;

	ComparePriceGreater f3;
	cout << typeid(f3).name() << endl;

	return 0;
}

//int main()
//{
//	int x = 0, y = 1;
//	cout << x << " " << y << endl;
//
//	auto f1 = [](int& r1, int& r2) {
//		int tmp = r1;
//		r1 = r2;
//		r2 = tmp;
//	};
//
//	f1(x, y);
//	cout << x << " " << y << endl << endl;
//
//
//	cout << x << " " << y << endl;
//	cout << &x << ":" << &y << endl;
//
//	// <lambda_uuid>
//	auto f2 = [x, y]() mutable {
//		cout << &x << ":" << &y << endl;
//
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	f2();
//	cout << x << " " << y << endl << endl;
//
//	cout << x << " " << y << endl;
//	cout << &x << ":" << &y << endl;
//	auto f3 = [&x, &y]() {
//		cout << &x << ":" << &y << endl;
//
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	f3();
//	cout << x << " " << y << endl << endl;
//	return 0;
//}

//class AA
//{
//public:
//	void func()
//	{
//		/*auto f1 = [this]() {
//			cout << a1 << endl;
//			cout << a2 << endl;
//		};*/
//		auto f1 = [=]() {
//			cout << a1 << endl;
//			cout << a2 << endl;
//		};
//
//		f1();
//	}
//private:
//	int a1 = 1;
//	int a2 = 1;
//};
//
//
//int main()
//{
//	int x = 0, y = 1, z = 2;
//
//	auto f1 = [=, &z]() {
//		z++;
//
//		cout << x << endl;
//		cout << y << endl;
//		cout << z << endl;
//	};
//
//	f1();
//
//	return 0;
//}


