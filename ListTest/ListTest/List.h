#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once

#pragma once
#include<assert.h>
namespace cgc
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;
		ListNode(const T& data = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(data)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
		Node* _node;
		ListIterator(Node* node)
			:_node(node)
		{}
		// typedef ListIterator<T, T&, T*> iterator;
		// typedef ListIterator<T, const T&, const T*> const_iterator;
		// ListIterator实例化为iterator时，这个函数是拷贝构造
		// ListIterator实例化为const_iterator时，这个函数支持iterator转换为const_iterator构造函数
		ListIterator(const ListIterator<T, T&, T*>& it)
			:_node(it._node)
		{}

		// ++it;
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		// 同一个类模板给不同参数会实例化出不同的类型
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}
		void empty_init()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}
		list()
		{
			empty_init();
		}

		/*list(initializer_list<T> il)
		{
			empty_init();
			for (const auto& e : il)
			{
				push_back(e);
			}
		}*/
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		// 没有iterator失效
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
			return iterator(newnode);
		}
	private:
		Node* _head;
	};
}