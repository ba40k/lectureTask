#include "mainwindow.h"
#include <QMenuBar>
#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include "AddBookDialog.h"
#include "AddUserDialog.h"
#include "Book.h"
#include "findBookDialog.h"
#include "findUserDialog.h"
#include "QHeaderView"
#include "RemoveBookDialog.h"
#include "removeUserDialog.h"

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
     tableView->setWordWrap(true);
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

    AddBookDialog* addBookDialog = new AddBookDialog();
    addBookDialog->exec();

    if (!addBookDialog->getErrorOccured()) {
        QString title = addBookDialog->getInputBookName();
        QString author = addBookDialog->getInputAuthorName();
        QString year = QString::fromStdString(std::to_string( addBookDialog->getInputYear()));
        model->setVerticalHeaderItem(model->rowCount(), new QStandardItem(title + " " + author + " " + year));
        Book book(title, author, year.toInt());
        lib.addBook(std::make_unique<Book>(book));
    }
    delete addBookDialog;
}
void MainWindow::findBookSlot() {
    FindBookDialog* findBookDialog = new FindBookDialog();
    findBookDialog->exec();
    if (!findBookDialog->getErrorOccured()) {
        QString title = findBookDialog->getInputBookName();
        QString author = findBookDialog->getInputBookAuthor();
        QString year = QString::fromStdString(std::to_string( findBookDialog->getInputBookYear()));
        Book book(title, author, year.toInt());


        QMessageBox* result = new QMessageBox(this);


        if (lib.findBook(std::make_unique<Book>(book))) {
            result->setText("Такая книга имеется в наличии");
            result->show();
        } else {
            result->setText("Такая книга отсутствует в наличии");
            result->show();
        }

    }




    delete findBookDialog;

}
void MainWindow::removeBookSlot() {
    RemoveBookDialog* removeBookDialog = new RemoveBookDialog(); // я только потом понял, что этот диалог подходит и для удаления
    removeBookDialog->exec();

    if (!removeBookDialog->getErrorOccured()) {

        QString title = removeBookDialog->getInputBookName();
        QString author = removeBookDialog->getInputAuthorName();
        QString year = QString::fromStdString(std::to_string( removeBookDialog->getInputYear()));
        Book book(title, author, year.toInt());
        if(lib.findBook(std::make_unique<Book>(book))) {

            for (int i =0;i<model->rowCount();i++) {
                int rows = model->rowCount();
                if (model->verticalHeaderItem(i)->text() == title + " " + author + " " + year) {
                    model->removeRow(i);
                    break;
                }
            }


            lib.removeBook(std::make_unique<Book>(book));
        }
    }
    delete removeBookDialog;
}
void MainWindow::addUserSlot() {
    AddUserDialog* addUserDialog = new AddUserDialog();
    addUserDialog->exec();

    if (!addUserDialog->getErrorOccured()) {
        QString name = addUserDialog->getInputUserName();
        User user(name.toStdString());
        model->setHorizontalHeaderItem(model->columnCount(), new QStandardItem(name + " "  + QString::fromStdString(std::to_string(user.getId()))));
        lib.addUser(std::make_shared<User>(user));
    }

    int newColumwWidth = WIDTH / model->columnCount();
    for(int i =0 ;i<model->columnCount();i++) {
        tableView->setColumnWidth(i, newColumwWidth);
    }


    delete addUserDialog;
}
void MainWindow::findUserSlot() {
    FindUserDialog* findUserDialog = new FindUserDialog();
    findUserDialog->exec();
    if (!findUserDialog->getErrorOccured()) {
        QString name = findUserDialog->getInputUserName();
        QString id = QString::fromStdString(std::to_string( findUserDialog->getInputUserId()));
        User user(name.toStdString(),findUserDialog->getInputUserId());
        QMessageBox* result = new QMessageBox(this);
        if (lib.findUser(std::make_unique<User>(user))) {
            result->setText("Такой пользователь существует");
            result->show();
        } else {
            result->setText("Такого пользователя не существует");
            result->show();
        }

    }
    delete findUserDialog;
}
void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    WIDTH = width();
    HEIGHT = height();
    centralWidget->setFixedWidth(WIDTH);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    tableView->setGeometry(QRect(0, 0, WIDTH, HEIGHT));
    if (tableView && model->columnCount() > 0) {
        int newColumwWidth = WIDTH / model->columnCount();
        for(int i =0 ;i<model->columnCount();i++) {
            tableView->setColumnWidth(i, newColumwWidth);
        }
    }

}
void MainWindow::removeUserSlot() {
    RemoveUserDialog* removeUserDialog = new RemoveUserDialog(); // я только потом понял, что этот диалог подходит и для удаления
    removeUserDialog->exec();

    if (!removeUserDialog->getErrorOccured()) {
        QString name = removeUserDialog->getInputUserName();
        User user(name.toStdString(), removeUserDialog->getInputUserId());
        if (lib.findUser(std::make_unique<User>(user))) {
            for (int i =0;i<model->columnCount();i++) {
                if (model->horizontalHeaderItem(i)->text() == name + " " + QString::fromStdString(std::to_string(user.getId()))) {
                    model->removeColumn(i);
                    break;
                }
            }
            lib.removeUser(std::make_shared<User>(user));
        }
    }
    if (model->columnCount() > 0) {
        int newColumwWidth = WIDTH / model->columnCount();
        for(int i =0 ;i<model->columnCount();i++) {
            tableView->setColumnWidth(i, newColumwWidth);
        }
    }

    delete removeUserDialog;
}

MainWindow::~MainWindow() {


}