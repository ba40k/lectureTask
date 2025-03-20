//
// Created by radamir on 19.03.25.
//

#include "Library.h"
#include <algorithm>
#include <iostream>

const std::shared_ptr<Book> Library::parseBookToSharedPtr(const Book &book) const {
  return std::make_shared<Book>(book);
}
std::weak_ptr<Book> Library::parseBookToWeakPtr(const Book &book) const {
  std::weak_ptr<Book> wp = parseBookToSharedPtr(book);
  return wp;
}
bool Library::findBook(const Book& book) const{
  for (auto &bookPointer : books) {
      if (*bookPointer == book) {
        return true;
      }
  }
  return false;
}
Library::bookIteratorType Library::getBookIterator(const Book& book) const {
  for (bookIteratorType it = books.begin(); it != books.end(); it++) {
    if (*(*it) == book) {
      return it;
    }
  }
  return books.end();
}
void Library::addBook(const Book& book){
  books.push_back(parseBookToSharedPtr(book));
}
void Library::removeBook(const Book& book){
  if (findBook(book)){
     books.erase(getBookIterator(book));
  }
}
int Library::getSize() const {
  return books.size();
}

std::vector<Book> Library::getAllBooksByAuthor(const QString &_author) const {
  std::vector<Book> result;
  for (bookIteratorType it = books.begin(); it != books.end(); it++) {
    if ((*it)->getAuthor() == _author) {
      result.push_back(*(*it));
    }
  }
  return result;
}
std::vector<Book> Library::getAllBooksByTitle(const QString &_title) const {
  std::vector<Book> result;
  for (bookIteratorType it = books.begin(); it != books.end(); it++) {
    if ((*it)->getTitle() == _title) {
      result.push_back(*(*it));
    }
  }
  return result;
}
std::vector<Book> Library::getAllBooksByAuthorAndTitle(const QString &_author,const QString &_title) const {
  std::vector<Book> result;
  for (bookIteratorType it = books.begin(); it != books.end(); it++) {
    if ((*it)->getTitle() == _title && (*it)->getAuthor() == _author) {
      result.push_back(*(*it));
    }
  }
  return result;
}

Book Library::getAnyBookByAuthor(const QString &_author) const {
  for (bookIteratorType it = books.begin(); it != books.end(); it++) {
    if ((*it)->getAuthor() == _author) {
      return *(*it);
    }
  }
}
Book Library::getAnyBookByTitle(const QString &_title) const {
  for (bookIteratorType it = books.begin(); it != books.end(); it++) {
    if ((*it)->getTitle() == _title) {
      return *(*it);
    }
  }
}

Book Library::getAnyBookByAuthorAndTitle(const QString &_author, const QString &_title) const {
  for (bookIteratorType it = books.begin(); it != books.end(); it++) {
    if ((*it)->getAuthor() == _author && (*it)->getTitle() == _title) {
      return *(*it);
    }
  }
}

std::vector<Book> Library::getBooksListed() const {
  std::vector<Book> res;
  for (auto &x : books) {
    res.push_back(*x);
  }
  return res;
}

