//
// Created by radamir on 05.04.25.
//

#ifndef REMOVEUSERDIALOG_H
#define REMOVEUSERDIALOG_H




#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class RemoveUserDialog  : public QDialog{
    Q_OBJECT
    QLabel *userNameHint;
    QLabel *userIdHint;
    QLineEdit *userName;
    QLineEdit *userId;

    QPushButton *RemoveButton;

    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalScreenSplit;
    QVBoxLayout *leftScreenPart;
    QVBoxLayout *rightScreenPart;

    QString inputUserName;
    uint64_t inputUserId;
    bool errorOccured;

    const int fixedHeight = 30;

    void RemoveUserSlot();
public:
    RemoveUserDialog(QWidget *parent = nullptr);
    QString getInputUserName();
    uint64_t getInputUserId();
    bool getErrorOccured();
};


#endif //REMOVEUSERDIALOG_H
