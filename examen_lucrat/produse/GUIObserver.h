//
// Created by munte on 21/06/2021.
//

#ifndef PRODUSE_GUIOBSERVER_H
#define PRODUSE_GUIOBSERVER_H

//
// Created by munte on 21/06/2021.
//

#ifndef SCREEN_WRITING_GUIOBSERVER_H
#define SCREEN_WRITING_GUIOBSERVER_H

#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QPainterPath>
#include <QtWidgets/QMainWindow>
#include <iostream>

#include <qstring.h>
#include <QString.h>
#include <QtWidgets/qwidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget.h>
#include <QFormLayout.h>
#include <QLineEdit.h>
#include <QPushButton.h>
#include <qDebug>
#include <QMessageBox.h>
#include <qpalette.h>
#include <qbrush.h>
#include <QTableWidget.h>
#include <QStandardItemModel.h>
#include <QHeaderView>
#include <QLabel.h>
#include <QPainter>
#include <QSpinBox.h>
#include <QTextEdit>
#include "Service.h"
#include "MyTableView.h"

using std::vector;

class Observer {
public:
    virtual void update() = 0;
};

class ProductWindow : public Observer, QWidget {
public:
    void notifyObservers() {
        for (auto& o : observers) {
            o->update();
        }
    }
    int prod_id;
    string prod_name;
    string prod_type;
    double prod_price;
    Service& serv;
    vector <Observer*>& observers;
    Produs& prod;
    QLabel* nm;
    QVBoxLayout* layout;
    QLabel* lbl;


    ProductWindow(Service& serv, vector<Observer*>& observers, Produs& prod) : serv {serv}, observers{observers}, prod{prod}{
        prod_id = prod.getId();
        prod_name = prod.getName();
        prod_type = prod.getType();
        prod_price = prod.getPrice();
        initGUI();
        //update();
        //make_connections();
    };
//    void loadData(const vector<Produs>& prds);
    void update() override;
    void initGUI();
    //void make_connections();

};

class GUIObserver: public QWidget, Observer{
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }


private:
    Service& serv;
    vector<Observer*> observers;
    QVBoxLayout* layout;
    QTableView* tblView = new QTableView();
    MyTableModel* tbl = new MyTableModel();
    QPushButton* addbtn;
    QLineEdit* new_id;
    QLineEdit* new_name;
    QLineEdit* new_type;
    QLineEdit* new_price;
    QSlider* slider;
    QHBoxLayout* hlayout;
    QLabel* sld_lbl;

public:
    void notifyObservers() {
        for (auto &o : observers) {
            o->update();
        }
    }

    GUIObserver(Service& service) : serv{ service } {
        initGUI();
        make_connections();
    }
    void loadData(const vector<Produs>& prds);
    void initGUI();
    void update() override;
    void make_connections();

};


#endif //SCREEN_WRITING_GUIOBSERVER_H


#endif //PRODUSE_GUIOBSERVER_H
