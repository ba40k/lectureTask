#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QDialog>
#include <QMenu>
QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    QMenuBar *menuBar;
    QMenu *addingMenu;
    QMenu *removeMenu;
    QMenu *findMenu;
    QAction *addBook;
    QAction *removeBook;
    QAction *findBook;
    QAction *addUser;
    QAction *removeUser;
    QAction *findUser;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H