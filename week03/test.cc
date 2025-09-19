#include "float_accumulator.h"
#include "gtest/gtest.h"
#include "int_accumulator.h"

class IntAccTest : public ::testing::Test {
 public:
  IntAccTest() : acc_(3) {}

 protected:
  void SetUp() override {}
  void TearDown() override {}
  int_accumulator::Accumulator acc_;
};

class FloatAccTest : public ::testing::Test {
 public:
  FloatAccTest() : acc_(3.0) {}

 protected:
  void SetUp() override {}
  void TearDown() override {}
  float_accumulator::Accumulator acc_;
};

TEST_F(IntAccTest, IntAccTest1) {
  acc_.Add(5);
  EXPECT_EQ(acc_.acc(), 8);
}
TEST_F(IntAccTest, IntAccTest2) {
  acc_.Add(3);
  EXPECT_EQ(acc_.acc(), 6);
}
TEST_F(IntAccTest, IntAccTest3) {
  acc_.Add(0);
  EXPECT_EQ(acc_.acc(), 3);
}

TEST_F(IntAccTest, IntSubTest1) {
  acc_.Sub(1);
  EXPECT_EQ(acc_.acc(), 2);
}
TEST_F(IntAccTest, IntSubTest2) {
  acc_.Sub(3);
  EXPECT_EQ(acc_.acc(), 0);
}
TEST_F(IntAccTest, IntSubTest3) {
  acc_.Sub(5);
  EXPECT_EQ(acc_.acc(), -2);
}

TEST_F(IntAccTest, IntMulTest1) {
  acc_.Mul(1);
  EXPECT_EQ(acc_.acc(), 3);
}
TEST_F(IntAccTest, IntMulTest2) {
  acc_.Mul(5);
  EXPECT_EQ(acc_.acc(), 15);
}
TEST_F(IntAccTest, IntMulTest3) {
  acc_.Mul(0);
  EXPECT_EQ(acc_.acc(), 0);
}

TEST_F(IntAccTest, IntDivTest1) {
  acc_.Div(5);
  EXPECT_EQ(acc_.acc(), 0);
}
TEST_F(IntAccTest, IntDivTest2) {
  acc_.Div(3);
  EXPECT_EQ(acc_.acc(), 1);
}
TEST_F(IntAccTest, IntDivTest3) { ASSERT_DEATH(acc_.Div(0), "Divide by Zero"); }

TEST_F(FloatAccTest, FloatAddTest1) {
  acc_.Add(5);
  EXPECT_EQ(acc_.acc(), 8.0);
}
TEST_F(FloatAccTest, FloatAddTest2) {
  acc_.Add(3);
  EXPECT_EQ(acc_.acc(), 6);
}
TEST_F(FloatAccTest, FloatAddTest3) {
  acc_.Add(0);
  EXPECT_EQ(acc_.acc(), 3);
}

TEST_F(FloatAccTest, FloatSubTest1) {
  acc_.Sub(1);
  EXPECT_EQ(acc_.acc(), 2);
}
TEST_F(FloatAccTest, FloatSubTest2) {
  acc_.Sub(3);
  EXPECT_EQ(acc_.acc(), 0);
}
TEST_F(FloatAccTest, FloatSubTest3) {
  acc_.Sub(5);
  EXPECT_EQ(acc_.acc(), -2);
}

TEST_F(FloatAccTest, FloatMulTest1) {
  acc_.Mul(1);
  EXPECT_EQ(acc_.acc(), 3);
}
TEST_F(FloatAccTest, FloatMulTest2) {
  acc_.Mul(5);
  EXPECT_EQ(acc_.acc(), 15);
}
TEST_F(FloatAccTest, FloatMulTest3) {
  acc_.Mul(0);
  EXPECT_EQ(acc_.acc(), 0);
}

TEST_F(FloatAccTest, FloatDivTest1) {
  acc_.Div(12);
  EXPECT_EQ(acc_.acc(), 3.0 / 12.0);
}
TEST_F(FloatAccTest, FloatDivTest2) {
  acc_.Div(3);
  EXPECT_EQ(acc_.acc(), 1);
}
TEST_F(FloatAccTest, FloatDivTest3) {
  ASSERT_DEATH(acc_.Div(0), "Divide by Zero");
}
