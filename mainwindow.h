#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <list>
#include <fstream>
#include <QMainWindow>
#include <QMessageBox>
#include "bookinfo.hpp"
#include "qtableitemnumber.h"
#include "dialogofaddingnew.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void printListBooks(const list<BookInfo> listBooks);

private slots:
    void on_actionNew_triggered();

    void on_actionAdd_Item_triggered();

    void on_actionAdd_Item_changed();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
