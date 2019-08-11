#include <iostream>

using namespace std;
class Node {
public:
	int data;
	Node* next;

	Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
public:
	Node* head;
	Node* tail;

	LinkedList() : head(NULL), tail(NULL) {}

	void push(int val);
	void print();
	bool isEmpty();
};

int main()
{
	LinkedList* list1 = new LinkedList(); // allocate me 16 bytes in memory
	list1->push(1);
	list1->push(2);
	list1->push(3);
	list1->push(4);
	list1->push(5);
	list1->print();
}

// insert
/*
BASE CASES=> is it empty?
			 probably more?

DIRECTIONS:
			Figure out a way that you will have access to previous and current node
			for loop? wihle loop?
*/

void LinkedList::push(int val)
{
	Node* new_node = new Node(val);
	Node* ptr = this->head;

	// base case
	if (this->isEmpty()) {
		this->head = new_node;
		this->tail = new_node;
		new_node = NULL; // free memory space
	}
	else {
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}

		ptr->next = new_node;
		tail = new_node;
		new_node = NULL; // free memory space
	}
}

void LinkedList::print()
{
	Node* ptr = this->head;

	cout << "Current nodes in the current Linked List are: " << endl;
	while (ptr != NULL) {
		cout <<ptr->data << endl;
		ptr = ptr->next;
	}
}

bool LinkedList::isEmpty()
{
	if (this->head == NULL) {
		return true;
	}
	return false;
}
