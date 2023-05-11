// Copyright 2023 Uvarkin Ilya

#include <gtest/gtest.h>
#include "include/set.h"

TEST(Set, assert_no_throw_in_default_constructor) {
  ASSERT_NO_THROW(Set set);
}

TEST(Set, assert_no_throw_in_constructor) {
  ASSERT_NO_THROW(Set set(std::vector<int>{1, 2, 3, 42}));
}

TEST(Set, count_elem_not_exist) {
  Set set;

  EXPECT_EQ(set.count(42), 0);
}

TEST(Set, count_elem_exist) {
  Set set;
  set.insert(42);
  EXPECT_EQ(set.count(42), 1);
}

TEST(Set, insert_elem) {
  Set set;
  set.insert(42);
  EXPECT_EQ(set.count(42), 1);
}

TEST(Set, erase_elem) {
  Set set;

  set.insert(42);
  set.erase(42);

  EXPECT_EQ(set.count(42), 0);
}
