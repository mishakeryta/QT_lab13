#ifndef DIALOGOFADDINGNEW_H
#define DIALOGOFADDINGNEW_H
#include <QLabel>
#include <QDialog>
#include <QWidget>
#include "bookinfo.hpp"
namespace Ui {
class DialogOfAddingNew;
}

class DialogOfAddingNew : public QWidget
{
    Q_OBJECT

public:
    explicit DialogOfAddingNew(QWidget *parent = 0);
    ~DialogOfAddingNew();
    BookInfo getBookInfo();

private slots:
    void on_lineEdit_author_textEdited(const QString &arg1);

    void on_lineEdit_Name_textEdited(const QString &arg1);

    void on_lineEdit_year_textEdited(const QString &arg1);

    void on_lineEdit_page_textEdited(const QString &arg1);

    void on_lineEdit_price_textEdited(const QString &arg1);


    void on_pushButton_Cancel_clicked();

private:
    inline bool isEvrythingReady();
    bool isOkeyPressed = false;
    void onTextEdited(const QString& text,bool (*checker)(const string& ),QLabel& error,bool& isFarmatTrue,const QString& errorMessage);
    bool authorFormat = false,nameFormat = false,priceFormat = false,pagesFormat = false,yearFormat = false;
    Ui::DialogOfAddingNew *ui;
};

#endif // DIALOGOFADDINGNEW_H
