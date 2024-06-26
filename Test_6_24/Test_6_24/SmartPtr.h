#pragma once

template<class T>
class SmartPtr
{
public:
	// RAII
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "~SmartPtr()->" << _ptr << endl;

		delete _ptr;
	}

	// ��ָ��һ��
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

namespace Ptr
{
	// C++98
	// ����Ȩת�ƣ����һ���������������Դ�����������󶼱��ÿ�
	// �ܶ๫˾����ȷ�涨�ˣ���Ҫ�����
	template<class T>
	class auto_ptr
	{
	public:
		// RAII
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete->" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		// ap2(ap1)
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		// ��ָ��һ��
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};


}