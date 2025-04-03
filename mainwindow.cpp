#include "mainwindow.h"
#include <QMenuBar>
#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include "AddBookDialog.h"
#include "AddUserDialog.h"
MainWindow::MainWindow(QWidget *parent) {
    setWindowTitle("Radamir's Library");
    setMinimumSize(QSize(WIDTH, HEIGHT));
    centralWidget = new QWidget(this);
    menuBar = new QMenuBar();
    addingMenu = new QMenu("Добавить");
    removeMenu = new QMenu("Удалить");
    findMenu = new QMenu("Найти");

    addBookAction = new QAction("Книгу");
    addingMenu->addAction(addBookAction);
    addUserAction = new QAction("Пользователя");
    addingMenu->addAction(addUserAction);

    removeBookAction = new QAction("Книгу");
    removeMenu->addAction(removeBookAction);
    removeUserAction = new QAction("Пользователя");
    removeMenu->addAction(removeUserAction);

    findBookAction = new QAction("Книгу");
    findMenu->addAction(findBookAction);
    findUserAction = new QAction("Пользователя");
    findMenu->addAction(findUserAction);

    menuBar->addMenu(addingMenu);
    menuBar->addMenu(removeMenu);
    menuBar->addMenu(findMenu);

    model = new QStandardItemModel();
    model->setColumnCount(0);
    model->setRowCount(0);


    tableView = new QTableView(centralWidget);
    tableView->setModel(model);

    tableView->setGeometry(QRect(0 , 0, WIDTH, HEIGHT));

    connect(addBookAction, &QAction::triggered,this, &MainWindow::addBookSlot);
    connect(findBookAction, &QAction::triggered,this, &MainWindow::findBookSlot);
    connect(removeBookAction, &QAction::triggered,this, &MainWindow::removeBookSlot);


    connect(addUserAction, &QAction::triggered,this, &MainWindow::addUserSlot);
    connect(findUserAction, &QAction::triggered,this, &MainWindow::findUserSlot);
    connect(removeUserAction, &QAction::triggered,this, &MainWindow::removeUserSlot);

    setMenuBar(menuBar);
    setCentralWidget(centralWidget);
}
void MainWindow::addBookSlot() {

    AddBookDialog* addBookDialog = new AddBookDialog(this);
    addBookDialog->exec();

    if (!addBookDialog->getErrorOccured()) {
        QString title = addBookDialog->getInputBookName();
        QString author = addBookDialog->getInputAuthorName();
        QString year = QString::fromStdString(std::to_string( addBookDialog->getInputYear()));

        QStandardItem* item = new QStandardItem();
        model->setVerticalHeaderItem(model->rowCount(), new QStandardItem(title + " " + author + " " + year));

    }
}
void MainWindow::findBookSlot() {

}
void MainWindow::removeBookSlot() {

}
void MainWindow::addUserSlot() {
    AddUserDialog* addUserDialog = new AddUserDialog(this);
    addUserDialog->exec();

    if (!addUserDialog->getErrorOccured()) {
        QString name = addUserDialog->getInputUserName();
        QString id = QString::fromStdString(std::to_string( addUserDialog->getInputUserId()));

        QStandardItem* item = new QStandardItem();
        model->setHorizontalHeaderItem(model->columnCount(), new QStandardItem(name + " "  + id));

    }
}
void MainWindow::findUserSlot() {

}
void MainWindow::removeUserSlot() {

}

MainWindow::~MainWindow() {


}