#pragma once

namespace lis
{
	template <class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
		list_node(const T& x = T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};

	template <class T>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T> self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node) 
		{}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;

			return tmp;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s)
		{
			return _node == s._node;
		}

	};

	//·Çconstµü´úÆ÷
	template <class T>
	class list
	{
		typedef list_node<T> Node;

	public:
		typedef __list_iterator<T> iterator;

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		list(list<T>& lt)
		{
			empty_init();
			for (auto li : lt)
			{
				push_back(li);
			}
		}

		/*list<int>& iterator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				clear();
				for (auto li : lt)
				{
					push_back(li);
				}
			}
			return this;
		}*/

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);

			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator lt = begin();
			while (lt != end())
			{
				lt = erase(lt);
			}
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			insert(begin());
		}

		void pop_back()
		{
			erase(--end());
		}

		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(x);
			Node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;

			newnode->_next = cur;
			cur->_prev = newnode;
			++_size;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* next = cur->_next;
			Node* prev = cur->_prev;

			delete cur;
			prev->_next = next;
			next->_prev = prev;
			--_size;

			return iterator(next);
		}

		size_t size()
		{
			return _size;
		}

	private:
		Node* _head;
		size_t _size;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		lt.push_back(7);
		lt.push_back(8);

		list<int>::iterator ls = lt.begin();
		while (ls != lt.end())
		{
			cout << *ls << " ";
			++ls;
		}
		cout << endl;
	}

	void test_list2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);

		list<int> lt2(lt);
		for (auto ch : lt)
		{
			cout << ch << " ";
		}
		cout << endl;

		for (auto ch : lt2)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		lt1.push_back(5);
		lt1.push_back(6);
		
		list<int> lt2;
		lt2.push_back(10);
		lt2.push_back(20);
		lt2.push_back(30);
		lt2.push_back(40);
		lt2.push_back(50);
		lt2.push_back(60);
		lt1 = lt2;


		for (auto ch : lt1)
		{
			cout << ch << " ";
		}
		cout << endl;

		for (auto ch : lt2)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

}