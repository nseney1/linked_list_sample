#include "LinkedList.h"
#include <__nullptr>
#include <iostream>

LinkedList::LinkedList(): size(0), head(nullptr) {}
LinkedList::LinkedList(Node* start): size(1), head(start) {}

Node* LinkedList::get_head() {
	return head;
}

int LinkedList::get_size() {
	return size;
}

Node* LinkedList::find(int value) {
	Node* current_node = get_head();

	for (int i=0; i<=size; i++) {
		if (current_node->get_data() < value) {
			current_node = current_node->next;
		} else if (current_node->get_data() == value) {
			break;
		} else {
			std::cout << "Node not found" << std::endl;
			return nullptr;
		}
	}
	return current_node;
}

void LinkedList::insert(int value) {
	Node* current_node = get_head();
	Node* prev_node = nullptr;
	
	if (current_node == nullptr) {
		head = new Node(value, nullptr, nullptr);
		size++;

		std::cout << "Creating Head Node with value: " << value << ", Size is: " << get_size() << std::endl;
		
		return;
	}

	for (int i=0; i<size; i++) {
		if (current_node->get_data() < value) {
			prev_node = current_node;
			current_node = current_node->next;
		} else if (current_node->get_data() > value && current_node != head) {
			Node* new_node = new Node(value, prev_node, current_node);
			
			current_node->update_prev(new_node);
			prev_node->update_next(new_node);

			std::cout << "Adding Node with value: " << value;
			break;
		} else if (current_node->get_data() > value && current_node == head) {
			Node* new_node = new Node(value, nullptr, current_node);
			head = new_node;
			
			current_node->update_prev(new_node);

			std::cout << "Creating new Head Node with value: " << value;
		} else {
			std::cout << "Node for this value already exists" << std::endl;
			return;
		}
	}

	if (current_node == nullptr) {
		Node* new_node = new Node(value, prev_node, nullptr);
		prev_node->update_next(new_node);
		std::cout << "Creating Tail Node with value: " << value; 
	}

	size++;
	std::cout << ", Size is: " << size << std::endl;
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
	for (int i=0; i<size; i++) {
		std::cout << current_node->get_data() << std::endl;
		current_node = current_node->next;
	}
}

void LinkedList::free_memory() {
	Node* current_node = get_head();

	std::cout << "Freeing Memory" << std::endl;

	for (int i=0; i<size; i++) {
		if (current_node == nullptr) {
			std::cout << "Finished Freeing memory" << std::endl;
		}

		Node* prev_node = current_node;
		current_node = current_node->next;
		
		std::cout << "Deleteing Node: " << prev_node->get_data() << std::endl;

		delete prev_node;
	}
}

