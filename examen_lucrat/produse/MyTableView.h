//
// Created by munte on 21/06/2021.
//

#ifndef PRODUSE_MYTABLEVIEW_H
#define PRODUSE_MYTABLEVIEW_H


//
// Created by munte on 21/06/2021.
//

#ifndef SCREEN_WRITING_MYTABLEVIEW_H
#define SCREEN_WRITING_MYTABLEVIEW_H

#pragma once

#include <QAbstractTableModel>
#include "QBrush"
#include "Produse.h"

using std::vector;

class MyTableModel:public QAbstractTableModel{
private:
    int value;
    vector<Produs> products;

public:
    MyTableModel() {};

    MyTableModel(const vector<Produs>& products, int val) : products{products}, value {val}{};

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 5;
    }
    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return products.size();
    }

    void setProducts(const vector<Produs>& prds, int val) {
        value = val;
        this->products = prds;
        QModelIndex topLeft = createIndex(0, 0);
        QModelIndex bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);
        emit layoutChanged();
    }

    QVariant data(const QModelIndex& index, int role) const override {

        if (role == Qt::BackgroundRole) {
            Produs p = products[index.row()];
            if (p.getPrice() <= value ) {
                return QBrush{ Qt::green };
            }
        }

        if (role == Qt::DisplayRole) {
            Produs p =  products[index.row()];
            if (index.column() == 0) {
                return QString::fromStdString(to_string(p.getId()));
            }
            if (index.column() == 1) {
                return QString::fromStdString(p.getName());
            }
            if (index.column() == 2) {
                return QString::fromStdString(p.getType());
            }
            if (index.column() == 3) {
                return QString::fromStdString(std::to_string(p.getPrice()));
            }
            if (index.column() == 4) {
                return QString::fromStdString(std::to_string(p.get_nr_vocale(p.getName())));
            }

        }
        return QVariant{};
    }

};

#endif //SCREEN_WRITING_MYTABLEVIEW_H



#endif //PRODUSE_MYTABLEVIEW_H
