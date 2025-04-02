#include <QApplication>
#include <QPushButton>
#include "Book.h"
#include <iostream>
#include "mainwindow.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow wndw;
    wndw.show();
    return QApplication::exec();
}
