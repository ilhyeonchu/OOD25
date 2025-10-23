#include "tree_util.h"

#include <string>

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
  const std::string current = node->value();
  const std::string left = PreOrderTraversal(node->left());
  const std::string right = PreOrderTraversal(node->right());
  std::string result = current;

  if (!left.empty()) {
    result += "," + left;
  }
  if (!right.empty()) {
    result += "," + right;
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
  const std::string left = InOrderTraversal(node->left());
  const std::string right = InOrderTraversal(node->right());
  std::string result = node->value();

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
  const std::string left = PostOrderTraversal(node->left());
  const std::string right = PostOrderTraversal(node->right());
  std::string result = node->value();

  if (!right.empty()) {
    result = right + "," + result;
  }
  if (!left.empty()) {
    result = left + "," + result;
  }

  return result;
}
