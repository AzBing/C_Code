#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include<mutex>
#include<thread>
#include<chrono>


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
//int main()
//{
//	mutex mtx;
//	int x = 1;
//	condition_variable cv;
//	bool flag = false;
//
//	// 如果保证t1先运行 condition_variable+flag
//	// 交替运行
//	thread t1([&]() {
//		for (size_t i = 0; i < 10; i++)
//		{
//			unique_lock<mutex> lock(mtx);
//			while (flag)
//				cv.wait(lock);
//
//			cout << this_thread::get_id() << ":" << x << endl;
//			++x;
//
//			flag = true;
//
//			cv.notify_one(); // t1notify_one的时候 t2还没有wait
//		}
//	});
//
//
//	thread t2([&]() {
//		for (size_t i = 0; i < 10; i++)
//		{
//			unique_lock<mutex> lock(mtx);
//			while(!flag)
//				cv.wait(lock);
//
//			cout << this_thread::get_id()<<":" << x << endl;
//			++x;
//			flag = false;
//
//			cv.notify_one();
//		}
//	});
//	
//	t1.join();
//	t2.join();
//		
//	return 0;
//}

//int main()
//{
//	size_t n1 = 10000;
//	size_t n2 = 10000;
//	//cin >> n1 >> n2;
//	mutex mtx;
//
//	size_t x = 0;
//
//	thread t1([n1, &x, &mtx]() {
//		for (size_t i = 0; i < n1; i++)
//		{
//			mtx.lock();
//			++x;
//			mtx.unlock();
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
//
//	return 0;
//}

//int main()
//{
//	size_t n1 = 10000000;
//	size_t n2 = 10000000;
//	//cin >> n1 >> n2;
//	mutex mtx;
//
//	size_t x = 0;
//
//	thread t1([n1, &x, &mtx]() {
//		for (size_t i = 0; i < n1; i++)
//		{
//			while (!mtx.try_lock())
//				this_thread::yield();
//			//mtx.lock();
//
//			++x;
//			mtx.unlock();
//		}
//		});
//
//	thread t2([n2, &x, &mtx]() {
//		for (size_t i = 0; i < n2; i++)
//		{
//			while (!mtx.try_lock())
//				this_thread::yield();
//			//mtx.lock();
//
//			++x;
//			mtx.unlock();
//		}
//		});
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//
//	return 0;
//}

//int main()
//{
//	size_t n1 = 10000000;
//	size_t n2 = 10000000;
//	//cin >> n1 >> n2;
//	mutex mtx;
//
//	atomic<bool> flag = true;
//
//	atomic<size_t> x = 0;
//	//size_t x = 0;
//	++x;
//
//	thread t1([&]() {
//		for (size_t i = 0; i < n1; i++)
//		{
//			++x;
//		}
//		});
//
//	thread t2([&]() {
//		for (size_t i = 0; i < n2; i++)
//		{
//			++x;
//		}
//		});
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//	//printf("%d\n", x.load());
//
//
//	return 0;
//}

int main()
{
	size_t n1 = 10000;
	size_t n2 = 10000;
	//cin >> n1 >> n2;
	mutex mtx;

	atomic<size_t> x = 0;

	thread t1([&]() {
		for (size_t i = 0; i < n1; i++)
		{
			size_t old, newval;
			do
			{
				old = x;
				newval = old + 2;
			} while (!atomic_compare_exchange_weak(&x, &old, newval));
		}
		});

	thread t2([&]() {
		for (size_t i = 0; i < n2; i++)
		{
			size_t old, newval;
			do
			{
				old = x;
				newval = old + 2;
			} while (!atomic_compare_exchange_weak(&x, &old, newval));
		}
		});

	t1.join();
	t2.join();

	cout << x << endl;

	return 0;
}