#include <gtest/gtest.h>

#include "list.h"
#include "queue.h"
#include "stack.h"
#include "vector.h"

class STLTest : public ::testing::Test {
 public:
 protected:
  STLTest() {}
  Vector* vector;
  List* list;
  Queue* queue;
  Stack* stack;
  void SetUp() override {
    vector = new Vector(4);
    list = new List();
    queue = new Queue();
    stack = new Stack(4);
  }
  void TearDown() override {
    delete vector;
    delete list;
    delete queue;
    delete stack;
  }
};

TEST_F(STLTest, VectorTest1) {
  vector->PushBack(3);
  EXPECT_EQ(vector->size(), 1);
  EXPECT_EQ(vector->capacity(), 4);
}

TEST_F(STLTest, VectorTest2) {
  int i = 0;
  Vector vector2(*vector);
  vector->PushBack(3);
  EXPECT_NE(vector2.size(), vector->size());
  ASSERT_DEATH(i = vector2[0], "Out of Bound");
}

TEST_F(STLTest, VectorTest3) {
  vector->PushBack(3);
  vector->PushBack(3);
  vector->PushBack(3);
  vector->PushBack(3);
  vector->PushBack(3);
  vector->PushBack(3);
  EXPECT_EQ(vector->size(), 6);
  EXPECT_EQ(vector->capacity(), 8);
}

TEST_F(STLTest, VectorTest4) {
  vector->PushBack(1);
  vector->PushBack(2);
  vector->PushBack(3);
  vector->PushBack(4);
  vector->PushBack(5);
  vector->PopBack();
  EXPECT_EQ(vector->size(), 4);
  EXPECT_EQ(vector->capacity(), 8);
  vector->PopBack();
  EXPECT_EQ(vector->capacity(), 8);
}

TEST_F(STLTest, VectorTest5) {
  EXPECT_TRUE(vector->IsEmpty());
  ASSERT_DEATH(vector->PopBack(), "Out of Bound");
}

TEST_F(STLTest, ListTest1) {
  list->PushBack(3);
  list->PushFront(1);
  EXPECT_EQ(list->size(), 2);
  EXPECT_EQ(list->At(0), 1);
}

TEST_F(STLTest, ListTest2) {
  int i = 0;
  List list2(*list);
  list->PushBack(3);
  EXPECT_NE(list2.size(), list->size());
  ASSERT_DEATH(i = list2.At(0), "Out of Bound");
}

TEST_F(STLTest, ListTest3) {
  list->PushBack(3);
  list->PushFront(2);
  list->PushFront(1);
  list->PushBack(4);
  list->PushBack(5);
  list->PushBack(6);
  EXPECT_EQ(list->size(), 6);
  ASSERT_DEATH(list->At(7), "Out of Bound");
}

TEST_F(STLTest, ListTest4) {
  list->PushBack(1);
  list->PushBack(2);
  list->PushBack(3);
  list->PushBack(4);
  list->PushBack(5);
  list->PopBack();
  EXPECT_EQ(list->size(), 4);
  EXPECT_EQ(list->At(3), 4);
  list->PopFront();
  EXPECT_EQ(list->At(0), 2);
}

TEST_F(STLTest, ListTest5) {
  EXPECT_TRUE(list->IsEmpty());
  ASSERT_DEATH(list->PopBack(), "Out of Bound");
}

TEST_F(STLTest, StackTest1) {
  stack->Push(3);
  EXPECT_EQ(stack->size(), 1);
  EXPECT_EQ(stack->capacity(), 4);
}

TEST_F(STLTest, StackTest2) {
  Stack stack2(0);
  stack2 = *stack;
  stack2.Push(1);
  stack->Push(3);
  EXPECT_EQ(stack2.Pop(), 1);
  EXPECT_NE(stack2.size(), stack->size());
  ASSERT_DEATH(stack2.Pop(), "Out of Bound");
}

TEST_F(STLTest, StackTest3) {
  stack->Push(3);
  stack->Push(3);
  stack->Push(3);
  stack->Push(3);
  stack->Push(3);
  stack->Push(3);
  EXPECT_EQ(stack->size(), 6);
  EXPECT_EQ(stack->capacity(), 8);
}

TEST_F(STLTest, StackTest4) {
  stack->Push(1);
  stack->Push(2);
  stack->Push(3);
  stack->Push(4);
  stack->Push(5);
  stack->Pop();
  EXPECT_EQ(stack->size(), 4);
  EXPECT_EQ(stack->capacity(), 8);
  stack->Pop();
  EXPECT_EQ(stack->capacity(), 8);
}

TEST_F(STLTest, StackTest5) {
  EXPECT_TRUE(stack->IsEmpty());
  ASSERT_DEATH(stack->Pop(), "Out of Bound");
}

TEST_F(STLTest, QueueTest1) {
  queue->Add(3);
  queue->Add(1);
  EXPECT_EQ(queue->size(), 2);
  EXPECT_EQ(queue->Poll(), 3);
}

TEST_F(STLTest, QueueTest2) {
  int i = 0;
  Queue queue2;
  queue2 = *queue;
  queue2.Add(4);
  queue->Add(3);
  EXPECT_EQ(queue2.Poll(), 4);
  EXPECT_NE(queue2.size(), queue->size());
  ASSERT_DEATH(queue2.Poll(), "Out of Bound");
}

TEST_F(STLTest, QueueTest3) {
  queue->Add(3);
  queue->Add(2);
  queue->Add(1);
  queue->Add(4);
  queue->Add(5);
  queue->Add(6);
  EXPECT_EQ(queue->size(), 6);
  EXPECT_EQ(queue->Poll(), 3);
}

TEST_F(STLTest, QueueTest4) {
  queue->Add(1);
  queue->Add(2);
  queue->Add(3);
  queue->Add(4);
  queue->Add(5);
  queue->Poll();
  EXPECT_EQ(queue->size(), 4);
  EXPECT_EQ(queue->Poll(), 2);
  queue->Poll();
  EXPECT_EQ(queue->size(), 2);
}

TEST_F(STLTest, QueueTest5) {
  EXPECT_TRUE(queue->IsEmpty());
  ASSERT_DEATH(queue->Poll(), "Out of Bound");
}
