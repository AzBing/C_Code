#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include<mutex>
#include<thread>
#include<chrono>

//#ifdef _WIN32
//CreateThread()
//#else
//pthread_create()
//#endif

//void Print1(size_t n, const string& s, mutex& m, int& rx)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		m.lock();
//
//		cout <<this_thread::get_id()<<s<<":" << i << endl;
//		++rx;
//
//		m.unlock();
//
//		this_thread::sleep_for(chrono::milliseconds(300));
//	}
//}
//
//int main()
//{
//	mutex mtx;
//	int x = 0;
//	thread t1(Print1, 100,  "线程1", ref(mtx), ref(x));
//	thread t2(Print1, 200, "线程2", ref(mtx), ref(x));
//
//	//thread t3(t1);
//
//	cout <<"线程1：" << t1.get_id() << endl;
//	cout <<"线程2："<< t2.get_id() << endl;
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}

//void Print2(size_t n, const string& s)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		cout << this_thread::get_id() << s << ":" << i << endl;
//	}
//}
//
//int main()
//{
//	size_t n;
//	cin >> n;
//
//	//创建n个线程执行Print
//	vector<thread> vthd(n);
//	size_t j = 0;
//	for (auto& thd : vthd)
//	{
//		// 移动赋值
//		thd = thread(Print2, 10,  "线程" + to_string(j++));
//	}
//
//	for (auto& thd : vthd)
//	{
//		thd.join();
//	}
//
//	thread t1(Print1, 100, 1, "线程1");
//	thread t2(move(t1));
//
//	t2.join();
//
//	return 0;
//}

// thread + lambda
//int main()
//{
//	size_t n1 = 0;
//	size_t n2 = 0;
//	cin >> n1 >> n2;
//	mutex mtx;
//	
//
//	size_t x = 0;
//
//	thread t1([n1, &x, &mtx]() {
//		for (size_t i = 0; i < n1; i++)
//		{
//			mtx.lock();
//			++x;
//			mtx.unlock();
//			//cout << this_thread::get_id() << ":" << i << endl;
//		}
//	});
//
//	thread t2([n2, &x, &mtx]() {
//		for (size_t i = 0; i < n2; i++)
//		{
//			mtx.lock();
//			++x;
//			mtx.unlock();
//			//cout << this_thread::get_id() << ":" << i << endl;
//		}
//	});
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}

//void func(int i)
//{
//	// mutex  lock时就死锁了
//	//....
//
//	func(i - 1);
//}

void func()
{
	srand(time(0));
	if (rand() % 2 == 0)
	{
		throw exception("异常");
	}
	else
	{
		cout << "func()" << endl;
	}
}

// RAII
template<class Lock>
class LockGuard
{
public:
	LockGuard(Lock& lk)
		:_lk(lk)
	{
		_lk.lock();
	}

	~LockGuard()
	{
		_lk.unlock();
	}
private:
	Lock& _lk;
};

//lock_guard
//unique_lock 
//a、可以跟time_mutex配合使用
//b、支持手动解锁，再加锁
// RTTI

//int main()
//{
//	mutex mtx;
//	size_t n1 = 10000;
//	size_t n2 = 10000;
//	
//	size_t x = 0;
//
//	thread t1([n1, &x, &mtx]() {
//		try {
//			for (size_t i = 0; i < n1; i++)
//			{
//				//mtx.lock();
//				//LockGuard<mutex> lg(mtx);
//				lock_guard<mutex> lg(mtx);
//
//				++x;
//				func();
//
//				//mtx.unlock();
//			}
//		}
//		catch (const exception& e)
//		{
//			cout << e.what() << endl;
//		}
//	});
//	
//	thread t2([n2, &x, &mtx]() {
//		for (size_t i = 0; i < n2; i++)
//		{
//			mtx.lock();
//			++x;
//			mtx.unlock();
//		}
//	});
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}

// t1打印奇数
// t2打印偶数
// 交替打印
int main()
{
	mutex mtx;
	int x = 1;
	condition_variable cv;
	bool flag = false;


	// 如果保证t1先运行 condition_variable+flag
	// 交替运行
	thread t1([&]() {
		for (size_t i = 0; i < 10; i++)
		{
			unique_lock<mutex> lock(mtx);
			if (flag)
				cv.wait(lock);

			cout << this_thread::get_id() << ":" << x << endl;
			++x;

			flag = true;

			cv.notify_one(); // t1notify_one的时候 t2还没有wait
		}
		});


	thread t2([&]() {
		for (size_t i = 0; i < 10; i++)
		{
			unique_lock<mutex> lock(mtx);
			if (!flag)
				cv.wait(lock);

			cout << this_thread::get_id() << ":" << x << endl;
			++x;
			flag = false;

			cv.notify_one();
		}
		});

	t1.join();
	t2.join();

	return 0;
}