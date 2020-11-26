#include "List.h"
#include <iostream>

List::List() {
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}

bool List::isEmpty() {
	return length == 0;
}

bool List::add(Node* n) {
	bool result = true;
	try {
		if (this->isEmpty()) {
			this->head = n;
			this->tail = n;
		}
		else {
			n->setPrev(this->tail);
			this->tail->setNext(n);
			this->tail = n;
		}
		++length;
		std::cout << length << std::endl;
	}
	catch (...) {
		result = false;
	}
	return result;
}

bool List::insert(Node* n, int index) {
	if (index<0 || index > length)
		return false;

	bool result = true;

	try {
		if (index == 0) {
			Node* target = this->head;
			target->setPrev(n);
			this->head = target;
		}
		Node* prev = this->get(index - 1);
		Node* next = this->get(index);
		prev->setNext(n);
		next->setPrev(n);

		++length;
	}
	catch (...) {
		result = false;
	}
	return result;
}

bool List::remove(int index) {
	if (index<0 || index > length) {
		return false;
	}

	Node* target = this->get(index);

	if (length == 1) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		if (index == 0) {
				Node* next = target->getNext();
				next->setPrev(nullptr);
				this->head = next;
			}
			else if (index == length - 1) {
				Node* prev = target->getPrev();
				prev->setNext(nullptr);
				this->tail = prev;
			}
			else {
				Node* prev = target->getPrev();
				Node* next = target->getNext();
				prev->setNext(next);
				next->setPrev(prev);
			}
	}
	
	delete target;
	--length;

	return true;
}

bool List::swap(int n1, int n2) {
	Node* node1 = nullptr;
	Node* node2 = nullptr;

	//check range
	if (n1<0 || n2<0 || n1 > length || n2 > length) {
		return false;
	}

	//assign node1 and node2 so that index node1 always less than node2
	if (n1 > n2) {
		node1 = this->get(n2);
		node2 = this->get(n1);
	}
	else {
		node1 = this->get(n1);
		node2 = this->get(n2);
	}

	Node* beforeNode1 = node1->getPrev();
	Node* afterNode1 = node1->getNext();

	Node* beforeNode2 = node2->getPrev();
	Node* afterNode2 = node2->getNext();
	
	//check if node1 and node2 is head or tail
	if (node1 == head)
		head = node2;

	if (node2 == tail)
		tail = node1;

	//change the pointer before and after the node 1 to node 2
	if (beforeNode1 != nullptr)
		beforeNode1->setNext(node2);
	if (afterNode1 != node2)
		afterNode1->setPrev(node2);

	//change the pointer before and after the node 2 to node 1
	if (afterNode2 != nullptr)
		afterNode2->setPrev(node1);
	if (beforeNode2 != node1)
		beforeNode2->setNext(node1);
	
	//change the pointer of node 1 and node 2
	node1->setNext(afterNode2);
	node2->setPrev(beforeNode1);

	if (beforeNode2 == node1) {
		node1->setPrev(node2);
		node2->setNext(node1);
	}
	else {
		node1->setPrev(beforeNode2);
		node2->setNext(afterNode1);
	}

	return true;
}

bool List::sort() {
	bool sorted = true;

	try {
		for (int i = 0; i < length - 1; ++i) {
			sorted = true;
			for (int j = i; j < length - 1; ++j) {
				if (!(this->get(j) < this->get(j + 1))) {
					this->swap(j, j + 1);
					sorted = false;
				}
			}
			if (sorted)
				break;
		}
		return true;
	}
	catch (...) {
		return false;
	}
}

Node* List::get(int index) {
	if (index<0 || index > length)
		return nullptr;
	
	Node* target = nullptr;
	if (index > length / 2) {
		target = this->tail;
		int move = length - index;
		for (int i = length-1; i > move; --i) {
			target = target->getPrev();
		}
	}
	else {
		target = this->head;
		for (int i = 0; i < index; ++i) {
			target = target->getNext();
		}
	}

	return target;
}

int List::size() {
	return length;
}

Node* List::getHead() {
	return head;
}

Node* List::getTail() {
	return tail;
}