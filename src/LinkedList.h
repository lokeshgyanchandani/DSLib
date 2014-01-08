#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

using namespace std;

#include "Node.h"
#include <iostream>

template <class T>
class LinkedList
{
	private:
		Node<T> *head;

	public:
		LinkedList();
		~LinkedList();

		void insert(T, int);
		void insertAtBeginning(T);
		void insertAfterElement(T, T);
		void insertAtEnd(T);
		void deleteFromBeginning();
		void deleteFromEnd();
		void deleteElement(T);
		void deleteAfterElement(T);
		void reverseList();
		int isEmpty();
		void printList();
		int getLength();
};

template <class T>
LinkedList<T> :: LinkedList() : head(NULL)
{
}

template <class T>
LinkedList<T> :: ~LinkedList()
{
	Node<T> *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

template <class T>
int LinkedList<T> :: isEmpty()
{
	if (head == NULL)
		return 1;
	else
		return 0;
}

template <class T>
void LinkedList<T> :: printList()
{
	Node<T> *temp = head;
	while (temp != NULL) {
		cout << temp->getInfo() << " ";
		temp = temp->getNext();
	}
}

template <class T>
void LinkedList<T> :: insertAtBeginning(T value)
{
	Node<T> *ptr = new Node<T> ();
	ptr->setInfo(value);

	ptr->setNext(head);
	head = ptr;
}

template <class T>
void LinkedList<T> :: insertAtEnd(T value)
{
	Node<T> *ptr = new Node<T> ();
	ptr->setInfo(value);
	ptr->setNext(NULL);

	if (head == NULL) {
		head = ptr;
	} else {
		Node<T> *temp = head;
		while (temp->getNext() != NULL) {
			temp = temp->getNext();
		}
		temp->setNext(ptr);
	}
}

template <class T>
int LinkedList<T> :: getLength()
{
	int count = 0;
	Node<T> *temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->getNext();
	}
	return count;
}

#endif
