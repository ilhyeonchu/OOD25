#include <gtest/gtest.h>

#include "int_node.h"
#include "string_node.h"
#include "tree_util.h"

class TreeUtilTest : public ::testing::Test {
 public:
  Node* node_3 = new IntNode(3, nullptr, nullptr);
  Node* node_2 = new IntNode(2, nullptr, nullptr);
  Node* node_1 = new IntNode(1, node_2, node_3);
  StringNode* string_3 = new StringNode("c", nullptr, nullptr);
  StringNode* string_2 = new StringNode("b", nullptr, nullptr);
  StringNode* string_1 = new StringNode("a", string_2, string_3);

 protected:
  void SetUp() override {}
  void TearDown() override {
    delete node_3;
    delete node_2;
    delete node_1;
    delete string_3;
    delete string_2;
    delete string_1;
  }
  TreeUtil* tree_util = TreeUtil::GetInstance();
};

TEST_F(TreeUtilTest, PreOrdertest1) {
  std::string result = tree_util->PreOrderTraversal(node_1);
  EXPECT_EQ(result, "1,2,3");
}

TEST_F(TreeUtilTest, PreOrdertest2) {
  std::string result = tree_util->PreOrderTraversal(string_1);
  EXPECT_EQ(result, "a,b,c");
}

TEST_F(TreeUtilTest, PreOrdertest3) {
  Node* root = new IntNode(0, node_1, string_1);
  std::string result = tree_util->PreOrderTraversal(root);
  EXPECT_EQ(result, "0,1,2,3,a,b,c");
  delete root;
}

TEST_F(TreeUtilTest, InOrdertest1) {
  std::string result = tree_util->InOrderTraversal(node_1);
  EXPECT_EQ(result, "2,1,3");
}

TEST_F(TreeUtilTest, InOrdertest2) {
  std::string result = tree_util->InOrderTraversal(string_1);
  EXPECT_EQ(result, "b,a,c");
}

TEST_F(TreeUtilTest, InOrdertest3) {
  Node* root = new IntNode(0, node_1, string_1);
  std::string result = tree_util->InOrderTraversal(root);
  EXPECT_EQ(result, "2,1,3,0,b,a,c");
  delete root;
}

TEST_F(TreeUtilTest, PostOrdertest1) {
  std::string result = tree_util->PostOrderTraversal(node_1);
  EXPECT_EQ(result, "2,3,1");
}

TEST_F(TreeUtilTest, PostOrdertest2) {
  std::string result = tree_util->PostOrderTraversal(string_1);
  EXPECT_EQ(result, "b,c,a");
}

TEST_F(TreeUtilTest, PostOrdertest3) {
  Node* root = new IntNode(0, node_1, string_1);
  std::string result = tree_util->PostOrderTraversal(root);
  EXPECT_EQ(result, "2,3,1,b,c,a,0");
  delete root;
}
