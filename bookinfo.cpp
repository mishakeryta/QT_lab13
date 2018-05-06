#include "bookinfo.hpp"
#include <QDebug>
ostream &operator<<(ostream &ost, const BookInfo &info)
{
    ost<<info.getAuthor()<<'|'<<info.getName()<<'|'<<info.getYear()<<'|'
        <<info.getPages()<<'|'<<info.getPrice()<<'\n';
    return ost;

}

int BookInfo::readBooks(istream &ist, list<BookInfo>& listBooks, list<int>& listOfIndexInapp)
{
    int index = 1;
    BookInfo tmp;
    while (ist)
    {
        try
        {
           ist >> tmp;
           listBooks.push_back(tmp);
        }
        catch(InappropriateLine exp)
        {
            listOfIndexInapp.push_back(index);
        }
        ++index;
    }
    return index -1;
}

bool BookInfo::isAuthorFormat(const string &name)
{
    std::regex reg{"\\s*([A-Z]|[a-z])([A-Z]|[a-z]|\\s)*\\s*"};
    return regex_match(name,reg);
}

bool BookInfo::isNameFormat(const string &author)
{
    std::regex reg{"\\s*([A-Z]|[a-z]|[0-9])([A-Z]|[a-z]|[0-9]| )*\\s*"};
    return regex_match(author,reg);
}

bool BookInfo::isPagesYearFormat(const string &num)
{
    std::regex reg{"\\s*[0-9]{1,6}\\s*"};
    return regex_match(num,reg);
}

bool BookInfo::isPriceFormat(const string &price)
{
    std::regex reg{"\\s*[0-9]{1,6}(.[0-9]{1,2})?\\s*"};
    return regex_match(price,reg);
}

bool BookInfo::operator <(const BookInfo& book) const
{
    if(getAuthor()<book.getAuthor()) return true;
    return false;
}

istream & operator>>(istream &ist, BookInfo& info)
{
    if(!ist) return ist;
    string newName,newAuthor,tmp;
    int year = 0, pages = 0;
    double price = 0;
    string line;
    getline(ist,line,'\n');
    istringstream inLine{line};
    getline(inLine,newAuthor,'|');
    if(!BookInfo::isAuthorFormat(newAuthor)||!inLine) throw InappropriateLine();

    getline(inLine,newName,'|');
    if(!BookInfo::isNameFormat(newName) || !inLine) throw InappropriateLine();

    getline(inLine,tmp,'|');
    if(!BookInfo::isPagesYearFormat(tmp) || !inLine) throw InappropriateLine();
    year = std::stoi(tmp);tmp = "";

    getline(inLine,tmp,'|');
    if(!BookInfo::isPagesYearFormat(tmp) || !inLine) throw InappropriateLine();
    pages = std::stoi(tmp);tmp = "";

    getline(inLine,tmp,'|');
    if(!BookInfo::isPriceFormat(tmp)) throw InappropriateLine();
    price = std::stof(tmp);

    if(!inLine.eof()||inLine.bad()|| inLine.fail()) throw InappropriateLine();
    info.author =newAuthor;
    info.name = newName;
    info.year = year;
    info.pages = pages;
    info.price = price;
    return ist;
}






