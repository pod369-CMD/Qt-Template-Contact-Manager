#ifndef SOLUTION_H
#define SOLUTION_H

#include <QVector>
#include <QTextStream>
#include <QDataStream>
#include <functional>
#include <algorithm>

template<typename T>
class Solution {
public:
    QVector<T> data;

public:
    Solution() = default;
    explicit Solution(const QVector<T>& vec) : data(vec) {}
    Solution(QVector<T>&& vec) noexcept: data(std::move(vec)) {}
    Solution(const Solution&) = default;
    Solution(Solution&&) noexcept = default;
    Solution& operator=(const Solution&) = default;
    Solution& operator=(Solution&&) noexcept = default;

    void add(const T& item) { data.append(item); }
    int size() const { return data.size(); }
    bool isEmpty() const { return data.isEmpty(); }
    void clear() { data.clear(); }
    const QVector<T>& getData() const { return data; }

    void sort(std::function<bool(const T&, const T&)> comparator) {
        std::sort(data.begin(), data.end(), comparator);
    }

    void sortByName() {
        sort([](const T& a, const T& b) { return a.name < b.name; });
    }

    void sortByTel1() {
        sort([](const T& a, const T& b) { return a.tel1 < b.tel1; });
    }

    // Бинарный поиск по имени
    int findByName(const QString& name) const {
        if (data.isEmpty()) return -1;
        T target(name); //объект с 1 полем name
        auto comp = [](const T& a, const T& b) { return a.name < b.name; };
        auto it = std::lower_bound(data.begin(), data.end(), target, comp);//поиск позиции
        if (it != data.end() && it->name == name) {
            return std::distance(data.begin(), it);
        }
        return -1;
    }

    void print(QTextStream& out) const {
        for (const auto& item : data) {
            out << item;
        }
    }

    // Текстовый ввод/вывод всего контейнера
    friend QTextStream& operator<<(QTextStream& out, const Solution& sol) {
        out << sol.data.size() << Qt::endl;
        for (const auto& item : sol.data) {
            out << item;
        }
        return out;
    }

    friend QTextStream& operator>>(QTextStream& in, Solution& sol) {
        int size;
        in >> size;
        in.readLine(); // сбросить перевод строки
        sol.data.clear();
        sol.data.reserve(size);
        for (int i = 0; i < size; ++i) {
            T temp;
            in >> temp;
            sol.data.append(temp);
        }
        return in;
    }

    // Бинарный ввод/вывод
    friend QDataStream& operator<<(QDataStream& out, const Solution& sol) {
        out.setVersion(QDataStream::Qt_5_0); //  для совместимости
        out << quint32(sol.data.size());    //  32-битный размер
        for (const auto& item : sol.data) {
            out << item;
        }
        return out;
    }

    friend QDataStream& operator>>(QDataStream& in, Solution& sol) {
        in.setVersion(QDataStream::Qt_5_0);
        quint32 size;
        in >> size;
        sol.data.clear();
        sol.data.reserve(size);
        for (quint32 i = 0; i < size; ++i) {
            T temp;
            in >> temp;
            sol.data.append(temp);
        }
        return in;
    }
};

#endif
