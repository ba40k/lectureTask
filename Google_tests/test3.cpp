//
// Created by radamir on 27.03.25.
//
#include "../Library.h"
#include <gtest/gtest.h>
class ComplexLibraryTesting : public ::testing::Test {
  public:
  Library lib;
};

TEST_F(ComplexLibraryTesting, handlesUserAddingTest1) {
  ASSERT_EQ(0,lib.getNumberOfUsers());
}