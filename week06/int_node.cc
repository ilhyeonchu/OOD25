#include "int_node.h"

#include "node.h"

IntNode::IntNode(int value, const Node* left, const Node* right)
    : Node(left, right), value_(value) {}

const int IntNode::value() const { return value_; }
