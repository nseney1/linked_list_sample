#include "Node.h"

Node::Node(int value, Node* prev_node, Node* next_node): data(value), prev(prev_node), next(next_node) {}

void Node::update_next(Node* next_node) {
	next = next_node;
}

void Node::update_prev(Node* prev_node) {
	prev = prev_node;
}

int Node::get_data() {
	return data;
}

int Node::update_data(int value) {
	data = value; 
	return data;
}

void Node::log_node() {
	std::cout << "Data: " << data << ", ";
	std::cout << "Next Node: " << next <<  ", ";
	std::cout << "Previous Node: " << prev << std::endl;
}

