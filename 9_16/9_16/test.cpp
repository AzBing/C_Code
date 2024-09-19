#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>
#include<list>
using namespace std;

// 单例
// 饿汉模式:提前(main函数启动时)创建好实例对象
// 优点：实现简单
// 缺点：1、可能会导致进程启动慢、2、如果两个单例有启动先后顺序，那么饿汉无法控制
// 
// 懒汉模式:第一次用的时候再创建（现吃现做）
class A
{
public:
	static A* GetInstance()
	{
		return &_inst;
	}

	void Add(const string& key, const string& value)
	{
		_dict[key] = value;
	}

	void Print()
	{
		for (auto& kv : _dict)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}
private:
	A()
	{}

	A(const A& aa) = delete;
	A& operator=(const A& aa) = delete;

	map<string, string> _dict;
	int _n = 0;

	static A _inst;
};

A A::_inst;

//int main()
//{
//	//A aa1;
//	//A aa2;
//
//	A::GetInstance()->Add("sort", "排序");
//	A::GetInstance()->Add("left", "左边");
//	A::GetInstance()->Add("right", "右边");
//	A::GetInstance()->Print();
//
//	/*A copy(*A::GetInstance());
//	copy.Print();
//
//	A::GetInstance()->Add("left", "剩余");
//	copy.Print();
//	A::GetInstance()->Print();*/
//
//	//*A::GetInstance() = *A::GetInstance();
//
//	return 0;
//}


// 懒汉模式:第一次用的时候再创建（现吃现做）
// todo:线程安全问题
// new的懒汉对象一般不需要释放，进程正常结束会释放资源
// 如果需要做一些动作，比如持久化，那么可以利用gc类static对象搞定
class B
{
public:
	static B* GetInstance()
	{
		if (_inst == nullptr)
		{
			_inst = new B;
		}

		return _inst;
	}

	void Add(const string& key, const string& value)
	{
		_dict[key] = value;
	}

	void Print()
	{
		for (auto& kv : _dict)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}

	static void DelInstance()
	{
		if (_inst)
		{
			delete _inst;
			_inst = nullptr;
		}
	}

private:
	B()
	{}

	~B()
	{
		// 持久化：要求把数据写到文件
		cout << "数据写到文件" << endl;
	}

	B(const B& aa) = delete;
	B& operator=(const B& aa) = delete;

	map<string, string> _dict;
	int _n = 0;

	static B* _inst;

	class gc
	{
	public:
		~gc()
		{
			DelInstance();
		}
	};

	static gc _gc;
};

B* B::_inst = nullptr;
B::gc B::_gc;

//int main()
//{
//	B::GetInstance()->Add("sort", "排序");
//	B::GetInstance()->Add("left", "左边");
//	B::GetInstance()->Add("right", "右边");
//	B::GetInstance()->Print();
//
//	B::GetInstance()->Add("right", "xxx");
//	B::GetInstance()->Print();
//	
//	//B::DelInstance();
//	cout << "xxxxxxxxxxx" << endl;
//
//	// 期望main函数结束后自动调用
//
//	return 0;
//}

//int main()
//{
//
//
//	return 0;
//}

//int main()
//{
//	ostream out(nullptr);
//	cerr << "xxxx" << endl;
//	clog << "yyyy" << endl;
//
//	cout.put(48);
//
//	// bool 整形 指针
//	string s1;
//	// istream& operator>> (istream& is, string& str);
//	//while (cin>>s1)
//	while (operator>>(cin, s1))
//	{
//		cout << s1 << endl;
//	}
//
//	return 0;
//}

// 类型转换
// 1、内置类型之间，相近类型可以转换 
// 2、构造函数，其他类型转换成自定义类型，有构造函数就可以支持
//    自定义类型 <- 内置类型  自定义类型 <- 自定义类型
// 3、operator type()  内置类型 <- 自定义类型
class C
{
public:
	C(int x)
	{}
};

class D
{
public:
	D(const C& c)
	{}
};

class E
{
public:
	operator int()
	{
		// ...
		return 0;
	}
};

//int main()
//{
//	int* p = nullptr;
//	int i = (int)p;
//
//	// 自定义类型 <- 内置类型
//	C c1 = 11;
//	string s1 = "xxxx";
//
//	// 自定义类型 <- 自定义类型
//	D d = c1;
//	list<int> lt;
//	list<int>::const_iterator it = lt.begin();
//
//	// 内置类型 <- 自定义类型
//	E e;
//	int x = e;
//	cout << x << endl;
//
//	return 0;
//}

class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	operator bool()
	{
		// 这里是随意写的，假设输入_year为0，则结束
		if (_year == 0)
			return false;
		else
			return true;
	}
private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;
	return out;
}

// C++ IO流，使用面向对象+运算符重载的方式
// 能更好的兼容自定义类型，流插入和流提取
int main()
{
	// 自动识别类型的本质--函数重载
	// 内置类型可以直接使用--因为库里面ostream类型已经实现了
	int i = 1;
	double j = 2.2;
	cout << i << endl;
	cout << j << endl;

	// 自定义类型则需要我们自己重载<< 和 >>
	Date d(2022, 4, 10);
	cout << d;
	while (d)
	{
		cin >> d;
		cout << d;
	}

	return 0;
}