#include "unity.h"

#include "logger.h"

TEST_CASE("Add two numbers", "[logger]") {
  TEST_ASSERT_EQUAL(3, add(1, 2));
}
