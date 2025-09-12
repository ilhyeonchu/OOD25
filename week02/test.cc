#include <cassert>

#include "gtest/gtest.h"
#include "util.h"

class UtilTest : public ::testing::Test {
 protected:
  void SetUp() override {}
  void TearDown() override {}
  Util u;
};

TEST_F(UtilTest, UtilAddTEst1) { EXPECT_EQ(u.Add(1, 3), 4); }

TEST_F(UtilTest, UtilDivTest1) { ASSERT_DEATH(u.Div(1, 0), "Divide by Zero"); }
