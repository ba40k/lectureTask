#include <gtest/gtest.h>

#include "../Library.h"

class LibraryTesting : public testing::Test {
    public:
    Library lib;
};

TEST_F(LibraryTesting, handlesSearchingTest1) {
    Book book("Kolobok", "Folk", 1000);
    lib.addBook(book);
    ASSERT_TRUE(lib.findBook(book));
}
TEST_F(LibraryTesting, handlesSearchingTest2) {
    Book book("C++ tour", "Bjarne Straustroup", 2022);
    lib.addBook(book);
    Book secondBook("C++ tour", "Bjorn Straustroop", 2022);
    ASSERT_FALSE(lib.findBook(secondBook));
}