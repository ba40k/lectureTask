#include <gtest/gtest.h>

#include "../Library.h"

class LibraryTesting : public testing::Test {
    public:
    Library lib;
};

TEST_F(LibraryTesting, handlesSearchingTest1) {
    Book book;

}