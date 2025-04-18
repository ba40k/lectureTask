//
// Created by radamir on 02.04.25.
//

#include "AddUserDialog.h"

#include <QMessageBox>

AddUserDialog::AddUserDialog(QWidget *parent){

    setParent(parent);
    setWindowFlags(Qt::Window);
    setWindowTitle("Добавление пользователя");
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

    userNameHint = new QLabel("Имя пользователя: ");
    leftScreenPart->addWidget(userNameHint);

    userName = new QLineEdit(this);

    rightScreenPart->addWidget(userName);


    userNameHint->setFixedHeight(fixedHeight);

    userName->setFixedHeight(fixedHeight);



    addUserButton = new QPushButton(this);
    addUserButton->setText("Добавить Пользователя");
    mainLayout->addWidget(addUserButton);

    connect(addUserButton, &QPushButton::clicked, this, &AddUserDialog::addUserSlot);

}
void AddUserDialog::addUserSlot() {


    QString name = userName->text();
    bool wrongInputFormat = false;

    if (name.size()==0) {
        wrongInputFormat = true;
    }
    if (wrongInputFormat) {
        QMessageBox* error = new QMessageBox(this);
        error->setText("Неверный формат входных данных");

        error->show();
        errorOccured = true;
        return ;
    }

    inputUserName = name;
    errorOccured=false;

    close();
}

QString AddUserDialog::getInputUserName() {
    return inputUserName;
}
bool AddUserDialog::getErrorOccured() {
    return errorOccured;
}
