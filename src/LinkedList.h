#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

using namespace std;

#include "Node.h"
#include <iostream>
#include <stdlib.h>

template <class T>
class LinkedList
{
	private:
		Node<T> *head;

	public:
		LinkedList();
		~LinkedList();

		void insertAtBeginning(T);
		void insertAtIndex(T, int);
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
void LinkedList<T> :: insertAtBeginning(T value)
{
	Node<T> *ptr = new Node<T> ();
	ptr->setInfo(value);

	ptr->setNext(head);
	head = ptr;
}

template <class T>
void LinkedList<T> :: insertAtIndex(T value, int position)
{
	int length = this->getLength();

	if (position > length + 1 || position < 1)
	{
		cout<<"Position out of bounds"<<endl<<"Terminating";
		return;
	}

	Node<T> *ptr = new Node<T>();
	ptr->setInfo(value);

	if (position == 1)
	{
		ptr->setNext(head);
		head = ptr;
	}
	else
	{
		Node<T> *temp = head;
		position = position - 2;
		while(position > 0)
		{
			temp = temp->getNext();
			position--;
		}
		ptr->setNext(temp->getNext());
		temp->setNext(ptr);
	}
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
void LinkedList<T> :: deleteFromBeginning()
{
	Node<T> *temp = head;

	if (head == NULL)
		return;

	head = head->getNext();
	delete temp;
}

template <class T>
void LinkedList<T> :: deleteFromEnd()
{
	Node<T> *temp;
	if (head == NULL)
	{
		return;
	}
	else if (head->getNext() == NULL)
	{
		temp = head;
		head = NULL;
		delete temp;
	}
	else
	{
		temp = head;
		while(temp->getNext()->getNext() != NULL)
		{
			temp = temp->getNext();
		}
		delete temp->getNext();
		temp->setNext(NULL);
	}
}

template <class T>
void LinkedList<T> :: deleteElement(T value)
{
	Node<T> *temp, *ntemp;
	if (head == NULL)
		return;
	else {
		temp = NULL;
		ntemp = head;
		while (ntemp!= NULL && ntemp->getInfo() != value)
		{
			temp = ntemp;
			ntemp = ntemp->getNext();
		}
		if (ntemp != NULL && ntemp->getInfo() == value)
		{
			if (ntemp == head)
			{
				temp = head;
				head = head->getNext();
				delete temp;
			}
			else
			{
				temp->setNext(ntemp->getNext());
				delete ntemp;
			}
		}
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
