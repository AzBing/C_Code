#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>
#include<vector>
#include<map>
using namespace std;

// ����ģʽ:һ��ʼ(main����֮ǰ)�ʹ�����������
// 1��������������ʼ�����ݺܶ࣬Ӱ�������ٶ�
// 2��������������࣬������������ϵ�� 
// ������A B���������࣬Ҫ��A�ȴ�����B�ٴ�����B�ĳ�ʼ����������A
namespace hungry
{
	class Singleton
	{
	public:
		// 2���ṩ��ȡ��������Ľӿں���
		static Singleton& GetInstance()
		{
			return _sinst;
		}

		void func();

		void Add(const pair<string, string>& kv)
		{
			_dict[kv.first] = kv.second;
		}

		void Print()
		{
			for (auto& e : _dict)
			{
				cout << e.first << ":" << e.second << endl;
			}
			cout << endl;
		}

	private:
		// 1�����캯��˽��
		Singleton()
		{
			// ...
		}

		// 3��������
		Singleton(const Singleton& s) = delete;
		Singleton& operator=(const Singleton& s) = delete;

		map<string, string> _dict;
		// ...

		static Singleton _sinst;
	};

	Singleton Singleton::_sinst;

	void Singleton::func()
	{
		// 
		_dict["xxx"] = "1111";
	}
}

namespace lazy
{
	class Singleton
	{
	public:
		// 2���ṩ��ȡ��������Ľӿں���
		static Singleton& GetInstance()
		{
			if (_psinst == nullptr)
			{
				// ��һ�ε���GetInstance��ʱ�򴴽���������
				_psinst = new Singleton;
			}

			return *_psinst;
		}

		// һ�㵥�������ͷš�
		// ���ⳡ����1����;��Ҫ��ʾ�ͷ�  2���������ʱ����Ҫ��һЩ���⶯������־û���
		static void DelInstance()
		{
			if (_psinst)
			{
				delete _psinst;
				_psinst = nullptr;
			}
		}

		void Add(const pair<string, string>& kv)
		{
			_dict[kv.first] = kv.second;
		}

		void Print()
		{
			for (auto& e : _dict)
			{
				cout << e.first << ":" << e.second << endl;
			}
			cout << endl;
		}

		class GC
		{
		public:
			~GC()
			{
				lazy::Singleton::DelInstance();
			}
		};

	private:
		// 1�����캯��˽��
		Singleton()
		{
			// ...
		}

		~Singleton()
		{
			cout << "~Singleton()" << endl;

			// map����д���ļ���
			FILE* fin = fopen("map.txt", "w");
			for (auto& e : _dict)
			{
				fputs(e.first.c_str(), fin);
				fputs(":", fin);
				fputs(e.second.c_str(), fin);
				fputs("\n", fin);
			}
		}

		// 3��������
		Singleton(const Singleton& s) = delete;
		Singleton& operator=(const Singleton& s) = delete;

		map<string, string> _dict;
		// ...

		static Singleton* _psinst;
		static GC _gc;
	};

	Singleton* Singleton::_psinst = nullptr;
	Singleton::GC Singleton::_gc;
}

int main()
{
	//Singleton s1;
	//Singleton s2;

	cout << &lazy::Singleton::GetInstance() << endl;
	cout << &lazy::Singleton::GetInstance() << endl;
	cout << &lazy::Singleton::GetInstance() << endl;

	//Singleton copy(Singleton::GetInstance());

	lazy::Singleton::GetInstance().Add({ "xxx", "111" });
	lazy::Singleton::GetInstance().Add({ "yyy", "222" });
	lazy::Singleton::GetInstance().Add({ "zzz", "333" });
	lazy::Singleton::GetInstance().Add({ "abc", "333" });

	lazy::Singleton::GetInstance().Print();

	//lazy::Singleton::DelInstance();

	lazy::Singleton::GetInstance().Add({ "abc", "444" });
	lazy::Singleton::GetInstance().Print();

	//lazy::Singleton::DelInstance();

	return 0;
}
