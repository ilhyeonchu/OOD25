#include "int_node.h"

#include <string>

IntNode::IntNode(int value, const Node* left, const Node* right)
    : Node(left, right), value_(value) {}

const std::string IntNode::value() const { return std::to_string(value_); }
