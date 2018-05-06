#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ifstream input{"Books.txt"};
    if(!input)
    {
        if(QMessageBox::Ok != QMessageBox::question(this,"Books.txt","You dont have Books.txt.Create it or close a program?",QMessageBox::Ok,QMessageBox::Cancel))
        {
            throw int{};
        }
        ofstream ostr{"Books.txt"};
        input.open("Books.txt");
    }
    list<int> listOfIndexInapp;
    list<BookInfo> listBooks;
    BookInfo::readBooks(input,listBooks,listOfIndexInapp);
    listBooks.sort();
    listBooks.reverse();
    ui->setupUi(this);
    printListBooks(listBooks);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void SortList(list<BookInfo>& listBooks)
{

}
void MainWindow::printListBooks(const list<BookInfo> listBooks)
{
    ui->tableWidget_Books->setRowCount(listBooks.size());
    auto iterator = listBooks.begin();
    for(unsigned int i = 0; i < listBooks.size();++i)
    {

        QTableWidgetItem * tmp =  new QTableWidgetItem(QString::fromStdString(iterator->getAuthor()));
        ui->tableWidget_Books->setItem(i,0,tmp);

        tmp =  new QTableWidgetItem(QString::fromStdString(iterator->getName()));
        ui->tableWidget_Books->setItem(i,1,tmp);
        tmp =  new QTableWidgetItemNumber(iterator->getYear());
        ui->tableWidget_Books->setItem(i,2,tmp);
        tmp =  new QTableWidgetItemNumber(iterator->getPages());
        ui->tableWidget_Books->setItem(i,3,tmp);
        tmp =  new QTableWidgetItemNumber(iterator->getPrice());
        ui->tableWidget_Books->setItem(i,4,tmp);
        ++iterator;
    }
}





void MainWindow::on_actionAdd_Item_triggered()
{
   // DialogOfAddingNew dialogOfAddingNew;
    //dialogOfAddingNew.show();
}

void MainWindow::on_actionAdd_Item_changed()
{
    DialogOfAddingNew dialogOfAddingNew;
    dialogOfAddingNew.show();
    dialogOfAddingNew.exec();
}
