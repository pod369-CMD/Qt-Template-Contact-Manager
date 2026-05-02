#ifndef CONTACT2_H
#define CONTACT2_H

#include <QString>
#include <QTextStream>
#include <QDataStream>

struct Contact2 {
    QString name;
    QString address;
    qlonglong tel1;

    Contact2();
    Contact2(const QString& n, const QString& addr, qlonglong t1);
    explicit Contact2(const QString& n); // для поиска по name

    // для Solution::sort
    static bool compareByName(const Contact2& a, const Contact2& b);
    static bool compareByTel1(const Contact2& a, const Contact2& b);

    // Текстовый вывод/ввод
    friend QTextStream& operator<<(QTextStream& out, const Contact2& c);
    friend QTextStream& operator>>(QTextStream& in, Contact2& c);

    // Бинарный вывод/ввод
    friend QDataStream& operator<<(QDataStream& out, const Contact2& c);
    friend QDataStream& operator>>(QDataStream& in, Contact2& c);
};

#endif
