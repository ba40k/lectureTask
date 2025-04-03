//
// Created by radamir on 02.04.25.
//

#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class AddBookDialog  : public QDialog{
    Q_OBJECT
    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalSplit;
    QVBoxLayout *leftScreenPart;
    QVBoxLayout *rightScreenPart;
    QLabel* bookNameHint;
    QLabel* authorNameHint;
    QLabel* yearHint;
    QLineEdit * bookName ;
    QLineEdit * authorName ;
    QLineEdit * year ;
    bool errorOccured = false;

    const int  fixedHeight = 30;

    QString inputBookName;
    QString inputAuthorName;
    short inputYear;

    QPushButton *addBookButton;
    void addBookSlot();
    public:
    AddBookDialog(QWidget *parent = nullptr);
    QString getInputBookName();
    QString getInputAuthorName();
    short getInputYear();
    bool getErrorOccured();

};



#endif //ADDBOOKDIALOG_H
