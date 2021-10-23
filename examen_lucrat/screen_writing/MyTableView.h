//
// Created by munte on 21/06/2021.
//

#ifndef SCREEN_WRITING_MYTABLEVIEW_H
#define SCREEN_WRITING_MYTABLEVIEW_H

#pragma once

#include <QAbstractTableModel>
#include "Idea.h"

using std::vector;

class MyTableModel:public QAbstractTableModel{
private:
    vector<Idea> ideas;

public:
    MyTableModel() {};

    MyTableModel(const vector<Idea>& ideas) : ideas{ideas} {};

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }
    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return ideas.size();
    }

    void setIdeas(const vector<Idea>& ids) {
        this->ideas = ids;
        QModelIndex topLeft = createIndex(0, 0);
        QModelIndex bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);
        emit layoutChanged();
    }

    QVariant data(const QModelIndex& index, int role) const override {
        if (role == Qt::BackgroundRole) {
            Idea i = ideas[index.row()];
            if (i.getStatus() == "accepted") {
                return QBrush{ Qt::green }
            }
        }
        if (role == Qt::DisplayRole) {
            Idea i = ideas[index.row()];
            if (index.column() == 0) {
                return QString::fromStdString(i.getDescription());
            }
            if (index.column() == 1) {
                return QString::fromStdString(i.getStatus());
            }
            if (index.column() == 2) {
                return QString::fromStdString(i.getCreator());
            }
            if (index.column() == 3) {
                return QString::fromStdString(std::to_string(i.getAct()));
            }

        }
        return QVariant{};
    }

};

#endif //SCREEN_WRITING_MYTABLEVIEW_H
