#include <gtest/gtest.h>

bool f() {
  return true;
}

TEST(ExampleTests, DemonstrateGTestMacros) {
  // //Convention is expected value first, actual value second
  const bool result = f();
  EXPECT_EQ(true, result);
  // EXPECT_EQ(true, true);
  // EXPECT_EQ(true, false);
  // EXPECT_TRUE(false);
  // ASSERT_TRUE(false);
  // EXPECT_TRUE(false);
}