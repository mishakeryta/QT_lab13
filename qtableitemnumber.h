#ifndef QTABLEITEMNUMBER_H
#define QTABLEITEMNUMBER_H
#include <QTableWidget>

class QTableWidgetItemNumber: public QTableWidgetItem {
public:
    explicit QTableWidgetItemNumber(double val)
    {
        setText(QString::number(val));
    }
    bool operator <(const QTableWidgetItem &other) const
    {
        return text().toDouble() < other.text().toDouble();
    }
};


#endif // QTABLEITEMNUMBER_H
