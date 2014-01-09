#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> *llist = new LinkedList<int>();
	llist->insertAtEnd(1);
	llist->insertAtEnd(5);
	llist->insertAtEnd(9);
	llist->insertAtEnd(20);
	llist->printList();
	cout<<"\n"<<"length: "<<llist->getLength()<<"\n";
	llist->insertAtIndex(10, 2);
	cout<<"\n";
	llist->printList();
	cout<<"\n\n";
	llist->insertAtEnd(2);
	llist->insertAtBeginning(50);
	llist->printList();
	llist->reverseList();
	llist->printList();
	return 0;
}
