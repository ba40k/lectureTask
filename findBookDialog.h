//
// Created by radamir on 03.04.25.
//

#ifndef FINDBOOKDIALOG_H
#define FINDBOOKDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class FindBookDialog  : public QDialog{
    Q_OBJECT
    QLabel *bookNameHint;
    QLabel *bookAuthorHint;
    QLabel *bookYearHint;
    QLineEdit *bookName;
    QLineEdit *bookAuthor;
    QLineEdit *bookYear;

    QPushButton *findButton;

    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalScreenSplit;
    QVBoxLayout *leftScreenPart;
    QVBoxLayout *rightScreenPart;

    QString inputBookName;
    QString inputBookAuthor;
    short inputBookYear;
    bool errorOccured;

    const int fixedHeight = 30;

    void findBookSlot();
    public:
    FindBookDialog(QWidget *parent = nullptr);
    QString getInputBookName();
    QString getInputBookAuthor();
    short getInputBookYear();
    bool getErrorOccured();
};



#endif //FINDBOOKDIALOG_H
