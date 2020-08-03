#include <iostream>
#include "Header.h"
using namespace std;

List::~List() {
	for (Node* p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}
void List::headPush(int el) {
	//create newnode tmp
	Node* tmp = new Node(el);
	tmp->info = el;
	//if list is empty
	if (tail == 0) {
		tmp->next = head;
		head = tmp;
		tail = head;
	}
	//else 
	else {
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}

}
void List::tailPush(int el) {
	//create newnode tmp
	Node* tmp = new Node(el);
	tmp->info = el;
	tmp->next = NULL;
	//if list is empty
	if (head == 0) {
		head = tmp;
		tail = head;

	}
	//else
	else {

		tail->next = tmp;
		tmp->prev = tail;
		tmp->next = NULL;
		tail = tail->next;
	}

}
int List::headPop() {

	//create tmp
	Node* tmp = head;
	int x;
	//if 1 node
	if (head == tail) {
		x = head->info;
		head = 0;
		tail = 0;

	}
	//else
	else {
		x = tmp->info;
		head = head->next;
		head->prev = NULL;
	}

	//return tmp->info;
	delete tmp;
	return x;

}
int List::tailPop() {

	//create tmp
	Node* tmp = head;
	int x;
	//if 1 node
	if (head == tail) {
		x = head->info;
		head = 0;
		tail = 0;

		delete tmp;
		return x;

	}
	//else
	else {

		tail = tail->prev;
		x = tail->next->info;
		tail->next = NULL;
		delete tail->next;
		return x;

	}


}
void List::deleteNode(int el) {
	//create cur and dele
	Node* cur = head;
	Node* dele = head;
	//if el = first node
	if (el == head->info) {
		head = dele->next;
		head->prev = NULL;
		cur = dele->next;
		delete dele;
	}
	//else
	else {

		//for find el in a list
		while (cur->next != NULL) {
			//if we found it

			if (cur->next->info == el) {

				if (cur->next == tail) {
					dele = cur->next;
					cur->next = NULL;
					tail = cur;
					delete dele;
					break;
				}
				else {
					//set dele for prepare to delete
					dele = cur->next;
					//change list
					cur->next = dele->next;
					dele->next->prev = cur;
					//delete
					delete dele;
					break;

				}
			}
			cur = cur->next;
			dele = cur;

		}

	}


}
bool List::isInList(int el) {
	//create cur
	Node* cur = head;
	//loop for find el
	while (cur != NULL) {
		//if we found it return true
		if (cur->info == el) {
			return true;
		}
		cur = cur->next;

	}
	return false;

}
//for display
void List::display() {
	Node* cur = head;
	Node* last = tail;
	while (cur != NULL) {
		cout << cur->info << " ";
		cur = cur->next;
	}
	cout << endl;
	//check node prev
	while (last != NULL) {
		cout << last->info << " ";
		last = last->prev;
	}
	cout << endl;
}
