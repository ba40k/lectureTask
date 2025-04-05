//
// Created by radamir on 05.04.25.
//

#ifndef REMOVEBOOKDIALOG_H
#define REMOVEBOOKDIALOG_H
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class RemoveBookDialog : public QDialog{
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

    QPushButton *RemoveBookButton;
    void RemoveBookSlot();
public:
    RemoveBookDialog(QWidget *parent = nullptr);
    QString getInputBookName();
    QString getInputAuthorName();
    short getInputYear();
    bool getErrorOccured();

};



#endif //REMOVEBOOKDIALOG_H
