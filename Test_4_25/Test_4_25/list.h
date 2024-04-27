#pragma once
namespace ls
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
	class list
	{
		typedef list_node<T> Node;
	public:
		
		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			tail->_next = newnode;
			newnode->_prev = tail;

			newnode->_next = _head;
			_head->_prev = newnode;
		}


	private:
		Node* _head;
	};
	void test_list1()
	{
		list<int> s1;
		s1.push_back(1);
		s1.push_back(2);
		s1.push_back(3);
		s1.push_back(4);
		s1.push_back(5);

	}
}
