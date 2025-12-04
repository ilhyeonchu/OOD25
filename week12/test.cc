#include <gtest/gtest.h>

#include <limits>
#include <stdexcept>
#include <string>

#include "divide_by_zero_exception.h"
#include "empty_container_exception.h"
#include "list.h"
#include "safe_int.h"
#include "vector.h"

class ExceptionTest : public ::testing::Test {
 protected:
  const int kMax = std::numeric_limits<int>::max();
  const int kMin = std::numeric_limits<int>::min();
};

TEST_F(ExceptionTest, SafeIntAddPP) {
  SafeInt lhs(kMax);
  SafeInt rhs(5);
  EXPECT_THROW(lhs + rhs, std::overflow_error);
  try {
    lhs + rhs;
  } catch (std::overflow_error& e) {
    std::string err = e.what();
    EXPECT_EQ("Integer overflow occurs in " + std::to_string(kMax) + " + 5",
              err);
  }
}

TEST_F(ExceptionTest, SafeIntAddNN) {
  SafeInt lhs(kMin);
  SafeInt rhs(-1);
  EXPECT_THROW(lhs + rhs, std::overflow_error);
  try {
    lhs + rhs;
  } catch (std::overflow_error& e) {
    std::string err = e.what();
    EXPECT_EQ("Integer overflow occurs in " + std::to_string(kMin) + " + -1",
              err);
  }
}

TEST_F(ExceptionTest, SafeIntSubNP) {
  SafeInt lhs(kMin);
  SafeInt rhs(1);
  EXPECT_THROW(lhs - rhs, std::overflow_error);
  try {
    lhs - rhs;
  } catch (std::overflow_error& e) {
    std::string err = e.what();
    EXPECT_EQ("Integer overflow occurs in " + std::to_string(kMin) + " - 1",
              err);
  }
}

TEST_F(ExceptionTest, SafeIntSubPN) {
  SafeInt lhs(kMax);
  SafeInt rhs(-1);
  EXPECT_THROW(lhs - rhs, std::overflow_error);
  try {
    lhs - rhs;
  } catch (std::overflow_error& e) {
    std::string err = e.what();
    EXPECT_EQ("Integer overflow occurs in " + std::to_string(kMax) + " - -1",
              err);
  }
}

TEST_F(ExceptionTest, SafeIntMulPP) {
  SafeInt lhs(50000);
  SafeInt rhs(50000);
  EXPECT_THROW(lhs * rhs, std::overflow_error);
  try {
    lhs* rhs;
  } catch (std::overflow_error& e) {
    std::string err = e.what();
    EXPECT_EQ("Integer overflow occurs in 50000 * 50000", err);
  }
}

TEST_F(ExceptionTest, SafeIntMulPN) {
  SafeInt lhs(kMax);
  SafeInt rhs(-2);
  EXPECT_THROW(lhs * rhs, std::overflow_error);
  try {
    lhs* rhs;
  } catch (std::overflow_error& e) {
    std::string err = e.what();
    EXPECT_EQ("Integer overflow occurs in " + std::to_string(kMax) + " * -2",
              err);
  }
}

TEST_F(ExceptionTest, SafeIntMulNN) {
  SafeInt lhs(-50000);
  SafeInt rhs(-50000);
  EXPECT_THROW(lhs * rhs, std::overflow_error);
  try {
    lhs* rhs;
  } catch (std::overflow_error& e) {
    std::string err = e.what();
    EXPECT_EQ("Integer overflow occurs in -50000 * -50000", err);
  }
}

TEST_F(ExceptionTest, SafeIntDivByZero) {
  SafeInt lhs(2147483647);
  SafeInt rhs(0);
  EXPECT_THROW(lhs / rhs, DivideByZeroException);
  try {
    lhs / rhs;
  } catch (DivideByZeroException& e) {
    std::string err = e.what();
    EXPECT_EQ("Divide-by-zero exception occurs in 2147483647 / 0", err);
  }
}

TEST_F(ExceptionTest, SafeIntModByZero) {
  SafeInt lhs(120);
  SafeInt rhs(0);
  EXPECT_THROW(lhs % rhs, DivideByZeroException);
  try {
    lhs % rhs;
  } catch (DivideByZeroException& e) {
    std::string err = e.what();
    EXPECT_EQ("Divide-by-zero exception occurs in 120 % 0", err);
  }
}

TEST_F(ExceptionTest, SafeIntNormal) {
  SafeInt a(18);
  SafeInt b(6);
  SafeInt c(-9);
  SafeInt d(4);

  EXPECT_EQ(24, (a + b).value());
  EXPECT_EQ(9, (a + c).value());
  EXPECT_EQ(12, (a - b).value());
  EXPECT_EQ(27, (a - c).value());
  EXPECT_EQ(72, (a * d).value());
  EXPECT_EQ(-162, (a * c).value());
  EXPECT_EQ(-36, (c * d).value());
  EXPECT_EQ(3, (a / b).value());
  EXPECT_EQ(-1, (c / b).value());
  EXPECT_EQ(6, (b % a).value());
  EXPECT_EQ(2, (a % d).value());
}

