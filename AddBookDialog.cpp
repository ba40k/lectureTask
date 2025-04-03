//
// Created by radamir on 02.04.25.
//

#include "AddBookDialog.h"

#include <QMessageBox>

AddBookDialog::AddBookDialog(QWidget *parent){

    setParent(parent);
    setWindowFlags(Qt::Window);
    setWindowTitle("Добавление книги");
    setModal(true);
    setFixedHeight(200);
    setFixedWidth(400);
    mainLayout = new QVBoxLayout(this);

    horizontalSplit = new QHBoxLayout();
    mainLayout->addLayout(horizontalSplit);
    leftScreenPart = new QVBoxLayout();
    rightScreenPart = new QVBoxLayout();
    horizontalSplit->addLayout(leftScreenPart);
    horizontalSplit->addLayout(rightScreenPart);

    bookNameHint = new QLabel("Название книги: ");
    authorNameHint = new QLabel("Имя автора: ");
    yearHint = new QLabel("Год публикации: ");
    leftScreenPart->addWidget(bookNameHint);
    leftScreenPart->addWidget(authorNameHint);
    leftScreenPart->addWidget(yearHint);

    bookName = new QLineEdit(this);
    authorName = new QLineEdit(this);
    year = new QLineEdit(this);

    rightScreenPart->addWidget(bookName);
    rightScreenPart->addWidget(authorName);
    rightScreenPart->addWidget(year);

    bookNameHint->setFixedHeight(fixedHeight);
    authorNameHint->setFixedHeight(fixedHeight);
    yearHint->setFixedHeight(fixedHeight);
    bookName->setFixedHeight(fixedHeight);
    authorName->setFixedHeight(fixedHeight);
    year->setFixedHeight(fixedHeight);

    addBookButton = new QPushButton(this);
    addBookButton->setText("Добавить книгу");
    mainLayout->addWidget(addBookButton);

    connect(addBookButton, &QPushButton::clicked, this, &AddBookDialog::addBookSlot);

}
void AddBookDialog::addBookSlot() {


    QString title = bookName->text();
    QString author = authorName->text();
    QString yearValue = year->text();
    bool wrongInputFormat = false;
    for (int i =0;i<year->text().length();i++) {
        if (!(yearValue[i]>='0' && yearValue[i]<='9')) {
            wrongInputFormat = true;
            break;
        }
    }
    if (title.size()==0 || author.size()==0 || year->text().size()==0) {
        wrongInputFormat = true;
    }
    if (wrongInputFormat) {
        QMessageBox* error = new QMessageBox(this);
        error->setText("Неверный формат входных данных");

        error->show();
        errorOccured = true;
        return ;
    }
    inputYear = yearValue.toInt();
    inputAuthorName = author;
    inputBookName = title;
    errorOccured=false;

    close();
}
short AddBookDialog::getInputYear() {
    return inputYear;
}
QString AddBookDialog::getInputAuthorName() {
    return inputAuthorName;
}
QString AddBookDialog::getInputBookName() {
    return inputBookName;
}
bool AddBookDialog::getErrorOccured() {
    return errorOccured;
}
