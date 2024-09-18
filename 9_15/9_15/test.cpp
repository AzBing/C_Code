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

int main()
{
	B::GetInstance()->Add("sort", "排序");
	B::GetInstance()->Add("left", "左边");
	B::GetInstance()->Add("right", "右边");
	B::GetInstance()->Print();

	B::GetInstance()->Add("right", "xxx");
	B::GetInstance()->Print();
	
	//B::DelInstance();
	cout << "xxxxxxxxxxx" << endl;

	// 期望main函数结束后自动调用

	return 0;
}

