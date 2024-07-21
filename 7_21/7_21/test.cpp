#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

int Add(int left, int right)
{
    return left + right;
}

// 通用加法函数
template<class T>
T Add(T left, T right)
{
    return left + right;
}

template<class T>
T* func(int n)
{
    return new T[n];
}

//int main()
//{
//	int x = 0, y = 1;
//	swap(x, y);
//
//	double a = 1.1, b = 2.2;
//	swap(a, b);
//
//	cout << Add(x, y) << endl;
//
//	cout << Add<int>(x, y) << endl;
//
//	int* ptr = func<int>(10);
//
//	return 0;
//}

template<class T>
class Vector
{
public:
    Vector(size_t capacity = 10)
        : _pData(new T[capacity])
        , _size(0)
        , _capacity(capacity)
    {}

    // 使用析构函数演示：在类中声明，在类外定义。
    ~Vector();

    void PushBack(const T& data);
    void PopBack();
    // ...

    size_t Size() { return _size; }

    T& operator[](size_t pos)
    {
        //assert(pos < _size);
        return _pData[pos];
    }

private:
    T* _pData;
    size_t _size;
    size_t _capacity;
};

template<class T>
Vector<T>::~Vector()
{
    delete[] _pData;
    _pData = nullptr;
}

// 类名 ： Vector
// 类型 ： Vector<T>

//int main()
//{
//    //Vector<int> v;
//
//    vector<int> v;
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(1);
//    v.reserve(100);
//
//    list<int> lt;
//    lt.push_back(1);
//
//
//
//    return 0;
//}

void test_string1()
{
    string s1;
    string s2("hello");

    cin >> s1;
    cout << s1 << endl;
    cout << s2 << endl;

    //cin >> s2;
    //cout << s2 << endl;

    //char str[1600];
    //scanf

    // strcat
    string ret1 = s1 + s1;
    cout << ret1 << endl;

    string ret2 = s1 + "我来了";
    cout << ret2 << endl;
}

void test_string2()
{
    string s1("hello world");
    string s2 = "hello world";

    // 遍历string
    for (size_t i = 0; i < s1.size(); i++)
    {
        // 读
        cout << s1[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < s1.size(); i++)
    {
        // 写
        s1[i]++;
    }
    cout << s1 << endl;

    // 迭代器
    string::iterator it = s1.begin();
    //while (it < s1.end())  // 这里可以但是不建议
    while (it != s1.end())  // 推荐玩法，通用
    {
        // 读
        cout << *it << " ";
        ++it;
    }
    cout << endl;


    it = s1.begin();
    while (it != s1.end())
    {
        // 写
        *it = 'a';
        ++it;
    }
    cout << endl;
    cout << s1 << endl;

    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    list<int>::iterator lit = lt.begin();
    while (lit != lt.end())
    {
        cout << *lit << " ";
        ++lit;
    }
    cout << endl;
}

int main()
{
    test_string2();

    return 0;
}