#include "MyDoublyList.h"
#include <iostream>
using namespace std;

MyDoublyList::MyDoublyList() :DoublyList()
{
	head = nullptr;
}

bool MyDoublyList::isEmpty()
{
	return (head == nullptr);
}

int MyDoublyList::sizeOfList()
{
	int size = 0;
	node* current = head;

	while (current != nullptr)
	{
		size++;
		current = current->next;
	}
	return size;
}

void MyDoublyList::insertAtFront(char*  value)
{
	node* newNode = new node(value);

	if (isEmpty())
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void MyDoublyList::insertAtEnd(char*  value)
{
	node* newNode = new node(value);

	if (isEmpty())
	{
		head = newNode;
	}
	else
	{
		node* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = newNode;
		newNode->prev = current;
	}

}

void MyDoublyList::insertNext(char*  Nodevalue, char*  value)
{
	if (isEmpty())
	{
		cout << "\nList is empty" << endl;
	}
	else
	{
		node* current = head;

		while (current != nullptr && current->data != Nodevalue)
		{
			current = current->next;
		}

		if (current == nullptr)
		{
			cout << "\nValue Not Found" << endl;
		}
		else
		{
			node* newNode = new node(value);
			if (current->next != nullptr)
			{
				node* temp = current->next;
				newNode->next = temp;
				temp->prev = newNode;
			}
			current->next = newNode;
			newNode->prev = current;
		}

	}
}

node* MyDoublyList::getNodeAtIndex(int index)
{
	if (index < 0 || index >= sizeOfList()) 
	{
		return nullptr;
	}

	node* current = head;
	for (int i = 0; i < index; ++i) 
	{
		current = current->next;
	}

	return current;
}

void MyDoublyList::displayList()
{
	node* current = head;

	cout << "\n";
	while (current != nullptr)
	{
		cout << "\t\t\t     "<<current->data << endl;
		current = current->next;
	}
}

void MyDoublyList::sortLinkedList()
{
	if (isEmpty() || head->next == nullptr)
	{
	}
	else
	{
		node* current = nullptr;
		node* last = nullptr;
		bool swapped;

		do {
			swapped = false;
			current = head;

			while (current->next != last) {
				if (current->data > current->next->data)
				{
					char* temp = current->data;
					current->data = current->next->data;
					current->next->data = temp;
					swapped = true;
				}

				current = current->next;
			}

			last = current;

		} while (swapped);
	}
}

char* MyDoublyList::removeFromFront()
{
	if (isEmpty())
	{
		cout << "\nList is Empty" << endl;
		return '\0';
	}
	else
	{
		node* temp = head;
		char* value = temp->data;
		if (temp->next != nullptr)
		{
			head = head->next;
			head->prev = nullptr;
		}
		delete temp;
		temp = nullptr;
		return value;
	}
}

char* MyDoublyList::removeNext(char* Nodevalue)
{
	if (isEmpty())
	{
		cout << "\nList is Empty" << endl;
		return '\0';
	}
	else
	{
		node* current = head;

		while (current != nullptr && current->data != Nodevalue)
		{
			current = current->next;
		}

		if (current == nullptr)
		{
			cout << "\nValue Not Found" << endl;
			return '\0';
		}
		else
		{
			node* temp = current->next;
			if (temp == nullptr)
			{
				cout << "\n Given value is itself in the last node" << endl;
				return '\0';
			}
			char* value = temp->data;
			if (temp->next != nullptr)
			{
				current->next = temp->next;
				current->next->prev = current;
			}
			current->next = nullptr;
			delete temp;
			temp = nullptr;
			return value;
		}
	}
}

void MyDoublyList::removeFromEnd()
{
	if (isEmpty())
	{
		cout << "\nList is Empty" << endl;
	}
	else
	{
		node* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		if (current->prev != nullptr)
		{
			current->prev->next = nullptr;
		}
		delete current;
		current = nullptr;
	}
}

MyDoublyList::~MyDoublyList()
{
	node* current = head;
	node* temp;

	while (current != nullptr)
	{
		temp = current->next;
		delete current;
		current = nullptr;
		current = temp;
	}
	head = nullptr;
}