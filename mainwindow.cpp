#include "mainwindow.h"
#include <QMenuBar>

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

    setMenuBar(menuBar);
    setCentralWidget(centralWidget);
}
MainWindow::~MainWindow() {

}