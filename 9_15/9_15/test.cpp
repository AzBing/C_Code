#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>
#include<list>
using namespace std;

// ����
// ����ģʽ:��ǰ(main��������ʱ)������ʵ������
// �ŵ㣺ʵ�ּ�
// ȱ�㣺1�����ܻᵼ�½�����������2��������������������Ⱥ�˳����ô�����޷�����
// 
// ����ģʽ:��һ���õ�ʱ���ٴ������ֳ�������
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
//	A::GetInstance()->Add("sort", "����");
//	A::GetInstance()->Add("left", "���");
//	A::GetInstance()->Add("right", "�ұ�");
//	A::GetInstance()->Print();
//
//	/*A copy(*A::GetInstance());
//	copy.Print();
//
//	A::GetInstance()->Add("left", "ʣ��");
//	copy.Print();
//	A::GetInstance()->Print();*/
//
//	//*A::GetInstance() = *A::GetInstance();
//
//	return 0;
//}


// ����ģʽ:��һ���õ�ʱ���ٴ������ֳ�������
// todo:�̰߳�ȫ����
// new����������һ�㲻��Ҫ�ͷţ����������������ͷ���Դ
// �����Ҫ��һЩ����������־û�����ô��������gc��static����㶨
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
		// �־û���Ҫ�������д���ļ�
		cout << "����д���ļ�" << endl;
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
	B::GetInstance()->Add("sort", "����");
	B::GetInstance()->Add("left", "���");
	B::GetInstance()->Add("right", "�ұ�");
	B::GetInstance()->Print();

	B::GetInstance()->Add("right", "xxx");
	B::GetInstance()->Print();
	
	//B::DelInstance();
	cout << "xxxxxxxxxxx" << endl;

	// ����main�����������Զ�����

	return 0;
}

