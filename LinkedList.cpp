#include "LinkedList.h"

LinkedList::LinkedList() {
	size = 0;
	head = tail = nullptr;
}

LinkedList::~LinkedList() {
	clear();
}

void LinkedList::enqueue(const Tile& tile) {
	Node* newNode = new Node(tile);
	if (head == nullptr) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode; // shift tail to the last node
	}

	size++;
}

Tile LinkedList::dequeue() {
	if (isEmpty()) {
		throw "Dequeue operation from empty.";
	}

	Tile tile = head->tile;
	Node* tmp = head;
	head = head->next;
	size--;
	delete tmp; // free the memory
	if (isEmpty()) {
		tail = nullptr;
	}

	return tile;
}

bool LinkedList::isEmpty() {
	return size == 0;
}

void LinkedList::clear() {
	while (!isEmpty()) {
		dequeue();
	}
}

Node* LinkedList::getHead(){
	return head;
}

Node* LinkedList::getTail(){
	return tail;
}


int LinkedList::getSize(){
	return this->size;
}
