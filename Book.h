//
// Created by radamir on 19.03.25.
//

#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <vector>
class QString;

class Book {
    QString title;
    QString author;
    short year;
    public:

    Book(const QString &_title,const QString &_author,const short &_year);
    QString getTitle() const;
    QString getAuthor() const;
    short getYear() const;
    void setTitle(const QString &_title);
    void setAuthor(const QString &_author);
    void setYear(const short &_year);
    std::vector<QString> getInformation();

    bool operator==(const Book & book) const = default;
    bool operator<(const Book & book) const;
};


#endif //BOOK_H
