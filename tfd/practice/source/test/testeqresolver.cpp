#include <limits.h>
#include "Variable.hpp"
#include "gtest/gtest.h"

namespace {

TEST(VariableTest, Negative) {
  Variable var;
  EXPECT_EQ(var.dumbMethodThatReturnsTrue(), true);
}

} // namespace
