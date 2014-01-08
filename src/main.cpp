#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> *llist = new LinkedList<int>();
	llist->insertAtBeginning(0);
	llist->insertAtEnd(1);
	llist->insertAtEnd(5);
	llist->printList();
	cout<<endl;
	cout<<llist->getLength();
	return 0;
}
