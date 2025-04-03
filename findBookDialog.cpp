//
// Created by radamir on 03.04.25.
//

#include "findBookDialog.h"
#include <QMessageBox>
FindBookDialog::FindBookDialog(QWidget *parent) {
    setParent(parent);
    setWindowFlags(Qt::Window);
    setWindowTitle("Поиск книги");
    setModal(true);
    setFixedHeight(200);
    setFixedWidth(400);

    mainLayout = new QVBoxLayout(this);
    horizontalScreenSplit = new QHBoxLayout();
    mainLayout->addLayout(horizontalScreenSplit);
    leftScreenPart = new QVBoxLayout();
    rightScreenPart = new QVBoxLayout();
    horizontalScreenSplit->addLayout(leftScreenPart);
    horizontalScreenSplit->addLayout(rightScreenPart);

    bookNameHint = new QLabel(this);
    bookNameHint->setText("Название книги: ");
    bookAuthorHint = new QLabel(this);
    bookAuthorHint->setText("Имя автора: ");
    bookYearHint = new QLabel(this);
    bookYearHint->setText("Год публикации");
    leftScreenPart->addWidget(bookNameHint);
    leftScreenPart->addWidget(bookAuthorHint);
    leftScreenPart->addWidget(bookYearHint);

    bookName = new QLineEdit(this);
    bookAuthor = new QLineEdit(this);
    bookYear = new QLineEdit(this);
    rightScreenPart->addWidget(bookName);
    rightScreenPart->addWidget(bookAuthor);
    rightScreenPart->addWidget(bookYear);

    bookName->setFixedHeight(fixedHeight);
    bookAuthor->setFixedHeight(fixedHeight);
    bookYear->setFixedHeight(fixedHeight);
    bookNameHint->setFixedHeight(fixedHeight);
    bookAuthorHint->setFixedHeight(fixedHeight);
    bookYearHint->setFixedHeight(fixedHeight);

    findButton = new QPushButton(this);
    findButton->setText("Найти книгу");
    mainLayout->addWidget(findButton);
    connect(findButton, &QPushButton::clicked, this, &FindBookDialog::findBookSlot);
}

void FindBookDialog::findBookSlot() {
    QString title = bookName->text();
    QString author = bookAuthor->text();
    QString yearValue = bookYear->text();
    bool wrongInputFormat = false;
    for (int i =0;i<bookYear->text().length();i++) {
        if (!(yearValue[i]>='0' && yearValue[i]<='9')) {
            wrongInputFormat = true;
            break;
        }
    }
    if (title.size()==0 || author.size()==0 || bookYear->text().size()==0) {
        wrongInputFormat = true;
    }
    if (wrongInputFormat) {
        QMessageBox* error = new QMessageBox(this);
        error->setText("Неверный формат входных данных");

        error->show();
        errorOccured = true;
        return ;
    }
    inputBookYear = yearValue.toInt();
    inputBookAuthor = author;
    inputBookName = title;
    errorOccured=false;

    close();
}
short FindBookDialog::getInputBookYear() {
    return inputBookYear;
}
QString FindBookDialog::getInputBookAuthor() {
    return inputBookAuthor;
}
QString FindBookDialog::getInputBookName() {
    return inputBookName;
}
bool FindBookDialog::getErrorOccured() {
    return errorOccured;
}