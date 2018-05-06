#include "dialogofaddingnew.h"
#include "ui_dialogofaddingnew.h"
#include <QDebug>
DialogOfAddingNew::DialogOfAddingNew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogOfAddingNew)
{
    ui->setupUi(this);
    ui->lineEdit_author->setPlaceholderText("Enter author name.Empty is not allowed.");
    ui->lineEdit_Name->setPlaceholderText("Enter book name.Empty is not allowed.");
    ui->lineEdit_year->setPlaceholderText("Enter year.Empty is not allowed.");
    ui->lineEdit_page->setPlaceholderText("Enter pages.Empty is not allowed.");
    ui->lineEdit_price->setPlaceholderText("Enter price.Empty is not allowed.");
}

DialogOfAddingNew::~DialogOfAddingNew()
{
    delete ui;
}

BookInfo DialogOfAddingNew::getBookInfo()
{
}



bool DialogOfAddingNew::isEvrythingReady()
{
    return authorFormat && nameFormat && priceFormat &&  yearFormat && pagesFormat;
}

void DialogOfAddingNew::onTextEdited(const QString &text, bool (*checker)(const string &), QLabel &error,bool& isFormatTrue,const QString& errorMessage)
{
    if(checker(text.toStdString()))
    {
        isFormatTrue = true;
        if(isEvrythingReady())
        {
            ui->pushButton_Ok->setEnabled(true);
        }
        error.setText("");

    }
    else
    {
        error.setText(errorMessage);

        ui->pushButton_Ok->setEnabled(false);
        isFormatTrue = false;
        error.setVisible(true);
    }
    if(text.isEmpty())
    error.setText("");
}
void DialogOfAddingNew::on_lineEdit_author_textEdited(const QString &arg1)
{

    onTextEdited(arg1,BookInfo::isAuthorFormat,*ui->label_errorAuthor,authorFormat,"At least one alpha,then alpha and blanks.");
}
void DialogOfAddingNew::on_lineEdit_Name_textEdited(const QString &arg1)
{
    onTextEdited(arg1,BookInfo::isNameFormat,*ui->label_errorName,nameFormat,"At least one alpha or digit,\nthen alpha,digits and blanks.");
}

void DialogOfAddingNew::on_lineEdit_year_textEdited(const QString &arg1)
{
    onTextEdited(arg1,BookInfo::isPagesYearFormat,*ui->label_errorYear,yearFormat,"At least 1 digit ,max 6.");
}

void DialogOfAddingNew::on_lineEdit_page_textEdited(const QString &arg1)
{
    onTextEdited(arg1,BookInfo::isPagesYearFormat,*ui->label_errorPagese,pagesFormat,"At least 1 digit ,max 6.");
}

void DialogOfAddingNew::on_lineEdit_price_textEdited(const QString &arg1)
{
    onTextEdited(arg1,BookInfo::isPriceFormat,*ui->label_errorPrice,priceFormat,"At least 1 digit, max 6,and 1 or 2 after point.");
}



void DialogOfAddingNew::on_pushButton_Cancel_clicked()
{
    this->close();
    qDebug()<<"Hello";
}
