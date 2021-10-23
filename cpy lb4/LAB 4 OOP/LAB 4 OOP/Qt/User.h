#pragma once
#include <QWidget>
#include <adoption.h>
#include <QListWidget>
#include "QTableWidget"
#include "QLineEdit"
#include "QGroupBox"
#include "QFormLayout"
#include "Service.h"

class MyTableModel;

class User : public QWidget {
public:
    RepoDog &repoDog;
    Service& service;
    std::unique_ptr<AdoptionList> adoptionList = nullptr;
    std::unique_ptr<AdoptionList> adoptionList0 = nullptr;
    //std::vector<Dog> adoptionList1;
    explicit User(RepoDog &repoDog, Service& service);

private:

    QTableView* tblView;
    //QItemSelectionModel* selectionModel;
    MyTableModel* tbl;
    QTableWidget* table;
    QLineEdit* name;
    QLineEdit* breed1;
    QLineEdit* age1;
    QPushButton* filtreaza;
    QListWidget* list_filtrat;
    QFormLayout* lyt_filtr;
    QGroupBox* grup_filtrare;

    static void showH();

    static void showC();

    void addDog();

    void populate_filtered();
};

class MyTableModel : public QAbstractTableModel {
    vector<Dog> dogs;


public:
    MyTableModel() = default;

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }
    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return dogs.size();
    }

    void setDogs(const std::vector<Dog>& dgs) {
        this->dogs = dgs;
        QModelIndex topLeft = createIndex(0, 0);
        QModelIndex bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);
        emit layoutChanged();
    }

    QVariant data(const QModelIndex& index , int role) const override {
        if (role == Qt::DisplayRole) {
            Dog d = dogs[index.row()];
            if (index.column() == 0)
                return QString::fromStdString(d.getBreed());
            if (index.column() == 1)
                return QString::fromStdString(d.getName());
            if (index.column() == 3)
                return QString::fromStdString(d.getPhoto());
            if (index.column() == 2) {
                return QString::fromStdString(to_string(d.getAge()));
            }
        }
        return QVariant{};
    }


    explicit MyTableModel(const vector<Dog>& dogs) : dogs{ dogs } {};
};