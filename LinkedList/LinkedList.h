#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Node/Node.h"

class LinkedList {
	private:
		int size;
	public:
		Node* head;

		LinkedList();
		LinkedList(Node* start);

		void sort_list();
		void insert(int value);
		void free_memory();
		void display_list();

		void remove(int value);
		int get_size();		
		
		Node* find(int value);
		Node* update(Node* node, int value);
		Node* get_head();
		Node* get_tail();
};

#endif

