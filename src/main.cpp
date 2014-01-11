#include <iostream>
#include "LinkedList.h"

int main() {
	LinkedList<int> *llist = new LinkedList<int>();
	llist->insertAtEnd(1);
	llist->insertAtEnd(5);
	llist->insertAtEnd(9);
	llist->insertAtEnd(20);
	llist->insertAtIndex(20, 2);
	llist->insertAtEnd(9);
	llist->printList();
	cout<<llist->getNthToLastNode(llist->getHead(), 7)->getInfo();
	llist->reverseList();
	llist->printList();
	return 0;
}
