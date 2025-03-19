//
// Created by radamir on 19.03.25.
//

#ifndef BOOK_H
#define BOOK_H

#include <QString>


class Book {
    QString title;
    QString author;
    short year;
    public:
    QString getTitle() const;
    QString getAuthor() const;
    short getYear() const;
    void setTitle(const QString &_title);
    void setAuthor(const QString &_author);
    void setYear(const short &_year);

};



#endif //BOOK_H
