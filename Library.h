//
// Created by radamir on 19.03.25.
//

#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include<memory>
#include "Book.h"
class Library {
    typedef  std::vector<std::shared_ptr<Book>>::const_iterator bookIteratorType;
    std::vector<std::shared_ptr<Book>> books;
    const std::shared_ptr<Book> parseBook(const Book& book) const;
    bookIteratorType getBookIterator(const Book& book) const;
    public:
    Library() = default;
    int getSize() const;
    bool findBook(const Book& book) const;
    void addBook(const Book& book);
    void removeBook(const Book& book);
};



#endif //LIBRARY_H
