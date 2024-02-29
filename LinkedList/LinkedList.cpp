#include "LinkedList.h"
#include <__nullptr>
#include <iostream>

LinkedList::LinkedList(): head(nullptr) {}
LinkedList::LinkedList(Node* start): head(start), size(1) {}

int LinkedList::get_size() {
	return size;
}

Node* LinkedList::find(int value) {
	Node* current_node = get_head();

	for (int i=0; i<size; ++i) {
		if (current_node->get_data() < value) {
			current_node = current_node->next;
		} else if (current_node->get_data() == value) {
			return current_node;
		} else {
			std::cout << "Node not found" << std::endl;
			return nullptr;
		}
	}
}

void LinkedList::insert(int value) {
	Node* current_node = get_head();
	Node* prev_node = nullptr;
	
	if (current_node == nullptr) {
		head = new Node(value, nullptr, nullptr);
		++size;
		return;
	}

	for (int i=0; i<size; ++i) {
		if (current_node == nullptr) {
			Node* new_node = new Node(value, prev_node, nullptr);
			++size;
		}

		if (current_node->get_data() < value) {
			prev_node = current_node;
			current_node = current_node->next;
		} else if (current_node->get_data() > value) {
			Node* new_node = new Node(value, prev_node, current_node);
			
			current_node->update_prev(new_node);
			prev_node->update_next(new_node);
			++size;
		} else {
			std::cout << "Node for this value already exists" << std::endl;
		}
	}
}

void LinkedList::remove(int value) {
	Node* node_to_remove = find(value);

	if (node_to_remove == nullptr) {
		return;
	}

	delete node_to_remove;
}	

void LinkedList::display_list() {
	Node* current_node = get_head();
	for (int i=0; i<get_size(); ++i) {
		std::cout << current_node->get_data() << std::endl;
		current_node = current_node->next;
	}
}

void LinkedList::free_memory() {
	Node* current_node = get_head();

	for (int i=0; i<get_size(); ++i) {
		if (current_node == nullptr) {
			std::cout << "Finished Freeing memory" << std::endl;
		}

		Node* prev_node = current_node;
		current_node = current_node->next;
		
		std::cout << "Deleteing Node: " << prev_node->get_data() << std::endl;

		delete prev_node;
	}
}

