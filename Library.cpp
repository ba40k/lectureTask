//
// Created by radamir on 19.03.25.
//

#include "Library.h"
#include <algorithm>
const std::shared_ptr<Book> Library::parseBook(const Book &book) const {
  return std::make_shared<Book>(book);
}
Library::bookIteratorType Library::getBookIterator(const Book& book) const{
  return  find(books.begin(), books.end(), parseBook(book));
}

bool Library::findBook(const Book& book) const{
  return getBookIterator(book) != books.end();
}
void Library::addBook(const Book& book){
  books.push_back(parseBook(book));
}
void Library::removeBook(const Book& book){
  if (findBook(book)){
     books.erase(getBookIterator(book));
  }
}