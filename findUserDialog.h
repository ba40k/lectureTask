//
// Created by radamir on 03.04.25.
//

#ifndef FINDUSERDIALOG_H
#define FINDUSERDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class FindUserDialog  : public QDialog{
    Q_OBJECT
    QLabel *userNameHint;
    QLabel *userIdHint;
    QLineEdit *userName;
    QLineEdit *userId;

    QPushButton *findButton;

    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalScreenSplit;
    QVBoxLayout *leftScreenPart;
    QVBoxLayout *rightScreenPart;

    QString inputUserName;
    uint64_t inputUserId;
    bool errorOccured;

    const int fixedHeight = 30;

    void findUserSlot();
public:
    FindUserDialog(QWidget *parent = nullptr);
    QString getInputUserName();
    uint64_t getInputUserId();
    bool getErrorOccured();
};



#endif //FINDUSERDIALOG_H
