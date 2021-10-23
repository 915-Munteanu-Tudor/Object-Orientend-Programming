//
// Created by munte on 22/06/2021.
//

#ifndef EXAMNE_PRACTIC_GUIOBSERVER_H
#define EXAMNE_PRACTIC_GUIOBSERVER_H


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
#include "Service.h"

using std::vector;

//Clasa Observer cu metoda virtuala update
class Observer {
public:
    virtual void update() = 0;
};


class EthnologistWindow : public Observer, QWidget {
public:
    void notifyObservers() {
        for (auto& o : observers) {
            o->update();
        }
    }
    string name_eth;
    string them_area_eth;
    Ethnologist& eth;
    Service& serv;
    vector <Observer*>& observers;
    QVBoxLayout* layout;
    QTableWidget* table;
    QLineEdit* id;
    QLineEdit* coordinates;
    QLineEdit* description;
    QPushButton* addbtn;
    QLineEdit* updated_location;
    QLineEdit* updated_description;
    QPushButton* upbtn;


    EthnologistWindow(Service& serv, vector<Observer*>& observers, Ethnologist& eth) : serv {serv}, observers{observers}, eth{eth}{
        //update();
        name_eth = eth.getName();
        them_area_eth = eth.getThematicArea();
        initGUI();
        make_connections();
    };
    void loadData(const vector<Building> &bld);
    void update() override;
    void initGUI();
    void make_connections();

};


class GUIObserver : public QWidget, Observer{
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }
private:
    Service& serv;
    vector<Observer*> observers;
    QVBoxLayout* layout;
    QLineEdit* search;
    QListWidget* answers;
    QLabel* question;

public:
    GUIObserver(Service& service) : serv{ service } {
        initGUI();
        make_connections();
    }
    void initGUI();
    void update() override;
    void make_connections();

};



#endif //EXAMNE_PRACTIC_GUIOBSERVER_H
