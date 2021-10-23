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

class WriterWindow : public Observer, QWidget {
public:
    void notifyObservers() {
        for (auto& o : observers) {
            o->update();
        }
    }
    string name_wrt;
    string wrt_exp;
    Service& serv;
    vector <Observer*>& observers;
    Writer& wrt;
    QVBoxLayout* layout;
    QTableView* tblView = new QTableView();
    MyTableModel* tbl = new MyTableModel();
    QLineEdit* description;
    QLineEdit* act;
    QPushButton* addIdea;
    QPushButton* revise;
    QPushButton* develop = new QPushButton("Develop an idea");
    QPushButton* save_plot;


    WriterWindow(Service& serv, vector<Observer*>& observers, Writer& wrt) : serv {serv}, observers{observers}, wrt{wrt}{
        name_wrt = wrt.getName();
        wrt_exp = wrt.getExpertise();
        initGUI();
        //update();
        make_connections();
    };
    void loadData(const vector<Idea>& ids);
    void update() override;
    void initGUI();
    void make_connections();

};

class GUIObserver: public QWidget, Observer{
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

private:
    Service& serv;
    vector<Observer*> observers;
    QVBoxLayout* layout;

public:
    GUIObserver(Service& service) : serv{ service } {
        initGUI();
        make_connections();
    }
    void initGUI();
    void update() override;
    void make_connections();

};


#endif //SCREEN_WRITING_GUIOBSERVER_H
