//
// Created by radamir on 19.03.25.
//

#include "Library.h"
#include <algorithm>
#include <iostream>

const std::shared_ptr<Book> Library::parseBook(const Book &book) const {
  std::cout<<std::make_shared<Book>(book)<<'\n';
  return std::make_shared<Book>(book);
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
  books.push_back(parseBook(book));
}
void Library::removeBook(const Book& book){
  if (findBook(book)){
     books.erase(getBookIterator(book));
  }
}