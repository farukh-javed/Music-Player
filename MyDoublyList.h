#pragma once
#include "Node.h"
#include "DoublyList.h"

class MyDoublyList : public DoublyList
{
public:
	node* head;

	MyDoublyList();
	bool isEmpty();
	int sizeOfList();
	void insertAtFront(char* valaue);
	void insertAtEnd(char* valaue);
	void insertNext(char* Nodevalue, char* valaue);
	void sortLinkedList();
	char* removeFromFront();
	char* removeNext(char* Nodevalue);
	void displayList();
	node* getNodeAtIndex(int index);
	void removeFromEnd();
	~MyDoublyList();
};