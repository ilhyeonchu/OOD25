#include <gtest/gtest.h>

#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

#include "sort.h"

template <typename T>
class SortTest : public ::testing::Test {
 public:
  class IntIncreasingOrder {
   public:
    int operator()(const int& x, const int& y) {
      if (x > y) {
        return 1;
      } else {
        return 0;
      }
    }
  };

  class IntDecreasingOrder {
   public:
    int operator()(const int& x, const int& y) {
      if (x < y) {
        return 1;
      } else {
        return 0;
      }
    }
  };

  class FloatIncreasingOrder {
   public:
    int operator()(const float& x, const float& y) {
      if (x > y) {
        return 1;
      } else {
        return 0;
      }
    }
  };

  class FloatDecreasingOrder {
   public:
    int operator()(const float& x, const float& y) {
      if (x < y) {
        return 1;
      } else {
        return 0;
      }
    }
  };

  class CharIncreasingOrder {
   public:
    int operator()(const char& x, const char& y) {
      if (x > y) {
        return 1;
      } else {
        return 0;
      }
    }
  };

  class CharDecreasingOrder {
   public:
    int operator()(const char& x, const char& y) {
      if (y > x) {
        return 1;
      } else {
        return 0;
      }
    }
  };

  class StringLengthIncreasingOrder {
   public:
    int operator()(const std::string& x, const std::string& y) {
      if (x.size() > y.size()) {
        return 1;
      } else {
        return 0;
      }
    }
  };

  class StringLengthDecreasingOrder {
   public:
    int operator()(const std::string& x, const std::string& y) {
      if (y.length() > x.length()) {
        return 1;
      } else {
        return 0;
      }
    }
  };

  template <typename T>
  std::string ContainerToString(const T& container) const {
    std::ostringstream oss;
    bool first = true;
    for (const auto& n : container) {
      if (!first) {
        oss << ' ';
      }
      oss << n;
      first = false;
    }
    return oss.str();
  }

 protected:
  SortTest() {}
  std::array<T, 8> arr;
  std::vector<T> vec;
  std::list<T> lst;
  std::deque<T> deq;
};

using IntSortTest = SortTest<int>;

TEST_F(IntSortTest, IntArrSortIncreasing) {
  this->arr = {1, 3, 5, 2, 6, 8, 4, 0};
  Sort<std::array<int, 8>, IntIncreasingOrder>(this->arr.begin(),
                                               this->arr.end());
  EXPECT_EQ(this->ContainerToString(this->arr), "0 1 2 3 4 5 6 8");
}

TEST_F(IntSortTest, IntVectorSortIncreasing) {
  this->vec = {4, 2, 7, 1, 9, 3, 6, 5};
  Sort<std::vector<int>, IntIncreasingOrder>(this->vec.begin(),
                                             this->vec.end());
  EXPECT_EQ(this->ContainerToString(this->vec), "1 2 3 4 5 6 7 9");
}

TEST_F(IntSortTest, IntListSortIncreasing) {
  this->lst = {8, 0, 5, 2, 7, 4, 6, 1};
  Sort<std::list<int>, IntIncreasingOrder>(this->lst.begin(), this->lst.end());
  EXPECT_EQ(this->ContainerToString(this->lst), "0 1 2 4 5 6 7 8");
}

TEST_F(IntSortTest, IntDequeSortIncreasing) {
  this->deq = {3, 3, 1, 2, 6, 5, 4, 0};
  Sort<std::deque<int>, IntIncreasingOrder>(this->deq.begin(), this->deq.end());
  EXPECT_EQ(this->ContainerToString(this->deq), "0 1 2 3 3 4 5 6");
}

using FloatSortTest = SortTest<float>;

TEST_F(FloatSortTest, FloatArrSortDecreasing) {
  this->arr = {1.5f, -2.0f, 3.5f, 0.0f, -1.0f, 2.0f, 4.0f, -3.0f};
  Sort<std::array<float, 8>, FloatDecreasingOrder>(this->arr.begin(),
                                                   this->arr.end());
  EXPECT_EQ(this->ContainerToString(this->arr), "4 3.5 2 1.5 0 -1 -2 -3");
}

TEST_F(FloatSortTest, FloatVectorSortDecreasing) {
  this->vec = {2.5f, -0.5f, 1.0f, 4.0f, -2.0f, 3.0f, -1.5f, 0.0f};
  Sort<std::vector<float>, FloatDecreasingOrder>(this->vec.begin(),
                                                 this->vec.end());
  EXPECT_EQ(this->ContainerToString(this->vec), "4 3 2.5 1 0 -0.5 -1.5 -2");
}

TEST_F(FloatSortTest, FloatListSortDecreasing) {
  this->lst = {-3.0f, 2.0f, 0.0f, 4.0f, -1.0f, 3.5f, -2.5f, 1.5f};
  Sort<std::list<float>, FloatDecreasingOrder>(this->lst.begin(),
                                               this->lst.end());
  EXPECT_EQ(this->ContainerToString(this->lst), "4 3.5 2 1.5 0 -1 -2.5 -3");
}

TEST_F(FloatSortTest, FloatDequeSortDecreasing) {
  this->deq = {0.0f, -1.0f, 2.0f, 5.0f, -2.0f, 3.0f, 1.0f, 4.0f};
  Sort<std::deque<float>, FloatDecreasingOrder>(this->deq.begin(),
                                                this->deq.end());
  EXPECT_EQ(this->ContainerToString(this->deq), "5 4 3 2 1 0 -1 -2");
}

using CharSortTest = SortTest<char>;

TEST_F(CharSortTest, CharArrSortIncreasing) {
  this->arr = {'d', 'a', 'c', 'b', 'h', 'e', 'g', 'f'};
  Sort<std::array<char, 8>, CharIncreasingOrder>(this->arr.begin(),
                                                 this->arr.end());
  EXPECT_EQ(this->ContainerToString(this->arr), "a b c d e f g h");
}

TEST_F(CharSortTest, CharVectorSortIncreasing) {
  this->vec = {'z', 'x', 'y', 'w', 'v', 'u', 't', 's'};
  Sort<std::vector<char>, CharIncreasingOrder>(this->vec.begin(),
                                               this->vec.end());
  EXPECT_EQ(this->ContainerToString(this->vec), "s t u v w x y z");
}

TEST_F(CharSortTest, CharListSortIncreasing) {
  this->lst = {'k', 'm', 'l', 'j', 'i', 'n', 'h', 'o'};
  Sort<std::list<char>, CharIncreasingOrder>(this->lst.begin(),
                                             this->lst.end());
  EXPECT_EQ(this->ContainerToString(this->lst), "h i j k l m n o");
}

TEST_F(CharSortTest, CharDequeSortIncreasing) {
  this->deq = {'c', 'b', 'd', 'a', 'h', 'g', 'f', 'e'};
  Sort<std::deque<char>, CharIncreasingOrder>(this->deq.begin(),
                                              this->deq.end());
  EXPECT_EQ(this->ContainerToString(this->deq), "a b c d e f g h");
}
