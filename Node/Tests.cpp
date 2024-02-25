#include <gtest/gtest.h>
#include "Node.h"
#include <iostream>

class NodeTests : public testing::Test {
 protected:
	void SetUp() override {}

	void TearDown() override {
		delete current_node;
		delete prev_node;
		delete next_node;
	}

	Node* prev_node = new Node(20, nullptr, nullptr);
	Node* next_node = new Node(40, nullptr, nullptr);
	Node* current_node = new Node(30, prev_node, next_node);
};

TEST_F(NodeTests, StandardUnitTests) {
	EXPECT_EQ(30, current_node->get_data());
	EXPECT_EQ(current_node->prev, prev_node);
	EXPECT_EQ(current_node->next, next_node);
}

TEST_F(NodeTests, StandardUpdateTests) {
	current_node->update_data(5);
	EXPECT_EQ(5, current_node->get_data());

	current_node->update_prev(next_node);
	current_node->update_next(prev_node);

	EXPECT_EQ(current_node->next, prev_node);
	EXPECT_EQ(current_node->prev, next_node);

}

