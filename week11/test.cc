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

  template <typename Container>
  std::string PrintContainer(const Container& container) const {
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
  EXPECT_EQ(this->PrintContainer(this->arr), "0 1 2 3 4 5 6 8");
}

TEST_F(IntSortTest, IntVectorSortIncreasing) {
  this->vec = {4, 2, 7, 1, 9, 3, 6, 5};
  Sort<std::vector<int>, IntIncreasingOrder>(this->vec.begin(),
                                             this->vec.end());
  EXPECT_EQ(this->PrintContainer(this->vec), "1 2 3 4 5 6 7 9");
}

TEST_F(IntSortTest, IntListSortIncreasing) {
  this->lst = {8, 0, 5, 2, 7, 4, 6, 1};
  Sort<std::list<int>, IntIncreasingOrder>(this->lst.begin(), this->lst.end());
  EXPECT_EQ(this->PrintContainer(this->lst), "0 1 2 4 5 6 7 8");
}

TEST_F(IntSortTest, IntDequeSortIncreasing) {
  this->deq = {3, 3, 1, 2, 6, 5, 4, 0};
  Sort<std::deque<int>, IntIncreasingOrder>(this->deq.begin(), this->deq.end());
  EXPECT_EQ(this->PrintContainer(this->deq), "0 1 2 3 3 4 5 6");
}

using FloatSortTest = SortTest<float>;

TEST_F(FloatSortTest, FloatArrSortDecreasing) {
  this->arr = {1.5f, -2.0f, 3.5f, 0.0f, -1.0f, 2.0f, 4.0f, -3.0f};
  Sort<std::array<float, 8>, FloatDecreasingOrder>(this->arr.begin(),
                                                   this->arr.end());
  EXPECT_EQ(this->PrintContainer(this->arr), "4 3.5 2 1.5 0 -1 -2 -3");
}

TEST_F(FloatSortTest, FloatVectorSortDecreasing) {
  this->vec = {2.5f, -0.5f, 1.0f, 4.0f, -2.0f, 3.0f, -1.5f, 0.0f};
  Sort<std::vector<float>, FloatDecreasingOrder>(this->vec.begin(),
                                                 this->vec.end());
  EXPECT_EQ(this->PrintContainer(this->vec), "4 3 2.5 1 0 -0.5 -1.5 -2");
}

TEST_F(FloatSortTest, FloatListSortDecreasing) {
  this->lst = {-3.0f, 2.0f, 0.0f, 4.0f, -1.0f, 3.5f, -2.5f, 1.5f};
  Sort<std::list<float>, FloatDecreasingOrder>(this->lst.begin(),
                                               this->lst.end());
  EXPECT_EQ(this->PrintContainer(this->lst), "4 3.5 2 1.5 0 -1 -2.5 -3");
}

TEST_F(FloatSortTest, FloatDequeSortDecreasing) {
  this->deq = {0.0f, -1.0f, 2.0f, 5.0f, -2.0f, 3.0f, 1.0f, 4.0f};
  Sort<std::deque<float>, FloatDecreasingOrder>(this->deq.begin(),
                                                this->deq.end());
  EXPECT_EQ(this->PrintContainer(this->deq), "5 4 3 2 1 0 -1 -2");
}

using CharSortTest = SortTest<char>;

TEST_F(CharSortTest, CharArrSortIncreasing) {
  this->arr = {'d', 'a', 'c', 'b', 'h', 'e', 'g', 'f'};
  Sort<std::array<char, 8>, CharIncreasingOrder>(this->arr.begin(),
                                                 this->arr.end());
  EXPECT_EQ(this->PrintContainer(this->arr), "a b c d e f g h");
}

TEST_F(CharSortTest, CharVectorSortIncreasing) {
  this->vec = {'z', 'x', 'y', 'w', 'v', 'u', 't', 's'};
  Sort<std::vector<char>, CharIncreasingOrder>(this->vec.begin(),
                                               this->vec.end());
  EXPECT_EQ(this->PrintContainer(this->vec), "s t u v w x y z");
}

TEST_F(CharSortTest, CharListSortIncreasing) {
  this->lst = {'k', 'm', 'l', 'j', 'i', 'n', 'h', 'o'};
  Sort<std::list<char>, CharIncreasingOrder>(this->lst.begin(),
                                             this->lst.end());
  EXPECT_EQ(this->PrintContainer(this->lst), "h i j k l m n o");
}

TEST_F(CharSortTest, CharDequeSortIncreasing) {
  this->deq = {'c', 'b', 'd', 'a', 'h', 'g', 'f', 'e'};
  Sort<std::deque<char>, CharIncreasingOrder>(this->deq.begin(),
                                              this->deq.end());
  EXPECT_EQ(this->PrintContainer(this->deq), "a b c d e f g h");
}

using StringSortTest = SortTest<std::string>;

TEST_F(StringSortTest, StringArrSortLengthDecreasing) {
  this->arr = {"gg3",      "aaaaaaaa9", "ddddd6",  "h2",
               "bbbbbbb8", "fff4",      "cccccc7", "eeee5"};
  Sort<std::array<std::string, 8>, StringLengthDecreasingOrder>(
      this->arr.begin(), this->arr.end());
  EXPECT_EQ(this->PrintContainer(this->arr),
            "aaaaaaaa9 bbbbbbb8 cccccc7 ddddd6 eeee5 fff4 gg3 h2");
}

TEST_F(StringSortTest, StringVectorSortLengthDecreasing) {
  this->vec = {"xx3",  "yyyyyyyy9", "z2",      "kkkkk6",
               "mmm4", "nnnn5",     "pppppp7", "qqqqqqq8"};
  Sort<std::vector<std::string>, StringLengthDecreasingOrder>(this->vec.begin(),
                                                              this->vec.end());
  EXPECT_EQ(this->PrintContainer(this->vec),
            "yyyyyyyy9 qqqqqqq8 pppppp7 kkkkk6 nnnn5 mmm4 xx3 z2");
}

TEST_F(StringSortTest, StringListSortLengthDecreasing) {
  this->lst = {"alpha6",    "b2",   "charlie8", "dd3",
               "echoecho9", "foo4", "gogo5",    "fwouhu7"};
  Sort<std::list<std::string>, StringLengthDecreasingOrder>(this->lst.begin(),
                                                            this->lst.end());
  EXPECT_EQ(this->PrintContainer(this->lst),
            "echoecho9 charlie8 fwouhu7 alpha6 gogo5 foo4 dd3 b2");
}

TEST_F(StringSortTest, StringDequeSortLengthDecreasing) {
  this->deq = {"sun4",   "moonlight10", "star5", "galaxywide11",
               "cosmo6", "planet7",     "io3",   "nebulae8"};
  Sort<std::deque<std::string>, StringLengthDecreasingOrder>(this->deq.begin(),
                                                             this->deq.end());
  EXPECT_EQ(this->PrintContainer(this->deq),
            "galaxywide11 moonlight10 nebulae8 planet7 cosmo6 star5 sun4 io3");
}
