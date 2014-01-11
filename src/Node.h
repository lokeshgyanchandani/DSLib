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
	if (this != NULL)
		return info;
	return -1;
}

template <class T>
void Node<T> :: setInfo(T info)
{
	if (this != NULL)
		this->info = info;
}

template <class T>
Node<T> * Node<T> :: getNext() const
{
	if (this != NULL)
		return next;
	return NULL;
}

template <class T>
void Node<T> :: setNext(Node<T> * next)
{
	if (this != NULL)
		this->next = next;
}

template <class T>
Node<T> * Node<T> :: getPrev() const
{
	if (this != NULL)
		return prev;
	return NULL;
}

template <class T>
void Node<T> :: setPrev(Node<T> * prev)
{
	if (this != NULL)
		this->prev = prev;
}

#endif
