#pragma once
namespace lt
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T>
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

		T& operator*()
		{
			return _node->_data;
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

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T> iterator;

		iterator begin()
		{
			//return iterator(_head->_next);
			return _head->_next;
		}

		iterator end()
		{
			//return iterator(_head->_next);
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

		// lt2(lt1)
		//list(const list<T>& lt)
		list(list<T>& lt)
		{
			empty_init();
			for (auto e : lt)
			{
				push_back(e);
			}
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(x);

			Node* prev = cur->_prev;

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;

			newnode->_next = cur;
			cur->_prev = newnode;

			++_size;

			return iterator(newnode);
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

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it += 20;

			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

	}
}

