#include "contact2.h"

Contact2::Contact2() : name(""), address(""), tel1(0) {}

Contact2::Contact2(const QString& n, const QString& addr, qlonglong t1)
    : name(n), address(addr), tel1(t1) {}

Contact2::Contact2(const QString& n) : name(n), address(""), tel1(0) {}

bool Contact2::compareByName(const Contact2& a, const Contact2& b) {
    return a.name < b.name;
}

bool Contact2::compareByTel1(const Contact2& a, const Contact2& b) {
    return a.tel1 < b.tel1;
}

QTextStream& operator<<(QTextStream& out, const Contact2& c) {
    out << c.name << Qt::endl
        << c.address << Qt::endl
        << c.tel1 << Qt::endl;
    return out;
}

QTextStream& operator>>(QTextStream& in, Contact2& c) {
    c.name = in.readLine();
    c.address = in.readLine();
    in >> c.tel1;
    in.readLine();
    return in;
}

QDataStream& operator<<(QDataStream& out, const Contact2& c) {
    out << c.name << c.address << c.tel1;
    return out;
}

QDataStream& operator>>(QDataStream& in, Contact2& c) {
    in >> c.name >> c.address >> c.tel1;
    return in;
}
