#include "tree_util.h"

#include <string>

#include "int_node.h"
#include "string_node.h"

TreeUtil* TreeUtil::instance_ = nullptr;

TreeUtil::TreeUtil() {}

TreeUtil* TreeUtil::GetInstance() {
  static TreeUtil instance;
  return &instance;
}

// empty 확인 empty면 return ""
// 아니면 result에 value 저장 좌 우 순으로 PreOrderTraversal 재귀
// 이후result = result, left, right 저장
// return result
const std::string TreeUtil::PreOrderTraversal(const Node* node) const {
  if (node == nullptr) {
    return "";
  }
  std::string result;
  std::string left;
  std::string right;

  if (const IntNode* intNode = dynamic_cast<const IntNode*>(node)) {
    result += std::to_string(intNode->value());
  } else if (const StringNode* stringNode =
                 dynamic_cast<const StringNode*>(node)) {
    result += stringNode->value();
  }

  left = PreOrderTraversal(node->left());
  right = PreOrderTraversal(node->right());

  if (!left.empty()) {
    result += ",";
    result += left;
  }
  if (!right.empty()) {
    result += ",";
    result += right;
  }

  return result;
}

// empty 확인 empty면 return ""
// 아니면 result에 value 저장 InOrderTraversal 재귀
// 이후result = left, result, right 저장
// return result
const std::string TreeUtil::InOrderTraversal(const Node* node) const {
  if (node == nullptr) {
    return "";
  }
  std::string result;
  std::string left;
  std::string right;

  if (const IntNode* intNode = dynamic_cast<const IntNode*>(node)) {
    result += std::to_string(intNode->value());
  } else if (const StringNode* stringNode =
                 dynamic_cast<const StringNode*>(node)) {
    result += stringNode->value();
  }

  left = InOrderTraversal(node->left());
  right = InOrderTraversal(node->right());

  if (!left.empty()) {
    result = left + "," + result;
  }
  if (!right.empty()) {
    result += "," + right;
  }

  return result;
}

// empty 확인 empty면 return ""
// 아니면 result에 value 저장 PostOrderTraversal 재귀
// 이후result = left, right, result 저장
// return result
const std::string TreeUtil::PostOrderTraversal(const Node* node) const {
  if (node == nullptr) {
    return "";
  }
  std::string result;
  std::string left;
  std::string right;

  if (const IntNode* intNode = dynamic_cast<const IntNode*>(node)) {
    result += std::to_string(intNode->value());
  } else if (const StringNode* stringNode =
                 dynamic_cast<const StringNode*>(node)) {
    result += stringNode->value();
  }

  left = PostOrderTraversal(node->left());
  right = PostOrderTraversal(node->right());

  if (!right.empty()) {
    result = right + "," + result;
  }
  if (!left.empty()) {
    result = left + "," + result;
  }

  return result;
}
