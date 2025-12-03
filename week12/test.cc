#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

#include "divide_by_zero_exception.h"
#include "empty_container_exception.h"
#include "list.h"
#include "safe_int.h"
#include "vector.h"

class STLTest : public ::testing::Test {
 public:
 protected:
  STLTest() {}
  Vector<int>* vector;
  List<int>* list;

  void SetUp() override {
    vector = new Vector<int>(4);
    list = new List<int>();
  }
  void TearDown() override {
    delete vector;
    delete list;
  }
};

class STLStringTest : public ::testing::Test {
 public:
 protected:
  STLStringTest() {}
  Vector<std::string>* vector;
  List<std::string>* list;
  void SetUp() override {
    vector = new Vector<std::string>(4);
    list = new List<std::string>();
  }
  void TearDown() override {
    delete vector;
    delete list;
  }
};

TEST_F(STLStringTest, VectorStringTest1) {
  vector->PushBack("world");
  EXPECT_EQ(vector->size(), 1);
  EXPECT_EQ(vector->capacity(), 4);
}

TEST_F(STLStringTest, VectorStringTest2) {
  Vector vector2(*vector);
  vector->PushBack("world");
  EXPECT_NE(vector2.size(), vector->size());
  // ASSERT_DEATH(vector2[0], "Out of Bound");
  EXPECT_THROW(vector2[0], std::out_of_range);
}

TEST_F(STLStringTest, VectorStringTest3) {
  vector->PushBack("hello");
  vector->PushBack("world");
  vector->PushBack("cpp");
  vector->PushBack("ewoifh");
  vector->PushBack("cpp");
  vector->PushBack("eofwih");

  EXPECT_EQ(vector->size(), 6);
  EXPECT_EQ(vector->capacity(), 8);
}

TEST_F(STLStringTest, VectorStringTest4) {
  vector->PushBack("world");
  vector->PushBack("cpp");
  vector->PushBack("ewoifh");
  vector->PushBack("cpp");
  vector->PushBack("eofwih");
  vector->PopBack();
  EXPECT_EQ(vector->size(), 4);
  EXPECT_EQ(vector->capacity(), 8);
  vector->PopBack();
  EXPECT_EQ(vector->capacity(), 8);
}

TEST_F(STLStringTest, VectorStringTest5) {
  EXPECT_TRUE(vector->IsEmpty());
  EXPECT_THROW(vector->PopBack(), EmptyContainerException);
  try {
    vector->PopBack();
  } catch (EmptyContainerException& e) {
    std::string err = e.what();
    EXPECT_EQ("This vector is empty", err);
  }
}

TEST_F(STLStringTest, ListStringTest1) {
  list->PushBack("world");
  EXPECT_EQ(list->At(0), "world");
  list->PushFront("hello");
  EXPECT_EQ(list->size(), 2);
  EXPECT_EQ(list->At(0), "hello");
}

TEST_F(STLStringTest, ListStringTest2) {
  List list2(*list);
  list->PushBack("cpp");
  EXPECT_NE(list2.size(), list->size());
  EXPECT_EQ(list->At(0), "cpp");
  // ASSERT_DEATH(list2.At(0), "Out of Bound");
  EXPECT_THROW(list2.At(0), std::out_of_range);
}

TEST_F(STLStringTest, ListStringTest3) {
  list->PushBack("world");
  list->PushFront("hello");
  list->PushFront("cpp");
  list->PushBack("weofihew");
  list->PushBack("ewfj");
  list->PushBack("wejf");
  EXPECT_EQ(list->At(5), "wejf");
  EXPECT_EQ(list->At(1), "hello");
  EXPECT_EQ(list->At(0), "cpp");
  EXPECT_EQ(list->size(), 6);
  // ASSERT_DEATH(list->At(7), "Out of Bound");
  EXPECT_THROW(list->At(7), std::out_of_range);
}

TEST_F(STLStringTest, ListStringTest4) {
  list->PushBack("world");
  list->PushFront("hello");
  list->PushFront("cpp");
  list->PushBack("weofihew");
  list->PushBack("ewfj");
  list->PopBack();
  EXPECT_EQ(list->size(), 4);
  EXPECT_EQ(list->At(3), "weofihew");
  list->PopFront();
  EXPECT_EQ(list->At(0), "hello");
}

TEST_F(STLStringTest, ListStringTest5) {
  EXPECT_TRUE(list->IsEmpty());
  // ASSERT_DEATH(list->PopBack(), "Out of Bound");
  EXPECT_THROW(list->PopBack(), EmptyContainerException);
}

TEST_F(STLStringTest, ListStringTest6) {
  list->PushBack("3");
  EXPECT_EQ(list->At(0), "3");
  list->PopBack();
  EXPECT_EQ(list->size(), 0);
  list->PushFront("1");
  list->PopFront();
  // ASSERT_DEATH(list->PopFront(), "Out of Bound");
  EXPECT_THROW(list->PopFront(), EmptyContainerException);
}
