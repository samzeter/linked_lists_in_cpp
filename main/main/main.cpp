#include "pch.h"
#include <iostream>

struct node
{
	int data;
	node* next;
};

class list
{
private:
	node *head;
	node *tail;
public:
	// default constructor
	list() {
		head = NULL;
		tail = NULL;
	}

	void create_node(int value) {

		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		// if at start of the list, head and tail both have this data
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		// if not at the start of the list, add a new node
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	// insert a node at the start
	// Algorithm:
	// 1. Make a temp node
	// 2. Add data to that node
	// 3. Make temp node point to head node (this positions the node)
	// 4. Set temp as the head (this confirms ndoe as the new head)


	//	+ ---- + ---- - ++---- - +---- - ++---- - +------ +
	//	| A | +-- > |     |     +-- > |     |      |
	//	+---- + ---- - ++---- - +---- - ++---- - +------ +
	//	/
	//	Head is pointing to location A.

	//	You make a new node

	//	+ ---- + ---- +
	//	| B  |    |
	//	+---- + ---- +
	//	/
	//	tmp now points to B.You insert data in tmp->data, and then make tmp->next = head;.So now we have :

	//+---- + ---- + +---- + ---- - ++---- - +---- - ++---- - +------ +
	//	| B | next | ---- > | A | +-- > |     |     +-- > |     |      |
	//	+---- + ---- + +---- + ---- - ++---- - +---- - ++---- - +------ +
	//	/
	//	And then you makehead to point to B instead of A.

	//	+ ---- + ---- + +---- + ---- - ++---- - +---- - ++---- - +------ +
	//	| B | next | ---- > | A | +-- > |     |     +-- > |     |      |
	//	+---- + ---- + +---- + ---- - ++---- - +---- - ++---- - +------ +
	//	/ \
	//	head & tmp point to B now

	void show_nodes() {

		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			std::cout << temp->data << " --";
			temp = temp->next;
		}
	}
};


int main()
{
	// end of list is NULL
	// if head is NULL - linked list is empty
	// tail pointer always points to last node

	list obj;

	obj.create_node(3);

	obj.show_nodes();




    std::cout << "Hello World!\n"; 
}
