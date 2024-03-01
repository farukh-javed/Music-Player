#pragma once
class DoublyList
{
public:
	virtual void insertAtFront(char* valaue) = 0;
	virtual void insertAtEnd(char*  value) = 0;
	virtual void insertNext(char*  Nodevalue, char*  value) = 0;
	virtual void sortLinkedList() = 0;
	virtual char* removeFromFront() = 0;
	virtual char* removeNext(char* Nodevalue) = 0;
	virtual void removeFromEnd() = 0;
	virtual ~DoublyList() {}
};