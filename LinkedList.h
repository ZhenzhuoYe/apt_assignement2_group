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

	//changef here
	//get tile for getting node data
	const Color getTileColor ()
    {
         return tile.getTileColor();
    }
	//get next node
	Node* & getNext ()
    {
         return next;
    }
	//
	
} Node;


class LinkedList {
public:
	LinkedList();  // default constructor
	~LinkedList(); // destructor
	void enqueue(const Tile& tile);
	Tile dequeue();
	bool isEmpty(); // return true if the linked list is empty
	void clear();   // clear the linked list
	
	//changed here
	int getSize();//get size of linked list
	Node * getHeadNode ();//get head node
	Node * getTail();//get tail of linked list
	//
	

private:
	int size;    // number of elements in linked list
	Node* head;  // node points to the head
	Node* tail;  // node points to the tail
};

#endif