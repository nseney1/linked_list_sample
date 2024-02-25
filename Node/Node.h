#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
	private:
		int data;

		void log_node();

	public:
		Node(int value, Node* prev_node, Node* next_node); 

		Node* next;
		Node* prev;

		int get_data();
		int update_data(int value);
	
		void update_next(Node* next_node);
		void update_prev(Node* prev_node);


};

#endif

