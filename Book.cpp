//
// Created by radamir on 19.03.25.
//



#include "Book.h"


QString Book::getTitle() const{
    return title;
}
QString Book::getAuthor() const{
  return author;
}
short Book::getYear() const{
  return year;
}
void Book::setTitle(const QString &_title){
  title = _title;
}
void Book::setAuthor(const QString &_author){
  author = _author;
}
void Book::setYear(const short &_year){
  year = _year;
}
Book::Book(const QString &_title, const QString &_author, const short &_year){
  setTitle(_title);
  setAuthor(_author);
  setYear(_year);
}