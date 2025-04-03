//
// Created by radamir on 02.04.25.
//

#ifndef ADDUserDIALOG_H
#define ADDUserDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class AddUserDialog  : public QDialog{
    Q_OBJECT
    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalSplit;
    QVBoxLayout *leftScreenPart;
    QVBoxLayout *rightScreenPart;
    QLabel* userNameHint;
    QLineEdit * userName ;
    bool errorOccured = false;

    const int  fixedHeight = 30;

    QString inputUserName;


    QPushButton *addUserButton;
    void addUserSlot();
public:
    AddUserDialog(QWidget *parent = nullptr);
    QString getInputUserName();
    bool getErrorOccured();

};



#endif //ADDUserDIALOG_H
