#ifndef NODE_IMPL_H_
#define NODE_IMPL_H_

#include <iostream>

template <class T>
class Node {
	private:
		T info;
		Node<T> *next;
		Node<T> *prev;

	public:
		Node();
		T getInfo() const;
		void setInfo(T);
		Node<T> *getNext() const;
		void setNext(Node<T> *);
		Node<T> *getPrev() const;
		void setPrev(Node<T> *);
};

template <class T>
Node<T> :: Node() : info(T()), next(NULL), prev (NULL)
{
}

template <class T>
T Node<T> :: getInfo() const
{
	return info;
}

template <class T>
void Node<T> :: setInfo(T info)
{
	this->info = info;
}

template <class T>
Node<T> * Node<T> :: getNext() const
{
	return next;
}

template <class T>
void Node<T> :: setNext(Node<T> * next)
{
	this->next = next;
}

template <class T>
Node<T> * Node<T> :: getPrev() const
{
	return prev;
}

template <class T>
void Node<T> :: setPrev(Node<T> * prev)
{
	this->prev = prev;
}

#endif
