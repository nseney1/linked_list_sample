#include "LinkedList.h"
#include <__nullptr>
#include <iostream>

LinkedList::LinkedList(Node* start): head(start), size(1) {}

Node* LinkedList::find(int value, Node* node) {
	if (node == nullptr) {
		node = head;
	} else if (node->get_data() == value) {
		return node;
	} else if (node->next == nullptr) {
		std::cout << "Node not found" << std::endl;
	}

	return find(value, node);
}

void LinkedList::insert(int value) {
	Node* node = head;
	for (int i=0; i<size; ++i) {
		if (node->get_data() < value) {

		} else if (node->get_data() > value) {

		} else {

		}

	}
}

