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
    userIdHint = new QLabel("Id пользователя: ");
    leftScreenPart->addWidget(userNameHint);
    leftScreenPart->addWidget(userIdHint);

    userName = new QLineEdit(this);
    userId = new QLineEdit(this);

    rightScreenPart->addWidget(userName);
    rightScreenPart->addWidget(userId);


    userNameHint->setFixedHeight(fixedHeight);
    userIdHint->setFixedHeight(fixedHeight);
    userId->setFixedHeight(fixedHeight);
    userName->setFixedHeight(fixedHeight);



    addUserButton = new QPushButton(this);
    addUserButton->setText("Добавить Пользователя");
    mainLayout->addWidget(addUserButton);

    connect(addUserButton, &QPushButton::clicked, this, &AddUserDialog::addUserSlot);

}
void AddUserDialog::addUserSlot() {


    QString name = userName->text();
    QString idValue = userId->text();
    bool wrongInputFormat = false;
    for (int i =0;i<idValue.size();i++) {
        if (!(idValue[i]>='0' && idValue[i]<='9')) {
            wrongInputFormat = true;
            break;
        }
    }
    if (name.size()==0 || idValue.size()==0) {
        wrongInputFormat = true;
    }
    if (wrongInputFormat) {
        QMessageBox* error = new QMessageBox(this);
        error->setText("Неверный формат входных данных");

        error->show();
        errorOccured = true;
        return ;
    }
    inputUserId = idValue.toULong();
    inputUserName = name;
    errorOccured=false;

    close();
}
uint64_t AddUserDialog::getInputUserId() {
    return inputUserId;
}
QString AddUserDialog::getInputUserName() {
    return inputUserName;
}
bool AddUserDialog::getErrorOccured() {
    return errorOccured;
}
