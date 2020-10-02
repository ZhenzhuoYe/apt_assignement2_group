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

Tile LinkedList::getHead(){
	return head->tile;
}

Node* LinkedList::getHeadNode(){
	return head;
}

int LinkedList::getSize(){
	return size;
}

Tile LinkedList::getTail(){
	return tail->tile;
}