TEST_F(ExceptionTest, VectorEmptyTest1) {
  Vector<int> v(2);
  EXPECT_THROW(v.PopBack(), EmptyContainerException);
  try {
    v.PopBack();
  } catch (EmptyContainerException& e) {
    std::string err = e.what();
    EXPECT_EQ("This vector is empty", err);
  }
}

TEST_F(ExceptionTest, VectorEmptyTest2) {
  Vector<int> v(2);
  v.PushBack(10);
  v.PopBack();
  EXPECT_THROW(v.PopBack(), EmptyContainerException);
  try {
    v.PopBack();
  } catch (EmptyContainerException& e) {
    std::string err = e.what();
    EXPECT_EQ("This vector is empty", err);
  }
}

TEST_F(ExceptionTest, VectorEmptyTest3) {
  Vector<int> v(2);
  v.PushBack(1);
  v.PushBack(2);
  v.PushBack(3);
  v.PushBack(4);
  v.PopBack();
  v.PopBack();
  v.PopBack();
  v.PopBack();
  EXPECT_THROW(v.PopBack(), EmptyContainerException);
  try {
    v.PopBack();
  } catch (EmptyContainerException& e) {
    std::string err = e.what();
    EXPECT_EQ("This vector is empty", err);
  }
}

TEST_F(ExceptionTest, ListEmptyTest1) {
  List<int> l;
  EXPECT_THROW(l.PopBack(), EmptyContainerException);
  try {
    l.PopBack();
  } catch (EmptyContainerException& e) {
    std::string err = e.what();
    EXPECT_EQ("This list is empty", err);
  }
}

TEST_F(ExceptionTest, ListEmptyTest2) {
  List<int> l;
  l.PushBack(1);
  l.PopBack();
  EXPECT_THROW(l.PopBack(), EmptyContainerException);
  try {
    l.PopBack();
  } catch (EmptyContainerException& e) {
    std::string err = e.what();
    EXPECT_EQ("This list is empty", err);
  }
}

TEST_F(ExceptionTest, ListEmptyTest3) {
  List<int> l;
  l.PushBack(1);
  l.PushBack(2);
  l.PushBack(3);
  l.PushBack(4);
  l.PopBack();
  l.PopBack();
  l.PopBack();
  l.PopBack();
  EXPECT_THROW(l.PopBack(), EmptyContainerException);
  try {
    l.PopBack();
  } catch (EmptyContainerException& e) {
    std::string err = e.what();
    EXPECT_EQ("This list is empty", err);
  }
}

TEST_F(ExceptionTest, VectorOutOfRangeTest1) {
  Vector<int> v(2);
  EXPECT_THROW(v[0], std::out_of_range);
  try {
    v[0];
  } catch (std::out_of_range& e) {
    std::string err = e.what();
    EXPECT_EQ("The index is 0, but the size is 0", err);
  }
}

TEST_F(ExceptionTest, VectorOutOfRangeTest2) {
  Vector<int> v(3);
  v.PushBack(1);
  v.PushBack(2);
  v.PushBack(3);
  EXPECT_THROW(v[4], std::out_of_range);
  try {
    v[4];
  } catch (std::out_of_range& e) {
    std::string err = e.what();
    EXPECT_EQ("The index is 4, but the size is 3", err);
  }
}

TEST_F(ExceptionTest, VectorOutOfRangeTest3) {
  Vector<int> v(3);
  v.PushBack(1);
  v.PushBack(2);
  v.PushBack(3);
  EXPECT_THROW(v[-1], std::out_of_range);
  try {
    v[-1];
  } catch (std::out_of_range& e) {
    std::string err = e.what();
    EXPECT_EQ("The index is -1, but the size is 3", err);
  }
}

TEST_F(ExceptionTest, ListOutOfRangeTest1) {
  List<int> l;
  EXPECT_THROW(l.At(0), std::out_of_range);
  try {
    l.At(0);
  } catch (std::out_of_range& e) {
    std::string err = e.what();
    EXPECT_EQ("The index is 0, but the size is 0", err);
  }
}

TEST_F(ExceptionTest, ListOutOfRangeTest2) {
  List<int> l;
  l.PushBack(1);
  l.PushBack(2);
  l.PushBack(3);
  EXPECT_THROW(l.At(5), std::out_of_range);
  try {
    l.At(5);
  } catch (std::out_of_range& e) {
    std::string err = e.what();
    EXPECT_EQ("The index is 5, but the size is 3", err);
  }
}

TEST_F(ExceptionTest, ListOutOfRangeTest3) {
  List<int> l;
  l.PushBack(1);
  l.PushBack(2);
  l.PushBack(3);
  EXPECT_THROW(l.At(-2), std::out_of_range);
  try {
    l.At(-2);
  } catch (std::out_of_range& e) {
    std::string err = e.what();
    EXPECT_EQ("The index is -2, but the size is 3", err);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
