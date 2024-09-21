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
//	thread t1(Print1, 100,  "�߳�1", ref(mtx), ref(x));
//	thread t2(Print1, 200, "�߳�2", ref(mtx), ref(x));
//
//	//thread t3(t1);
//
//	cout <<"�߳�1��" << t1.get_id() << endl;
//	cout <<"�߳�2��"<< t2.get_id() << endl;
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
//	//����n���߳�ִ��Print
//	vector<thread> vthd(n);
//	size_t j = 0;
//	for (auto& thd : vthd)
//	{
//		// �ƶ���ֵ
//		thd = thread(Print2, 10,  "�߳�" + to_string(j++));
//	}
//
//	for (auto& thd : vthd)
//	{
//		thd.join();
//	}
//
//	thread t1(Print1, 100, 1, "�߳�1");
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
//	// mutex  lockʱ��������
//	//....
//
//	func(i - 1);
//}

void func()
{
	srand(time(0));
	if (rand() % 2 == 0)
	{
		throw exception("�쳣");
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
//a�����Ը�time_mutex���ʹ��
//b��֧���ֶ��������ټ���
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

// t1��ӡ����
// t2��ӡż��
// �����ӡ
int main()
{
	mutex mtx;
	int x = 1;
	condition_variable cv;
	bool flag = false;


	// �����֤t1������ condition_variable+flag
	// ��������
	thread t1([&]() {
		for (size_t i = 0; i < 10; i++)
		{
			unique_lock<mutex> lock(mtx);
			if (flag)
				cv.wait(lock);

			cout << this_thread::get_id() << ":" << x << endl;
			++x;

			flag = true;

			cv.notify_one(); // t1notify_one��ʱ�� t2��û��wait
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