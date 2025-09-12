#include "gtest/gtest.h"
#include "util.h"

class UtilTest : public ::testing::Test {
 protected:
  void SetUp() override {}
  void TearDown() override {}
  Util u;
};

TEST_F(UtilTest, UtilAddTest1) { EXPECT_EQ(u.Add(1, 3), 4); }
TEST_F(UtilTest, UtilAddTest2) { EXPECT_EQ(u.Add(2, 3), 5); }
TEST_F(UtilTest, UtilAddTest3) { EXPECT_EQ(u.Add(1, 2), 3); }

TEST_F(UtilTest, UtilDivTest1) { ASSERT_DEATH(u.Div(1, 0), "Divide by Zero"); }
TEST_F(UtilTest, UtilDivTest2) { EXPECT_EQ(u.Div(6, 2), 3); }
TEST_F(UtilTest, UtilDivTest3) { EXPECT_EQ(u.Div(5, 2), 2); }

TEST_F(UtilTest, UtilSubTest1) { EXPECT_EQ(u.Sub(7, 3), 4); }
TEST_F(UtilTest, UtilSubTest2) { EXPECT_EQ(u.Sub(4, 3), 1); }
TEST_F(UtilTest, UtilSubTest3) { EXPECT_EQ(u.Sub(11, 0), 11); }

TEST_F(UtilTest, UtilMulTest1) { EXPECT_EQ(u.Mul(1, 3), 3); }
TEST_F(UtilTest, UtilMulTest2) { EXPECT_EQ(u.Mul(2, 3), 6); }
TEST_F(UtilTest, UtilMulTest3) { EXPECT_EQ(u.Mul(2, 2), 4); }
