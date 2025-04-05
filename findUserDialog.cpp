//
// Created by radamir on 03.04.25.
//

#include "findUserDialog.h"
#include <QMessageBox>
FindUserDialog::FindUserDialog(QWidget *parent) {
    setParent(parent);
    setWindowFlags(Qt::Window);
    setWindowTitle("Поиск пользователя");
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

    userNameHint = new QLabel(this);
    userNameHint->setText("Имя пользователя: ");
    userIdHint = new QLabel(this);
    userIdHint->setText("Id пользователя: ");
    leftScreenPart->addWidget(userNameHint);
    leftScreenPart->addWidget(userIdHint);

    userName = new QLineEdit(this);
    userId = new QLineEdit(this);
    rightScreenPart->addWidget(userName);
    rightScreenPart->addWidget(userId);

    userName->setFixedHeight(fixedHeight);
    userId->setFixedHeight(fixedHeight);
    userNameHint->setFixedHeight(fixedHeight);
    userIdHint->setFixedHeight(fixedHeight);

    findButton = new QPushButton(this);
    findButton->setText("Найти пользователя");
    mainLayout->addWidget(findButton);
    connect(findButton, &QPushButton::clicked, this, &FindUserDialog::findUserSlot);
}

void FindUserDialog::findUserSlot() {
    QString name = userName->text();
    QString idValue = userId->text();
    bool wrongInputFormat = false;
    for (int i =0;i<userId->text().length();i++) {
        if (!(userId->text()[i]>='0' && userId->text()[i]<='9')) {
            wrongInputFormat = true;
            break;
        }
    }
    if (name.size()==0 || userId->text().size()==0) {
        wrongInputFormat = true;
    }
    if (wrongInputFormat) {
        QMessageBox* error = new QMessageBox(this);
        error->setText("Неверный формат входных данных");

        error->show();
        errorOccured = true;
        return ;
    }
    inputUserId = idValue.toULongLong();
    inputUserName = name;
    errorOccured=false;
    close();
}
uint64_t FindUserDialog::getInputUserId() {
    return inputUserId;
}
QString FindUserDialog::getInputUserName() {
    return inputUserName;
}
bool FindUserDialog::getErrorOccured() {
    return errorOccured;
}