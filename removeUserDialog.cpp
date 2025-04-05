//
// Created by radamir on 05.04.25.
//

#include "removeUserDialog.h"
#include <QMessageBox>
RemoveUserDialog::RemoveUserDialog(QWidget *parent) {
    setParent(parent);
    setWindowFlags(Qt::Window);
    setWindowTitle("Удаление пользователя");
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

    RemoveButton = new QPushButton(this);
    RemoveButton->setText("Удалить пользователя");
    mainLayout->addWidget(RemoveButton);
    connect(RemoveButton, &QPushButton::clicked, this, &RemoveUserDialog::RemoveUserSlot);
}

void RemoveUserDialog::RemoveUserSlot() {
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
uint64_t RemoveUserDialog::getInputUserId() {
    return inputUserId;
}
QString RemoveUserDialog::getInputUserName() {
    return inputUserName;
}
bool RemoveUserDialog::getErrorOccured() {
    return errorOccured;
}