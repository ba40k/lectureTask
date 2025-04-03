//
// Created by radamir on 03.04.25.
//

#include "findBookDialog.h"

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



}

