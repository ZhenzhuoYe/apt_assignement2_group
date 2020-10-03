#ifndef AZUL_LINKEDLIST
#define AZUL_LINKEDLIST
#include "Tile.h"

typedef struct Node {
	Tile tile; 
	Node* next; // next node
	Node(const Tile& tile) {
		this->tile = tile;
		this->next = nullptr;
	}
} Node;


class LinkedList {
public:
	LinkedList();  // default constructor
	~LinkedList(); // destructor


	void enqueue(const Tile& tile);
	Tile dequeue();


	bool isEmpty(); // return true if the linked list is empty
	void clear();   // clear the linked list

	Tile getHead();// return the head of the node
	Tile getTail();// return the tail of the node

	Node* getHeadNode();//return head node
	int getSize();//return size

	
private:
	int size;    // number of elements in linked list
	Node* head;  // node points to the head
	Node* tail;  // node points to the tail
};

#endif