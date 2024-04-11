#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)
//		: _pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//
//	// 使用析构函数演示：在类中声明，在类外定义。
//	~Vector();
//
//	void PushBack(const T& data);
//	void PopBack();
//		// ...
//
//		size_t Size() { return _size; }
//
//	T& operator[](size_t pos)
//	{
//		assert(pos < _size);
//		return _pData[pos];
//	}
//
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//
//template<class T>
//Vector<T>::~Vector()
//{
//	delete[] _pData;
//	_pData = nullptr;
//	_size = _capacity = 0;
//}
//
//int main()
//{
//	Vector<int> v1;
//
//	return 0;
//}

int main()
{
	char str1[] = "apple";

	char str2[] = "哈哈";
	cout << sizeof(str2) << endl;

	str2[3]++;
	cout << str2 << endl;

	str2[3]++;
	cout << str2 << endl;

	str2[3]--;
	cout << str2 << endl;

	str2[3]--;
	cout << str2 << endl;

	str2[3]--;
	cout << str2 << endl;

	return 0;
}