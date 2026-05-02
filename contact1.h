#ifndef CONTACT1_H
#define CONTACT1_H

#include <QString>
#include <QTextStream>
#include <QDataStream>

struct Contact1 {
    QString name;
    qlonglong tel1;
    qlonglong tel2;

    Contact1();
    Contact1(const QString& n, qlonglong t1, qlonglong t2);
    explicit Contact1(const QString& n); // для поиска по имени

    // для Solution::sort
    static bool compareByName(const Contact1& a, const Contact1& b);
    static bool compareByTel1(const Contact1& a, const Contact1& b);

    // Текстовый вывод/ввод
    friend QTextStream& operator<<(QTextStream& out, const Contact1& c);
    friend QTextStream& operator>>(QTextStream& in, Contact1& c);

    // Бинарный вывод/ввод
    friend QDataStream& operator<<(QDataStream& out, const Contact1& c);
    friend QDataStream& operator>>(QDataStream& in, Contact1& c);
};

#endif
