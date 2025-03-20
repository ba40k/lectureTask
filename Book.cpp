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
bool Book::operator<(const Book &_other) const {
  return (title + author + QString::number(year) < _other.getTitle() + _other.getAuthor() + QString::number(_other.getYear()));
}
std::vector<QString> Book::getInformation() {
  std::vector<QString> information;
  information.push_back(title);
  information.push_back(author);
  information.push_back(QString::number(year));
  return information;
}


