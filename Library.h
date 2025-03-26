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
    const std::shared_ptr<Book> parseBookToSharedPtr(const std::unique_ptr<Book> &book) const;
    std::weak_ptr<Book> parseBookToWeakPtr(const std::unique_ptr<Book> &book) const;
    bookIteratorType getBookIterator(const std::unique_ptr<Book> &book) const;
    public:
    Library() = default;
    int getSize() const;
    std::vector<QString> getBookInfo(const std::unique_ptr<Book> &book) const;
    bool findBook(const std::unique_ptr<Book> &book) const;
    std::vector<Book> getAllBooksByAuthor(const QString &_author) const; // дает все книги с заданным автором
    std::vector<Book> getAllBooksByTitle(const QString &_title) const;  // дает все книги с заданным названием
    std::vector<Book> getAllBooksByAuthorAndTitle(const QString &_author, const QString &_title) const; // дает все книги с заданным автором и названием
    Book getAnyBookByAuthor(const QString &_author) const; // дает некую книгу с заданным автором
    Book getAnyBookByTitle(const QString &_title) const;  // дает некую книгу с заданным названием
    Book getAnyBookByAuthorAndTitle(const QString &_author, const QString &_title) const; // дает некую книгу с заданным автором и названием
    std::vector<Book> getBooksListed() const ;
    void addBook(const std::unique_ptr<Book> &book);
    void removeBook(const std::unique_ptr<Book> &book);
};

#endif //LIBRARY_H
