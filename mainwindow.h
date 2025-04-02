#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTableView>
#include <QStandardItemModel>
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
    QAction *addBookAction;
    QAction *removeBookAction;
    QAction *findBookAction;
    QAction *addUserAction;
    QAction *removeUserAction;
    QAction *findUserAction;
    QWidget* centralWidget;

    QTableView* tableView;
    QStandardItemModel *model;

    void addBookSlot();
    void removeBookSlot();
    void findBookSlot();
    void addUserSlot();
    void removeUserSlot();
    void findUserSlot();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H