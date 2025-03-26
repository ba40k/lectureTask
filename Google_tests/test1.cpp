#include <gtest/gtest.h>

#include "../Library.h"

class LibraryTesting : public testing::Test {
    public:
    Library lib;
};
TEST_F(LibraryTesting, handlesInsertingTest1) {
    ASSERT_EQ(0,lib.getSize());
}
TEST_F(LibraryTesting, handlesInsertingTest2) {
    Book book("Kolobok", "Folk", 1000);
    lib.addBook(std::make_unique<Book>(book));
    ASSERT_EQ(1,lib.getSize());
}
TEST_F(LibraryTesting, handlesInsertingTest3) {
    Book book("Kolobok", "Folk", 1000);
    lib.addBook(std::make_unique<Book>(book));
    lib.addBook(std::make_unique<Book>(book));
    ASSERT_EQ(2,lib.getSize());
}
TEST_F(LibraryTesting, handlesDeletingTest1) {
    Book book("Kolobok", "Folk", 1000);
    lib.removeBook(std::make_unique<Book>(book));
    ASSERT_EQ(0,lib.getSize());
}
TEST_F(LibraryTesting, handlesDeletingTest2) {
    Book book("Kolobok", "Folk", 1000);
    lib.addBook(std::make_unique<Book>(book));
    lib.removeBook(std::make_unique<Book>(book));
    ASSERT_EQ(0,lib.getSize());
}
TEST_F(LibraryTesting, handlesDeletingTest3) {
    Book book("Kolobok", "Folk", 1000);
    lib.addBook(std::make_unique<Book>(book));
    lib.addBook(std::make_unique<Book>(book));
    lib.removeBook(std::make_unique<Book>(book));
    ASSERT_EQ(1,lib.getSize());
}
TEST_F(LibraryTesting, handlesSearchingTest1) {
    Book book("Kolobok", "Folk", 1000);
    lib.addBook(std::make_unique<Book>(book));
    ASSERT_TRUE(lib.findBook(std::make_unique<Book>(book)));
}
TEST_F(LibraryTesting, handlesSearchingTest2) {
    Book book("C++ tour", "Bjarne Straustroup", 2022);
    lib.addBook(std::make_unique<Book>(book));
    Book secondBook("C++ tour", "Bjorn Straustroop", 2022);
    ASSERT_FALSE(lib.findBook(std::make_unique<Book>(secondBook)));
}
TEST_F(LibraryTesting, handlesSearchingTest3) {
    Book book("C++ tour", "Bjarne Straustroup", 2022);
    lib.addBook(std::make_unique<Book>(book));
    Book secondBook("C++ tour", "Bjarne Straustroup", 222);
    ASSERT_FALSE(lib.findBook(std::make_unique<Book>(secondBook)));
}
TEST_F(LibraryTesting, handlesSearchingTest4) {
    Book book("C++_tour", "Bjarne Straustroup", 2022);
    lib.addBook(std::make_unique<Book>(book));
    Book secondBook("C++ tour", "Bjarne Straustroup", 2022);
    ASSERT_FALSE(lib.findBook(std::make_unique<Book>(secondBook)));
}
TEST_F(LibraryTesting, handlesMixedTest1) {
    Book book("C++ tour", "Bjarne Straustroup", 2022);
    lib.addBook(std::make_unique<Book>(book));
    lib.removeBook(std::make_unique<Book>(book));
    ASSERT_FALSE(lib.findBook(std::make_unique<Book>(book)));
}
TEST_F(LibraryTesting, handlesMixedTest2) {
    Book book("C++ tour", "Bjarne Straustroup", 2022);
    lib.addBook(std::make_unique<Book>(book));
    lib.addBook(std::make_unique<Book>(book));
    lib.removeBook(std::make_unique<Book>(book));
    ASSERT_TRUE(lib.findBook(std::make_unique<Book>(book)));
}

