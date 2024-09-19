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

//int main()
//{
//	B::GetInstance()->Add("sort", "����");
//	B::GetInstance()->Add("left", "���");
//	B::GetInstance()->Add("right", "�ұ�");
//	B::GetInstance()->Print();
//
//	B::GetInstance()->Add("right", "xxx");
//	B::GetInstance()->Print();
//	
//	//B::DelInstance();
//	cout << "xxxxxxxxxxx" << endl;
//
//	// ����main�����������Զ�����
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
//	// bool ���� ָ��
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

// ����ת��
// 1����������֮�䣬������Ϳ���ת�� 
// 2�����캯������������ת�����Զ������ͣ��й��캯���Ϳ���֧��
//    �Զ������� <- ��������  �Զ������� <- �Զ�������
// 3��operator type()  �������� <- �Զ�������
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
//	// �Զ������� <- ��������
//	C c1 = 11;
//	string s1 = "xxxx";
//
//	// �Զ������� <- �Զ�������
//	D d = c1;
//	list<int> lt;
//	list<int>::const_iterator it = lt.begin();
//
//	// �������� <- �Զ�������
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
		// ����������д�ģ���������_yearΪ0�������
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

// C++ IO����ʹ���������+��������صķ�ʽ
// �ܸ��õļ����Զ������ͣ������������ȡ
int main()
{
	// �Զ�ʶ�����͵ı���--��������
	// �������Ϳ���ֱ��ʹ��--��Ϊ������ostream�����Ѿ�ʵ����
	int i = 1;
	double j = 2.2;
	cout << i << endl;
	cout << j << endl;

	// �Զ�����������Ҫ�����Լ�����<< �� >>
	Date d(2022, 4, 10);
	cout << d;
	while (d)
	{
		cin >> d;
		cout << d;
	}

	return 0;
}