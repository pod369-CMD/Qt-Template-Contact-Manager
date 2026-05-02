#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "solution.h"

template<typename T>
class TableModel : public QAbstractTableModel {
    Solution<T>* sol;
    QStringList headers;

public:
    TableModel(Solution<T>* data, const QStringList& h, QObject* parent = nullptr)
        : QAbstractTableModel(parent), sol(data), headers(h) {}

    int rowCount(const QModelIndex& = QModelIndex()) const override { return sol->getData().size(); }
    int columnCount(const QModelIndex& = QModelIndex()) const override { return headers.size(); }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) return headers[section];
        return QVariant();
    }

    QVariant data(const QModelIndex& index, int role) const override {
        if (!index.isValid() || (role != Qt::DisplayRole && role != Qt::EditRole)) return QVariant();
        const auto& item = sol->getData()[index.row()];

        if constexpr (std::is_same_v<T, Contact1>) {
            if (index.column() == 0) return item.name;
            if (index.column() == 1) return (qlonglong)item.tel1;
            if (index.column() == 2) return (qlonglong)item.tel2;
        } else {
            if (index.column() == 0) return item.name;
            if (index.column() == 1) return item.address;
            if (index.column() == 2) return (qlonglong)item.tel1;
        }
        return QVariant();
    }

    // РАЗРЕШАЕМ РЕДАКТИРОВАНИЕ
    Qt::ItemFlags flags(const QModelIndex& index) const override {
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    }

    // СОХРАНЯЕМ ИЗМЕНЕНИЯ
    bool setData(const QModelIndex& index, const QVariant& value, int role) override {
        if (role == Qt::EditRole) {
            auto& item = const_cast<T&>(sol->getData()[index.row()]); // Хитрость для изменения
            if constexpr (std::is_same_v<T, Contact1>) {
                if (index.column() == 0) item.name = value.toString();
                else if (index.column() == 1) item.tel1 = value.toLongLong();
                else if (index.column() == 2) item.tel2 = value.toLongLong();
            } else {
                if (index.column() == 0) item.name = value.toString();
                else if (index.column() == 1) item.address = value.toString();
                else if (index.column() == 2) item.tel1 = value.toLongLong();
            }
            emit dataChanged(index, index);
            return true;
        }
        return false;
    }
};
#endif
