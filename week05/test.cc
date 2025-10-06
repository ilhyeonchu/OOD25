#include <functional>

#include "gtest/gtest.h"
#include "int_set.h"

class IntSetTest : public ::testing::Test {
 public:
  IntSetTest() : intset_(6), addset_(3) {}
  std::function<bool(int)> Lt20 = [](int i) {
    if (i < 20) {
      return true;
    } else {
      return false;
    }
  };
  std::function<bool(int)> Gt10 = [](int i) {
    if (i > 10) {
      return true;
    } else {
      return false;
    }
  };
  std::function<bool(int)> Eq15 = [](int i) {
    if (i == 15) {
      return true;
    } else {
      return false;
    }
  };
  std::function<int(int)> Add10 = [](int i) { return i + 10; };
  std::function<int(int)> Double = [](int i) { return i * 2; };
  std::function<int(int)> Sub3 = [](int i) { return i - 3; };
  std::function<int(int)> Mul0 = [](int i) { return i * 0; };

 protected:
  void SetUp() override {
    addset_.Add(22);
    addset_.Add(9);
    intset_.Add(11);
    intset_.Add(18);
    intset_.Add(12);
  }
  void TearDown() override {}
  IntSet intset_;
  IntSet addset_;
};

TEST_F(IntSetTest, DeepCopyTest1) {
  IntSet copyset_(addset_);
  EXPECT_EQ(copyset_.size(), addset_.size());
}

TEST_F(IntSetTest, DeepCopyTest2) {
  IntSet copyset_(addset_);
  addset_.Add(15);
  EXPECT_NE(copyset_.size(), addset_.size());
}

TEST_F(IntSetTest, DeepCopyTest3) {
  IntSet copyset_(addset_);
  EXPECT_EQ(copyset_.capacity(), addset_.capacity());
}

TEST_F(IntSetTest, CapacityTest1) { EXPECT_EQ(intset_.capacity(), 6); }

TEST_F(IntSetTest, CapacityTest2) { EXPECT_EQ(addset_.capacity(), 3); }

TEST_F(IntSetTest, CapacityTest3) {
  intset_.Add(5);
  intset_.Add(6);
  intset_.Add(7);
  intset_.Add(14);
  EXPECT_EQ(intset_.size(), 7);
  EXPECT_EQ(intset_.capacity(), 10);
}

TEST_F(IntSetTest, SizeTest1) { EXPECT_EQ(intset_.size(), 3); }

TEST_F(IntSetTest, SizeTest2) {
  intset_.Add(5);
  intset_.Add(5);
  EXPECT_EQ(intset_.size(), 4);
}

TEST_F(IntSetTest, SizeTest3) {
  intset_.Add(addset_);
  EXPECT_EQ(intset_.size(), 5);
}

TEST_F(IntSetTest, AddTest1) {
  intset_.Add(3);
  EXPECT_EQ(intset_.size(), 4);
}

TEST_F(IntSetTest, AddTest2) {
  intset_.Add(3);
  intset_.Add(3);
  EXPECT_EQ(intset_.size(), 4);
}

TEST_F(IntSetTest, AddTest3) {
  intset_.Add(5);
  intset_.Add(6);
  intset_.Add(7);
  EXPECT_EQ(intset_.size(), 6);
}

TEST_F(IntSetTest, AddSetTest1) {
  intset_.Add(addset_);
  EXPECT_EQ(intset_.size(), 5);
}

TEST_F(IntSetTest, AddSetTest2) {
  intset_.Add(addset_);
  addset_.Add(3);
  EXPECT_EQ(intset_.size(), 5);
}

TEST_F(IntSetTest, AddSetTest3) {
  addset_.Add(3);
  intset_.Add(addset_);
  EXPECT_EQ(intset_.size(), 6);
}

TEST_F(IntSetTest, MapTest1) {
  intset_.Map(Add10);
  EXPECT_EQ(intset_.elements()[0], 21);
  EXPECT_EQ(intset_.elements()[1], 28);
  EXPECT_EQ(intset_.elements()[2], 22);
}

TEST_F(IntSetTest, MapTest2) {
  intset_.Map(Double);
  EXPECT_EQ(intset_.elements()[0], 22);
  EXPECT_EQ(intset_.elements()[1], 36);
  EXPECT_EQ(intset_.elements()[2], 24);
}

TEST_F(IntSetTest, MapTest3) {
  intset_.Map(Sub3);
  EXPECT_EQ(intset_.elements()[0], 8);
  EXPECT_EQ(intset_.elements()[1], 15);
  EXPECT_EQ(intset_.elements()[2], 9);
}

TEST_F(IntSetTest, ForAllTest1) { EXPECT_TRUE(intset_.ForAll(Lt20)); }

TEST_F(IntSetTest, ForAllTest2) { EXPECT_FALSE(intset_.ForAll(Eq15)); }

TEST_F(IntSetTest, ForAllTest3) {
  intset_.Add(addset_);
  intset_.Map(Add10);
  EXPECT_TRUE(intset_.ForAll(Gt10));
}

// 수정한 부분 destructor, operator(overloading), Add, Map
TEST_F(IntSetTest, NewMapTest1) {
  intset_.Map(Mul0);
  EXPECT_EQ(intset_.size(), 1);
  EXPECT_EQ(intset_.elements()[2], 0);
}

TEST_F(IntSetTest, NewAddTest1) {
  intset_.Add(24);
  EXPECT_EQ(intset_.size(), 4);
}

TEST_F(IntSetTest, NewAddTest2) {
  intset_.Add(24);
  intset_.Add(55);
  intset_.Add(37);
  intset_.Add(56);
  EXPECT_EQ(intset_.size(), 7);
  EXPECT_EQ(intset_.capacity(), 10);
}

TEST_F(IntSetTest, NewAddTest3) {
  intset_.Add(24);
  intset_.Add(55);
  intset_.Add(37);
  intset_.Add(56);
  intset_.Add(197);
  EXPECT_EQ(intset_.size(), 8);
  EXPECT_EQ(intset_.capacity(), 10);
}

TEST_F(IntSetTest, NewAddSetTest1) {
  intset_.Add(addset_);
  EXPECT_EQ(intset_.capacity(), 6);
  EXPECT_EQ(intset_.size(), 5);
}

TEST_F(IntSetTest, NewAddSetTest2) {
  intset_.Add(24);
  intset_.Add(55);
  intset_.Add(37);
  intset_.Add(addset_);
  EXPECT_EQ(intset_.size(), 8);
  EXPECT_EQ(intset_.capacity(), 10);
}

TEST_F(IntSetTest, NewAddSetTest3) {
  intset_.Add(24);
  intset_.Add(55);
  intset_.Add(37);
  intset_.Add(56);
  intset_.Add(68);
  intset_.Add(addset_);
  intset_.Add(addset_);
  addset_.Add(106);
  EXPECT_EQ(intset_.size(), 10);
  EXPECT_EQ(intset_.capacity(), 10);
}

TEST_F(IntSetTest, OpTest1) { EXPECT_EQ(intset_[2], 12); }

TEST_F(IntSetTest, OpTest2) { ASSERT_DEATH(intset_[4], "Out of bound"); }

TEST_F(IntSetTest, OpTest3) { ASSERT_DEATH(intset_[-3], "Out of bound"); }
