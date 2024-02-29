#include "./LinkedList/LinkedList.h"
#include "./Node/Node.h"

#include <iostream>

int main() {
	LinkedList* linked_list = new LinkedList();
	std::cout << "Let's create a linked list" << std::endl;

	for (int i=0; i<5; ++i) {
		int value;
		
		std::cout << "Enter a number: ";
		std::cin >> value; 
		std::cout << std::endl;

		linked_list->insert(value);
	}

	linked_list->display_list();
	linked_list->free_memory();
}
