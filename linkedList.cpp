// Linked list related basic function implementations
#include <iostream>
using namespace std;

//XXX: Make generic
struct node {
	int data;
	node* next;
};

// Function to add new node at start of list
void insertAtHead(int n, node** headRef) {
	node* temp = new node();
	temp->data = n;
	temp->next = *headRef;
	*headRef = temp;
}

// Function to add new node at end of list
void insertAtTail(int n, node** headRef) {
	node* head = *headRef;
	node* temp = new node();
	temp->data = n;
	temp->next = NULL;
	if(head) {
		node* last = head;
		while(last->next != NULL) {
			last = last->next;
		}
		last->next = temp;
	}
	else {
		head = temp;
	}
	*headRef = head;
}

// Function to print list
void printList(node* head) {
	while(head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}
	cout << "//" << endl;
}

// Function to delete a node using key
// Return true on success, false otherwise
bool deleteNodeWithKey(int key, node** headRef) {
	node* head = *headRef;
	if(head == NULL)
		return false;
	node* temp;
	if(head->data == key) {	//head needs to be updated
		temp = head->next;
		delete(head);
		head = temp;
		*headRef = head;
		return true;
	}
	temp = head;
	while(temp->next != NULL && temp->next->data != key) {
		temp = temp->next;
	}
	if(temp->next == NULL) {
		return false;	//key not found
	}
	else {
		node* newNext = temp->next->next;
		node* toBeNuked = temp->next;
		temp->next = temp->next->next;
		delete(toBeNuked);
		toBeNuked = NULL;
	}
	return true;
}

// Function to delete node using position
void deleteNodeWithPosition(int pos, node** headRef) {

}

// Function to reverse list iteratively
void iterRev(node** headRef) {
	node* head = *headRef;
	if(head == NULL)
		return;
	if(head->next == NULL)	//only one node in list; no need to reverse
		return;
	node* prev = NULL;
	node* current = head;
	node* newNext
	;
	while(current != NULL) {
		newNext = current->next;
		current->next = prev;
		prev = current;
		current = newNext;
	}
	head = prev;
	*headRef = head;
}

// Function to reverse list recursively
void recRev(node** headRef) {
	node* head = *headRef;
	if(head == NULL)
		return;
	node* rest = head->next;		//IMP: It is important to use a separate pointer for head->next(rest). This is for the head reference update.
	if(rest == NULL){
		return;
	}
	recRev(&rest);
	head->next->next = head;
	head->next = NULL;
	*headRef = rest;
}

// Function to delete entire list recursively
void recDelete(node** headRef) {
	node* head = *headRef;
	if(head == NULL)
		return;
	recDelete(&head->next);
	delete(head);
	head = NULL;
	*headRef = head;
}

// Function to delete entire list iteratively
void iterDelete(node** headRef) {
	node* head = *headRef;
	node* temp;
	while(head != NULL) {
		temp = head->next;
		delete(head);
		head = temp;
	}
	*headRef = NULL;
}

// Function to return the length of a list iteratively
int iterLength(node* head) {
	int len = 0;
	while(head) {
		len += 1;
		head = head->next;
	}
	return len;
}

// Function to return the length of a list recursively
int recLength(node* head) {
	static int len = 0;
	if(head == NULL) {
		return len;
	}
	return 1 + recLength(head->next);
}

// Function to print the middle element of a list
void printMiddle(node* head) {
	int mid = iterLength(head)/2;
	while(mid !=0) {
		head = head->next;
		mid -= 1;
	}
	cout << "Middle element of the list is " << head->data << endl;
}

// Alternate function to print the middle element of a list
void printMiddle2(node* head) {
	if(head == NULL)
		return;
	// Uses 2 pointers
	node* fast = head;
	node* slow = head;
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "Middle element of list is " << slow->data << endl;
}

// Alternate function to print the middle element of a list
void printMiddle3(node* head) {
	//XXX: use single pointer; update only when count var is odd; when you reach end of list, return pointer->data
	node* mid = head;
	int nodeCount = 0;
	while(head != NULL ) {
		nodeCount += 1;
		if(nodeCount % 2 == 1) 
			mid = mid->next;
		head = head->next;
	}
	cout << "Middle element of list " << mid->data << endl;
}

int main() {
	node* head = NULL;
	insertAtHead(1, &head);
	insertAtHead(0, &head);
	insertAtTail(2, &head);
	insertAtTail(3, &head);
	insertAtTail(4, &head);
	printList(head);
	// iterDelete(&head);
	// recRev(&head);
	// printList(head);
	// cout << deleteNodeWithKey(3, &head) << endl;
	// printList(head);
	// cout << "Length of list using iteration: " << iterLength(head) << endl;
	// cout << "Length of list using recursion: " << recLength(head) << endl;
	// printMiddle3(head);
	// iterRev(&head);
	// printList(head);
	return 0;
}