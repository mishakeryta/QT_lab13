#ifndef BOOKINFO_H
#define BOOKINFO_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <regex>
#include <string>
#include <sstream>
#include <list>

using namespace std;
class InappropriateLine
{

};
class BookInfo
{
    friend istream &operator>>(istream &ist,BookInfo& info);
    friend ostream &operator<<(ostream& ost,const BookInfo& info);
public:
    static int readBooks(istream& ist,list<BookInfo>& listBooks,list<int>& listOfIndexInapp);
    static bool isAuthorFormat(const string& name);
    static bool isNameFormat(const string& author);
    static bool isPagesYearFormat(const string& num);
    static bool isPriceFormat(const string& price);
    BookInfo() = default;
    string getName() const { return name;}
    string getAuthor() const { return author;}
    int getYear() const {return year;}
    int getPages() const {return pages;}
    double getPrice() const {return price;}
    bool operator <(const BookInfo& book) const;
private:
    string author;
    string name;
    int pages;
    int year;
    double price;
};

#endif // BOOKINFO_H
