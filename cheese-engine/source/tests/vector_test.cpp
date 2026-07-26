#include "vector_2.hpp"
#include "vector_3.hpp"
#include "vector_4.hpp"

#include <iostream>
#include <gtest/gtest.h>
#include <SDL3/SDL.h>


TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}