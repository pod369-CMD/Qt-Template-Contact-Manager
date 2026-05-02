#include "contact1.h"

Contact1::Contact1() : name(""), tel1(0), tel2(0) {}

Contact1::Contact1(const QString& n, qlonglong t1, qlonglong t2)
    : name(n), tel1(t1), tel2(t2) {}

Contact1::Contact1(const QString& n) : name(n), tel1(0), tel2(0) {} //для findByName

bool Contact1::compareByName(const Contact1& a, const Contact1& b) {
    return a.name < b.name;
}

bool Contact1::compareByTel1(const Contact1& a, const Contact1& b) {
    return a.tel1 < b.tel1;
}

QTextStream& operator<<(QTextStream& out, const Contact1& c) {
    out << c.name << Qt::endl
        << c.tel1 << Qt::endl
        << c.tel2 << Qt::endl;
    return out;
}

QTextStream& operator>>(QTextStream& in, Contact1& c) {
    c.name = in.readLine();
    in >> c.tel1;
    in.readLine();
    in >> c.tel2;
    in.readLine();
    return in;
}

QDataStream& operator<<(QDataStream& out, const Contact1& c) {
    out << c.name << c.tel1 << c.tel2;
    return out;
}

QDataStream& operator>>(QDataStream& in, Contact1& c) {
    in >> c.name >> c.tel1 >> c.tel2;
    return in;
}
