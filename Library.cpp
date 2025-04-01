//
// Created by radamir on 19.03.25.
//

#include "Library.h"
#include <algorithm>
#include <iostream>

const std::shared_ptr<Book> Library::parseBookToSharedPtr(const std::unique_ptr<Book> &book) const {
  return std::make_shared<Book>(*book);
}
std::weak_ptr<Book> Library::parseBookToWeakPtr(const std::unique_ptr<Book> &book) const {
  std::weak_ptr<Book> wp = parseBookToSharedPtr(book);
  return wp;
}
bool Library::findBook(const std::unique_ptr<Book> &book) const{
  for (auto &bookPointer : books) {
      if (*bookPointer == *book) {
        return true;
      }
  }
  return false;
}
Library::bookIteratorType Library::getBookIterator(const std::unique_ptr<Book> &book) const {
  for (bookIteratorType it = books.begin(); it != books.end(); it++) {
    if (*(*it) == *book) {
      return it;
    }
  }
  return books.end();
}
void Library::addBook(const std::unique_ptr<Book> &book){
  books.push_back(parseBookToSharedPtr(book));
}
void Library::removeBook(const std::unique_ptr<Book> &book){
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
std::vector<QString> Library::getBookInfo(const std::unique_ptr<Book> &book) const {
  return book->getInformation();
}
bool Library::findBookOnHands(const std::unique_ptr<Book> &book)  {
  for (uint64_t i =0 ;i < users.size();i++) {
    for (auto &x : usersBooks[users[i]->getId()]) {
      if (*x == *book) {
        return true;
      }
    }
  }
  return false;
}
bool Library::findUser(const std::shared_ptr<User> &user) const {
  for (auto &x : users) {
    if (*x == *user) {
      return true;
    }
  }
  return false;
}

void Library::addUser(const std::shared_ptr<User> &user) {
      if (!findUser(user)) {
        users.push_back(user);
        usersBooks[user->getId()].push_back({});
      }
}

void Library::removeUser(const std::shared_ptr<User> &user){
    int deletingIndex = -1;
    for (int i =0;i<users.size();i++) {
      if (*users[i] == *user) {
        deletingIndex = i;
        break;
      }
    }
    if (deletingIndex != -1) {
      users.erase(users.begin() + deletingIndex);
      usersBooks.erase(usersBooks.find(users[deletingIndex]->getId()));
    }
}
void Library::giveBook(std::unique_ptr<Book> &book, std::shared_ptr<User> &user) {
  if (findUser(user) && findBook(book)) {
    removeBook(book);
    usersBooks[user->getId()].push_back(std::make_shared<Book>(*book));
  }
}

int Library::getNumberOfUsers() const {
  return users.size();
}
int Library::getNumberOfBooksOnHands() const {
  int res = 0;
  for (auto &[ id, books] : usersBooks) {
    res+=books.size();
  }
  return res;
}

std::vector<User> Library::getUsersListed() const {
  std::vector<User>  res;
  int i =0;
  for (auto &x : users) {
    res.push_back(*x);
  }
  return res;
}

std::vector<Book> Library::getUserBooksListed(const std::shared_ptr<User> &user)  {
  std::vector<std::shared_ptr<Book>> booksPtr = usersBooks[user->getId()];

  std::vector<Book> res;

  for (auto &x : booksPtr) {
    res.push_back(*x);
  }

  return res;
}



